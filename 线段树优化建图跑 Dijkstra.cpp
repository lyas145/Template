#include<bits/stdc++.h>
#define qwq return
using namespace std;
typedef long long ll;
const int N=1e5+5,M=N*26;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,st,tot;
ll dis[N<<2];
bool vis[N<<2];
int in[N],out[N];
int h[N<<2],e[M],w[M],ne[M],idx=1;
struct SGT{
	int l,r;
	int in,out;
}tr[N<<2];
struct Node{
	int u;
	ll s;
	bool operator< (const Node &A)const {
		qwq s>A.s;
	}
};
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
void add(int a,int b,int c) {
	e[idx]=b;w[idx]=c;ne[idx]=h[a];h[a]=idx++;
}
void dijkstra(int st) {
	priority_queue<Node> q;
	memset(dis+1,0x3f,sizeof (ll)*tot);
	q.push({st,dis[st]=0});
	while (!q.empty()) {
		int u=q.top().u;
		q.pop();
		if (vis[u]) {continue;}
		vis[u]=1;
		for (int i=h[u];i;i=ne[i]) {
			int v=e[i];
			if (dis[v]>dis[u]+(ll)w[i]) {
				dis[v]=dis[u]+(ll)w[i];
				if (!vis[v]) {q.push({v,dis[v]});}
			}
		}
	}
}
void build(int u,int l,int r) {
	tr[u]={l,r,++tot,++tot};
	if (l==r) {
		in[l]=tr[u].in;out[l]=tr[u].out;
		add(tr[u].in,tr[u].out,0);
		add(tr[u].out,tr[u].in,0);
		qwq ;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	add(tr[u<<1].in,tr[u].in,0);
	add(tr[u<<1|1].in,tr[u].in,0);
	add(tr[u].out,tr[u<<1].out,0);
	add(tr[u].out,tr[u<<1|1].out,0);
}
void connect(int u,int l,int r,int x,int k,bool ty) {
	if (l<=tr[u].l && tr[u].r<=r) {
		if (!ty) {add(in[x],tr[u].out,k);}
		else {add(tr[u].in,out[x],k);}
		qwq ;
	}
	int mid=tr[u].l+tr[u].r>>1;
	if (l<=mid) {connect(u<<1,l,r,x,k,ty);}
	if (mid<r) {connect(u<<1|1,l,r,x,k,ty);}
}
void print(int u) {
	if (tr[u].l==tr[u].r) {
		int t=out[tr[u].l];
		printf("%lld ",dis[t]==INF?-1:dis[t]);
		qwq ;
	}
	print(u<<1);
	print(u<<1|1);
}
int main() {
	n=read();m=read();st=read();
	build(1,1,n);
	while (m--) {
		int op=read(),x=read();
		if (op==1) {
			int y=read(),w=read();
			add(in[x],out[y],w);
		}
		else if (op==2) {
			int l=read(),r=read(),w=read();
			connect(1,l,r,x,w,0);
		}
		else {
			int l=read(),r=read(),w=read();
			connect(1,l,r,x,w,1);
		}
	}
	dijkstra(in[st]);
	print(1);
	puts("");
	qwq 0;
}
