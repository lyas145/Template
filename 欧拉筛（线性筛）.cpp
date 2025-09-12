#include<bits/stdc++.h>
#define qwq return
using namespace std;
const int N=1e7+5;
int n;
int p[N];
bool isp[N];
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
void euler() {
	for (int i=2;i<=n;i++) {
		if (!isp[i]) {p[++p[0]]=i;}
		for (int j=1;j<=p[0] && p[j]<=n/i;j++) {
			isp[i*p[j]]=1;
			if (i%p[j]==0) {break;}
		}
	}
}
int main() {
	n=read();
	euler();
	
	//do something . . .
	
	qwq 0;
}
