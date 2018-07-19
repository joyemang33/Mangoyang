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
#define N (500005)
#define int ll
int a[N], b[N], n, ans;
namespace Ls{
	int s[N]; int lens = 0;
	inline int calc(int x){
		int res = upper_bound(s + 1, s + lens + 1, x) - s - 1;
		return res;
	}
	inline void Realmain(){
		for(int i = 1; i <= n; i++) s[i] = a[i];
		sort(s + 1, s + n + 1);
		lens = unique(s + 1, s + n + 1) - s - 1;
	}
}
struct Fenwick{
	int s[N];
	inline int lowbit(int x){ return x & -x; }
	inline void add(int x, int v){
		for(int i = x; i <= n; i += lowbit(i)) s[i] += v;
	}
	inline int query(int x){
		int ans = 0;
		for(int i = x; i; i -= lowbit(i)) ans += s[i];
		return ans;
	}
}Bit;
namespace Treap{
	int sz[N], ch[N][2], s[N], l[N], r[N], st[N], top;
	inline void Getsize(int u){
		sz[u] = 1; 
		int ls = ch[u][0], rs = ch[u][1];
		if(ls) Getsize(ls), sz[u] += sz[ls];
		if(rs) Getsize(rs), sz[u] += sz[rs];
		if(!u) sz[u] = 0;
	}
	inline void Add(int u){
		Bit.add(b[u], 1);
		if(ch[u][0]) Add(ch[u][0]);
		if(ch[u][1]) Add(ch[u][1]);
	}
	inline void Clear(int u){
		Bit.add(b[u], -1);
		if(ch[u][0]) Clear(ch[u][0]);
		if(ch[u][1]) Clear(ch[u][1]);
	}
	inline int Count(int u, int val){
		int pos = Ls::calc(val / a[u]);
		int res = Bit.query(pos);
		if(ch[u][0]) res += Count(ch[u][0], val);
		if(ch[u][1]) res += Count(ch[u][1], val);
		return res;
	}
	inline void solve(int u){
		int p = sz[ch[u][0]] > sz[ch[u][1]] ? 0 : 1;
		int ms = ch[u][p], ls = ch[u][p^1];
		if(ls) solve(ls), Clear(ls);
		if(ms) solve(ms); 
		if(ls) ans += Count(ls, a[u]);
		if(u){ if(ls) Add(ls); Bit.add(b[u], 1); } 
	}
	inline void Build(){
		for(int i = 1; i <= n; i++){
			while(a[st[top]] <= a[i] && top) r[st[top--]] = i - 1;
			int f = st[top]; l[i] = f + 1;
			ch[i][0] = ch[f][1], ch[f][1] = i, st[++top] = i; 
		}
		for(int i = 1; i <= n; i++) if(!r[i]) r[i] = n;
	}
	inline void Realmain(){
		Build(), Getsize(0), solve(0);
		for(int i = 1; i <= n; i++) s[i] = s[i-1] + (a[i] == 1 ? 1 : 0);
		for(int i = 1; i <= n; i++) ans += s[r[i]] - s[l[i]-1];
		cout << ans << endl;
	}
}
main(){
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]);
	Ls::Realmain();
	for(int i = 1; i <= n; i++) b[i] = Ls::calc(a[i]);
	Treap::Realmain();
	return 0;
}
