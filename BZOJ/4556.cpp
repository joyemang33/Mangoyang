/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (200005)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
} 
char s[N]; int n, m;
struct Segment_Tree{
	int sum[N*25], lc[N*25], rc[N*25], cnt;
	inline void modify(int &u, int l, int r, int pos){
		u = ++cnt;
		if(l == r) return (void) (sum[u]++);
		int mid = l + r >> 1; 
		if(pos <= mid) modify(lc[u], l, mid, pos); 
		else modify(rc[u], mid + 1, r, pos);
		sum[u] = sum[lc[u]] + sum[rc[u]];
	}
	inline int merge(int x, int y, int l, int r){
		if(!x || !y) return x + y; int o = ++cnt;
		if(l == r) sum[o] = sum[x] + sum[y];
		else{
			int mid = l + r >> 1;
			lc[o] = merge(lc[x], lc[y], l, mid);
			rc[o] = merge(rc[x], rc[y], mid + 1, r);
			sum[o] = sum[lc[o]] + sum[rc[o]];
		}
		return o;
	}
	inline int query(int u, int l, int r, int L, int R){
		if(!u) return 0;
		if(l >= L && r <= R) return sum[u];
		int mid = l + r >> 1, res = 0;
		if(L <= mid) res += query(lc[u], l, mid, L, R);
		if(mid < R) res += query(rc[u], mid + 1, r, L, R);
		return res;
	}
}Seg;
struct Suffix_Automaton{
	int f[N][23], rt[N<<1], buf[N], a[N];
	int ch[N][26], fa[N], dep[N], pos[N], tail, size;
	inline Suffix_Automaton(){ tail = size = 1; }
	inline int newnode(int x){ dep[++size] = x; return size; }
	inline void ins(int c, int id){
		int p = tail, np = newnode(dep[p] + 1);
		Seg.modify(rt[np], 1, n, id), pos[id] = np;
		for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
		if(!p) return (void) (fa[np] = 1, tail = np);
		int q = ch[p][c];
		if(dep[q] == dep[p] + 1) fa[np] = q;
		else{
			int nq = newnode(dep[p] + 1);
			fa[nq] = fa[q], fa[q] = fa[np] = nq;
			for(int i = 0; i < 26; i++) ch[nq][i] = ch[q][i];
			for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
		}tail = np;
	}
	inline void prepare(){
		for(int i = 1; i <= size; i++) f[i][0] = fa[i];
		for(int j = 1; j <= 22; j++)
			for(int i = 1; i <= size; i++) f[i][j] = f[f[i][j-1]][j-1];
		for(int i = 1; i <= size; i++) buf[dep[i]]++;
		for(int i = 1; i <= size; i++) buf[i] += buf[i-1];
		for(int i = 1; i <= size; i++) a[buf[dep[i]]--] = i;
		for(int i = size; i >= 2; i--){
			int u = a[i];
			rt[fa[u]] = Seg.merge(rt[u], rt[fa[u]], 1, n);
		}
	}
	inline bool check(int x, int len, int l, int r){
		x = pos[x];
		for(int i = 22; i >= 0; i--) if(dep[f[x][i]] >= len) x = f[x][i];
		return Seg.query(rt[x], 1, n, l, r) >= 1; 
	}
}van;
inline int solve(int a, int b, int c, int d){
	int l = 1, r = min(b - a + 1, d - c + 1), ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(van.check(c + mid - 1, mid, a + mid - 1, b))
			ans = mid, l = mid + 1; else r = mid - 1;
	}
	return ans;
}
int main(){
	read(n), read(m), scanf("%s", s + 1); 
	for(int i = 1; i <= n; i++) van.ins(s[i] - 'a', i);
	van.prepare();
	for(int i = 1; i <= m; i++){
		int a, b, c, d;
		read(a), read(b), read(c), read(d);
		printf("%d\n", solve(a, b, c, d));
	}
	return 0;
}
