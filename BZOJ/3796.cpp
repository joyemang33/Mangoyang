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
int ans;
char s1[N], s2[N], s3[N];
struct SuffixAutomaton{
	vector<int> g[N];
	int ch[N][30], f[N][4], dep[N], tag[N], fa[N], sz[N], size, tail;
	inline SuffixAutomaton(){ tail = size = 1; }
	inline int newnode(int x){ dep[++size] = x; return size; }
	inline void ins(int c){
		int p = tail, np = newnode(dep[p] + 1);
		for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
		if(!p) return (void) (fa[np] = 1, tail = np);
		int q = ch[p][c];
		if(dep[q] == dep[p] + 1) fa[np] = q;
		else{
			int nq = newnode(dep[p] + 1);
			fa[nq] = fa[q], fa[q] = fa[np] = nq;
			for(int i = 0; i < 26; i++) ch[nq][i] = ch[q][i];
			for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
		}tail = np;
	}
	inline void instring(char *s, int type){
		int len = strlen(s), p = 1; tail = 1;
		for(int i = 0; i < len; i++){
			int c = s[i] - 'a';
			ins(c), p = ch[p][c], sz[p] = 1, f[p][type] = 1;
		}
	}
	inline void find(char *s){
		int len = strlen(s); int p = 1, now = 0;
		for(int i = 0; i < len; i++){
			int c = s[i] - 'a'; p = ch[p][c];
			if(!p) return;
		} if(p) tag[p] = 1, cout << p << endl;
	}
	inline void addedge(){ 
		for(int i = 2; i <= size; i++) g[fa[i]].push_back(i); 
	}
	inline void solve(int u){
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i]; if(tag[v]) continue;
			solve(v), sz[u] += sz[v];
			f[u][1] |= f[v][1], f[u][2] |= f[v][2];
		}
		if(f[u][1] && f[u][2] && sz[u]) ans = Max(ans, dep[u]);	
	}
}van;
int main(){
	scanf("%s", s1), scanf("%s", s2), scanf("%s", s3);
	van.instring(s1, 1), van.instring(s2, 2);
	van.addedge(), van.find(s3), van.solve(1), cout << Max(ans, strlen(s3) - 1); 
	return 0;
}
