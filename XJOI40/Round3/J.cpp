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
const int Mod = 1000000007;
int f[2][1005][60], g[1005], s[60], lcm[60][60], n, m, k, tot;
inline void solve(){
	tot = 0;
	memset(s, 0, sizeof(s));
	memset(f, 0, sizeof(f));
	memset(lcm, 0, sizeof(lcm));
	for(int i = 1; i <= m; i++) 
		if(m % i == 0) s[++tot] = i, g[i] = tot;
	for(int i = 1; i <= tot; i++)
		for(int j = 1; j <= tot; j++) 
			lcm[i][j] = g[s[i]*s[j]/__gcd(s[i], s[j])];
	for(int i = 1; i <= tot; i++) f[1][s[i]][i] = 1;
	for(int i = 1; i <= k; i++){
		int o = i & 1;
		memset(f[o^1], 0, sizeof(f[o^1]));
		for(int j = 0; j <= n; j++)
			for(int k1 = 1; k1 <= tot; k1++)
				for(int k2 = 1; k2 <= tot; k2++) if(j + s[k2] <= n) 
					(f[o^1][j+s[k2]][lcm[k1][k2]] += f[o][j][k1]) %= Mod;
		//cout << f[1][2][1] << endl;
		
	}
	cout << f[k&1][n][tot] << endl;
}
main(){
	while(~scanf("%lld%lld%lld", &n, &m, &k)) solve();
	return 0;
}
