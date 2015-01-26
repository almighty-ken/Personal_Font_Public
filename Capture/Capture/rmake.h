
#include<cv.h>
#include<highgui.h>
#include<cstdio>
#include<string>
#include<cmath>
#include<iostream>
#include<fstream>
using namespace std;

IplImage *created_char;
IplImage *component;
IplImage *cutcomponent;
IplImage *newcomponent;
int newheight,newwidth,w,h,x,y;

void Search(){
	int top=-1,down=-1,right=-1,left=-1;
	for(int i=0 ; i<component->height ; i++){
		for(int j=0 ; j<component->widthStep ; j++){
			if(component->imageData[i*component->widthStep + j]==0){
				top=i;
				break;
			}
		}
		if(top!=-1){
			break;
		}
	}
	for(int i=component->height-1 ; i>=0 ; i--){
		for(int j=0 ; j<component->widthStep ; j++){
			if(component->imageData[i*component->widthStep + j]==0){
				down=i;
				break;
			}
		}
		if(down!=-1){
			break;
		}
	}
	for(int i=0 ; i<component->widthStep ; i++){
		for(int j=0 ; j<component->height ; j++){
			if(component->imageData[j*component->widthStep + i]==0){
				left=i;
				break;
			}
		}
		if(left!=-1){
			break;
		}
	}
	for(int i=component->widthStep-1 ; i>=0 ; i--){
		for(int j=0 ; j<component->height ; j++){
			if(component->imageData[j*component->widthStep + i]==0){
				right=i;
				break;
			}
		}
		if(right!=-1){
			break;
		}
	}
	int k=15;
	top=top-k;
	down=down+k;
	right=right+k;
	left=left-k;
	newheight = down-top;
	newwidth = right-left;
	CvSize cutsize;
	cutsize.height = newheight;
	cutsize.width = newwidth;
	cutcomponent = cvCreateImage(cutsize,component->depth,1);
	cvSet(cutcomponent , cvScalar(255));
	for(int i=k ; i<cutcomponent->height-k ; i++){
		for(int j=k ; j<cutcomponent->width-k ; j++){
			cutcomponent->imageData[i*cutcomponent->widthStep+j] =component->imageData[(top+i)*component->widthStep+(left+j)];
		}
	}
	return;
}

void Replace(){
	CvSize newsize;
	newsize.height = h;
	newsize.width =  w;
	newcomponent = cvCreateImage(newsize,component->depth,1);
	cvSet(newcomponent , cvScalar(255));
	cvResize(cutcomponent,newcomponent,CV_INTER_CUBIC);
	for(int i=0 ; i<newcomponent->height ; i++){
		for(int j=0 ; j<newcomponent->width ; j++){
			if(newcomponent->imageData[i*newcomponent->widthStep+j] != -1){
				newcomponent->imageData[i*newcomponent->widthStep+j] = 0;
			}
		}
	}
	for(int i=0 ; i<newcomponent->height ; i++){
		for(int j=0 ; j<newcomponent->width ; j++){
			if(created_char->imageData[(y+i)*created_char->widthStep+(x+j)]==-1){
				created_char->imageData[(y+i)*created_char->widthStep+(x+j)] = newcomponent->imageData[i*newcomponent->widthStep+j];
			}
		}
	}
}

void Input(){
	string s;
	int cpn_num; int cpn_type;
	scanf("%d",&cpn_num);
	scanf("%d",&cpn_type);
	scanf("%d %d",&x,&y);
	scanf("%d %d",&w,&h);
	stringstream ss(s);
	ss << cpn_type;
	s = ss.str();
	s = "./personal_comp/"+s + ".bmp";
	component = cvLoadImage(s.c_str(),0);
	return ;
}

