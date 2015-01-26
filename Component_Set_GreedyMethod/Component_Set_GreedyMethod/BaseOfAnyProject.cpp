#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

//open an array of set to store component information

int main(){
	static const int data_size=3750;
	freopen("data.txt","r",stdin);
	freopen("component_set.txt","w",stdout);

	int current_sn,current_comp_cnt;
	set<int> data[data_size];
	vector<int> seq;
	int pre_pro[55];

	while(scanf("%d%d",&current_sn,&current_comp_cnt)!=EOF){
		set<int> current_data;
		for(int i=0; i<current_comp_cnt; i++){
			int tmp;
			scanf("%d",&tmp);
			current_data.insert(tmp);
		}
		data[current_sn]=current_data;
	}

	/*
	freopen("nc.txt","r",stdin);

	for(int i=0; i<53; i++){
		scanf("%d",&pre_pro[i]);
	}

	for(int i=0; i<53; i++){
		int max_loc=pre_pro[i];
		int max_comp_cnt=data[max_loc].size();
		set<int>::iterator it;
		for(it=data[max_loc].begin();it!=data[max_loc].end();++it){
			int comp_sn=*it;
			for(int i=0; i<data_size; i++){
				if(i!=max_loc){
					if(data[i].empty()){
						continue;
					}
					if(data[i].find(comp_sn)!=data[i].end()){
						data[i].erase(comp_sn);
					}
				}
			}
		}
		seq.push_back(max_loc);
		data[max_loc].clear();
	}
	*/

	while(1){
		int max_comp_cnt=0; int max_loc;	
		for(int i=0; i<data_size; i++){
			if(data[i].size()>max_comp_cnt){
				max_comp_cnt=data[i].size();
				max_loc=i;
			}
		}
		if(max_comp_cnt==0){
			for(vector<int>::iterator i=seq.begin(); i!=seq.end(); i++){
				cout<<*i<<endl;
			}
			return 0;
		}
		set<int>::iterator it;
		for(it=data[max_loc].begin();it!=data[max_loc].end();++it){
			int comp_sn=*it;
			for(int i=0; i<data_size; i++){
				if(i!=max_loc){
					if(data[i].empty()){
						continue;
					}
					if(data[i].find(comp_sn)!=data[i].end()){
						data[i].erase(comp_sn);
					}
				}
			}
		}
		seq.push_back(max_loc);
		data[max_loc].clear();


	}
}