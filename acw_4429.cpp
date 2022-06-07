#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n;
char s[N];
int work(){
	int cnt=0,r=0;
	for(int i=0;i<n;i++){
		if(s[i]=='(') cnt++;
		else{
			cnt--;
			r++;
			if(cnt<0){
				cnt+=2;
				for(int j=i+1;j<n;j++){
					if(s[j]=='(') cnt++;
					else cnt--;
					if(cnt<0){
						return 0;
					}
				}
				return r;
			}
		}
	}
	return 0;
}
int main(){
	cin>>n>>s;
	int l=0,r=0;
	for(int i=0;i<n;i++){
		if(s[i]=='(') l++;
		else r++;
	}
	if(r==l+2) printf("%d\n",work());
	else if(l==r+2){
		reverse(s,s+n);
		for(int i=0;i<n;i++){
			if(s[i]=='(') s[i]=')';
			else s[i]='(';
		}
		printf("%d\n",work());
	}
	else printf("0");
	return 0;
}