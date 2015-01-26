#include "capture.h"
#include "rmake.h"
#include <QPixmap>
#include <QStringList>
#include <Windows.h>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <QLCDNumber>



int a;
int b = 1;
using namespace std;
int input_thread=0;
int input_arr[373];
bool firstrun=true;

void init_database(){
	ifstream getsequence;
	char filename[]="user_input_sequence.txt";
	char input[5];
	getsequence.open(filename,ios::in);
	for(int i=0; i<373; i++){
		getsequence.getline(input,sizeof(input),'\n');
		input_arr[i]=atoi(input);
	}
	getsequence.close();
}

void open_cap(int a_use){
	string path;
	stringstream ss;
	ss<<a_use;
	path = "start Component_Capture_with_Pressure.exe " + ss.str();
	system(path.c_str());
}

Capture::Capture(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setGeometry(50, 70, geometry().width(), geometry().height());
	
}

Capture::~Capture()
{

}

void Capture::Change_Thread(){
	int start = Capture::ui.spinBox_2->value();
	input_thread=start-1;
	slot1();
}

void Capture::slot1()
{
	if(firstrun){
		init_database();
	}
	QPixmap word;
	QPixmap stroke;
	QStringList address_word, address_stroke;
	ui.lcdNumber->display(input_thread+1);
	a=input_arr[input_thread];
	if(a<10){
		address_word.append(".\\char_graph\\000"+QString::number(a)+".bmp");
		//address_stroke.append(".\\stroke_seq_graph\\str000"+QString::number(a)+".png");
	}
	if(a<100&&a>9){
		address_word.append(".\\char_graph\\00"+QString::number(a)+".bmp");
		//address_stroke.append(".\\stroke_seq_graph\\str00"+QString::number(a)+".png");
	}
	if(a<1000&&a>99){
		address_word.append(".\\char_graph\\0"+QString::number(a)+".bmp");
		//address_stroke.append(".\\stroke_seq_graph\\str0"+QString::number(a)+".png");
	}
	if(a<10000&&a>999){
		address_word.append(".\\char_graph\\"+QString::number(a)+".bmp");
		
	}
	address_stroke.append(".\\stroke_seq_graph\\"+QString::number(a)+".png");
	word.load(address_word.front());
	stroke.load(address_stroke.front());
	ui.label->setPixmap(word);
	ui.label_3->setScaledContents(true);
	ui.label_3->setPixmap(stroke);
	open_cap(a);

	//system("start Element_Capture_with_Pressure.exe ");
	//"\"C:\\xxx\\xxx\\xxx.exe -xxx -xxx xxx.xxx xxx.xxx xxx.xxx\""
	input_thread++;
	firstrun=false;
}

void Capture::slot2()
{
	/*QPixmap result;
	QStringList address2;
	address2.append("200"+QString::number(b)+".bmp");
	result.load(address2.front());
	ui.label_2->setPixmap(result);
	b++;*/
	make1();
	//ui.label_2->setText(ui.textEdit->toPlainText());
}

void Capture::make_one(){
	int sn=ui.spinBox_2->value();
	make_specific(sn);
}

void Capture::Full_Scope(){
	string path;
	path = "start Multi_Char_Input.exe ";
	system(path.c_str());
}

