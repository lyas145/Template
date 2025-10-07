#include<bits/stdc++.h>
#define qwq return
using namespace std;
const int N=55;
int n,k,P;
struct Matrix{
	int a[N][N];
	void init() {
		memset(a,0,sizeof a);
		for (int i=1;i<=n;i++) {a[i][i]=1;}
	}
	Matrix operator* (const Matrix &A)const {
		Matrix res;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				res.a[i][j]=0;
				for (int k=1;k<=n;k++) {
					res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*A.a[k][j]%P)%P;
				}
			}
		}
		qwq res;
	}
}a;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
Matrix qpower(Matrix a,int k) {
	Matrix res;
	res.init();
	while (k) {
		if (k&1) {res=res*a;}
		a=a*a;
		k>>=1;
	}
	qwq res;
}
int main() {
	n=read();k=read();P=read();
	
	//handle the identity matrix a
	
	Matrix ans=qpower(a,k);
	
	//do something . . .
	
	qwq 0;
}
