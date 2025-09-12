#include<bits/stdc++.h>
#define qwq return
using namespace std;
const int N=1e7+5;
int n;
int a[N],l[N],r[N];
int stk[N],top;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
int main() {
	n=read();
	for (int i=1;i<=n;i++) {a[i]=read();}
	for (int i=1;i<=n;i++) {
		int k=top;
		while (k && a[stk[k]]>a[i]) {k--;}
		if (k) {r[stk[k]]=i;}
		if (k<top) {l[i]=stk[k+1];}
		stk[top=++k]=i;
	}
    
    //do something . . .
    
	qwq 0;
}
