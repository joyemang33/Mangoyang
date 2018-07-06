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
int fa[N], l[N], r[N], st[N], sum[N], Ans[N], n, m, top;
struct Query{ int x, id; }; vector<Query> q[N];
inline int ask(int x){ return x == fa[x] ? x : fa[x] = ask(fa[x]); } 
main(){
	read(n);
	for(int i = 1, x, y; i <= n; i++)
		read(x), read(y), l[i] = x, r[i] = x + y;
	for(int i = 1; i <= n; i++) fa[i] = i;
	read(m);
	for(int i = 1, L, R; i <= m; i++)
		read(L), read(R), q[L].push_back((Query){R, i});
	for(int i = n; i >= 1; i--){
		int x = i;
		while(top && l[st[top]] <= r[x]){
			r[x] = Max(r[x], r[st[top]]);
			fa[ask(st[top])] = x, top--;
		}
		if(top) sum[x] = sum[st[top]] + l[st[top]] - r[x];
		st[++top] = x;
		for(int j = 0; j < q[i].size(); j++){
			int id = q[i][j].id, y = q[i][j].x;
			Ans[id] = sum[ask(x)] - sum[ask(y)];
		}
	}
	for(int i = 1; i <= m; i++) printf("%lld\n", Ans[i]);
	return 0;
}
