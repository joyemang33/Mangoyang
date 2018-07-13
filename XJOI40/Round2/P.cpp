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
#define N (2005)
#define int ll
const int Mod = 1000000007;
int js[N], inv[N], f[N][N][2][2], g[N], n, k;
inline int pow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = a * a % Mod)
		if(b & 1) ans = ans * a % Mod;
	return ans;
}
inline int C(int n, int i){ return js[n] * inv[i] % Mod * inv[n-i] % Mod; }
main(){
	read(n), read(k), f[0][0][0][0] = 1, js[0] = inv[0] = 1;
	for(int i = 1; i <= n; i++){
		js[i] = js[i-1] * i % Mod;
		inv[i] = pow(js[i], Mod - 2);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= n; j++){
			(f[i][j][0][0] += f[i-1][j][0][0] + f[i-1][j][1][1]) %= Mod;
			(f[i][j][0][0] += f[i-1][j][0][1] + f[i-1][j][1][0]) %= Mod;
			if(j >= 1 && i > 1){ 
				(f[i][j][1][0] += f[i-1][j-1][1][0] + f[i-1][j-1][0][0]) %= Mod;
				(f[i][j][0][1] += f[i-1][j-1][0][1] + f[i-1][j-1][0][0]) %= Mod;
			}
			if(j >= 2 && i > 1) (f[i][j][1][1] += f[i-1][j-2][0][0]) %= Mod;
		}
	for(int i = 0; i <= n; i++){
		int res = 0;
		(res += f[n][i][0][0] + f[n][i][1][0]) %= Mod;
		(res += f[n][i][0][1] + f[n][i][1][1]) %= Mod;
		g[i] = res * js[n-i] % Mod; //cout << g[i] << " ";
	}
	//cout << endl;
	int ans = 0;
	for(int i = k; i <= n; i++){
		int p = ((i - k) & 1) ? Mod - 1 : 1; 
		(ans += C(i, k) * p % Mod * g[i] % Mod) %= Mod;
	}
	cout << ans << endl;
	return 0;
}
