#include<bits/stdc++.h>
#define qwq return
using namespace std;
const int N=1e4+5,S=55,M=1e6+5;
int n;
char str[M];
bool st[N*S];
int tr[N*S][26],cnt[N*S],ne[N*S],tri;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
void insert() {
	int p=0;
	for (int i=0;str[i];i++) {
		int t=str[i]-'a';
		if (!tr[p][t]) {tr[p][t]=++tri;}
		p=tr[p][t];
	}
	cnt[p]++;
}
void build() {
	queue<int> q;
	for (int i=0;i<26;i++) {
		if (tr[0][i]) {q.push(tr[0][i]);}
	}
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (int i=0;i<26;i++) {
			int v=tr[u][i];
			if (!v) {tr[u][i]=tr[ne[u]][i];}
			else {
				ne[v]=tr[ne[u]][i];
				q.push(v);
			}
		}
	}
}
int main() {
	n=read();
	while (n--) {
		scanf("%s",str);
		insert();
	}
	build();
	scanf("%s",str);
	for (int i=0,j=0;str[i];i++) {
		int t=str[i]-'a';
		j=tr[j][t];
		
		//do something . . .
		
		/*
		int p=j;
		while (p) {
			if (st[p]) {break;}
			st[p]=1;
			ans+=cnt[p];
			p=ne[p];
		}
		*/
	}
	qwq 0;
}
