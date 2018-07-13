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
int f[N][23], dep[N], tot; 
inline void addson(int u){
	int v = ++tot; 
	dep[v] = dep[u] + 1, f[v][0] = u;
	for(int j = 1; j <= 22; j++) f[v][j] = f[f[v][j-1]][j-1];
}
inline int Lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 22; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(dep[x] == dep[y]) break;
	}
	if(x == y) return x;
	for(int i = 22; i >= 0; i--)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
inline int dis(int x, int y){
	int lca = Lca(x, y); return dep[x] + dep[y] - 2 * dep[lca];	
}
int main(){
	dep[2] = dep[3] = dep[4] = 1;
	f[2][0] = f[3][0] = f[4][0] = 1, tot = 4;
	int n, l = 2, r = 4, ans = 2;
	read(n);
	for(int i = 1; i <= n; i++){
		int x; read(x);
		addson(x), addson(x);
		int nl = tot - 1, nr = tot;
		int s1 = dis(nl, r), s2 = dis(nl, l);
		int s3 = dis(nr, l), s4 = dis(nr, r);
		ans = Max(ans, Max(Max(s1, s2), Max(s3, s4)));
		if(ans == s1) l = nl;
		else if(ans == s2) r = nl;
		else if(ans == s3) r = nr;
		else if(ans == s4) l = nr;
		printf("%d\n", ans); 
	}	
	return 0;
}
