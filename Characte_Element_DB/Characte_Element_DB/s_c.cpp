//Coded by Almighty_Ken
//All rights reserved
//Project code: Data Base Fast Builder

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cv.h>
#include <highgui.h>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;


struct point{
	//Simple coordination presentation method
	int sn,x,y;
};

/*
struct stroke{
//sn for serial number, start and end for the endpoints
int sn; int type;	point start;	point end;	double m,k;
};
*/

/*
struct cross{
//sn for serial number, followed by the serial of the crossing strokes
//s for the crossing point, s1_p, s2_p for the percentage of the point on the stroke
int sn,stroke_sn1,stroke_sn2; 	point s;	float s1_p,s2_p;
};
*/

struct element{
	point p1,p2;
	int e_sn;
};

struct Cchar{
	int e_cnt; int sn;
	element c_data[10];
};

struct Cchar_dat{
	int e_cnt; int sn;
	int e_sn[10];
};


//These parameters should be changed every time
int start_sn;

IplImage* disp;
IplImage* t_disp;
char filename[]="database.txt";
CvPoint textpos;
int current_sn;
string filename_c;
Cchar temp;
CvFont Font1=cvFont(1,1);
fstream fp;
int clsflag=0;
int oldx, oldy, fl=0, csn_str=0, newx, newy;
Cchar_dat elem_data[3750];
/*
void auto_cross(){
for(int i=0; i<temp.stroke_cnt; i++){
temp.s_data[i].m=(double)(temp.s_data[i].start.y-temp.s_data[i].end.y)/(double)(temp.s_data[i].start.x-temp.s_data[i].end.x);
temp.s_data[i].k=(double)((temp.s_data[i].start.y*temp.s_data[i].end.x)-(temp.s_data[i].start.x*temp.s_data[i].end.y))/(double)(temp.s_data[i].start.x-temp.s_data[i].end.x);
}
for(int i=0; i<temp.stroke_cnt; i++)
for(int j=i+1; j<temp.stroke_cnt; j++){
double delta=temp.s_data[j].m-temp.s_data[i].m;
double deltax=temp.s_data[j].k-temp.s_data[i].k;
double deltay=(temp.s_data[i].m*temp.s_data[j].k)-(temp.s_data[j].m*temp.s_data[i].k);
int coordx,coordy; coordx=deltax/delta; coordy=deltay/delta;
if((coordx-(temp.s_data[i].start.x))*(coordx-(temp.s_data[i].end.x))<0){
if((coordx-(temp.s_data[j].start.x))*(coordx-(temp.s_data[j].end.x))<0){					
temp.c_data[temp.cross_cnt].sn=temp.cross_cnt;
temp.c_data[temp.cross_cnt].stroke_sn1=i;
temp.c_data[temp.cross_cnt].stroke_sn1=j;
temp.c_data[temp.cross_cnt].s.sn=-1;
temp.c_data[temp.cross_cnt].s.x=coordx;
temp.c_data[temp.cross_cnt].s.y=coordy;							
temp.c_data[temp.cross_cnt].s1_p=sqrtf((coordx-temp.s_data[i].start.x)*(coordx-temp.s_data[i].start.x)+
(coordy-temp.s_data[i].start.y)*(coordy-temp.s_data[i].start.y));
temp.c_data[temp.cross_cnt].s2_p=sqrtf((coordx-temp.s_data[j].start.x)*(coordx-temp.s_data[j].start.x)+
(coordy-temp.s_data[j].start.y)*(coordy-temp.s_data[j].start.y));
cvRectangle(disp,cvPoint(coordx-20,coordy-20),cvPoint(coordx+20,coordy+20),cvScalarAll(temp.cross_cnt*30),3);
temp.cross_cnt++;


}

}
}
}
*/

void elem_data_init(){
	char filename[]="elem_data.txt";
	ifstream scan;
	char input[5];
	scan.open(filename,ios::in);
	if(!scan){
		std::cout<<"fail to read database"<<endl;
	}

	for(int i=1; i<3750; i++){
		scan.getline(input,sizeof(input),' ');
		int c_sn=atoi(input);
		if(c_sn!=i){cout<<"Unexpected database read error"<<endl;}
		scan.getline(input,sizeof(input),' ');
		int elem_cnt=atoi(input);
		elem_data[i].sn=i;
		elem_data[i].e_cnt=elem_cnt;
		for(int j=0; j<elem_cnt; j++){
			scan.getline(input,sizeof(input),' ');
			int elem=atoi(input);
			elem_data[i].e_sn[j]=elem;
		}
	}
}



void printnreset_temp_char(){
	//print section
	fp<<temp.sn; fp<<" "; fp<<temp.e_cnt;
	//data are being presented by the Loc point and size
	for(int i=0; i<temp.e_cnt; i++){
		fp<<" ";	fp<<i; fp<<" ";	fp<<temp.c_data[i].e_sn; fp<<" "; fp<<temp.c_data[i].p1.x; fp<<" "; fp<<temp.c_data[i].p1.y; fp<<" ";
		fp<<temp.c_data[i].p2.x-temp.c_data[i].p1.x;	fp<<" "; fp<<temp.c_data[i].p2.y-temp.c_data[i].p1.y;
	}
	fp<<endl;

	//reset section
	for(int i=0; i<10; i++){
		temp.c_data[i].e_sn=0; temp.c_data[i].p1.x=0;
		temp.c_data[i].p1.sn=0; temp.c_data[i].p1.y=0;
	}		
	fl=0;
	csn_str=0;
	temp.sn=0;
}


