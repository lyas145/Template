#include<bits/stdc++.h>
#define qwq return
using namespace std;
const int N=1e6+5;
int n,m;
int ne[N];
char a[N],b[N];
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
int main() {
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	for (int i=2,j=0;i<=m;i++) {
		while (j && b[j+1]!=b[i]) {j=ne[j];}
		j+=(b[j+1]==b[i]);
		ne[i]=j;
	}
	for (int i=1,j=0;i<=n;i++) {
		while (j && b[j+1]!=a[i]) {j=ne[j];}
		j+=(b[j+1]==a[i]);
		//if j is equal to m,a match will be completed.
	}
	
	//do something . . .
	
	qwq 0;
}