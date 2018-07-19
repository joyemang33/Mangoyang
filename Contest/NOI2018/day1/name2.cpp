/*pragram by mangoyang*/
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
const int N = 3500005, MAXN = 1500005;
char s[N]; int rt[N], n;
struct SegmentTree{
	int lc[MAXN*25], rc[MAXN*25], sz[MAXN*25], size;
	inline SegmentTree(){ size = 1; }
	inline void ins(int &u, int l, int r, int pos){
		if(!u) u = ++size;
		if(l == r) return (void) (sz[u]++);
		int mid = l + r >> 1; 
		if(pos <= mid) ins(lc[u], l, mid, pos);
		else ins(rc[u], mid + 1, r, pos); 
		sz[u] = sz[lc[u]] + sz[rc[u]];
	}
	inline int merge(int x, int y, int l, int r){
		if(!x || !y) return x + y;
		int mid = l + r >> 1, o = ++size;
		if(l == r) sz[o] = sz[x] + sz[y];
		else{
			lc[o] = merge(lc[x], lc[y], l, mid);
			rc[o] = merge(rc[x], rc[y], mid + 1, r);
			sz[o] = sz[lc[o]] + sz[rc[o]];
		}
		return o;
	}
	inline int query(int u, int l, int r, int pos){
		if(!sz[u]) return 0;
		if(l == r) return l;
		int mid = l + r >> 1;
		if(pos <= mid) return query(lc[u], l, mid, pos);
		int rans = query(rc[u], mid + 1, r, pos);
		return rans ? rans : query(lc[u], l, mid, pos);
	}
}Seg;
struct SuffixAutomaton{
	vector<int> g[N], v; ll dep[N];
	int ch[N][26], fa[N], vis[N], tail, size;
	inline SuffixAutomaton(){ size = tail = 1, rt[1] = 1; }
	inline int newnode(int x){ return dep[++size] = x, size; }
    inline void ins(int c, int ff, int pos){
        int p = tail, np = newnode(dep[p] + 1);
        if(ff) v.push_back(np); else Seg.ins(rt[np], 1, n, pos);
        for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
        if(!p) return (void) (fa[np] = 1, tail = np);
        int q = ch[p][c];
        if(dep[q] == dep[p] + 1) fa[np] = q;
        else{
            int nq = newnode(dep[p] + 1);
            fa[nq] = fa[q], fa[np] = fa[q] = nq;
            if(ff) rt[nq] = rt[q];
            for(int i = 0; i < 26; i++) ch[nq][i] = ch[q][i];
            for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;	
        }tail = np;
    }
	inline void addedge(){
		for(int i = 2; i <= size; i++) g[fa[i]].push_back(i);
	}
	inline void dfs(int u){
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			dfs(v), rt[u] = Seg.merge(rt[u], rt[v], 1, n);	
		}
	}
	inline void prepare(char *s){
		for(int i = 0; i < n; i++) ins(s[i] - 'a', 0, i + 1);
		addedge(), dfs(1);
	}	
	inline ll calc(char *s, int l, int r){
		tail = 1; v.clear(); 
		ll len = strlen(s), ans = 0, all = 0;
		for(int i = 0; i < len; i++) ins(s[i] - 'a', 1, 0);
		for(int i = 0; i < v.size(); i++){
			int u = v[i];
			for(int p = u; p > 1; p = fa[p]) {
				if(vis[p]) break; int OK = 0;
				all += dep[p] - dep[fa[p]], vis[p] = 1;
				if(rt[p]){
					if((l == 1 && r == n) || OK)
						{ ans += dep[p] - dep[fa[p]]; continue; }
					int mxlen = Seg.query(rt[p], 1, n, r) - l + 1;
					if(mxlen > dep[fa[p]]) 
						ans += Min(dep[p], mxlen) - dep[fa[p]];
					if(mxlen >= dep[p]) OK = 1;
				}
			}
		}
		for(int i = 0; i < v.size(); i++){
			int u = v[i];
			for(int p = u; p > 1; p = fa[p]){
				if(!vis[p]) break; vis[p] = 0;
			}
		}
		//cout << all << " " << ans << endl;
		return all - ans;
	}	
}van;
int main(){
	scanf("%s", s); n = strlen(s);
	int Q; read(Q), van.prepare(s);
	while(Q--){
		int l, r;
		scanf("%s", s), read(l), read(r);
		printf("%lld\n", van.calc(s, l, r));
	}
}
