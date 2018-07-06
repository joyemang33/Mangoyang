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
#define N (2000005)
#define int ll
int a[N], n, m, k;
struct Point{ int x, id; } s[N];
inline bool cmp(Point A, Point B){ return A.x > B.x; }
inline bool check(int mid){
	int p1 = 1, p2 = mid, tot = 0, d = 0;
	while(p1 <= n || p2){
		if(p1 <= n && (a[p1] < s[p2].x || !p2)){
			if(a[p1] < d) return 0; p1++;
		}
		else{
			if(s[p2].x < d) return 0; p2--;
		}
		if(++tot == k) tot = 0, d++;
	}
	return 1;
}
main(){
	read(n), read(m), read(k);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= m; i++) read(s[i].x), s[i].id = i;
	sort(a + 1, a + n + 1);
	sort(s + 1, s + m + 1, cmp);
	int l = 0, r = m, ans = -1;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)) 
			ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	if(ans != -1)
		for(int i = ans; i >= 1; i--) printf("%d ", s[i].id);
 	return 0;
}
