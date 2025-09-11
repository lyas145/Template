#include<bits/stdc++.h>
#define qwq return
using namespace std;
const double alf=0.75;
const int N=1e5+5;
int n,rt,tri;
int a[N],cnt;
struct ST{
	int l,r;
	int w,s,siz,asiz;
}tr[N];
stack<int> stk;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
int makenode(int v) {
	int u;
	if (!stk.empty()) {u=stk.top();stk.pop();}
	else {u=++tri;}
	tr[u]={0,0,v,1,1,1};
	qwq u;
}
void pushup(int u) {
	tr[u].siz=tr[u].s+tr[tr[u].l].siz+tr[tr[u].r].siz;
	tr[u].asiz=max(1,tr[u].s)+tr[tr[u].l].asiz+tr[tr[u].r].asiz;
}
bool check(int u) {
	if (!tr[u].s) {qwq 0;}
	if (tr[tr[u].l].asiz>=tr[u].asiz*alf) {qwq 1;}
	if (tr[tr[u].r].asiz>=tr[u].asiz*alf) {qwq 1;}
	if (tr[u].siz<=tr[u].asiz*alf) {qwq 1;}
	qwq 0;
}
void dfs(int u) {
	if (tr[u].l) {dfs(tr[u].l);}
	if (tr[u].s) {a[++cnt]=u;}
	else {stk.push(u);}
	if (tr[u].r) {dfs(tr[u].r);}
}
void rebuild(int &u,int l,int r) {
	if (l>r) {qwq ;}
	int mid=l+r>>1;
	u=a[mid];
	tr[u].l=tr[u].r=0;
	if (l^r) {
		rebuild(tr[u].l,l,mid-1);
		rebuild(tr[u].r,mid+1,r);
	}
	pushup(u);
}
void build(int &u) {
	cnt=0;
	dfs(u);
	u=0;
	rebuild(u,1,cnt);
}
void insert(int &u,int v) {
	if (!u) {u=makenode(v);qwq ;}
	if (v==tr[u].w) {tr[u].s++;pushup(u);qwq ;}
	if (v<tr[u].w) {insert(tr[u].l,v);}
	else {insert(tr[u].r,v);}
	pushup(u);
	if (check(u)) {build(u);}
}
void del(int &u,int v) {
	if (v==tr[u].w) {tr[u].s--;pushup(u);qwq ;}
	if (v<tr[u].w) {del(tr[u].l,v);}
	else {del(tr[u].r,v);}
	pushup(u);
	if (check(u)) {build(u);}
}
int get_rk(int u,int v) {
	if (!u) {qwq 0;}
	if (v==tr[u].w) {qwq tr[tr[u].l].siz;}
	if (v<tr[u].w) {qwq get_rk(tr[u].l,v);}
	qwq get_rk(tr[u].r,v)+tr[tr[u].l].siz+tr[u].s;
}
int get_kth(int u,int k) {
	if (k<=tr[tr[u].l].siz) {qwq get_kth(tr[u].l,k);}
	k-=tr[tr[u].l].siz;
	if (k<=tr[u].s) {qwq tr[u].w;}
	k-=tr[u].s;
	qwq get_kth(tr[u].r,k);
}
int main() {
	
	//do something . . .
	
	qwq 0;
}