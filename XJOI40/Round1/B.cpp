/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (1000005)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
vector<int> g[N];
int f[N][24], dep[N], ff[N], n, k;
inline void dfs(int u, int fa){
	dep[u] = dep[fa] + 1, f[u][0] = fa;
	//cout << "#" << u << " " << dep[u] << " " << f[u][0] << endl;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v != fa) dfs(v, u);
	}
}
inline int get(int x){
	//cout << f[4][0] << endl;
	//cout << "*" << ff[2] << endl;
	for(int i = 22; i >= 0; i--){
		//cout << x << " " << f[x][i] << endl;
		if(!ff[f[x][i]] && f[x][i]) x = f[x][i];
	}
	return x;
}
int main(){
	read(n), read(k), k = n - k;
	for(int i = 1, x, y; i < n; i++){
		read(x), read(y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(n, 0);
	//cout << "%######" << f[4][0] << endl;
	for(int j = 1; j <= 22; j++)
		for(int i = 1; i <= n; i++) 
			f[i][j] = f[f[i][j-1]][j-1];
	//cout << "%######" << f[4][0] << endl;
	for(int i = n; i >= 1; i--) if(!ff[i]){
		int u = i, ls = get(u);
		//cout << u << " " << ls << " " << dep[u] - dep[ls] + 1 << endl;
		if(dep[u] - dep[ls] + 1 <= k)
			k -= dep[u] - dep[ls] + 1; else continue;
		for(int s = u; s != ls; s = f[s][0]) ff[s] = 1;
		ff[ls] = 1;
		if(!k) break;
	}
	for(int i = 1; i <= n; i++) 
		if(!ff[i]) printf("%d ", i);
	return 0;
}
