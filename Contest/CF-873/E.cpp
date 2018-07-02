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
#define N (10005)
int f[N][20], g[N], Log[N], ans[N], mx, my, mz, s1, s2, s3, n;
struct Node{ int x, id; } a[N];
inline bool cmp(Node A, Node B){ return A.x > B.x; }
inline int chkmax(int x, int y){ return g[x] > g[y] ? x : y; }
inline int Getmax(int l, int r){
	int g = Log[r-l+1]; 
	return chkmax(f[l][g], f[r-(1<<g)+1][g]);
}
inline int checkans(int x, int y, int z){
	if(x < mx) return 0;
	if(x > mx) return mx = x, my = y, mz = z, 1;
	if(y < my) return 0;
	if(y > my) return mx = x, my = y, mz = z, 1;
	if(z > mz) return mx = x, my = y, mz = z, 1;
	return 0;
}	
int main(){
	read(n);
	for(int i = 2; i < N; i++) Log[i] = Log[i>>1] + 1;
	for(int i = 1; i <= n; i++) read(a[i].x), a[i].id = i;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++) g[i] = a[i].x - a[i+1].x;
	for(int i = 1; i <= n; i++) f[i][0] = i;
	for(int j = 1; j <= 18; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++) 
			f[i][j] = chkmax(f[i][j-1], f[i+(1<<j-1)][j-1]);
	for(int p1 = 1; p1 <= n - 2; p1++)
		for(int p2 = p1 + 1; p2 <= n - 1; p2++){
			int c1 = p1, c2 = p2 - p1;
			if(2 * c1 < c2 || 2 * c2 < c1) continue;
			int l1 = (c1 & 1) ? c1 / 2 + 1 : c1 / 2;
			int l2 = (c2 & 1) ? c2 / 2 + 1 : c2 / 2;
			int l = p2 + Max(l1, l2), r = Min(n, p2 + Min(c1 * 2, c2 * 2));
			if(l > r || l > n || r <= p2) continue;
			int p3 = Getmax(l, r);
			if(checkans(g[p1], g[p2], g[p3])) s1 = p1, s2 = p2, s3 = p3;
		}
	for(int i = 1; i <= s1; i++) ans[a[i].id] = 1;
	for(int i = s1 + 1; i <= s2; i++) ans[a[i].id] = 2;
	for(int i = s2 + 1; i <= s3; i++) ans[a[i].id] = 3;
	for(int i = s3 + 1; i <= n; i++) ans[a[i].id] = -1;
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}
