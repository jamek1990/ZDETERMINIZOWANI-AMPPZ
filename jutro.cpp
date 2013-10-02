#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> t[1000000];
int main(){
	int a;
	cin>>a;
	for(int i=0;i<a;i++)
		cin>>t[i].second >>t[i].first;
	sort(t,t+a);
	int start = t[a-1].first;
	for(int i=a-1;i>=0;i--)
		start=min(start,t[i].first)-t[i].second;
	cout<<start<<"\n";
	return 0;
}
