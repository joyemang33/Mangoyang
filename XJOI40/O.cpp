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
#define N (1000005)
const int win = 1;
const int lose = 2;
const int lover = 3;
const int fucker = 4;
char s[N];
int ch[N][26], f[N], n, k, size;
inline void insert(char *s){
	int p = 1, len = strlen(s);
	for(int i = 0; i < len; i++){
		int c = s[i] - 'a';
		if(!ch[p][c]) ch[p][c] = ++size;
		p = ch[p][c];
	}
}
inline void solve(int u){
	f[u] = lose; int cwin = 0, close = 0, all = 0;
	for(int c = 0; c < 26; c++) if(ch[u][c]){
		int v = ch[u][c]; solve(v), all++;
		//cout << f[v] << endl;
		if(f[v] == lose) cwin = 1;
		if(f[v] == win) close = 1;
		if(f[v] == fucker) return (void) (f[u] = lover); 
	}
	if(cwin && close) return (void) (f[u] = lover);
	if(!cwin && !close && all) return (void) (f[u] = fucker);
	if(cwin) f[u] = win; if(close) f[u] = lose; 
}
int main(){
	size = 1;
	read(n), read(k);
	for(int i = 1; i <= n; i++) scanf("%s", s), insert(s);
	solve(1); //cout << f[1] << endl;
	if(f[1] == lover) return puts("First"), 0;
	if(f[1] == fucker || f[1] == lose) return puts("Second"), 0;
	if(k & 1) puts("First"); else puts("Second");
	return 0;
}
