/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
typedef unsigned long long ull;
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
char s[N], t[N]; 
ll hs[N], ht[N], pw[N];
int f[N][32], n, m, k; 
inline ll Gets(int l, int r){ return (hs[r] - (hs[l-1] * pw[r-l+1]) % Mod + Mod) % Mod; }
inline ll Gett(int l, int r){ return (ht[r] - (ht[l-1] * pw[r-l+1]) % Mod + Mod) % Mod; }
int main(){
	read(n), scanf("%s", s + 1);
	read(m), scanf("%s", t + 1);
	read(k), pw[1] = 233; int flag = 0;
	for(int i = 2; i < N; i++) pw[i] = pw[i-1] * 233  % Mod;
	for(int i = 1; i <= n; i++) hs[i] = (hs[i-1] * 233 + s[i]) % Mod;
	for(int i = 1; i <= m; i++) ht[i] = (ht[i-1] * 233 + t[i]) % Mod;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= k; j++){
			if(f[i][j] == m) return puts("Yes"), 0;
			f[i+1][j] = Max(f[i+1][j], f[i][j]);
			int len = f[i][j], l = 1, r = Min(n - i, m - len), now = -1;
			while(l <= r){
				int mid = l + r >> 1;
				if(Gets(i + 1, i + mid) == Gett(len + 1, len + mid))
					l = mid + 1, now = mid; else r = mid - 1;
			}
			if(~now) f[i+now][j+1] = Max(f[i+now][j+1], f[i][j] + now);
		}
	puts("No");	
	return 0;
}
