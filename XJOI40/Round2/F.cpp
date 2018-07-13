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
#define fi first
#define par pair<int, int>
#define se second
#define N (100005)
int f[N], a[N], c[N], n, m;
inline int solve(int x, int y){
	int ans = 0; f[0] = 0;
	for(int i = 1; i <= n; i++) f[i] = -(ll)(1e18);
	par now = make_pair(0, 0);
	for(int i = 1; i <= n; i++){
		int s1 = (now.fi == c[i]) ? x * a[i] : y * a[i];
		int s2 = (now.se == c[i]) ? x * a[i] : y * a[i];
		int res = Max(f[now.fi] + s1, f[now.se] + s2);
		if(f[c[i]] > - (ll) (1e18)) 
			res = Max(res, f[c[i]] + Max(x * a[i], 0ll));
		if(!now.fi && !now.se){
			if(res > 0) now.fi = c[i]; else now.se = c[i];
			f[c[i]] = res;
			continue;
		}
		if(res > f[now.fi] && c[i] != now.fi) now.se = now.fi, now.fi = c[i];
		else 
			if(res > f[now.se] && c[i] != now.fi) now.se = c[i];
		f[c[i]] = res;
	}
	for(int i = 1; i <= n; i++) ans = Max(f[c[i]], ans);
	return ans;
}
main(){
	read(n), read(m);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++) read(c[i]);
	for(int i = 1, x, y; i <= m; i++)
		read(x), read(y), printf("%lld\n", solve(x, y));
	return 0;
}
