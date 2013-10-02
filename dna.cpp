#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GEN[4];
string G = "ACGT";
int main(){
	string gen;
	int n;
	cin>>n>>gen;
	for(int i=0;i<n;i++){
		if(gen[i]=='A')GEN[0]++;
		if(gen[i]=='C')GEN[1]++;
		if(gen[i]=='G')GEN[2]++;
		if(gen[i]=='T')GEN[3]++;
	}
	int minimum = 10000000;
	int co = -1;
	for(int i=0;i<4;i++){
		if(minimum>GEN[i]){
			minimum=GEN[i];
			co = i;
		}
	}
	cout<<minimum<<"\n";
	for(int i=0;i<n;i++)
		cout<<G[co];
	
	return 0;
	
}
