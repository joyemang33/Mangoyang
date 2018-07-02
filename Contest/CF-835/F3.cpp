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
#define N (600005)
int a[N], b[N], head[N], nxt[N], cnt;
int st[N], ct[N], vis[N], success;
int g[N], dep[N], c[N], s[N], tot, top, rt, n;
struct Node{ 
	int val, id;
	bool operator < (const Node &A) const{ return val < A.val; }
};
multiset<Node> s1, s2;
inline void add(int x, int y, int z){
	a[++cnt] = y, b[cnt] = z; nxt[cnt] = head[x], head[x] = cnt;
}
inline int Getcircle(int u, int fa){
	cout << u << endl;
	if(vis[u]) return (rt = u), 1;
	int now = 0; vis[u] = 1; 
	for(int p = head[u]; p; p = nxt[p]){
		int v = a[p];
		if(v != fa && (now = Getcircle(v, u))){
			if(now == 1){
				st[++tot] = v, s[tot] = b[p];
				if(u != rt) return 1;
			}
			return 2;
		}
	}
	return 0;
}
inline int dfs(int u, int fa){
	int mx = u;
	for(int p = head[u]; p; p = nxt[p]){
		int v = a[p];
		if(v != fa && !vis[v]){
			dep[v] = dep[u] + b[p];
			int now = dfs(v, u);
			if(dep[now] > dep[mx]) mx = now;
		} 
	}
	return mx;	
}
inline int dfs2(int u, int fa, int dis, int t){
	int res = dis;
	for(int p = head[u]; p; p = nxt[p]){
		int v = a[p];
		if(v != fa){
			if(vis[v] && t) continue;
			if(!vis[v]){
				int now = dfs2(v, u, dis + b[p], t);
				if(now > res) res = now;
			}
			else{
				int now = dfs2(v, u, dis + b[p], 1);
				if(now > res) res = now;
			}
		}
	}
	return res;
}
inline ll calc1(){
	multiset<Node>::iterator it2 = s2.begin();
	int id = it2 -> id;
	s1.erase(s1.find((Node){s[id] + g[id], id}));
	multiset<Node>::iterator it1 = s1.end(); it1--;
	int ans = it1 -> val - it2 -> val;
	s1.insert((Node){s[id] + g[id], id});
	return ans;
}
inline ll calc2(){
	multiset<Node>::iterator it1 = s1.end(); it1--;
	int id = it1 -> id;
	s2.erase(s2.find((Node){s[id] - g[id], id}));
	multiset<Node>::iterator it2 = s2.begin();
	int ans = it1 -> val - it2 -> val;
	s2.insert((Node){s[id] - g[id], id});
	return ans;
}
inline ll calc(){ return max(calc1(), calc2()); }
main(){
	read(n);
	if(n <= 2) return puts("0"), 0;
	for(int i = 1, x, y, z; i <= n; i++){
		read(x), read(y), read(z);
		add(x, y, z), add(y, x, z);
	}
	ll ans = 0;  Getcircle(1, 0);
	for(int i = 1; i <= tot; i++) c[i] = st[tot-i+1];
	for(int i = 1; i <= n; i++) vis[i] = 0;
	for(int i = 1; i <= tot; i++) vis[c[i]] = 1;
	for(int i = 1; i <= tot; i++) cout << c[i] << " "; cout << endl;
	for(int i = 1; i <= tot; i++) cout << s[i] << " "; cout << endl;
	for(int i = 1; i <= tot; i++){
		int mx = dfs(c[i], 0); 
		g[i] = dep[mx], ans = max(ans, g[i]);
		ans = max(ans, dfs2(mx, 0, 0, mx == c[i] ? 1 : 0));
	}
	for(int i = 1; i <= tot; i++) cout << g[i] << " "; cout << endl;
	for(int i = 1; i <= tot; i++) g[i+tot] = g[i];
	for(int i = 1; i <= tot; i++) s[i+tot] = s[i];
	tot *= 2;	 	
	for(int i = 1; i <= tot; i++) s[i] += s[i-1];
	for(int i = 1; i <= tot; i++) cout << s[i] << " "; cout << endl;
	for(int i = 1; i <= tot; i++) cout << g[i] << " "; cout << endl;
	for(int i = 1; i <= tot / 2; i++){
		s1.insert((Node){s[i] + g[i], i});
		s2.insert((Node){s[i] - g[i], i});
	}
	ll tmp = calc();	
	for(int i = 2; i <= tot / 2; i++){
		int l = i, r = i + tot / 2 - 1;
		s1.insert((Node){s[r] + g[r], r});
		s2.insert((Node){s[r] - g[r], r});
		s1.erase(s1.find((Node){s[l-1] + g[l-1], l - 1}));
		s2.erase(s2.find((Node){s[l-1] - g[l-1], l - 1}));
		cout << l << " " << r << " " << calc() << endl;
		tmp = min(tmp, calc());
	}
	cout << Max(ans, tmp);
	return 0;
}                                     
