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
#define int ll
double val[N], ans;
int a[N], nxt[N], head[N], sz[N], X[N], Y[N], cnt, n;
struct Point{ int id, x; }; vector<Point> pr;
inline void add(int x, int y){
	a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt;
}
inline void dfs(int u, int fa){
	sz[u] = 1;
	for(int p = head[u]; p; p = nxt[p]){
		int v = a[p];
		if(v != fa) dfs(v, u), sz[u] += sz[v];
	}
}
inline void solve(int id, double v){
	double now = v - val[id]; val[id] = v;
	int x = X[id], y = Y[id];
	if(sz[x] > sz[y]) swap(x, y);
	int l = sz[x], r = n - sz[x];
	//cout << sz[x] << " " << n - sz[x] << endl;
	if(l >= 2) ans += (l * (l - 1) / 2 * r) * now * 12;
	if(r >= 2) ans += (r * (r - 1) / 2 * l) * now * 12; 
}
main(){
	read(n);
	for(int i = 1, x, y, z; i < n; i++){
		read(x), read(y), read(z);
		add(x, y), add(y, x), X[i] = x, Y[i] = y;
		pr.push_back((Point){i, z});
	}	
	dfs(1, 0);
	double all = n * (n - 1) * (n - 2);
	for(int i = 0; i < pr.size(); i++) solve(pr[i].id, pr[i].x);
	int m; read(m);
	//printf("\n%.7lf\n", (double) ans / all);
	for(int i = 1, id, x; i <= m; i++){
		read(id), read(x), solve(id, x);
		printf("%.12lf\n", (double) ans / all);
	}
	return 0;
}
