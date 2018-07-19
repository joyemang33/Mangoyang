/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
#define int ll
#define N (3005)
#define x1 xx1
#define y1 yy1
#define x2 xx2
#define y2 yy2
const ull p1 = 233;
const ull p2 = 97;
char s[N][N], t[N][N];
ull ss[N][N], tt[N][N], pw1[N], pw2[N];
int lx, ly, n, m, ans;
inline ull solve(int x1, int y1, int x2, int y2){
	return ss[x2][y2] - ss[x2][y1] * pw1[y2-y1] - ss[x1][y2] * pw2[x2-x1] + ss[x1][y1] * pw1[y2-y1] * pw2[x2-x1];
}
main(){
	read(lx), read(ly), read(n), read(m);
	for(int i = 1; i <= lx; i++) scanf("%s", t[i] + 1);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	pw1[0] = pw2[0] = 1;
	for(int i = 1; i < N; i++){
		pw1[i] = pw1[i-1] * p1;
		pw2[i] = pw2[i-1] * p2;
	} 
	for(int i = 1; i <= lx; i++)
		for(int j = 1; j <= ly; j++)
			tt[i][j] = tt[i][j-1] * p1 + tt[i-1][j] * p2 - tt[i-1][j-1] * p1 * p2 + t[i][j];
	ull all = tt[lx][ly];
	//cout << all << endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			ss[i][j] = ss[i][j-1] * p1 + ss[i-1][j] * p2 - ss[i-1][j-1] * p1 * p2 + s[i][j];
			if(i >= lx && j >= ly){
				ull now = solve(i - lx, j - ly, i, j);
				//cout << i << " " << j << " " << now << endl;
				if(now == all) ans++;
			}
		} 
		cout << ans << endl;
	return 0;
}