void cvThin( IplImage* src, IplImage* dst, int iterations)
{
	CvSize size = cvGetSize(src);
	cvCopy(src, dst);

	int n = 0,i = 0,j = 0;
	for(n=0; n<iterations; n++)
	{
		IplImage* t_image = cvCloneImage(dst);

		for(i=0; i<size.height;  i++)
		{
			for(j=0; j<size.width; j++)
			{
				if(CV_IMAGE_ELEM(t_image,uchar,i,j)==1)
				{
					int ap=0;
					int p2 = (i==0)?0:CV_IMAGE_ELEM(t_image,uchar, i-1, j);
					int p3 = (i==0 || j==size.width-1)?0:CV_IMAGE_ELEM(t_image,uchar, i-1, j+1);
					if (p2==0 && p3==1)
					{
						ap++;
					}

					int p4 = (j==size.width-1)?0:CV_IMAGE_ELEM(t_image,uchar,i,j+1);
					if(p3==0 && p4==1)
					{
						ap++;
					}

					int p5 = (i==size.height-1 || j==size.width-1)?0:CV_IMAGE_ELEM(t_image,uchar,i+1,j+1);
					if(p4==0 && p5==1)
					{
						ap++;
					}

					int p6 = (i==size.height-1)?0:CV_IMAGE_ELEM(t_image,uchar,i+1,j);
					if(p5==0 && p6==1)
					{
						ap++;
					}

					int p7 = (i==size.height-1 || j==0)?0:CV_IMAGE_ELEM(t_image,uchar,i+1,j-1);
					if(p6==0 && p7==1)
					{
						ap++;
					}

					int p8 = (j==0)?0:CV_IMAGE_ELEM(t_image,uchar,i,j-1);
					if(p7==0 && p8==1)
					{
						ap++;
					}

					int p9 = (i==0 || j==0)?0:CV_IMAGE_ELEM(t_image,uchar,i-1,j-1);
					if(p8==0 && p9==1)
					{
						ap++;
					}
					if(p9==0 && p2==1)
					{
						ap++;
					}

					if((p2+p3+p4+p5+p6+p7+p8+p9)>1 && (p2+p3+p4+p5+p6+p7+p8+p9)<7)
					{
						if(ap==1)
						{
							if(!(p2 && p4 && p6))
							{
								if(!(p4 && p6 && p8)) 
								{
									CV_IMAGE_ELEM(dst,uchar,i,j)=0;
								}
							}
						}
					}

				}
			}
		}

		cvReleaseImage(&t_image);

		t_image = cvCloneImage(dst);

		for(i=0; i<size.height;  i++)
		{
			for(int j=0; j<size.width; j++)
			{
				if(CV_IMAGE_ELEM(t_image,uchar,i,j)==1)
				{
					int ap=0;
					int p2 = (i==0)?0:CV_IMAGE_ELEM(t_image,uchar, i-1, j);
					int p3 = (i==0 || j==size.width-1)?0:CV_IMAGE_ELEM(t_image,uchar, i-1, j+1);
					if (p2==0 && p3==1)
					{
						ap++;
					}
					int p4 = (j==size.width-1)?0:CV_IMAGE_ELEM(t_image,uchar,i,j+1);
					if(p3==0 && p4==1)
					{
						ap++;
					}
					int p5 = (i==size.height-1 || j==size.width-1)?0:CV_IMAGE_ELEM(t_image,uchar,i+1,j+1);
					if(p4==0 && p5==1)
					{
						ap++;
					}
					int p6 = (i==size.height-1)?0:CV_IMAGE_ELEM(t_image,uchar,i+1,j);
					if(p5==0 && p6==1)
					{
						ap++;
					}
					int p7 = (i==size.height-1 || j==0)?0:CV_IMAGE_ELEM(t_image,uchar,i+1,j-1);
					if(p6==0 && p7==1)
					{
						ap++;
					}
					int p8 = (j==0)?0:CV_IMAGE_ELEM(t_image,uchar,i,j-1);
					if(p7==0 && p8==1)
					{
						ap++;
					}
					int p9 = (i==0 || j==0)?0:CV_IMAGE_ELEM(t_image,uchar,i-1,j-1);
					if(p8==0 && p9==1)
					{
						ap++;
					}
					if(p9==0 && p2==1)
					{
						ap++;
					}
					if((p2+p3+p4+p5+p6+p7+p8+p9)>1 && (p2+p3+p4+p5+p6+p7+p8+p9)<7)
					{
						if(ap==1)
						{
							if(p2*p4*p8==0)
							{
								if(p2*p6*p8==0)
								{
									CV_IMAGE_ELEM(dst, uchar,i,j)=0;
								}
							}
						}
					}                    
				}

			}

		}            
		cvReleaseImage(&t_image);
	}

}

