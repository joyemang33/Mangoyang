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
main(){
	int n, m, k, ans = inf; read(n), read(k);
	for(int i = 1; i <= n; i++){
		int x; read(x); if(x == 1) m = i;
	}
	for(int i = 1; i <= k; i++){
		int RR = n - (m + k - i), LL = m - i;
		if(LL < 0 || RR < 0) continue;
		int nl = (LL % (k - 1) == 0) ? LL / (k - 1) : LL / (k - 1) + 1;
		int nr = (RR % (k - 1) == 0) ? RR / (k - 1) : RR / (k - 1) + 1; 
		ans = Min(ans, nl + nr + 1);
	}
	cout << ans << endl;
	return 0;
}
