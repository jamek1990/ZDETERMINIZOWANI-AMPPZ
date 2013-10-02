#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t[1000000];
vector<int>INW;
int main(){
	int n,inw=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>t[i];
	int maks =0;
	INW.push_back(0);
	for(int i=0;i<n;i++){
		maks= max(maks,t[i]);
		if(maks==i+1){inw++;INW.push_back(i+1);};
	}	
	cout<<inw<<"\n";
	for(int i=1;i<=inw;i++){
		cout<<INW[i]-INW[i-1]<<" ";
		for(int j=INW[i-1]+1;j<=INW[i];j++)
			cout<<j<<" ";
		cout<<"\n";
	}
	return 0;
}
