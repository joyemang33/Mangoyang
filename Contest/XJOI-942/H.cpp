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
#define N (200005)
struct SegmentTree{
	#define lson (u << 1)
	#define rson (u << 1 | 1)
	int mx[N<<2], tag[N<<2];
	inline void pushdown(int u){
		if(!tag[u]) return;
		mx[lson] += tag[u], mx[rson] += tag[u];
		tag[lson] += tag[u], tag[rson] += tag[u], tag[u] = 0;
	}
	inline void change(int u, int l, int r, int L, int R, int v){
		if(l >= L && r <= R){ mx[u] += v, tag[u] += v; return; }
		int mid = l + r >> 1; pushdown(u);
		if(L <= mid) change(lson, l, mid, L, R, v);
		if(mid < R) change(rson, mid + 1, r, L, R, v);
		mx[u] = Max(mx[lson], mx[rson]);
	}
	inline int query(int u, int l, int r, int L, int R){
		if(l >= L && r <= R) return mx[u];
		int mid = l + r >> 1, res = 0; pushdown(u);
		if(L <= mid) res = max(res, query(lson, l, mid, L, R));
		if(mid < R) res = max(res, query(rson, mid + 1, r, L, R));
		return res;
	}
}van;
int main(){
	int n, s, m;
	read(n), read(s), read(m);
	for(int i = 1; i <= m; i++){
		int l, r, x;
		read(l), read(r), read(x), r--;
		int mx = van.query(1, 1, n, l, r);
		if(mx + x > s){ puts("N"); continue; }
		van.change(1, 1, n, l, r, x), puts("T");
	}
	return 0;
}
