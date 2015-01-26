#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cv.h>
#include<highgui.h>
#include<sstream>
/*
using namespace std;

extern IplImage* img;
extern IplImage* element_d[30];
extern int cnt;

void mymouse(int event, int x, int y, int flag, void* param)
{
	static int oldx, oldy, now_down=0;

	if(event==CV_EVENT_LBUTTONDOWN){
		cvCircle(img, cvPoint(x,y), 8,cvScalar(0));		
		oldx=x;oldy=y;
		now_down=1;
		if(cnt==30){cout<<"Limit exceeded!"<<endl; return;}
	}
	if(event==CV_EVENT_LBUTTONUP){
		now_down=0;
		cnt++;
	}
	if(event==CV_EVENT_MOUSEMOVE && now_down==1){
		cvLine(img, cvPoint(x,y), cvPoint(oldx, oldy), cvScalar(0),5,8);
		cvLine(element_d[cnt], cvPoint(x,y), cvPoint(oldx, oldy), cvScalar(0),5,CV_AA);
		oldx=x;oldy=y;
	}
	cvShowImage("Board", img); 
}

int element_capture()
{
	img=cvCreateImage(  cvSize(500,500), IPL_DEPTH_8U, 1);
	cvSet(img, cvScalar(255));
	for(int i=0; i<30; i++){
		element_d[i]=cvCreateImage(cvSize(500,500),IPL_DEPTH_8U, 1);
		cvSet(element_d[i],cvScalar(255));
	}
	system("TITLE Stroke_Record_Test_V1");
	cout<<"Press any key after finishing all the strokes!"<<endl;
	cout<<"Press any key to begin recording!"<<endl;
	system("pause");
	cvShowImage("Board", img);
    
	cvSetMouseCallback("Board", mymouse);	
	cvWaitKey(0);
	cvDestroyWindow("Board");
	
	for(int i=0; i<cnt; i++){
		cvShowImage("Display",element_d[i]);
		string name;
		stringstream ss;
		ss<<i;
		name = ss.str() + ".bmp";		
		cvSaveImage(name.c_str(),element_d[i]);
		cvWaitKey(0);
	}

	return 0;	
}
*/