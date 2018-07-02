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
#define N (5005)
#define Mod (1000000007)
char s[N];
int hs[N], ht[N], pw[N], f[N][N], ans[N], n;
inline int Hs(int l, int r){
	return (hs[r] - (hs[l-1] * pw[r-l+1]) % Mod + Mod) % Mod;
}
inline int Ht(int l, int r){
	return (ht[l] - (ht[r+1] * pw[r-l+1]) % Mod + Mod) % Mod;
}
main(){
	scanf("%s", s + 1), n = strlen(s + 1), pw[1] = 233;
	for(int i = 2; i <= n; i++) pw[i] = (pw[i-1] * 233) % Mod;
	for(int i = 1; i <= n; i++) hs[i] = (hs[i-1] * 233 + s[i]) % Mod;
	for(int i = n; i >= 1; i--) ht[i] = (ht[i+1] * 233 + s[i]) % Mod;
	for(int i = 1; i <= n; i++) f[i][i] = 1, ans[1]++;
	for(int i = n - 1; i >= 1; i--)
		for(int j = i + 1; j <= n; j++){
			int l = i, r = j, mid = (r - l + 1) / 2, r1 = l + mid - 1, l2;
			if((r - l + 1) & 1) l2 = l + mid + 1; else l2 = l + mid;
			if(Hs(l, r1) == Ht(l2, r)) f[l][r] = f[l][r1] + 1, ans[f[l][r]]++;
			//cout << l << " " << r1 << " " << l2 << " " << r << " " << f[l][r] << endl;
		}
	for(int i = n - 1; i >= 1; i--) ans[i] += ans[i+1];
	for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}
