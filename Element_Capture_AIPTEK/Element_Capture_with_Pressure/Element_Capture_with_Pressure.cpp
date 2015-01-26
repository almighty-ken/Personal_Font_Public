#include <windows.h>
#include <iostream>
#include "stdafx.h"
#include <vector>
#include <math.h>
#include <cstdio>
#include <sstream>
#include <thread>
#include "cv_Capture.h"
//#include <atomic>
//#include <chrono>
#include <io.h>
#include <fcntl.h>
#include<cv.h>
#include<highgui.h>


//using namespace cv;
using namespace std;

/*
* Function that receives messages from OS
*
* LRESULT --> returns a 32-bit number (64 for 64 OS)
* CALLBACK --> specifies how in assembly parameters will get passed
* 				and returned from the function
* HWND --> Handle to the window that is receiving messages from the OS
* UINT --> Says what type of message is being sent
* WPARAM/LPARAM --> es. X and Y mouse position
*/
LRESULT CALLBACK WndProc (
	HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam);

string int2str(int &i);
int p;
bool brush(false);
bool thread_flag(false);


struct pendata{
	BYTE head;
	BYTE button_flag;
	BYTE x1;
	BYTE x2;
	BYTE y1;
	BYTE y2;
	BYTE p1;
	BYTE p2;
	BYTE t1;
	BYTE t2;
};


void InitRawInput(HWND hWnd)
{
	RAWINPUTDEVICE Rid[1];
	Rid[0].usUsagePage = 0x0d;
	Rid[0].usUsage = 0x02;
	Rid[0].dwFlags = RIDEV_INPUTSINK;
	Rid[0].hwndTarget = hWnd;

	if (RegisterRawInputDevices(Rid,1,sizeof(Rid[0])) == false) 
	{

		MessageBox(NULL, "Registration failed", "ERROR", MB_OK);
		return;
	}
	MessageBox(NULL,"Registration updated","",MB_OK);
}


