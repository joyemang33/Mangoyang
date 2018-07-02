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
vector<int> v;
main(){
	int T; read(T);
	while(T--){
		int k, p, flag = 0; read(k), read(p);
		ll c = 1, add = 0;
		int l = 1ll, r = (1ll << k) - 1ll;
		if(p == 1){ puts("0"); continue; }
		while(l < r){
			int mid = l + r >> 1ll;
			if(p >= mid){
				printf("%lld\n", p - mid);
				break;
			}
			else r = mid - 1ll;		
		}
	}	
	return 0;
}
