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
#define N (1005)
char s[N][N];
queue<int> q;
int a[N*100], nxt[N*100], head[N*100], d[N*100], Ans[N*100], buf[N], tot, cnt, n;
inline void add(int x, int y){
	a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt, d[y]++;
}
int main(){
	read(n);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n - 1; i++)
		for(int j = i + 1; j <= n; j++){
			int l1 = strlen(s[i] + 1), l2 = strlen(s[j] + 1), flag = 0;
			for(int k = 1; k <= Min(l1, l2); k++)
				if(s[i][k] != s[j][k]){ add(s[i][k], s[j][k]), flag = 1; break; }
			if(!flag && l1 > l2) return puts("Impossible"), 0;
		}
	for(int i = 'a'; i <= 'z'; i++) if(!d[i]) q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int p = head[u]; p; p = nxt[p])
			if(!--d[a[p]]) q.push(a[p]);
		Ans[++tot] = u;
	}
	for(int i = 'a'; i <= 'z'; i++) if(d[i]) return puts("Impossible"), 0;
	for(int i = 1; i <= tot; i++) buf[Ans[i]] = 1;
	for(int i = 1; i <= tot; i++) putchar(Ans[i]);
	for(int i = 'a'; i <= 'z'; i++) if(!buf[i]) putchar(i);		
	return 0;
}
