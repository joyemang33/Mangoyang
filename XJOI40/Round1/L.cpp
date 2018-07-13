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
#define N (2005)
const int Lim = 200005;
int prime[Lim+5], f[Lim+5], tot;
int dp[N], c[N], a[N], n, ans;
vector<int> pr[N], pc[N];
map<int, int> mp;
inline void update(int mask){
	for(int i = 1; i <= n; i++){
		int tmp = 0;
		for(int j = 0; j < pc[i].size(); j++){
			int x = pc[i][j];
			if((1 << x) & mask) tmp |= (1 << x);
		}
		if(tmp != mask && dp[tmp] > dp[mask] + c[i]){
			dp[tmp] = dp[mask] + c[i]; if(tmp) update(tmp);
		}
	}	 	
}
inline void solve(int x){
	if(a[x] == 1) return (void) (ans = Min(ans, c[x])); 
	int col = 0, mask = 0;
	mp.clear(), memset(dp, 127, sizeof(dp));
	for(int i = 0; i < pr[x].size(); i++) 
		mp[pr[x][i]] = ++col, mask |= (1 << col);
	for(int i = 1; i <= n; i++) pc[i].clear();
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < pr[i].size(); j++){
			int x = mp[pr[i][j]];
			if(x > 0) pc[i].push_back(x);
		}
	dp[mask] = c[x], update(mask), ans = Min(ans, dp[0]); 
}
main(){
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++) read(c[i]);
	for(int i = 2; i < Lim; i++){
		if(!f[i]) f[i] = i, prime[++tot] = i;
		for(int j = 1; i * prime[j] <= Lim && j <= tot; j++){
			f[prime[j]*i] = prime[j];
			if(i % prime[j] == 0) break;
		}
	}
	for(int i = 1; i <= n; i++){
		int x = a[i];
		for(int j = 1; j <= tot; j++){
			if(x % prime[j] == 0) pr[i].push_back(prime[j]);
			while(x % prime[j] == 0) x /= prime[j];
		}
		if(x > 1) pr[i].push_back(x);
	}
	ans = inf;
	for(int i = 1; i <= n; i++) solve(i);
	if(ans == inf) cout << -1; else cout << ans;	
	return 0;
}
