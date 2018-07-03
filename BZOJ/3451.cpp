/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (300005)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
#define double long double
const double pi = acos(-1);
struct Node{
	double a, b;
	Node operator + (const Node &A){ return (Node){A.a + a, A.b + b}; }
	Node operator - (const Node &A){ return (Node){a - A.a, b - A.b}; }
	Node operator * (const Node &A){ return (Node){A.a * a - A.b * b, A.a * b + A.b * a}; }
}A[N];
double Ans[N];
int a[N], nxt[N], head[N], cnt, n;
inline void add(int x, int y){
	a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt; 
}
namespace FFT{
	int rev[N], len, lg;
	inline void DFT(Node *A, int type){
		for(int i = 0; i < len; i++) 
			if(i < rev[i]) swap(A[i], A[rev[i]]);
		for(int k = 2; k <= len; k <<= 1){
			Node w = (Node){cos(2 * pi / k), sin(2 * pi / k) * type};
			for(int i = 0; i < len; i += k){
				Node now = {1.0, 0.0};
				for(int j = i; j < i + (k >> 1); j++){
					Node x = A[j], y = A[j+(k>>1)] * now;
					A[j] = x + y, A[j+(k>>1)] = x - y, now = now * w;
				}
			}
		}
		if(type == -1) for(int i = 0; i < len; i++) A[i].a /= len;
	}
	inline void COV(Node *A, int slen){
		for(len = 1, lg = 0; len < 2 * slen + 1; len <<= 1) lg++;
		for(int i = 0; i < len; i++) 
			rev[i] = (rev[i>>1] >> 1) | (i & 1) << (lg - 1);
		DFT(A, 1);
		for(int i = 0; i < len; i++) A[i] = A[i] * A[i]; DFT(A, -1);
	}
}
namespace DivTree{
	int sz[N], vis[N], rsize, all, rt;
	inline void find(int u, int fa){
		int now = 0; sz[u] = 1;
		for(int p = head[u]; p; p = nxt[p]){
			int v = a[p];
			if(!vis[v] && v != fa){
				find(v, u), sz[u] += sz[v];
				if(sz[v] > now) now = sz[v];
			}
		}
		now = Max(now, all - sz[u]);
		if(now < rsize) rsize = now, rt = u;
	}
	inline int getdis(Node *A, int u, int fa, int dis){
		int mx = dis; A[dis].a += 1.0;
		for(int p = head[u]; p; p = nxt[p]){
			int v = a[p];
			if(!vis[v] && v != fa) 
				mx = max(mx, getdis(A, v, u, dis + 1));
		}
		return mx;
	}
	inline int calc(Node *A, int u, int d){
		int len = getdis(A, u, 0, d) + 1;
		FFT::COV(A, len + 2); return 2 * (len + 2) + 2;
	}
	inline void Doit(int u){
		vis[u] = 1; int len = calc(A, u, 0);
		for(int i = 0; i < len; i++) Ans[i] = Ans[i] + A[i].a;
		for(int i = 0; i < len; i++) A[i].a = A[i].b = 0;
		for(int p = head[u]; p; p = nxt[p]){
			int v = a[p];
			if(!vis[v]){
				int len = calc(A, v, 1);
				for(int i = 0; i < len; i++) Ans[i] = Ans[i] - A[i].a;
				for(int i = 0; i < len; i++) A[i].a = A[i].b = 0;
			}
		}
		int last = all;
		for(int p = head[u]; p; p = nxt[p]){
			int v = a[p];
			if(!vis[v]){
				all = sz[v] > sz[u] ? last - sz[u] : sz[v];
				rsize = inf, find(u, 0), Doit(rt);
			}
		}
 	}
 	inline void realmain(){ 
 		all = n, rsize = inf,  find(1, 0),  Doit(rt); 
 	}
}
int main(){
	read(n);
	for(int i = 1, x, y; i < n; i++)
		read(x), read(y), x++, y++, add(x, y), add(y, x);
	DivTree::realmain();
	double ans = 0;
	for(int i = 0; i <= n; i++) if(Ans[i]) ans += (1.0 / (i + 1)) * Ans[i];
	printf("%.4Lf", ans);
	return 0;
}
