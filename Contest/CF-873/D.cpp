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
#define N (200005)
#define lson (u << 1)
#define rson (u << 1 | 1)
int ls[N], rs[N], n, k;
struct Node{
	int l, r, s, g;
	inline void put1(){ 
		//cout << "*" << l << " " << r << endl;
		for(int i = r; i >= l; i--) printf("%d ", i + 1); 
	}
	inline void put2(){ 
		//cout << "$" << l << " " << r << endl;
		for(int i = l; i <= r; i++) printf("%d ", i + 1); 
	}
}a[N<<2];
inline void build(int u, int l, int r){
	a[u].l = l, a[u].r = r; 
	if(l == r) return (void)(a[u].s = 1);
	int mid = l + r >> 1;
	ls[u] = lson, rs[u] = rson;
	build(ls[u], l, mid), build(rson, mid + 1, r);
	a[u].s = a[lson].s + a[rson].s + 1;
}
inline void solve(int u, int l, int r, int k){
	int mid = l + r >> 1;
	if(!k){ puts("-1"); exit(0); }
	if(k == a[u].s){ a[u].g = 1; return;}
	if(k == 1){ a[u].g = 2; return; } k--;
	if(a[ls[u]].s >= k - 1){
		solve(ls[u], l, mid, k - 1);
		a[rs[u]].g = 2; swap(ls[u], rs[u]); return;
	}
	if(a[rs[u]].s >= k - 1){
		solve(rs[u], mid + 1, r, k - 1);
		a[ls[u]].g = 2; swap(ls[u], rs[u]); return;
	}
	solve(ls[u], l, mid, a[ls[u]].s);
	k -= a[ls[u]].s;
	solve(rs[u], mid + 1, r, k); swap(ls[u], rs[u]);
	//swap(ls[u], rs[u]);
}
inline void write(int u){
	if(a[u].g == 1) return (void) (a[u].put1());
	if(a[u].g == 2) return (void) (a[u].put2());
	if(ls[u]) write(ls[u]);
	if(rs[u]) write(rs[u]);
}
int main(){
	read(n), read(k);
	build(1, 0, n - 1);
	if(k > a[1].s) return puts("-1"), 0;
	solve(1, 0, n - 1, k), write(1);
	return 0;
}