int WINAPI WinMain(HINSTANCE hInstance,	   HINSTANCE hPrevInstance,	   LPSTR lpCmdLine,	   int nShowCmd){

	/*
	AllocConsole();

	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
	FILE* hf_out = _fdopen(hCrt, "w");
	setvbuf(hf_out, NULL, _IONBF, 1);
	*stdout = *hf_out;

	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
	hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
	FILE* hf_in = _fdopen(hCrt, "r");
	setvbuf(hf_in, NULL, _IONBF, 128);
	*stdin = *hf_in;
	*/


	HWND hWnd;

	//Struct that holds information for the window
	WNDCLASSEX wc;

	/*
	Reset the window class
	1. Address of block to fill with zero
	2. Size of the block to fill with zero
	*/
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	//Fill the struct with the needed information
	wc.cbSize = sizeof(WNDCLASSEX); //Size the struct as WINDOCLASSEX size
	wc.style = CS_HREDRAW|CS_VREDRAW; //Redraw window if it is moved vertically or horizonatally
	wc.lpfnWndProc = WndProc; //Function to use when it get messages from OS
	wc.hInstance = hInstance; //Handle to a copy of our application
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; //Holds the brush to color the background
	wc.lpszClassName = "BasicWindowClass"; //Name of the window class we created

	//Register the window class
	RegisterClassEx(&wc);

	//Create the window and use the result as the handle
	hWnd = CreateWindowEx(NULL,
		"BasicWindowClass", //Name of the window class to use
		"Basic Win32 Application", //Window Title
		WS_OVERLAPPEDWINDOW, //Style of the window 
		100, //X position
		100, //Y position
		800, //Width
		600, //Height
		NULL, //Parent Window
		NULL, //Menu isn't used
		hInstance, //Application handle
		NULL); //use for multiple window


	bool supported_touch_present (false);
	// get the number of HID input devices
	UINT input_device_count (0);
	if (GetRawInputDeviceList (NULL, &input_device_count, sizeof (RAWINPUTDEVICELIST)) != 0) 
	{
		return 0;
	}
	// allocate memory for their structures
	vector<RAWINPUTDEVICELIST> input_devices;
	input_devices.resize (input_device_count);
	// then populate the device list
	if (GetRawInputDeviceList (&input_devices [0], &input_device_count, 
		sizeof (RAWINPUTDEVICELIST)) == (UINT)-1)
	{
		return 0;
	}
	// for each device...
	RID_DEVICE_INFO device_info;
	for (vector<RAWINPUTDEVICELIST>::iterator device_iterator (input_devices.begin ());
		device_iterator != input_devices.end ();
		++device_iterator)
	{
		UINT info_size (sizeof (RID_DEVICE_INFO));
		if (GetRawInputDeviceInfo (device_iterator->hDevice, 
			RIDI_DEVICEINFO, (LPVOID)&device_info, &info_size) == info_size)
		{
			// non-keyboard, non-mouse HID device?
			if (device_info.dwType == RIM_TYPEHID)
			{
				/*
				//WACOM FAIL
				if ((device_info.hid.dwVendorId == 0x056A)
					&& (device_info.hid.dwProductId == 0x030E))
				{
					supported_touch_present = true;

				}
				*/
				
				if ((device_info.hid.dwVendorId == 0x172F)
					&& (device_info.hid.dwProductId == 0x504))
				{
					supported_touch_present = true;

				}
				
			}
		}
	}



	ShowWindow(hWnd,SW_SHOW);

	InitRawInput(hWnd);

	thread call_draw(start_draw);
	thread_flag=true;
	//Struct to hold windows event messages
	MSG msg;

	/*
	UINT nDevices;
	RAWINPUTDEVICELIST *pRawInputDeviceList;
	GetRawInputDeviceList(NULL, &nDevices, sizeof(RAWINPUTDEVICELIST));
	pRawInputDeviceList = (RAWINPUTDEVICELIST*)malloc(sizeof(RAWINPUTDEVICELIST) * nDevices);
	//if ( != 0) { return 0;}
	//if (() == NULL) {return 0;}
	GetRawInputDeviceList(pRawInputDeviceList, &nDevices, sizeof(RAWINPUTDEVICELIST));
	//if ( == (dtype rid="UINT"/>)-1) {Error();}
	// do the job...

	// after the job, free the RAWINPUTDEVICELIST
	free(pRawInputDeviceList);
	*/

	while (GetMessage(&msg, NULL,0,0))
	{
		TranslateMessage(&msg);
		if(thread_flag==false){
			call_draw.join();
			PostQuitMessage(0);			
		}
		DispatchMessage(&msg);
		
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,	 UINT msg,	 WPARAM wParam,	 LPARAM lParam){

	LPBYTE lpb;
	UINT dwSize;
	RAWINPUT *raw;
	switch(msg)
	{
	case WM_DESTROY:

		PostQuitMessage(0);

		break;

	case WM_INPUT:
		{

			GetRawInputData((HRAWINPUT)lParam,RID_INPUT,NULL,&dwSize,sizeof(RAWINPUTHEADER));

			lpb = new BYTE[dwSize];

			if (lpb == NULL)
				return 0;

			if (GetRawInputData((HRAWINPUT)lParam,RID_INPUT,lpb,&dwSize,sizeof(RAWINPUTHEADER)) != dwSize)
			{
				OutputDebugString(TEXT("GetRawInputData doesn't return correct size\n"));
				MessageBox(NULL,"GetRawInputData doesn't return correct size\n","",MB_OK);
				return 0;
			}

			raw = (RAWINPUT*) lpb;

			if (raw->header.dwType == RIM_TYPEHID)
			{

				// reinterpret the data as our nicely formatted digitizer-specific structure
				pendata* result ((pendata*)&raw->data.hid.bRawData [raw->data.hid.dwSizeHid-10]);
				unsigned char pressure1;unsigned char pressure2;
				pressure1=result->p2;	pressure2=result->p1;
				//int p1=atoi(pressure1);	int p2=atoi(pressure2);
				unsigned int p1=pressure1-'0'+48; unsigned int p2=pressure2-'0'+48;
				p=p1*256+p2;
				string out;
				out=int2str(p);
				unsigned char b;	b=result->button_flag;
				unsigned int b_temp=b-'0'+48;
				if(b_temp-6==11){
					brush=true;
				}
				else{
					brush=false;
				}
				SetWindowText(hWnd,out.c_str());
			}

			delete[] lpb;
			return 0;
		}
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

string int2str(int &i) {
	string s;
	stringstream ss(s);
	ss << i;
	return ss.str();
}