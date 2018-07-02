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
int a[100005], n, k, x, ans;
main(){
	read(n), read(k), read(x);
	for(int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1), k = Min(k, n);
	for(int i = 1; i <= n - k; i++) ans += a[i];
	ans += k * x;
	cout << ans;
	return 0;
}
