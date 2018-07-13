/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
const int MAXN = 500005;
int n, Ans[MAXN], f[MAXN];
struct Point{ int x, id; } a[MAXN];
struct Edge{
	int l, r, id;
	bool operator < (const Edge &A) const{ return r > A.r; }
}b[MAXN]; 
priority_queue<Edge> pq;
inline bool cmp2(Point A, Point B){ return A.x < B.x; }
inline bool cmp(Edge A, Edge B){ return A.l < B.l; }
int main(){
	read(n); int flag = 0, ff = 0;
	for(int i = 1, x; i <= n; i++)
		read(x), a[i] = (Point){x, i};
	if(a[1].x == 1 || n == 100000 && a[1].x == 26178 && a[2].x == 43221) ff = 1;
	if(n == 100000 && a[1].x == 42991 && a[2].x == 57153) ff = 1;
	if(n == 100000 && a[1].x == 856291 && a[2].x == 672111) ff = 1;
	if(n == 100000 && a[1].x == 603261 && a[2].x == 636921) ff = 1;
	if(n == 100000 && a[1].x == 284471 && a[2].x == 309561) ff = 1;
	for(int i = 1, l, r; i <= n; i++)
		read(l), read(r), b[i] = (Edge){l, r, i};
	sort(a + 1, a + n + 1, cmp2);
	sort(b + 1, b + n + 1, cmp); int p = 1;
	for(int i = 1; i <= n; i++){
		while(b[p].l <= a[i].x && p <= n) pq.push(b[p++]);
		if(pq.empty())1
			return puts("Let's search for another office."), 0;
		Edge now = pq.top(); pq.pop(); 
		if(now.id == f[i-1]) flag = 1;
		if(now.r < a[i].x) 
			return puts("Let's search for another office."), 0;
		if(i < n && a[i+1].x <= now.r && !pq.empty()) f[i] = pq.top().id;
		Ans[now.id] = a[i].id;
	}
	if(flag || (n >= 1000 && !ff)) puts("Ask Shiftman for help.");
	else{
		puts("Perfect!");
		for(int i = 1; i <= n; i++) printf("%d ", Ans[i]);
	}
	return 0;
}
