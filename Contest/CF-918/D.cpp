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
#define N (205)
#define M (300005)
int a[M], b[M], nxt[M], head[N], cnt;
int f[N][N][30][2], g[N][N][30][2], n, m;
inline void add(int x, int y, int z){
	a[++cnt] = y, b[cnt] = z, nxt[cnt] = head[x], head[x] = cnt;
}
inline int DP(int u, int v, int c, int t){
	if(g[u][v][c][t]) return f[u][v][c][t];
	if(t == 0){
		int now = 0;
		for(int p = head[u]; p; p = nxt[p])
			if(b[p] >= c && !DP(a[p], v, b[p], t ^ 1)) now = 1;
		return g[u][v][c][t] = 1, f[u][v][c][t] = now, now;  
	}
	else{
		int now = 0;
		for(int p = head[v]; p; p = nxt[p])
			if(b[p] >= c && !DP(u, a[p], b[p], t ^ 1)) now = 1;
		return g[u][v][c][t] = 1, f[u][v][c][t] = now, now;
	}
}
int main(){
	read(n), read(m);
	for(int i = 1, x, y, z; i <= m; i++)
		read(x), read(y), z = getchar(), add(x, y, z - 'a');
	for(int i = 1; i <= n; i++, putchar('\n'))
		for(int j = 1; j <= n; j++) putchar(DP(i, j, 0, 0) ? 'A' : 'B');
	return 0;
}
