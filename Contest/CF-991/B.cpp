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
int a[300005], n, ans, s;
int main(){
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s += a[i];
	for(int i = 1; i <= n; i++){
		if(((double) s / (double) n) - 4.5 > -(1e-5)) return cout << ans, 0;
		s += 5 - a[i], ans++;
		if(((double) s / (double) n) - 4.5 > -(1e-5)) return cout << ans, 0;
	}
	return 0;
}
