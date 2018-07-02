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
#define int ll
int f[20][205][205], a[20][205][205], n, q, c;
main(){
	read(n), read(q), read(c);
	for(int i = 1, x, y, s; i <= n; i++){
		read(x), read(y), read(s);
		for(int t = 0; t <= c; t++)
			a[t][x][y] += s, s = (s + 1) % (c + 1);
	}
	for(int t = 0; t <= c; t++){
		for(int i = 1; i <= 100; i++)
			for(int j = 1; j <= 100; j++) 
				f[t][i][j] = f[t][i-1][j] + f[t][i][j-1] - f[t][i-1][j-1] + a[t][i][j];
	}
	while(q--){
		int t, xl, yl, xr, yr;
		read(t), read(xl), read(yl), read(xr), read(yr);
		t %= (c + 1);
		int ans = f[t][xr][yr] - f[t][xl-1][yr] - f[t][xr][yl-1] + f[t][xl-1][yl-1];
		printf("%lld\n", ans);
	}
	return 0;
}
