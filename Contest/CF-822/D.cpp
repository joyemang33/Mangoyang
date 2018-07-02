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
#define int ll
#define N (5000005)
#define P (1000000007)
ll f[N], prime[N], g[N], tot;
main(){
	ll t, l, r; ll ans = 0;
	read(t), read(l), read(r);
	for(int i = 2; i < N; i++){
		if(!g[i]) g[i] = i, prime[++tot] = i;
		for(int j = 1; i * prime[j] < N && j <= tot; j++){
			g[i*prime[j]] = prime[j];
			if(i % prime[j] == 0) break;
		}
		f[i] = (i * (g[i] - 1) / 2 + f[i/g[i]]) % P; 
	}
	for(int i = l, now = 1; i <= r; i++, (now *= t) %= P)
		(ans += now * f[i] % P) %= P;
	cout << ans << endl;
	return 0;
}
/*
	对于含有质因子x的数y 假设有两个因数k1x k2x (k1 < k2)
	那么有f[k2]
*/
