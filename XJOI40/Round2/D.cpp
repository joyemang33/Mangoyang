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
#define N (200005)
const int Mod = 1000000007;
int js[N], inv[N], a[N], b[N], tot, n, k;
inline int pow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = a * a % Mod)
		if(b & 1) ans = ans * a % Mod;
	return ans;
}
inline int C(int n, int i){
	return js[n] * inv[i] % Mod * inv[n-i] % Mod;
}
main(){
	read(n), js[0] = 1, inv[0] = pow(1, Mod - 2); int res = 0;
	for(int i = 1; i <= n; i++) 
		js[i] = js[i-1] * i % Mod, inv[i] = pow(js[i], Mod - 2);
	for(int i = 1; i <= n; i++){
		int x; read(x);
		if(~x) a[x] = 1, b[i] = 1; else tot++;
	}
	for(int i = 1; i <= n; i++) if(!a[i] && !b[i]) k++;
	//cout << k << " " << tot << endl;
	for(int i = 1; i <= k; i++){
		int p = (i & 1) ? 1 : Mod - 1;
		(res += p * C(k, i) % Mod * js[tot-i] % Mod) %= Mod;
		//cout << res << " " << p * C(k, i) % Mod * js[tot-i] % Mod << endl;
	}
	cout << (js[tot] - res + Mod) % Mod;
	return 0;
}
