#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long uciecie[200001];
long long zm[200001];
pair<long long,int> zmiazdzenie[200001];
vector<int> odrasta[200001];

bool zrobiona[200001];
long long wynik[200001];
vector<int>graphT[200001];
int liczbaOdrastajacych[200001];

void odpal(int S){
	long long ile =0;
	for(int k=0;k<odrasta[S].size();k++)
		ile+=wynik[odrasta[S][k]];
	ile += uciecie[S];
	wynik[S]=min(zm[S],ile);
}

vector<int> kol;
void odejmij(int T){
	for(int j=0;j<graphT[T].size();j++){
		liczbaOdrastajacych[graphT[T][j]]--;
		if(liczbaOdrastajacych[graphT[T][j]]==0)
			kol.push_back(graphT[T][j]);
	}
}
int main(){
	int g,a;
	int liczbaGlow;
	cin>>liczbaGlow;
	for(int i=1;i<=liczbaGlow;i++){
		cin>>uciecie[i];
		cin>>zmiazdzenie[i].first;
		zm[i]=zmiazdzenie[i].first;
		
		zmiazdzenie[i].second = i;
		cin>>g;
		liczbaOdrastajacych[i]=g;
		while(g--){
			cin>>a;
			odrasta[i].push_back(a);
		}
	}
	
	sort(zmiazdzenie+1,zmiazdzenie+(liczbaGlow+1));

	for(int i=1;i<=liczbaGlow;i++)
		for(int j=0;j<odrasta[i].size();j++)
			graphT[odrasta[i][j]].push_back(i);
			
	for(int i=1;i<=liczbaGlow;i++){
		if(!zrobiona[zmiazdzenie[i].second]){
			zrobiona[zmiazdzenie[i].second]=true;
			wynik[zmiazdzenie[i].second]=zm[zmiazdzenie[i].second];
			odejmij(zmiazdzenie[i].second);
			while(!kol.empty()){
				int T = kol.back();
				kol.pop_back();
				zrobiona[T]=true;
				odpal(T);
				odejmij(T);
			}
		}
	}
	cout<<wynik[1]<<"\n";
	return 0;
	
}
