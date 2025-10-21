#include<bits/stdc++.h>
#define qwq return
#define F first
#define S second
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+5;
mt19937 rd(time(0));
uniform_int_distribution<int> rng(1,1919810);
int n,m,tri,rt[N];
struct FHQ_Treap{
	int l,r;
	int siz,w,k;
}tr[N*60];
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!(c&16) || (c&64)) {f=(c=='-'?-1:1);c=getchar();}
	while ((c&16) && !(c&64)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
int makenode(int v) {
	int x=++tri;
	tr[x]={0,0,1,v,rng(rd)};
	qwq x;
}
int copy(int x) {
	int p=++tri;
	tr[p]=tr[x];
	qwq p;
}
void pushup(int x) {
	tr[x].siz=tr[tr[x].l].siz+tr[tr[x].r].siz+1;
}
PII split_by_rk(int x,int k) {
	if (!x) {qwq {0,0};}
	x=copy(x);
	if (k<=tr[tr[x].l].siz) {
		PII o=split_by_rk(tr[x].l,k);
		tr[x].l=o.S;
		pushup(x);
		o.S=x;
		qwq o;
	}
	PII o=split_by_rk(tr[x].r,k-tr[tr[x].l].siz-1);
	tr[x].r=o.F;
	pushup(x);
	o.F=x;
	qwq o;
}
PII split_by_val(int x,int v) {
	if (!x) {qwq {0,0};}
	x=copy(x);
	if (v<=tr[x].w) {
		PII o=split_by_val(tr[x].l,v);
		tr[x].l=o.S;
		pushup(x);
		o.S=x;
		qwq o;
	}
	PII o=split_by_val(tr[x].r,v);
	tr[x].r=o.F;
	pushup(x);
	o.F=x;
	qwq o;
}
int merge(int x,int y) {
	if (!x || !y) {qwq x|y;}
	if (tr[x].k>tr[y].k) {
		x=copy(x);
		tr[x].r=merge(tr[x].r,y);
		pushup(x);
		qwq x;
	}
	y=copy(y);
	tr[y].l=merge(x,tr[y].l);
	pushup(y);
	qwq y;
}
bool find(int x,int v) {
	if (!x) {qwq 0;}
	if (v<tr[x].w) {qwq find(tr[x].l,v);}
	if (v==tr[x].w) {qwq 1;}
	qwq find(tr[x].r,v);
}
void insert(int i,int v) {
	PII o=split_by_val(rt[i],v);
	int x=makenode(v);
	rt[m]=merge(o.F,merge(x,o.S));
}
void del(int i,int v) {
	PII o=split_by_val(rt[i],v);
	PII t=o;
	if (find(o.S,v)) {t=split_by_rk(o.S,1);}
	rt[m]=merge(o.F,t.S);
}
int get_rk(int x,int v) {
	if (!x) {qwq 1;}
	if (v<=tr[x].w) {qwq get_rk(tr[x].l,v);}
	qwq tr[tr[x].l].siz+1+get_rk(tr[x].r,v);
}
int get_kth(int x,int k) {
	if (k<=tr[tr[x].l].siz) {qwq get_kth(tr[x].l,k);}
	k-=tr[tr[x].l].siz;
	if (k==1) {qwq tr[x].w;}
	k--;
	qwq get_kth(tr[x].r,k);
}
int main() {
	
	//do something . . .
	
	qwq 0;
}
