#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cv.h>
#include<highgui.h>
#include<sstream>
#include<vector>
#include"stdafx.h"

IplImage* img;
IplImage* out;
IplImage* element_d[50];
int cnt=0;
extern int p;
extern bool thread_flag;
extern bool brush;
bool past_brush;

int getbrush_width(){
	int width;
	width=p/20;
	return width;
}

void mymouse(int event, int x, int y, int flag, void* param)
{

	static int oldx, oldy, now_down=0;

	if(//event==CV_EVENT_LBUTTONDOWN
		brush==true && past_brush==false
		){
			cvCircle(img, cvPoint(x,y), 8,cvScalar(0));		
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
			cnt++;
	}
	if(//event==CV_EVENT_MOUSEMOVE && 
		now_down==1){
			//cvCircle(img, cvPoint(x,y),getbrush_width(),cvScalar(0),-1);
			cvLine(img, cvPoint(x,y), cvPoint(oldx, oldy), cvScalar(0),getbrush_width()+1,CV_AA);
			cvLine(out, cvPoint(x,y), cvPoint(oldx, oldy), cvScalar(0),getbrush_width()+1,CV_AA);
			cvLine(element_d[cnt], cvPoint(x,y), cvPoint(oldx, oldy), cvScalar(0),getbrush_width()+1,CV_AA);
			oldx=x;oldy=y;
	}
	cvShowImage("Board", img); 
}



void start_draw(){
	img=cvCreateImage(  cvSize(500,500), IPL_DEPTH_8U, 1);
	out=cvCreateImage(  cvSize(500,500), IPL_DEPTH_8U, 1);
	cvSet(img, cvScalar(255));
	cvSet(out, cvScalar(255));
	for(int i=0; i<30; i++){
		element_d[i]=cvCreateImage(cvSize(500,500),IPL_DEPTH_8U, 1);
		cvSet(element_d[i],cvScalar(255));
	}

	//	system("TITLE Stroke_Record_Test_V1");
	//	cout<<"Press any key after finishing all the strokes!"<<endl;
	//	cout<<"Press any key to begin recording!"<<endl;
	//	system("pause");
	cvShowImage("Board", img);

	cvSetMouseCallback("Board", mymouse);	
	cvWaitKey(0);

	cvDestroyWindow("Board");

	cvSaveImage("Full_Char.bmp",out);
	for(int i=0; i<cnt; i++){
		cvShowImage("Display",element_d[i]);
		std::string name;
		std::stringstream ss;
		ss<<i;
		name = ss.str() + ".bmp";		
		cvSaveImage(name.c_str(),element_d[i]);
		cvWaitKey(0);
	}
	thread_flag=false;
}