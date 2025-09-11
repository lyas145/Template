#include<bits/stdc++.h>
#define qwq return
#define F first
#define S second
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+5;
int n,rt,tri;
mt19937 rng(time(0));
uniform_int_distribution<int> rd(1,114514);
struct FHQ_Treap{
	int l,r;
	int siz,w,k;
}tr[N];
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
int makenode(int v) {
	int u=++tri;
	tr[u]={0,0,1,v,rd(rng)};
	qwq u;
}
void pushup(int u) {
	tr[u].siz=tr[tr[u].l].siz+tr[tr[u].r].siz+1;
}
PII split_by_rk(int u,int k) {
	if (!u) {qwq {0,0};}
	if (k<=tr[tr[u].l].siz) {
		PII o=split_by_rk(tr[u].l,k);
		tr[u].l=o.S;
		pushup(u);
		o.S=u;
		qwq o;
	}
	PII o=split_by_rk(tr[u].r,k-tr[tr[u].l].siz-1);
	tr[u].r=o.F;
	pushup(u);
	o.F=u;
	qwq o;
}
PII split_by_val(int u,int v) {
	if (!u) {qwq {0,0};}
	if (v<=tr[u].w) {
		PII o=split_by_val(tr[u].l,v);
		tr[u].l=o.S;
		pushup(u);
		o.S=u;
		qwq o;
	}
	PII o=split_by_val(tr[u].r,v);
	tr[u].r=o.F;
	pushup(u);
	o.F=u;
	qwq o;
}
int merge(int x,int y) {
	if (!x || !y) {qwq x|y;}
	if (tr[x].k>tr[y].k) {
		tr[x].r=merge(tr[x].r,y);
		pushup(x);
		qwq x;
	}
	tr[y].l=merge(x,tr[y].l);
	pushup(y);
	qwq y;
}
int find(int u,int v) {
	if (!u) {qwq 0;}
	if (v<tr[u].w) {qwq find(tr[u].l,v);}
	if (v==tr[u].w) {qwq u;}
	qwq find(tr[u].r,v);
}
void insert(int v) {
	PII o=split_by_val(rt,v);
	int u=makenode(v);
	rt=merge(merge(o.F,u),o.S);
}
void del(int v) {
	PII o=split_by_val(rt,v);
	PII t=split_by_rk(o.S,1);
	rt=merge(o.F,t.S);
}
int get_rk(int v) {
	PII o=split_by_val(rt,v);
	int res=tr[o.F].siz;
	rt=merge(o.F,o.S);
	qwq res+1;
}
int get_kth(int k) {
	PII x=split_by_rk(rt,k-1);
	PII y=split_by_rk(x.S,1);
	int res=tr[y.F].w;
	rt=merge(x.F,merge(y.F,y.S));
	qwq res;
}
int main() {
	
	//do something . . .
	
	qwq 0;
}