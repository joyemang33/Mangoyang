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
inline ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }
int main(){
	ll x, y, l, r; 
	read(l), read(r), read(x), read(y);
	ll now = y, s = (ll) sqrt(now), ans = 0;
	for(ll i = x; i <= s * x; i += x) if(now % i == 0){
		if(i < l || (now / i) * x > r) continue;
		if(i > r || (now / i) * x < l) continue;
		if(gcd(i, (now / i) * x) != x) continue;
		if(i > (now / i) * x) break;
		if(i * i / x == now) ans += 1; else ans += 2;
	}
	cout << ans;
	return 0;
}
