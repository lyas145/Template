#include<bits/stdc++.h>
#define qwq return
using namespace std;
const int N=1.1e7+5;
int n,len;
int R[N<<1];
char s[N<<1],tmp[N];
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
void manacher() {
	int x=0,p=0,mx=0;
	for (int i=2;i<len;i++) {
		if (i<mx) {x=min(mx-i,R[2*p-i]);}
		else {x=1;}
		while (s[i-x]==s[i+x]) {x++;}
		if (i+x>mx) {mx=i+x;p=i;}
		R[i]=x;
	}
}
int main() {
	scanf("%s",tmp+1);
	n=strlen(tmp+1);
	len=2*n+3;
	s[1]='$';
	for (int i=1;i<=n;i++) {
		s[i<<1]='#';
		s[i<<1|1]=tmp[i];
	}
	s[len-1]='#';
	s[len]='@';
	manacher();
	
	//do something . . .
	
	qwq 0;
}