void mouse_str(int event, int x, int y, int flag, void* param)
{
	t_disp=cvCloneImage(disp);
	cvLine(t_disp,cvPoint(x,0),cvPoint(x,500),cvScalar(0),2);
	cvLine(t_disp,cvPoint(0,y),cvPoint(500,y),cvScalar(0),2);
	cvShowImage(filename_c.c_str(), t_disp); 
	if(event==CV_EVENT_LBUTTONDOWN&&fl==0){
		cvCircle(disp, cvPoint(x,y), 10,cvScalar(0),3);
		cvCircle(t_disp, cvPoint(x,y), 10,cvScalar(0),3);
		oldx=x; oldy=y; fl=1;
	}else{
		if(event==CV_EVENT_LBUTTONDOWN&&fl==1){
			cvCircle(disp, cvPoint(x,y), 15,cvScalar(0),3);
			cvLine(disp,cvPoint(oldx,oldy),cvPoint(x,oldy),cvScalar(0),1.5);
			cvLine(disp,cvPoint(oldx,oldy),cvPoint(oldx,y),cvScalar(0),1.5);
			cvLine(disp,cvPoint(x,y),cvPoint(x,oldy),cvScalar(0),1.5);
			cvLine(disp,cvPoint(x,y),cvPoint(oldx,y),cvScalar(0),1.5);
			cvCircle(t_disp, cvPoint(x,y), 15,cvScalar(0),3,1.5);
			cvLine(t_disp,cvPoint(oldx,oldy),cvPoint(x,oldy),cvScalar(0),1.5);
			cvLine(t_disp,cvPoint(oldx,oldy),cvPoint(oldx,y),cvScalar(0),1.5);
			cvLine(t_disp,cvPoint(x,y),cvPoint(x,oldy),cvScalar(0),1.5);
			cvLine(t_disp,cvPoint(x,y),cvPoint(oldx,y),cvScalar(0),1.5);
			newx=x; newy=y; fl=0;
			temp.c_data[csn_str].p1.x=oldx;
			temp.c_data[csn_str].p1.y=oldy;
			temp.c_data[csn_str].p2.x=newx;
			temp.c_data[csn_str].p2.y=newy;
			csn_str++;

			string t; stringstream st; st<<csn_str;
			t="Element "+st.str()+" finished.";
			cvPutText(disp,t.c_str(),cvPoint(10,csn_str*10+20),&Font1,cvScalar(0));
		}
	}
	if(event==CV_EVENT_RBUTTONDOWN){
		//the actual amount of strokes
		temp.e_cnt=csn_str;
		cvPutText(disp,"Element data saved, press any key to continue",cvPoint(10,450),&Font1,cvScalar(0));
		cvPutText(t_disp,"Element data saved, press any key to continue",cvPoint(10,450),&Font1,cvScalar(0));
	}
	cvReleaseImage(&t_disp);

}

int main(){
	elem_data_init();
	fp.open(filename,ios::out|ios::app);
	if(!fp){
		cout<<"Fail to open file!"<<endl;
		system("pause");
	}	
	//cout<<"File Descriptor: "<<fp<<endl;
	cout<<"Please input the serial number of the character to start"<<endl;
	cin>>start_sn; current_sn=start_sn;

	//enter main loop
	while(1){
		stringstream ss;	string snumber; 
		temp.sn=current_sn;
		ss<<current_sn;
		if(current_sn<10){snumber="000"+ss.str();}
		if(current_sn<100&&current_sn>9){snumber="00"+ss.str();}
		if(current_sn<1000&&current_sn>99){snumber="0"+ss.str();}
		if(current_sn<10000&&current_sn>999){snumber=ss.str();}
		filename_c=snumber+".bmp";
		disp = cvLoadImage(filename_c.c_str(),CV_LOAD_IMAGE_GRAYSCALE);		
		textpos=cvPoint(10,20);
		cvPutText(disp,filename_c.c_str(),textpos,&Font1,cvScalar(0));
		cvLine(disp, cvPoint(100,0), cvPoint(100, 500), cvScalar(0));
		cvLine(disp, cvPoint(200,0), cvPoint(200, 500), cvScalar(0));
		cvLine(disp, cvPoint(300,0), cvPoint(300, 500), cvScalar(0));
		cvLine(disp, cvPoint(400,0), cvPoint(400, 500), cvScalar(0));
		cvLine(disp, cvPoint(0,100), cvPoint(500, 100), cvScalar(0));
		cvLine(disp, cvPoint(0,200), cvPoint(500, 200), cvScalar(0));
		cvLine(disp, cvPoint(0,300), cvPoint(500, 300), cvScalar(0));
		cvLine(disp, cvPoint(0,400), cvPoint(500, 400), cvScalar(0));

		cvShowImage(filename_c.c_str(),disp);
		cvSetMouseCallback(filename_c.c_str(),mouse_str);
		cvWaitKey(0);
		//system("pause");

		for(int j=0; j<temp.e_cnt; j++){
			int e_type;
			e_type=elem_data[current_sn].e_sn[j];
			temp.c_data[j].e_sn=e_type;
		}		
		cvDestroyWindow(filename_c.c_str());
		//string n_windowname; n_windowname=filename_c+" With cross";
		//cvShowImage(n_windowname.c_str(),disp);
		//cvWaitKey(0);
		//cvDestroyWindow(n_windowname.c_str());
		printnreset_temp_char();
		cvReleaseImage(&t_disp);
		cvReleaseImage(&disp);
		cvReleaseImage(&t_disp);
		cvReleaseImageHeader(&t_disp);
		cvReleaseImageHeader(&disp);
		cvReleaseImageHeader(&t_disp);
		//several minor bugs following
		cout<<"continue work? y=0 n=1"<<endl;
		cin>>clsflag;
		if(clsflag==1){break;}
		current_sn++;
		system("cls");
	}
	fp.close();
	cout<<"Succesfully ended this work section";
}
