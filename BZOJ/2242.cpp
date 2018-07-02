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
int y, z, Mod;
map<int, int> mp;
inline int gcd(int a, int b){ return b ? gcd(b, a % b) : a; }
inline int pow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = a * a % Mod)
		if(b & 1) ans = ans * a % Mod;
	return ans % Mod;
}
inline int exgcd(int a, int b, int &x, int &y){
	if(!b) return x = 1, y = 0, a;
	int g = exgcd(b, a % b, y, x);
	return y -= (a / b) * x, g;
}
inline void Query1(){
	return (void) printf("%lld\n", pow(y, z));
}
inline void Query2(){
	int xx, yy, g = gcd(Mod, y);
	if(z % g != 0) puts("Orz, I cannot find x!");
	else{
		g = exgcd(y, Mod, xx, yy);
		printf("%lld\n", ((xx + Mod) % Mod) * (z / g) % Mod);
	}
}
inline void Query3(){
	y %= Mod;
	if(!y && !z) return (void) (puts("1"));
	if(!y) return (void) (puts("Orz, I cannot find x!"));
	int m = (int) sqrt(Mod); mp.clear();
	for(int i = 0; i < m; i++){
		int now = pow(y, i);
		if(!mp[now]) mp[now] = i + 1;
	}
	for(int i = 0; i <= Mod - 1; i += m){
		int now = z * pow(y, Mod - 1 - i) % Mod;
		if(mp[now]) return (void) (printf("%lld\n", i + mp[now] - 1));
	}
	puts("Orz, I cannot find x!");
}
main(void){
	int T, k; read(T), read(k);
	while(T--){
		read(y), read(z), read(Mod);
		if(k == 1) Query1();
		if(k == 2) Query2();
		if(k == 3) Query3();
	}
	return 0;
}
