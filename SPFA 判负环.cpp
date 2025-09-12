#include<bits/stdc++.h>
#define qwq return
using namespace std;
const int N=2e3+5,M=6e3+5;
int T,n,m;
bool vis[N];
int dis[N],d[N];
int h[N],e[M],w[M],ne[M],idx=1;
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
	memset(dis,0x3f,sizeof dis);
	q.push(1);vis[1]=1;dis[1]=0;d[1]=1;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		vis[u]=0;
		for (int i=h[u];i;i=ne[i]) {
			int v=e[i];
			if (dis[v]>dis[u]+w[i]) {
				dis[v]=dis[u]+w[i];
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
int main() {
	n=read();m=read();
	while (m--) {
		int a=read(),b=read(),c=read();
		add(a,b,c);
		if (a==b && c<0) {puts("YES");qwq 0;}
		//It`s an optimization and it isn`t necessary.
	}
	puts(SPFA()?"YES":"NO");
	qwq 0;
}
