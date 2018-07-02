/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (1000005)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
queue<int> q;
int a[N], nxt[N], head[N], cnt;
int d[N], f[N], s[N], n, ans;
inline void add(int x, int y){
	a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt;
}
int main(){
	read(n);
	for(int i = 1, x, y; i <= n; i++){
		read(x), read(s[x]), read(y);
		if(y) add(y, x), d[x]++;
		while(y){
			read(y);
			if(y) add(y, x), d[x]++;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) if(!d[i]) f[i] = s[i], q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
		//cout << u << " " << f[u] << endl;
		for(int p = head[u]; p; p = nxt[p]){
			int v = a[p];
			f[v] = Max(f[u] + s[v], f[v]);
			if(!--d[v]) ans = Max(ans, f[v]), q.push(v);
		}
	}
	cout << ans << endl;
	return 0;
}
