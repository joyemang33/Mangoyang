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
const int N = 1005;
int f[N][N], s[N], tot, n;
struct Point{ int l, r, x; } a[N];
namespace Ls{
	int len; 
	inline int calc(int x){
		return lower_bound(s + 1, s + len + 1, x) - s;
	}
	inline void realmain(){
		sort(s + 1, s + tot + 1);
		len = unique(s + 1, s + tot + 1) - s - 1;
	}
}
inline void solve(){
	tot = 0, read(n);
	for(int i = 1, l, r, x; i <= n; i++){
		read(l), read(r), read(x);
		s[++tot] = l, s[++tot] = r;
		a[i] = (Point){l, r, x};
	}
	Ls::realmain();
	for(int i = 1; i <= n; i++){
		a[i].l = Ls::calc(a[i].l);
		a[i].r = Ls::calc(a[i].r);
	}
	//cout << "READ OK" << endl;
	int Lim = 0;
	memset(f, 127, sizeof(f));
	for(int i = 1; i <= n; i++) Lim = Max(Lim, a[i].r + 1);
	for(int i = Lim; i >= 0; i--)
		for(int j = i; j <= Lim; j++){
			int pos = 0;
			//cout << i << " " << j << endl;
			for(int k = 1; k <= n; k++)
				if(a[k].l > i && a[k].r < j && a[k].x > a[pos].x) pos = k;
			if(!pos){ f[i][j] = 0; continue; }
			for(int k = a[pos].l; k <= a[pos].r; k++)
				f[i][j] = Min(f[i][k] + f[k][j] + a[pos].x, f[i][j]);
		}
	printf("%d\n", f[0][Lim]);
}	
int main(){
	int T; read(T);
	while(T--) solve();
	return 0;
}
