#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

struct Cchar_dat{
	int e_cnt; int sn;
	int e_sn[10];
};

Cchar_dat elem_data[3750];

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

int main(){
	int sn;
	elem_data_init();
	while(1){
		FILE *db;
		stringstream ss; string inbuf;
		cout<<"Please type the serial number of the character"<<endl;
		cin>>sn;
		if(sn==-1){			
			return 0;
		}
		ss<<sn; inbuf=ss.str()+".txt";
		db=fopen(inbuf.c_str(),"w");
		cout<<"Please type strokes for first component, strokes for second component..."<<endl;
		int compcnt; int strcnt=0; int compstr[10]; int comptype[10];
		compcnt=elem_data[sn].e_cnt; 
		for(int i=0; i<compcnt; i++){
			cin>>compstr[i]; strcnt+=compstr[i];
		}
		stringstream sd;
		sd<<compcnt; inbuf=sd.str(); fputs(inbuf.c_str(),db);
		fputs(" ",db);
		stringstream sf;
		sf<<strcnt; inbuf=sf.str(); fputs(inbuf.c_str(),db);
		fputs(" ",db);
		for(int l=0; l<compcnt; l++){
			stringstream sg;
			sg<<elem_data[sn].e_sn[l];
			inbuf=sg.str();
			fputs(inbuf.c_str(),db);
			fputs(" ",db);
		}
		for(int j=0; j<compcnt; j++){
			for(int k=0; k<compstr[j]; k++){
				stringstream sg;
				sg<<j+1; inbuf=sg.str();
				fputs(inbuf.c_str(),db);
				fputs(" ",db);
			}
		}
		fclose(db);		
	}

	//system("pause");
	return 0;
}