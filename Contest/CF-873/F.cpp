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
#define int ll
char s[N], a[N];
int  n, ans;
struct SuffixAutoMaton{
	int buf[N], a[N];
	int sz[N], dep[N], ch[N][26], fa[N], size, tail;
	SuffixAutoMaton(){ tail = size = 1; }
	inline int newnode(int x){ dep[++size] = x; return size; }
    inline void ins(int c, int v){
        int p = tail, np = newnode(dep[p] + 1); sz[np] += v;
        for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
        if(!p) return (void) (fa[np] = 1, tail = np);
        int q = ch[p][c];
        if(dep[q] == dep[p] + 1) fa[np] = q;
        else{
            int nq = newnode(dep[p] + 1);
            fa[nq] = fa[q], fa[np] = fa[q] = nq;
            for(int i = 0; i < 26; i++) ch[nq][i] = ch[q][i];
            for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;	
        }tail = np;
    }
	inline void calc(){
		for(int i = 1; i <= size; i++) buf[dep[i]]++;
		for(int i = 1; i <= size; i++) buf[i] += buf[i-1];
		for(int i = 1; i <= size; i++) a[buf[dep[i]]--] = i;
		for(int i = size; i > 1; i--){
			int u = a[i]; sz[fa[u]] += sz[u]; 
			ans = Max(ans, 1ll * dep[u] * sz[u]);
			//if(dep[u] * sz[u] >= 147) cout << dep[u] << " " << sz[u] << endl; 
		} 
	}
}van;
main(){
	read(n); scanf("%s", s), scanf("%s", a);
	for(int i = 0; i < n; i++) 
		van.ins(s[i] - 'a', (a[i] - 48) ^ 1);
	van.calc();
	cout << ans << endl;
	return 0;
}
