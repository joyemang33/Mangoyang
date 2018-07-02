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
#define N (300005)
#define int ll
struct Node{ int l, r, x; } a[N];
struct Point{ int x, y; }; 
vector<Point> v[N];
int n, m, ans, buf[N];
inline bool cmp(Node A, Node B){ return A.l < B.l; }
inline void Clear(int c){
	for(int j = 0; j < v[c].size(); j++)
		buf[v[c][j].x] = Min(buf[v[c][j].x], v[c][j].y);
}
main(){
	read(n), read(m); ans = inf;
	for(int i = 0; i < N; i++) buf[i] = inf;
	for(int i = 1; i <= n; i++) read(a[i].l), read(a[i].r), read(a[i].x);
	sort(a + 1, a + n + 1, cmp);
	int p = 0;
	for(int i = 1; i <= n; i++){
		int l = a[i].l, r = a[i].r, len = r - l + 1;
		while(p < l - 1) Clear(++p);
		if(len >= m) continue;
		ans = Min(ans, a[i].x + buf[m-len]);
		//cout << l << " " << r << " " << len << " " << buf[m-len] << endl;
		v[r].push_back((Point){len, a[i].x});	
	}
	if(ans < inf) cout << ans; else cout << -1; 
	return 0;
}
