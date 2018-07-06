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
#define int ll
#define Mod (1032992941)
#define N (1000105)
int a[N], nxt[N], head[N], cnt;
int f[N][2], s[N][2], n;
inline void add(int x, int y){
	a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt;
}
inline void DP(int u, int fa){
	int tot0 = 1, mnsum = 0; 
	s[u][0] = s[u][1] = 1, f[u][0] = f[u][1] = inf;
	for(int p = head[u]; p; p = nxt[p]){
		int v = a[p];
		if(v == fa) continue;
		DP(v, u), (tot0 *= s[v][0]) %= Mod;
		(s[u][1] *= (s[v][0] + s[v][1])) %= Mod;
		(s[u][0] *= (s[v][0] + s[v][1])) %= Mod; 
		mnsum += Min(f[v][0], f[v][1]);
	}
	f[u][1] = mnsum + 1;
	s[u][0] = (s[u][0] - tot0 + Mod) % Mod;
	for(int p = head[u]; p; p = nxt[p]){
		int v = a[p]; 
		if(v == fa) continue;
		int det = f[v][1] - Min(f[v][0], f[v][1]);
		f[u][0] = Min(f[u][0], mnsum + det);
	}
}
main(){
	read(n);
	for(int i = 1, x, y; i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	DP(1, n);
	cout << Min(f[1][0], f[1][1]) << endl;
	cout << (s[1][0] + s[1][1]) % Mod << endl;
	return 0;
}
