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
#define int ll
#define N (500005)
int l[N], r[N], Ans[N], n, m;
struct Node{ int x, id; } a[N];
struct Seg{
	int l, r, id;
	bool operator < (const Seg &A) const{ return r > A.r; }
}s[N];
inline bool cmp(Seg A, Seg B){ return A.l < B.l; }
inline bool cmp2(Node A, Node B){ return A.x < B.x; }
priority_queue<Seg> pq;
main(){
	read(n), read(m);
	if(m < n - 1) return puts("No"), 0;
	for(int i = 1; i <= n; i++) read(l[i]), read(r[i]);
	for(int i = 1; i <= m; i++) read(a[i].x), a[i].id = i;
	for(int i = 1; i < n; i++) 
		s[i] = (Seg){l[i+1] - r[i], r[i+1] - l[i], i};
	sort(s + 1, s + n, cmp);
	sort(a + 1, a + m + 1, cmp2);
	int p = 1;
	for(int i = 1; i <= m; i++){
		while(a[i].x >= s[p].l && p < n) pq.push(s[p]), p++;
		if(pq.empty()) continue; 
		if(pq.top().r < a[i].x) return puts("No"), 0;
		Seg now = pq.top(); pq.pop(); Ans[now.id] = a[i].id;
	}
	for(int i = 1; i < n; i++) if(!Ans[i]) return puts("No"), 0;
	puts("Yes");
	for(int i = 1; i < n; i++) printf("%lld ", Ans[i]);
	return 0;
}
