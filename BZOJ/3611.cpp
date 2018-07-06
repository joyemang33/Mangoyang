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
namespace VirTree{
	inline void solve(int u, int fa){
		fs[u] = fx[u], fn[u] = inf, sz[u] = 1;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			if(v != fa){
				solve(v, u), sz[u] += sz[v];
				fs[u] += (fs[v] + 1) * sz[v];
				fx[u] = Max(fx[u], fx[v] + 1);
				fn[u] = Min(fn[u], fn[v] + 1);
			}
		}
		
		if(fn[u] == inf) return 0; 
	}
	inline void realmain(int *A, int len){
		for(int i = 1; i <= tot; i++) g[vr[i]].clear();
		int top = 0; tot = 0;
		sort(A + 1, A + len + 1, cmp);
		for(int i = 1; i <= len; i++){
			int u = A[i], lca = Lca::get(u, st[top]);
			if(!top){ st[++top] = u, vr[++tot] = u; continue; }
			for(; top > 1 && dep[st[top]] > dep[lca]; top--)
				if(dep[st[top-1]] < dep[lca]) fa[st[top]] = lca;
			if(st[top] != lca) 
				fa[lca] = st[top], st[++top] = lca, vr[++tot] = lca;
			fa[u] = lca, st[++top] = u, vr[++tot] = u;
		}
		sort(vr + 1, vr + tot + 1, cmp);
		for(int i = 1; i <= tot; i++) g[fa[vr[i]]].push_back(vr[i]);
		anssum = ansmax = 0, ansmin = inf;
		solve(vr[1], 0);
		printf("%lld %lld %lld\n", anssum, ansmax, ansmin);
	}
}
int main(){
	
	return 0;
}
