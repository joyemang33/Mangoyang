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
int col[10][10], c[40], n, m, k, flag;
inline void write(){
	puts("YES");
	for(int i = 1; i <= n; i++, putchar('\n')){
		for(int j = 1; j < m; j++) printf("%d ", col[i][j]);
		printf("%d", col[i][m]);
	}
}	
inline void dfs(int x, int y){
	if(x > n || y > m) return (void)( write(), flag = 1);
	int sum = 0;
	for(int i = 1; i <= k; i++) sum += c[i];
	for(int i = 1; i <= k; i++) if(c[i] > (sum + 1) / 2) return;
	int ny = y < m ? y + 1 : 1, nx = (ny == 1) ? x + 1 : x;
	for(int i = 1; i <= k; i++) if(c[i]){
		if(x > 1 && col[x-1][y] == i) continue;
		if(y > 1 && col[x][y-1] == i) continue;
		col[x][y] = i, c[i]--, dfs(nx, ny), c[i]++;
		if(flag) return;
	}
}
int main(){
	int T; read(T);
	for(int Case = 1; Case <= T; Case++){
		read(n), read(m), read(k);
		for(int i = 1; i <= k; i++) read(c[i]);
		printf("Case #%d:\n", Case); 
		flag = 0, dfs(1, 1); if(!flag) puts("NO");
	}
	return 0;	
}
