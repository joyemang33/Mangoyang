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
#define N (300005)
#define Mod (1000000007)
#define int ll
char s[N], t[N];
ll ls[N],vs[N], n;
inline ll pow(ll a, ll b){
	ll ans = 1;
	for(; b; b >>= 1, a = a * a % Mod)
		if(b & 1) ans = ans * a % Mod;
	return ans;
}
struct Node{
	vector<int> a; int f;
	inline void init(){
		scanf("%s", s); 
		int m = strlen(s); f = s[0] - '0';
		for(int i = 1; i < m; i++) 
			if(isdigit(s[i])) a.push_back(s[i]-'0'); 
	}
	inline void calc(){
		ll len = 0, val = 0;
		for(int i = 0; i < a.size(); i++){
			(len += ls[a[i]]) %= (Mod - 1);
			val = (val * pow(10ll, ls[a[i]]) + vs[a[i]]) % Mod;
		}
		ls[f] = len, vs[f] = val;
	}
}q[N];
main(){
	ll ans = 0;
	scanf("%s", t), read(n); int len = strlen(t);
	for(int i = 0; i <= 9; i++) ls[i] = 1, vs[i] = i; 
	for(int i = 1; i <= n; i++) q[i].init();	
	for(int i = n; i >= 1; i--) q[i].calc();
	for(int i = 0; i < len; i++)
		ans = (ans * pow(10ll, ls[t[i]-'0']) + vs[t[i]-'0']) % Mod;
	cout << ans << endl;
	return 0;
}
