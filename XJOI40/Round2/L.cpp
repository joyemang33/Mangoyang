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
#define N (45)
#define x1 xx1
#define y1 yy1
#define x2 xx2
#define y2 yy2
char s[N][N];
int f[N][N][N][N], g[N][N], xx[N], ff[N], n, m, q, top;
int main(){
	read(n), read(m), read(q);
	for(int i = 1; i <= n; i++)	scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			int tot = 0;
			for(int k = i; k >= 1; k--, tot++)
				if(s[k][j] == '1') break;
			g[i][j] = tot;
		}
	for(int x1 = 1; x1 <= n; x1++)	
		for(int x2 = x1; x2 <= n; x2++)
			for(int y1 = 1; y1 <= m; y1++){
				int res = 0; top = 0, xx[0] = y1 - 1;
				for(int y2 = y1; y2 <= m; y2++){
					int len = Min(x2 - x1 + 1, g[x2][y2]);
					while(top && len <= ff[top]) top--;
					xx[++top] = y2, ff[top] = len;
					for(int i = top; i >= 1; i--) res += (xx[i] - xx[i-1]) * ff[i];
					f[x1][y1][x2][y2] = res;
				}
			}
	for(int x1 = 1; x1 <= n; x1++)
		for(int x2 = x1; x2 <= n; x2++)
			for(int y1 = 1; y1 <= m; y1++)
				for(int y2 = y1; y2 <= m; y2++) 
					if(x2 > x1) f[x1][y1][x2][y2] += f[x1][y1][x2-1][y2];
	for(int i = 1, x1, x2, y1, y2; i <= q; i++){
		read(x1), read(y1), read(x2), read(y2);
		printf("%d\n", f[x1][y1][x2][y2]);
	}	  
	return 0;
}
