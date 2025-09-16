#include<bits/stdc++.h>
#define qwq return
using namespace std;
typedef long long ll;
typedef pair<ll,int> PLI;
const int N=3e3+5,M=6e3+5+N;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m;
int d[N];
bool vis[N];
ll dis[N],f[N];
int h[N],e[M],ne[M],idx=1;
ll w[M];
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
bool SPFA() {
	queue<int> q;
	memset(f,0x3f,sizeof f);
	q.push(0);
	f[0]=d[0]=0;vis[0]=1;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		vis[u]=0;
		for (int i=h[u];i;i=ne[i]) {
			int v=e[i];
			if (f[v]>f[u]+w[i]) {
				f[v]=f[u]+w[i];
				if (!vis[v]) {
					q.push(v);
					vis[v]=1;
					d[v]=d[u]+1;
					if (d[v]>n) {qwq 1;}
				}
			}
		}
	}
	qwq 0;
}
void dijkstra(int st) {
	priority_queue<PLI,vector<PLI>,greater<PLI>> q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	q.push({dis[st]=0,st});
	while (!q.empty()) {
		int u=q.top().second;
		q.pop();
		if (vis[u]) {continue;}
		vis[u]=1;
		for (int i=h[u];i;i=ne[i]) {
			int v=e[i];
			if (dis[v]>dis[u]+w[i]+f[u]-f[v]) {
				dis[v]=dis[u]+w[i]+f[u]-f[v];
				if (!vis[v]) {q.push({dis[v],v});}
			}
		}
	}
}
int main() {
	n=read();m=read();
	while (m--) {
		int a=read(),b=read(),c=read();
		add(a,b,c);
		if (a==b && c<0) {puts("-1");qwq 0;}
	}
	for (int i=1;i<=n;i++) {add(0,i,0);}
	if (SPFA()) {puts("-1");qwq 0;}
	for (int i=1;i<=n;i++) {
		dijkstra(i);
		
		//do something . . .
		
	}
	qwq 0;
}
