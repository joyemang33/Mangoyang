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
#define N (5000005)
vector<int> g[N], ans;
int sz[N], n, rt, ned;
inline void dfs(int u, int fa){
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v != fa) dfs(v, u), sz[u] += sz[v];
	}
	if(sz[u] == ned && u != rt && ans.size() < 2) ans.push_back(u), sz[u] = 0;
	//cout << u << " " << sz[u] << endl;
}
int main(){
	read(n); int sum = 0;
	for(int i = 1, x, y; i <= n; i++){
		read(x), read(y);
		if(!x) rt = i; 
		else g[x].push_back(i);
		sz[i] = y, sum += y;
	}
	if(sum % 3 != 0) return puts("-1"), 0;
	ned = sum / 3;
	if(!rt) return puts("-1"), 0;
	dfs(rt, 0);
	if(ans.size() >= 2){
		for(int i = 0; i < 2; i++) 
			printf("%d ", ans[i]);
		cout << endl;
	}
	else cout << -1 << endl;
	return 0;
}
