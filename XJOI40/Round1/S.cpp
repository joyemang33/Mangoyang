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
#define N (500005)
vector<int> g[N];
int sz[N], Ans[N], n;
struct Point{ double x, y; int id; } a[N], O;
inline double cross(double X1, double X2, double Y1, double Y2){
	return X1 * Y2 - X2 * Y1;
}	
inline bool cmp(Point A, Point B){
	return cross(A.x - O.x, A.y - O.y, B.x - O.x, B.y - O.y) > 0;
}
inline void dfs(int u, int fa){
	sz[u] = 1;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v != fa) dfs(v, u), sz[u] += sz[v];
	}
}
inline void solve(int u, int fa, int l, int r){
	int co = l;
	for(int i = l + 1; i <= r; i++)
		if(a[i].y < a[co].y || a[i].y == a[co].y && a[i].x < a[co].x) co = i;
	if(co != l) swap(a[co], a[l]); 
	O = a[l], Ans[a[l].id] = u;
	sort(a + l + 1, a + r + 1, cmp);
	int pos = l + 1;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v != fa) 
			solve(v, u, pos, pos + sz[v] - 1), pos += sz[v];
	}
	
}		
int main(){
	read(n);
	for(int i = 1, x, y; i < n; i++){
		read(x), read(y);
		g[x].push_back(y), g[y].push_back(x);
	}
	for(int i = 1; i <= n; i++)
		scanf("%lf%lf", &a[i].x, &a[i].y), a[i].id = i;
	dfs(1, 0), solve(1, 0, 1, n);
	for(int i = 1; i <= n; i++) printf("%d ", Ans[i]);
	return 0;
}
