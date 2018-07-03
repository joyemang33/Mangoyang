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
char s[36];
int f[36][36][36], n, m, l, q; 
inline int solve(int x, int y, int z){
	memset(f, 0, sizeof(f)); 
	int ans = 0; f[x][y][z] = 1;
	for(int i = x; i <= n; i++)
		for(int j = y; j <= m; j++)
			for(int k = 1; k <= l; k++){
				if(i == n && j == m) ans += f[i][j][k];
				if(k < l) f[i+1][j][k+1] += f[i][j][k];
				f[i+1][j+1][1] += f[i][j][k];
			}
	return ans; 
}
int main(){
	read(n), read(m), read(l), read(q);
	cout << solve(1, 1, 1) << endl;
	while(q--){
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		int d = 0, e = 0, ans = 0;
		for(int i = 1; i <= len; i++){
			if(s[i] == '1' && i > 1){
				if(s[i-1] == '0') ans += solve(i, d, e + 1);
				if(s[i-1] == '1') ans += solve(i, d + 1, 1);
			}
			if(s[i] != s[i-1]) d++, e = 1; else e++;
		}
		cout << ans << endl;
	}
	return 0;
}
