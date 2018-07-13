/*program by mangoyang*/
#include<bits/stdc++.h>
#define INF (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (500005)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
	int f = 0, ch = 0; x = 0;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
	for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
	if(f) x = -x;
}
int a[N], n, m;
struct Link_Cut_Tree{
	int ch[N][2], fa[N], rev[N], mx[N], sz[N], st[N];
	inline int get(int x){ return ch[fa[x]][1] == x; }
	inline int isroot(int x){ return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
	inline void update(int x){   
		mx[x] = x <= n ? x : 0, sz[x] = 1;
		if(ch[x][0]){
			mx[x] = Max(mx[x], mx[ch[x][0]]);
			sz[x] += sz[ch[x][0]];
		}
		if(ch[x][1]){
			mx[x] = Max(mx[x], mx[ch[x][1]]);
			sz[x] += sz[ch[x][1]];
		}
	} 
	inline void pushdown(int x){
		if(!rev[x]) return;
		if(ch[x][0]) rev[ch[x][0]] ^= 1;
		if(ch[x][1]) rev[ch[x][1]] ^= 1;
		swap(ch[x][0], ch[x][1]), rev[x] = 0;
	}
	inline void rotate(int x){
		int F = fa[x], G = fa[F], w = get(x);
		if(!isroot(F)) ch[G][get(F)] = x; fa[x] = G;
		ch[F][w] = ch[x][w^1], fa[ch[x][w^1]] = F;
		ch[x][w^1] = F, fa[F] = x, update(F); 
	}
	inline void splay(int x){
		int top = 0; st[++top] = x;
		for(int i = x; !isroot(i); i = fa[i]) st[++top] = fa[i];
		for(int i = top; i >= 1; i--) pushdown(st[i]);
		for(int F = fa[x]; !isroot(x); rotate(x), F = fa[x])
			if(!isroot(F)) rotate(get(x) == get(F) ? F : x);
		update(x);
	}
	inline void access(int x){
		for(int c = 0; x; c = x, x = fa[x]) splay(x), ch[x][1] = c;
	}
	inline void makeroot(int x){ 
		access(x), splay(x), rev[x] ^= 1; 
	}
	inline void link(int x, int y){ 
		//cout << "LINK" << " " << x << " " << y << endl;
		makeroot(x), fa[x] = y; 
	}
	inline void cut(int x, int y){
		//cout << "CUT" << " " << x << " " << y << endl;
		makeroot(x), access(y), splay(y);
		if(ch[y][0] == x) fa[x] = ch[y][0] = 0;
	}
	inline pair<int, int> query(int x, int y){
		makeroot(x), access(y), splay(y); return make_pair(mx[y], sz[y]);
	}
}van;
int main(){
	read(n), read(m);
	for(int i = 1, x; i <= n; i++)
		read(a[i]), van.link(i, i + a[i] <= n ? i + a[i] : n + 1);
	for(int i = 1; i <= m; i++){
		int op, x, y;
		read(op), read(x);
		if(op == 0){
			read(y), van.cut(x, x + a[x] <= n ? x + a[x] : n + 1);
			a[x] = y, van.link(x, x + a[x] <= n ? x + a[x] : n + 1);
		}
		else{
			pair<int, int> now = van.query(x, n + 1);
			printf("%d %d\n", now.first, now.second - 1);
		} 
	}
	return 0;
}

