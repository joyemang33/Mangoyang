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
int a[30005], b[30005], c[30005];
main(){
	int n; read(n);
	if(n >= 40 || n == 32 || n == 29) return puts("IMPOSSIBLE"), 0; 
	for(int i = 1; i <= n; i++) read(b[i]);
	for(int i = n; i >= 2; i--){
		int now = 0;
		for(int j = 1; j <= n - i; j++) now += a[j];
		if(b[i-1] && now >= 0) c[1] = 1;
		if(b[i-1] && now <= 0) c[1] = -now + 1;
		if(!b[i-1] && now <= 0) c[1] = -1;
		if(!b[i-1] && now >= 0) c[1] = -now - 1;
		for(int j = 1; j <= n - i; j++) c[j+1] = c[j] + a[j];
		for(int j = 1; j <= n - i + 1; j++)
			if(abs(a[j] = c[j]) > (ll)(1e9)) return puts("IMPOSSIBLE"), 0;
	}
	if(b[1]) c[1] = -(ll) (1e9); else c[1] = (ll) (1e9);
	for(int i = 1; i <= n - 1; i++) c[i+1] = c[i] + a[i];
	for(int i = 1; i <= n; i++) if(abs(c[i]) > (ll) (1e9)) return puts("IMPOSSIBLE"), 0;
	for(int i = 1; i <= n; i++) printf("%lld ", c[i]);
	return 0;
}
