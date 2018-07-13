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
#define N (6005)
#define Lim (300005)
map<int, int> mp;
int a[N], f[Lim+5], prime[Lim+5], b[N], tot, n, m;
inline int gcd(int a, int b){ return b ? gcd(b, a % b) : a; }
inline int calc(int x){
	//cout << x << " ";
	if(x == 1) return 0; int ans = 0;
	for(int j = 1; j <= tot; j++)
		while(x % prime[j] == 0){
			x /= prime[j];
			if(mp[prime[j]]) ans--; else ans++;
		}
	if(x > 1){
		if(mp[x]) ans--; else ans++;
	}
	//cout << ans << endl;
	return ans; 
}
int main(){
	read(n), read(m);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= m; i++) read(b[i]), mp[b[i]] = 1;
	for(int i = 2; i < Lim; i++){
		if(!f[i]) f[i] = i, prime[++tot] = i;
		for(int j = 1; i * prime[j] <= Lim && j <= tot; j++){
			f[prime[j]*i] = prime[j];
			if(i % prime[j] == 0) break;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += calc(a[i]);
	for(int i = n; i >= 1; i--){
		int g = a[1];
		for(int j = 2; j <= i; j++) g = gcd(g, a[j]);
		if(calc(g) < 0){
			ans -= calc(g) * i;
			for(int j = 1; j <= i; j++) a[j] /= g;
		}
		//for(int i = 1; i <= n; i++) cout << a[i] << " "; 
		cout << endl;
	}
	cout << ans << endl;
	return 0;
}
