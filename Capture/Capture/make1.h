#include<cv.h>
#include<highgui.h>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;

extern IplImage *word;
extern IplImage *component;
extern IplImage *cutcomponent;
extern IplImage *newcomponent;
extern int newheight,newwidth,w,h,x,y;

int make1();