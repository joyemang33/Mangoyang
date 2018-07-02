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
#define int ll
inline ll check(ll n, ll k){
	ll now = 0;
	while(n > 0){
		ll tmp = Min(n, k);
		n -= tmp, now += tmp;
		n = n - (n / 10);
	}
	return now;
}
main(){
	ll n; read(n);
	int l = 1, r = n, c = (n + 1) / 2, ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(n, mid) >= c) ans = mid, r = mid - 1;
		else l = mid + 1;
	}	
	cout << ans;
	return 0;
}
