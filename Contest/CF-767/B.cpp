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
int a[300005], e[300005], L, R, n, t;
main(){
	int mn = inf;
	read(L), read(R), read(t), read(n);
	if(n == 0) return printf("%lld", L), 0;
	for(int i = 1; i <= n; i++)
		read(a[i]), mn = Min(a[i], mn);
	sort(a + 1, a + n + 1);
	if(a[1] > L) return cout << L << endl, 0; 
	int tim = (ll) (1e18), ans = -1;
	if(mn - 1 >= 0)
		tim = L + t - mn + 1, ans = mn - 1;
	e[1] = Max(a[1], L) + t - 1;
	for(int i = 2; i <= n; i++){
		if(a[i] > a[i-1]){
			int now = Max(e[i-1] + t, Max(a[i] - 1, L) + t - 1);
			//cout << i << " " << Max(e[i-1] + 1, Max(a[i] - 1, L)) << " " << now << endl;
			if(now < R && now - a[i] + 1 < tim)
				tim = now - a[i] + 1, ans = a[i] - 1;
		}
		int s = Max(Max(a[i], L), e[i-1] + 1); 
		e[i] = s + t - 1;
		//cout << i << " " << e[i] << endl;
	}
	if(e[n] + t < R) cout << e[n] + 1 << endl; 
	else cout << ans << endl;
	//cout << tim << endl; 
	return 0;
}
