#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cv.h>
#include<highgui.h>
#include<sstream>
#include<vector>
#include"stdafx.h"
#include <fstream>
#include <sstream>

IplImage* img;
extern int p;
extern bool thread_flag;
extern bool brush;
bool past_brush;
bool hor_clr[400];
bool ver_clr[1100];
double vertical_distance=0;
double ver_bound=0;
int horizontal_distance[10];
int cnt=0;
double avg_hor_diatance;
double word_height=0;
double word_width=0;

using namespace std;

void analyze(){
	//array init
	for(int p=0; p<400; p++){
		hor_clr[p]=false;
	}
	for(int p=0; p<1100; p++){
		ver_clr[p]=false;
	}
	std::fstream out;
	out.open("multi_char_data.txt",ios::out);
	IplImage* img_bin;
	img_bin = cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
	cvZero(img_bin);
	cvThreshold(img,img_bin,254,1,CV_THRESH_BINARY_INV);
	CvSize size = cvGetSize(img_bin);

	//distant between rows

	for(int hor=0; hor<size.height; hor++){
		bool cl=true;
		for(int ver=0; ver<size.width; ver++){
			if(CV_IMAGE_ELEM(img_bin,uchar,hor,ver)==1){
				cl=false;
			}
		}
		hor_clr[hor]=cl;
	}
	bool first_contact=true;
	bool second_contact=false;
	for(int check=0; check<400; check++){
		if((hor_clr[check]==true && first_contact==false)&&second_contact==false){
			vertical_distance++;
			if(ver_bound==0){
				ver_bound=check;
			}
		}
		if(hor_clr[check]==false){
			if(second_contact==false){
				word_height++;
			}
			first_contact=false;
		}
		if(vertical_distance!=0&&hor_clr[check]==false){
			second_contact=true;
		}
	}
	out<<(double)(vertical_distance/word_height); out<<" ";

	//distant between characters in the same row

	for(int ver=0; ver<1100; ver++){
		bool cl=true;
		for(int hor=0; hor<ver_bound; hor++){
			if(CV_IMAGE_ELEM(img_bin,uchar,hor,ver)==1){
				cl=false;
			}
		}
		ver_clr[ver]=cl;
	}

	bool between_char=false; bool last_good=false;
	for(int ver=0; ver<1100; ver++){
		if(ver_clr[ver]==false && between_char==false){
			between_char=true;
		}
		if(ver_clr[ver]==false&&cnt==0){
			word_width++;
		}
		if(ver_clr[ver]==true && between_char == true){
			horizontal_distance[cnt]++; last_good=true;
		}
		if((ver_clr[ver]==false && between_char==true)&&last_good==true){
			cnt++;	last_good=false;
		}
	}
	int sum=0; int sum_cnt=0; bool first=true;
	for(int i=9; i>-1; i--){
		if(horizontal_distance[i]>40){
			if(first==true){first=false; continue;}
			sum+=horizontal_distance[i];	sum_cnt++;
		}
	}
	avg_hor_diatance=sum/sum_cnt;
	out<<(double)(avg_hor_diatance/word_width);

	out.close();
}

int getbrush_width(){
	int width;
	width=p/15+1;
	return width;
}

void mymouse(int event, int x, int y, int flag, void* param)
{

	static int oldx, oldy, now_down=0;

	if(//event==CV_EVENT_LBUTTONDOWN
		brush==true && past_brush==false
		){
			//cvCircle(img, cvPoint(x,y), 8,cvScalar(0));		
			oldx=x;oldy=y;
			now_down=1;
			past_brush=true;
			//if(cnt==30){cout<<"Limit exceeded!"<<endl; return;}
	}
	if(//event==CV_EVENT_LBUTTONUP
		past_brush==true && brush==false
		){
			past_brush=false;
			now_down=0;
			//cnt++;
	}
	if(//event==CV_EVENT_MOUSEMOVE && 
		now_down==1){
			cvLine(img, cvPoint(x,y), cvPoint(oldx, oldy), cvScalar(0),getbrush_width(),CV_AA);
			//cvLine(out, cvPoint(x,y), cvPoint(oldx, oldy), cvScalar(0),getbrush_width(),CV_AA);
			//cvLine(element_d[cnt], cvPoint(x,y), cvPoint(oldx, oldy), cvScalar(0),getbrush_width(),CV_AA);
			oldx=x;oldy=y;
	}
	cvShowImage("Board", img); 
}



void start_draw(){
	img=cvCreateImage(  cvSize(1100,400), IPL_DEPTH_8U, 1);
	cvSet(img, cvScalar(255));
	cvShowImage("Board", img);
	//cv::moveWindow("Board", 750, 225);
	cvSetMouseCallback("Board", mymouse);	
	cvWaitKey(0);
	cvDestroyWindow("Board");
	analyze();
	cvSaveImage("Full_Char.bmp",img);
	exit(0);
	thread_flag=false;

}