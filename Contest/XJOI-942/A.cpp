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
inline bool check(ll x){
	if(x < 2) return 0;
	int lim = (int) sqrt(x);
	for(int i = 2; i <= lim; i++)
		if(x % i == 0) return 0;
	return 1;
}	
main(){
	ll l, r;
	read(l), read(r);
	if(l > r) swap(l, r);
	for(int i = l; i <= r; i++)
		if(check(i)) printf("%lld ", i);
	return 0;
}
