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
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
}
#define int ll
#define N (2000005)
int s[N], d[N], b[N], prime[N], tot, cx, cy, n;
main(){
	read(n), read(cx), read(cy); int k = cx / cy;
	for(int i = 1, x; i <= n; i++) read(x), s[x]++;
	for(int i = 1; i < N; i++) 
		d[i] = d[i-1] + s[i] * i, s[i] += s[i-1];
	for(int i = 2; i < N; i++){
		if(!b[i]) prime[++tot] = i;
		for(int j = 1; i * prime[j] < N && j <= tot; j++){
			b[i*prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	int ans = (ll) (1e18);
	for(int i = 1; i <= tot; i++){
		int now = 0;
		for(int y = prime[i]; y < N; y += prime[i]){
			int x = y - prime[i];
			if(y - k <= x) now += (y * (s[y] - s[x]) - d[y] + d[x]) * cy;
			else{
				int xx = y - k - 1;
				now += (s[xx] - s[x]) * cx;
				now += (y * (s[y] - s[xx]) - d[y] + d[xx]) * cy;
			}
		}
		ans = Min(ans, now);
	}
	cout << ans; 
	return 0;
}