void Thining(){
	IplImage *pSrc = NULL,*pDst = NULL,*pTmp = NULL;
	pSrc = cvCreateImage(cvGetSize(created_char),created_char->depth,created_char->nChannels);
	cvCopy(created_char,pSrc,NULL);

	pTmp = cvCloneImage(pSrc);
	pDst = cvCreateImage(cvGetSize(pSrc),pSrc->depth,pSrc->nChannels);
	cvZero(pDst);
	cvThreshold(pSrc,pTmp,68,1,CV_THRESH_BINARY_INV);

	cvThin(pTmp,pDst,18);

	//	cvNamedWindow("src",1);
	//	cvNamedWindow("dst",1);
	//	cvShowImage("src",pSrc);

	int i = 0,j = 0;
	CvSize size = cvGetSize(pDst);
	for(i=0; i<size.height;  i++)
	{
		for(j=0; j<size.width; j++)
		{
			if(CV_IMAGE_ELEM(pDst,uchar,i,j)==1)
			{
				CV_IMAGE_ELEM(pDst,uchar,i,j) = 0;
			}
			else
			{
				CV_IMAGE_ELEM(pDst,uchar,i,j) = 255;
			}
		}
	}
	cvCopy(pDst,created_char,NULL);
	//	cvSaveImage("dst_8.bmp",pDst);

	//	cvShowImage("dst",pDst);
	//	cvWaitKey(0);

	cvReleaseImage(&pSrc);
	cvReleaseImage(&pDst);
	cvReleaseImage(&pTmp);

	//	cvDestroyWindow("src");
	//	cvDestroyWindow("dst");

	return ;
}

void cvExpand( IplImage* src, IplImage* dst, int iterations)
{
	CvSize size = cvGetSize(src);
	cvCopy(src, dst);

	int n = 0,i = 0,j = 0;
	for(n=0; n<iterations; n++)
	{
		IplImage* t_image = cvCloneImage(dst);

		for(i=1; i<size.height;  i++)
		{
			for(j=1; j<size.width; j++)
			{
				if(CV_IMAGE_ELEM(t_image,uchar,i,j)==0)
				{
					int cnt=0;
					if(CV_IMAGE_ELEM(t_image,uchar,i-1,j-1)==1){
						cnt++;
					}
					if(CV_IMAGE_ELEM(t_image,uchar,i,j-1)==1){
						cnt++;
					}
					if(CV_IMAGE_ELEM(t_image,uchar,i+1,j-1)==1){
						cnt++;
					}
					if(CV_IMAGE_ELEM(t_image,uchar,i-1,j)==1){
						cnt++;
					}
					if(CV_IMAGE_ELEM(t_image,uchar,i-1,j+1)==1){
						cnt++;
					}
					if(CV_IMAGE_ELEM(t_image,uchar,i,j+1)==1){
						cnt++;
					}
					if(CV_IMAGE_ELEM(t_image,uchar,i+1,j+1)==1){
						cnt++;
					}
					if(CV_IMAGE_ELEM(t_image,uchar,i+1,j)==1){
						cnt++;
					}
					if(cnt!=0){
						CV_IMAGE_ELEM(dst,uchar,i,j)=1;
					}
				}
			}
		}
	}
}

