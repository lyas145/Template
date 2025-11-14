#include<bits/stdc++.h>
#define qwq return
using namespace std;
const int N=1e5+5;
int n,rt,tri;
struct Splay{
	int s[2],p;
	int w,siz,cnt;
}tr[N];
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	qwq x*f;
}
void pushup(int x) {
	tr[x].siz=tr[tr[x].s[0]].siz+tr[tr[x].s[1]].siz+tr[x].cnt;
}
void rotate(int x) {
	int y=tr[x].p,z=tr[y].p;
	int k=(tr[y].s[1]==x);
	tr[z].s[tr[z].s[1]==y]=x;tr[x].p=z;
	tr[y].s[k]=tr[x].s[k^1];tr[tr[x].s[k^1]].p=y;
	tr[x].s[k^1]=y;tr[y].p=x;
	pushup(y);pushup(x);
}
void splay(int x,int k) {
	while (tr[x].p^k) {
		int y=tr[x].p,z=tr[y].p;
		if (z^k) {
			if ((tr[y].s[1]==x)^(tr[z].s[1]==y)) {rotate(x);}
			else {rotate(y);}
		}
		rotate(x);
	}
	if (!k) {rt=x;}
}
int find(int v) {
	int x=rt;
	while (x) {
		if (v==tr[x].w) {qwq x;}
		x=tr[x].s[v>tr[x].w];
	}
	qwq 0;
}
void insert(int v) {
	int x=rt,p=0;
	while (x) {
		if (v==tr[x].w) {tr[x].cnt++;splay(x,0);qwq ;}
		p=x;
		x=tr[x].s[v>tr[x].w];
	}
	x=++tri;
	if (p) {tr[p].s[v>tr[p].w]=x;}
	tr[x].p=p;tr[x].w=v;
	tr[x].siz=tr[x].cnt=1;
	splay(x,0);
}
void del(int v) {
	int x=find(v);
	splay(x,0);
	if (tr[x].cnt>1) {tr[x].cnt--;}
	else if (!tr[x].s[0] && !tr[x].s[1]) {rt=0;}
	else if (tr[x].s[0] && tr[x].s[1]) {
		int y=tr[x].s[0];
		tr[y].p=0;
		while (tr[y].s[1]) {y=tr[y].s[1];}
		splay(y,0);
		tr[y].s[1]=tr[x].s[1];
		tr[tr[x].s[1]].p=y;
		pushup(y);
	}
	else {
		rt=tr[x].s[0]|tr[x].s[1];
		tr[rt].p=0;
	}
}
int get_rk(int v) {
	insert(v);
	int x=find(v);
	int res=tr[tr[x].s[0]].siz;
	del(v);
	qwq res+1;
}
int get_kth(int k) {
	int x=rt;
	while (x) {
		if (k<=tr[tr[x].s[0]].siz) {x=tr[x].s[0];continue;}
		k-=tr[tr[x].s[0]].siz;
		if (k<=tr[x].cnt) {qwq tr[x].w;}
		k-=tr[x].cnt;
		x=tr[x].s[1];
	}
	qwq 0;
}
int main() {
	
	//do something . . .
	
	qwq 0;
}
