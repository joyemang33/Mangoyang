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
struct PersistableArray{
	inline void build(int &u, int l, int r, int *a){
		u = ++size;
		if(l == r) return (void) (s[u] = a[l]);
		int mid = l + r >> 1;
		build(lc[u], l, mid, a), build(rc[u], mid + 1, r, a);
	}	
	inline void Ins(int &u, int pr, int l, int r, int pos, int v){
		u = ++size;
		if(l == r) return (void) (s[u] = v);
		int mid = l + r >> 1; 
		lc[u] = lc[pr], rc[u] = rc[pr];
		if(pos <= mid) Ins(lc[u], lc[pr], l, mid, pos, v);
		else Ins(rc[u], rc[pr], mid + 1, r, pos, v);
	}
	inline int query(int u, int l, int r, int pos){
		if(l == r) return s[u];
		int mid = l + r >> 1;
		if(pos <= mid) return query(lc[u], l, mid, pos);
		else return query(rc[u], mid + 1, r, pos);
	}
	inline int get(int u, int pos){ return query(rt[u], 1, n, pos); }
	inline void mof(int u, int pos, int v){ Ins(rt[u], 1, n, pos, v); }
}fa;
namespace Dsu{
	inline int ask(int now, int x){
		if(fa.get(now, x) <= 0) return x;
		else 
	}
}	
int main(){
	
	return 0;
}