void Capture::result_output(){
	QPixmap result;
	QPixmap result_single;
	QStringList result_address;
	QStringList result_address_single;
	int o = ui.spinBox->value();
	result_address_single.append("./personal_font/test"+QString::number(o)+".bmp");
	result_single.load(result_address_single.front());
	ui.label_2->setScaledContents(true);
	ui.label_2->setPixmap(result_single);
	/*
	char *c;
	int k = 0;
	int count = 4;
	QByteArray bytearray = ui.textEdit->toPlainText().toLocal8Bit();
	c = bytearray.data();
	for(int i=0;i<30;i++){
		if(c[i] != ' '){
			k = k*10 + (c[i]-'0');
		}
		else{
			if(count==4){
				result_address.append("./personal_font/test"+QString::number(k)+".bmp");
				result.load(result_address.front());
				ui.label_4->setScaledContents(true);
				ui.label_4->setPixmap(result);
				k = 0;
				count = count +1;
				result_address.clear();
			}
			else if(count==5){
				result_address.append("./personal_font/test"+QString::number(k)+".bmp");
				result.load(result_address.front());
				ui.label_5->setScaledContents(true);
				ui.label_5->setPixmap(result);
				k = 0;
				count = count +1;
				result_address.clear();
			}
			else if(count==6){
				result_address.append("./personal_font/test"+QString::number(k)+".bmp");
				result.load(result_address.front());
				ui.label_6->setScaledContents(true);
				ui.label_6->setPixmap(result);
				k = 0;
				count = count +1;
				result_address.clear();
			}
			else if(count==7){
				result_address.append("./personal_font/test"+QString::number(k)+".bmp");
				result.load(result_address.front());
				ui.label_7->setScaledContents(true);
				ui.label_7->setPixmap(result);
				k = 0;
				count = count +1;
				result_address.clear();
			}
			else if(count==8){
				result_address.append("./personal_font/test"+QString::number(k)+".bmp");
				result.load(result_address.front());
				ui.label_8->setScaledContents(true);
				ui.label_8->setPixmap(result);
				k = 0;
				count = count +1;
				result_address.clear();
			}
		}
	}

	*/
	//result_address.append("test"+QString::number(o)+".bmp");
	//result.load(result_address.front());
	//ui.label_2->setScaledContents(true);
	//ui.label_2->setPixmap(result);
}

void Capture::again(){
	input_thread--;
	QPixmap word;
	QPixmap stroke;
	QStringList address_word, address_stroke;
	a=input_arr[input_thread];
	if(a<10){
		address_word.append(".\\char_graph\\000"+QString::number(a)+".bmp");
		//address_stroke.append(".\\stroke_seq_graph\\str000"+QString::number(a)+".png");
	}
	if(a<100&&a>9){
		address_word.append(".\\char_graph\\00"+QString::number(a)+".bmp");
		//address_stroke.append(".\\stroke_seq_graph\\str00"+QString::number(a)+".png");
	}
	if(a<1000&&a>99){
		address_word.append(".\\char_graph\\0"+QString::number(a)+".bmp");
		//address_stroke.append(".\\stroke_seq_graph\\str0"+QString::number(a)+".png");
	}
	if(a<10000&&a>999){
		address_word.append(".\\char_graph\\"+QString::number(a)+".bmp");
		
	}
	address_stroke.append(".\\stroke_seq_graph\\"+QString::number(a)+".png");
	word.load(address_word.front());
	stroke.load(address_stroke.front());
	ui.label->setPixmap(word);
	ui.label_3->setScaledContents(true);
	ui.label_3->setPixmap(stroke);
	open_cap(a);
	input_thread++;
}

void Capture::back(){
	input_thread-=2;
	QPixmap word;
	QPixmap stroke;
	QStringList address_word, address_stroke;
	a=input_arr[input_thread];
	if(a<10){
		address_word.append(".\\char_graph\\000"+QString::number(a)+".bmp");
		//address_stroke.append(".\\stroke_seq_graph\\str000"+QString::number(a)+".png");
	}
	if(a<100&&a>9){
		address_word.append(".\\char_graph\\00"+QString::number(a)+".bmp");
		//address_stroke.append(".\\stroke_seq_graph\\str00"+QString::number(a)+".png");
	}
	if(a<1000&&a>99){
		address_word.append(".\\char_graph\\0"+QString::number(a)+".bmp");
		//address_stroke.append(".\\stroke_seq_graph\\str0"+QString::number(a)+".png");
	}
	if(a<10000&&a>999){
		address_word.append(".\\char_graph\\"+QString::number(a)+".bmp");
		
	}
	address_stroke.append(".\\stroke_seq_graph\\"+QString::number(a)+".png");
	word.load(address_word.front());
	stroke.load(address_stroke.front());
	ui.label->setPixmap(word);
	ui.label_3->setScaledContents(true);
	ui.label_3->setPixmap(stroke);
	open_cap(a);
	input_thread++;
}