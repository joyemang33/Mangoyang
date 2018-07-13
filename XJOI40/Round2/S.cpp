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
vector<int> Ans;
vector< vector<int> > AAns;
int s[N], a[N], f[N], prime[N], b[N], vis[N], nxt[N], head[N], cnt, n, S, T, tot, Tot;
inline void add(int x, int y, int z){
	a[++cnt] = y, b[cnt] = z, nxt[cnt] = head[x], head[x] = cnt;
	a[++cnt] = x, b[cnt] = 0, nxt[cnt] = head[y], head[y] = cnt;
}
namespace Flow{
	int dis[N], cur[N], g[N];
	inline int isap(int u, int flow){
		if(u == T) return flow;
		if(!cur[u]) cur[u] = head[u];
		int used = 0, Mindis = Tot - 1;
		for(int p = head[u]; p; p = nxt[p]){
			int v = a[p];
			if(dis[u] == dis[v] + 1 && b[p]){
				int x = isap(v, Min(b[p], flow - used));
				used += x, b[p] -= x, b[p^1] += x;
				if(b[p]) cur[u] = p;
				if(used == flow) return flow;
			}
			if(dis[v] < Mindis && b[p]) Mindis = dis[v]; 
		}
		if(!--g[dis[u]]) dis[S] = Tot;
		else g[dis[u]=Mindis+1]++, cur[u] = head[u];
		return used; 
	}
	inline int solve(){
		int ans = 0; g[0] = Tot;
		while(dis[S] < Tot) ans += isap(S, inf); return ans;
	}
}
inline void find(int u){
	Ans.push_back(u), vis[u] = 1;
	for(int p = head[u]; p; p = nxt[p]){
		int v = a[p];
		if(v == S || v == T) continue;
		if(p % 2 == 0 && b[p]) continue;
		if(p % 2 == 1 && !b[p]) continue;
		if(!vis[a[p]]) find(a[p]); 
	}
} 
int main(){
	cnt = 1, read(n); Tot = n + 2;
	for(int i = 1; i <= n; i++) read(s[i]);
	for(int i = 2; i < N; i++){
		if(!f[i]) prime[++tot] = i;
		for(int j = 1; i * prime[j] < N && j <= tot; j++){
			f[prime[j]*i] = 1;
			if(i % prime[j] == 0) break; 
		}
	}
	S = 0, T = n + 1;
	for(int i = 1; i <= n; i++) if(s[i] & 1)
		for(int j = 1; j <= n; j++)
			if(!f[s[i]+s[j]]) add(i, j, 1);
	for(int i = 1; i <= n; i++) 
		if(s[i] & 1) add(S, i, 2); else add(i, T, 2);
	int ans = Flow::solve();
	if(ans != n) return puts("Impossible"), 0;
	for(int p = head[S]; p; p = nxt[p]) 
		if(!b[p] && !vis[a[p]]){
			Ans.clear(), find(a[p]);
			AAns.push_back(Ans);
		}
	cout << AAns.size() << endl;
	for(int i = 0; i < AAns.size(); i++){
		cout << AAns[i].size() << " ";
		for(int j = 0; j < AAns[i].size(); j++) cout << AAns[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*
锄禾日当午，贺题好辛苦
对着博客园，一贺一上午
贺了一上午，还要贺下午
贺完还要改，不然更痛苦
不贺没前途，只能去跑路
*/
