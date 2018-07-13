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
#define N (300005)
map<string, int> mp;
vector<int> g[N];
struct Query{ int x, id; }; vector<Query> q[N];
int a[N], Ans[N], n, m, col;
namespace Dsu{
	map<int, int> mp[N];
	int sz[N], dep[N], ms[N], tot[N];
	inline void getsize(int u, int fa){
		sz[u] = 1, dep[u] = dep[fa] + 1;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			getsize(v, u), sz[u] += sz[v];
			if(sz[v] > sz[ms[u]]) ms[u] = v;	
		}	
	}
	inline void Clear(int u){
		if(!(--mp[dep[u]][a[u]])) tot[dep[u]]--;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i]; Clear(v);
		}
	}
	inline void Addans(int u){
		if((++mp[dep[u]][a[u]]) == 1) tot[dep[u]]++;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i]; Addans(v);
		}
	}
	inline void solve(int u){	
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			if(v != ms[u]) solve(v), Clear(v);
		}
		if(ms[u]) solve(ms[u]); 
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			if(v != ms[u]) Addans(v);
		}
		if((++mp[dep[u]][a[u]]) == 1) tot[dep[u]]++;
		for(int i = 0; i < q[u].size(); i++){
			Ans[q[u][i].id] = tot[dep[u]+q[u][i].x];
		}
	}
	inline void realmain(){
		getsize(1, 0), solve(1); 
		for(int i = 1; i <= m; i++) printf("%d\n", Ans[i]);
	}
}
int main(){
	read(n);
	for(int i = 1, x; i <= n; i++){
		string s;
		cin >> s; read(x);
		if(!mp[s]) mp[s] = ++col; 
		a[i+1] = mp[s], g[x+1].push_back(i+1);
	}
	read(m);
	for(int i = 1, x, y; i <= m; i++){
		read(x), read(y);
		q[x+1].push_back((Query){y, i});
	}
	Dsu::realmain();
	return 0;
}
