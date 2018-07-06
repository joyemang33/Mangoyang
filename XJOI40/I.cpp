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
#define N (1000005)
int s[N], a[N], rt[N], n;
struct SegmentTree{
	int rc[N*25], lc[N*25], sz[N*25], cnt;
	inline void ins(int &u, int pr, int l, int r, int pos){
		u = ++cnt, sz[u] = sz[pr] + 1;
		lc[u] = lc[pr], rc[u] = rc[pr];
		if(l == r) return; int mid = l + r >> 1;
		if(pos <= mid) ins(lc[u], lc[pr], l, mid, pos);
		else ins(rc[u], rc[pr], mid + 1, r, pos);
	}
	inline int query(int x, int y, int l, int r, int L, int R){
		if(l >= L && r <= R) return sz[y] - sz[x];
		int mid = l + r >> 1, res = 0;
		if(L <= mid) res += query(lc[x], lc[y], l, mid, L, R);
		if(mid < R) res += query(rc[x], rc[y], mid + 1, r, L, R);
		return res; 	
	}
}van;
inline int solve(int k){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int l = k * (i - 1) + 2, r = Min(n, k * i + 1);
		if(l > n) return ans;
		if(a[i] == 1) continue;
		ans += van.query(rt[l-1], rt[r], 1, n, 1, a[i] - 1);
	}	 
	return ans;
}
int main(){
	read(n);
	for(int i = 1; i <= n; i++) 
		read(a[i]), s[i] = a[i];
	sort(s + 1, s + n + 1);
	int sz = unique(s + 1, s + n + 1) - s - 1;
	for(int i = 1; i <= n; i++){
		a[i] = lower_bound(s + 1, s + sz + 1, a[i]) - s;
		van.ins(rt[i], rt[i-1], 1, n, a[i]);
	}
	//for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
	for(int k = 1; k < n; k++) printf("%d ", solve(k));
	return 0;
}
