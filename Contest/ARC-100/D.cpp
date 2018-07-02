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
#define N (1000005)
int s[N], n, ans;
inline void checkmax(int &x, int y){ if(y > x) x = y; }
inline void checkmin(int &x, int y){ if(y < x) x = y; }
inline int solve(int L, int R){
	int l = L, r = R - 1, ans = l;
	while(l <= r){
		int mid = l + r >> 1;
		if(s[mid] - s[L-1] <= s[R] - s[mid]) 
			ans = mid, l = mid + 1; else r = mid - 1;
	}	
	return ans;
}
inline int solve2(int L, int R){
	int l = L, r = R - 1, ans = r;
	while(l <= r){
		int mid = l + r >> 1;
		if(s[mid] - s[L-1] > s[R] - s[mid]) 
			ans = mid, r = mid - 1; else l = mid + 1;
	}	
	return ans;
}
main(){
	read(n); int ans = (ll) (1e18);
	for(int i = 1; i <= n; i++) read(s[i]), s[i] += s[i-1];
	for(int i = 2; i <= n - 2; i++){
		int p1 = solve(1, i), p2 = solve(i + 1, n);
		int mx = 0, mn = (ll) (1e18);
		checkmax(mx, s[p1]), checkmax(mx, s[i] - s[p1]);
		checkmax(mx, s[p2] - s[i]), checkmax(mx, s[n] - s[p2]);	
		checkmin(mn, s[p1]), checkmin(mn, s[i] - s[p1]);
		checkmin(mn, s[p2] - s[i]), checkmin(mn, s[n] - s[p2]);
		checkmin(ans, abs(mx - mn));
	}
	for(int i = 2; i <= n - 2; i++){
		int p1 = solve2(1, i), p2 = solve(i + 1, n);
		int mx = 0, mn = (ll) (1e18);
		checkmax(mx, s[p1]), checkmax(mx, s[i] - s[p1]);
		checkmax(mx, s[p2] - s[i]), checkmax(mx, s[n] - s[p2]);	
		checkmin(mn, s[p1]), checkmin(mn, s[i] - s[p1]);
		checkmin(mn, s[p2] - s[i]), checkmin(mn, s[n] - s[p2]);
		checkmin(ans, abs(mx - mn));
	}
	for(int i = 2; i <= n - 2; i++){
		int p1 = solve(1, i), p2 = solve2(i + 1, n);
		int mx = 0, mn = (ll) (1e18);
		checkmax(mx, s[p1]), checkmax(mx, s[i] - s[p1]);
		checkmax(mx, s[p2] - s[i]), checkmax(mx, s[n] - s[p2]);	
		checkmin(mn, s[p1]), checkmin(mn, s[i] - s[p1]);
		checkmin(mn, s[p2] - s[i]), checkmin(mn, s[n] - s[p2]);
		checkmin(ans, abs(mx - mn));
	}
	for(int i = 2; i <= n - 2; i++){
		int p1 = solve2(1, i), p2 = solve2(i + 1, n);
		int mx = 0, mn = (ll) (1e18);
		checkmax(mx, s[p1]), checkmax(mx, s[i] - s[p1]);
		checkmax(mx, s[p2] - s[i]), checkmax(mx, s[n] - s[p2]);	
		checkmin(mn, s[p1]), checkmin(mn, s[i] - s[p1]);
		checkmin(mn, s[p2] - s[i]), checkmin(mn, s[n] - s[p2]);
		checkmin(ans, abs(mx - mn));
	}
	cout << ans << endl;
	return 0;
}