void Expanding()
{
	IplImage *pSrc = NULL,*pDst = NULL,*pTmp = NULL;

	pSrc = cvCreateImage(cvGetSize(created_char),created_char->depth,created_char->nChannels);
	cvCopy(created_char,pSrc,NULL);

	pTmp = cvCloneImage(pSrc);
	pDst = cvCreateImage(cvGetSize(pSrc),pSrc->depth,pSrc->nChannels);
	cvZero(pDst);
	cvThreshold(pSrc,pTmp,254,1,CV_THRESH_BINARY_INV);

	//	cvShowImage("disp",pTmp);
	int itercnt=3;
	//	cout<<"Input the iteration count"<<endl;
	//	cin >> itercnt;

	cvExpand(pTmp,pDst,itercnt);

	//	cvNamedWindow("src",1);
	//	cvNamedWindow("dst",1);
	//	cvShowImage("src",pSrc);

	int i = 0,j = 0;
	CvSize size = cvGetSize(pDst);
	for(i=0; i<size.height;  i++)
	{
		for(j=0; j<size.width; j++)
		{
			if(CV_IMAGE_ELEM(pDst,uchar,i,j)==1)
			{
				CV_IMAGE_ELEM(pDst,uchar,i,j) = 0;
			}
			else
			{
				CV_IMAGE_ELEM(pDst,uchar,i,j) = 255;
			}
		}
	}
	//	cvSaveImage("dst_8.bmp",pDst);

	//	cvShowImage("dst",pDst);
	//	cvWaitKey(0);

	cvCopy(pDst,created_char,NULL);

	cvReleaseImage(&pSrc);
	cvReleaseImage(&pDst);
	cvReleaseImage(&pTmp);

	//	cvDestroyWindow("src");
	//	cvDestroyWindow("dst");

	return ;
}

int make1(){
	freopen("database.txt","r",stdin);
	int num,amount;
	string Filename;
	while(scanf("%d",&num)!=EOF){
		Filename = "";
		scanf("%d",&amount);
		created_char = cvCreateImage(cvSize(500,500),IPL_DEPTH_8U,1);
		for(int i=0 ; i<created_char->width ; i++){
			for(int j=0  ; j<created_char->height ; j++){
				created_char->imageData[i*created_char->width+j]=255;
			}
		}
		for(int i=0 ; i<amount ; i++){
			Input();
			Search();
			Replace();
			cvReleaseImage(&component);
			cvReleaseImage(&cutcomponent);
			cvReleaseImage(&newcomponent);
		}
		//		Thining();
		//		Expanding();
		stringstream ss(Filename);
		ss << num;
		Filename = ss.str();
		Filename = "./personal_font/test" + Filename + ".bmp";
		cvSaveImage(Filename.c_str() , created_char);
		cvReleaseImage(&created_char);
	}
	return 0;
}

void make_specific(int sn){
	freopen("database.txt","r",stdin);
	int num,amount; int trash;
	string Filename;
	while(scanf("%d",&num)!=EOF){
		if(num==sn){
			Filename = "";
			scanf("%d",&amount);
			created_char = cvCreateImage(cvSize(500,500),IPL_DEPTH_8U,1);
			for(int i=0 ; i<created_char->width ; i++){
				for(int j=0  ; j<created_char->height ; j++){
					created_char->imageData[i*created_char->width+j]=255;
				}
			}
			for(int i=0 ; i<amount ; i++){
				Input();
				Search();
				Replace();
				cvReleaseImage(&component);
				cvReleaseImage(&cutcomponent);
				cvReleaseImage(&newcomponent);
			}
			//		Thining();
			//		Expanding();
			stringstream ss(Filename);
			ss << num;
			Filename = ss.str();
			Filename = "./personal_font/test" + Filename + ".bmp";
			cvSaveImage(Filename.c_str() , created_char);
			cvReleaseImage(&created_char);
			return;
		}
		else{
			scanf("%d",&amount);		
			for(int i=0 ; i<amount ; i++){
				scanf("%d",&trash);
				scanf("%d",&trash);
				scanf("%d %d",&trash,&trash);
				scanf("%d %d",&trash,&trash);
			}
		}

	}

}