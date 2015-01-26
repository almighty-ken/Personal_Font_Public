#include "capture.h"
#include <QApplication>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cv.h>
#include<highgui.h>
#include<sstream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Capture w;

	//w.setWindowTitle("sdfghgfd");
	w.show();
	//element_capture();
	return a.exec();
}
