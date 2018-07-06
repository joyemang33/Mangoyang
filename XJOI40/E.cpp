/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf ((ll)1e18)
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
#define N (2000005)
int a[N], s[N], n, m, p;
inline bool check(int x){
	int p = n;
	for(int i = 1; i <= n; i++) s[i] = a[i];
	for(int i = 1; i <= m; i++){
		int tim = x - p;
		while(s[p] <= tim && p) tim -= s[p], s[p] = 0, p--;
		if(!p) return 1;
		if(tim) s[p] -= tim;
	}
	return 0;
}	
main(){
	read(n), read(m);
	for(int i = 1; i <= n; i++) read(a[i]);
	while(!a[n] && n) n--;
	if(!n) return puts("0"), 0;
	int l = 1, r = inf, ans = inf;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)) r = mid - 1, ans = mid; else l = mid + 1;
	}	
	cout << ans << endl;
	return 0;
}
