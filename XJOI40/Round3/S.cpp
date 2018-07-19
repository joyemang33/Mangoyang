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
const int N = 100, D = 7, INF = 1ll << 31;
struct Lover{ int a, b, c; }; vector<Lover> ans;
main(){
	int n = N, T;
	for(int i = 2 ; i <= D + 1 ; ++ i)ans.push_back((Lover) {1, i, 0});
	for (int i = N - D, delta = 1 ; i > 1 ; i -= D, delta = delta * D, delta = delta >= INF ? 1 : delta)
		for (int j = i + D - 1, v = - 1 ; j >= i ; -- j, v -= delta, v = v <= -INF ? -1 : v) 
			for (int k = i + D ; k <= i + D + D - 1 && k <= N ; ++ k)  ans.push_back((Lover) {j, k, v});
    while(scanf("%lld",&T) != EOF){
  	    printf("%lld %lld\n", n, (int) ans.size());
  		  for (int i = 0 ; i < (int) ans.size() ; ++ i)
    	  printf("%lld %lld %lld\n", ans[i].a,ans[i].b,ans[i].c); 
    }
  return 0;
}

