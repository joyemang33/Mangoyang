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
#define par pair<int, int>
#define fi first
#define se second
par f[(1<<19)+105]; 
main(){
	int n; read(n);
	for(int i = 0; i < (1 << n); i++) read(f[i].fi);
	for(int j = 0; j < n; j++)
		for(int i = 1; i < (1 << n); i++){
			if(i & (1 << j)){
				par now = f[i^(1<<j)];
				if(now.fi > f[i].fi){
					f[i].se = Max(f[i].fi, now.se);
					f[i].fi = now.fi;
				}
				else f[i].se = Max(f[i].se, now.fi);	
			}
		}
	for(int i = 1; i < (1 << n); i++){
		//cout << i << " " << f[i].fi << " " << f[i].se << endl;
		par now = f[i-1];
		if(now.fi + now.se > f[i].fi + f[i].se) f[i] = now;
		printf("%lld\n", f[i].fi + f[i].se);
	}
	return 0;
}

