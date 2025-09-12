#include<bits/stdc++.h>
#define qwq return
using namespace std;
const int N=2e7+5;
int n;
char s[N];
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
int get_min() {
	int i=0,j=1;
	while (i<n && j<n) {
		int k=0;
		while (s[i+k]==s[j+k]) {k++;}
		if (k==n) {break;}
		if (s[i+k]>s[j+k]) {i+=k+1;}
		else {j+=k+1;}
		j+=(i==j);
	}
	int k=min(i,j);
	s[n+k]=0;
	qwq k;
}
int main() {
	n=read();
	scanf("%s",s);
	memcpy(s+n,s,n);
	
	//do something . . .
	
	qwq 0;
}
