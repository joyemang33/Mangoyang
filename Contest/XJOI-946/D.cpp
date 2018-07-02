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
int d[N], n, m;
vector<int> g[N];
priority_queue<int> q;
int main(){
	read(n), read(m);
	for(int i = 1, x, y; i <= m; i++){
		read(x), read(y);
		g[x].push_back(y), d[y]++;
	}
	for(int i = 1; i <= n; i++) if(!d[i]) q.push(-i);
	while(!q.empty()){
		int u = -q.top(); q.pop();
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			if(!--d[v]) q.push(-v);
		}
		printf("%d ", u);	
	}
	return 0;
}
