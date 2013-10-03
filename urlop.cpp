#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	int t;string s;
	cin>>t>>s;
	char c = s[0];
	int maks = 0;
	int ile = 0;
	if(c=='S')ile = 1;
	for(int i=1;i<s.size();i++){
		if(s[i]=='S'){
			ile++;
		}else{
			if(maks<ile)
				maks = ile;
			ile = 0;
			//c = s[i];
		}
	
	}
	if(maks<ile)maks = ile;
	cout<<maks<<"\n";
	return 0;
}
