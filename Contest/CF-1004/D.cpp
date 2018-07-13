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
int buf[N], a[N], ff[N], mx, t;
int main(){
	read(t); int mx = 0, x = 1;
	for(int i = 1; i <= t; i++) 
		read(a[i]), buf[a[i]]++, mx = Max(mx, a[i]);
	for(int i = 1; i <= t; i++)
		if(i * 4 > buf[i]){ x = i; break; }
	//cout << x << " " << mx << endl;
	for(int n = 1; n <= t; n++) if(t % n == 0){
		int m = t / n, flag = 0; 
		int y = n + m - mx - x;
		memset(ff, 0, sizeof(ff));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				ff[abs(i-x)+abs(j-y)]++;
		for(int i = 0; i <= mx; i++)
			if(ff[i] != buf[i]){ flag = 1; break; }
		if(!flag) return printf("%d %d\n%d %d", n, m, x, y);  
	}
	puts("-1");
	return 0;
}
