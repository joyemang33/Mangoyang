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
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
}
#define S (1100000)
int p[S], c[S], s[S], n, m;
ll f[S][21], dis[22][22], ss[22], cc[22];
inline int lowbit(int x){ return x & -x; }
inline void solve(){
	read(n), read(m);
	for(register int i = 1; i <= n; i++) p[1<<i-1] = i;
	for(register int i = 1; i <= n; i++) 
		for(register int j = 1; j <= n; j++) dis[i][j] = inf;
	for(register int i = 0; i < 1 << n; i++) c[i] = s[i] = 0;
 	for(register int i = 1, x; i <= n; i++)
		read(x), cc[i] = x, read(x), ss[i] = x;
	for(register int i = 1; i < 1 << n; i++)
		for(register int j = i; j; j -= lowbit(j))
			c[i] += cc[p[lowbit(j)]], s[i] += ss[p[lowbit(j)]]; 
	for(register int i = 1, x, y, z; i <= m; i++){
		read(x), read(y), read(z);
		if(z < dis[x][y]) dis[x][y] = dis[y][x] = z;
	}
	for(register int k = 1; k <= n; k++)
		for(register int i = 1; i <= n; i++)
			for(register int j = 1; j <= n; j++)
				dis[i][j] = Min(dis[i][j], dis[i][k] + dis[k][j]);
	ll ans = 0;
	for(register int i = 1; i < (1 << n); i++)
		for(register int j = 1; j <= n; j++) f[i][j] = inf;
	f[1][1] = 0;
	for(register int i = 1; i < (1 << n); i++)
		for(register int j = i; j; j -= lowbit(j)){
			int u = p[lowbit(j)];
			for(register int k = i; k; k -= lowbit(k)) if(k != j){
				int v = p[lowbit(k)], d = i ^ lowbit(j);
				f[i][u] = Min(f[i][u], f[d][v] + dis[v][u] * s[(1<<n)-1-d]); 
			}
			ans = Max(ans, c[i] - f[i][u]); 	
		}
	printf("%lld\n", ans);
}
main(){
	int T; read(T);  
	while(T--) solve(); 
	return 0;
}
/*
f[s][u]表示已经选取了s集合走到点u上时，浪费的最小新鲜度之和
f[s][u] = min(f[s^i][i] + dis[i][u] * s[S-(s^i)]) ans = max(sum[s] - f[s][i])
*/
