/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define P (1000000007)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
}
inline ll Pow(ll a, ll b){
	ll ans = 1;
	for(; b; b >>= 1, a = a * a % P)
		if(b & 1) ans = ans * a % P;
	return ans;
}
int main(){
	ll x, k; read(x), read(k); 
	if(!k || !x) cout << 2ll * (x % P) % P;
	else x %= P, cout << (2ll * (Pow(2ll, k) * x % P - Pow(2ll, k - 1) + P) % P + 1ll) % P; 
	return 0;
}
p = k(s - (+))(*)
Bi(1 - ci / cx) = mx / cx

