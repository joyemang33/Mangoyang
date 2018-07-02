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
#define int ll
ll c[N], a[N], n, q;
inline void add(int x, ll y){ for(int i = x; i <= n; i += i & -i) c[i] += y; }
inline ll sum(int x){ ll ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans; }
inline void solve(){
	int x = 1;
	if(sum(1) == 0) return (void)( puts("1") );
	while(x < n){
		int l = x + 1, r = n, k = x, now = 2 * sum(x);
		if(sum(x + 1) == now) return (void) (printf("%d\n", x + 1));
		while(l <= r){
			int mid = l + r >> 1;
			if(sum(mid) < now) k = mid, l = mid + 1; else r = mid - 1;
		}
		if(k + 1 > n) break;
		x = (k == x) ? k + 1 : k;
	}
	puts("-1");
}
main(){
	read(n), read(q);
	for(int i = 1; i <= n; i++) read(a[i]), add(i, a[i]);
	for(int i = 1; i <= q; i++){
		int x, y; read(x), read(y);
		add(x, y - a[x]), a[x] = y, solve();
	}
	return 0;
}
