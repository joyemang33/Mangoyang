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
#define N (400005)
int a[N], n;
inline int calc(int x){
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += abs(a[i] - (x + i));
	return ans;
}
main(){
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]);
	int l = -inf, r = inf;
	for(int t = 0; t < 100; t++){
		int m = (r - l + 1) / 3;
		int m1 = l + m, m2 = r - m;
		if(calc(m1) < calc(m2)) r = m2; else l = m1;
	}
	cout << calc(l);
	return 0;
}
