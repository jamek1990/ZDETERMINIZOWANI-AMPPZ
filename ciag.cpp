#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t[1000000];
int zer[1000000];
int jed[1000000];
int m[1000000];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>t[i];
	for(int j=0;j<k;j++)
		for(int i=j;i<n;i+=k)
			if(t[i]%2)
				jed[j]++;
			else
				zer[j]++;
	for(int j=0;j<k;j++)
		m[j]=min(zer[j],jed[j]);
	int ile = 0;
	for(int j=0;j<k;j++)
		ile+=m[j];
	int ileJed=0;
	for(int i=0;i<k;i++){
		if(jed[i]==zer[i]){
			ileJed=0;break;
		}
		if(jed[i]>zer[i])
			ileJed++;
	}
	if(ileJed%2==0)
		cout<<ile<<"\n";
	else{
		int minimum = 10000000;
		for(int i=0;i<k;i++)
			minimum = min(minimum,abs(zer[i]-jed[i]));
		cout<<ile+minimum<<"\n";
	}
	
	return 0;
}
