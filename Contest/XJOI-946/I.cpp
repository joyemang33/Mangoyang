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
map<int, string> ss;
int a[N], nxt[N], head[N], st[N], cnt, num, n, m, ed, top;
inline void add(int x, int y){
	a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt;
}
inline int dfs(int u, int fa){
	if(u == ed) return st[++top] = u, 1;
	for(int p = head[u]; p; p = nxt[p]){
		int v = a[p];
		if(v != fa && dfs(v, u))
			return st[++top] = u, 1;
	}
	return 0;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		string s1, s2; cin >> s1 >> s2;
		if(!mp[s1]) mp[s1] = ++num, ss[num] = s1;
		if(!mp[s2]) mp[s2] = ++num, ss[num] = s2;
		int x = mp[s1], y = mp[s2]; add(x, y), add(y, x);
	}
	for(int i = 1, x, y; i <= m; i++){
		string s1, s2; cin >> s1 >> s2; 
		x = mp[s1], y = mp[s2];
		ed = y, top = 0, dfs(x, 0);
		for(int j = top; j >= 1; j--){
			int u = st[j];
			string now = ss[u]; cout << now[0];
		}
		cout << " ";
	}
	return 0;
}
