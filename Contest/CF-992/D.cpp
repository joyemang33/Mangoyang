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
#define N (500005)
#define int ll
int s[N], a[N], v[N], num, n, k, ans;
main(){
	read(n), read(k);
	if(k == 1) ans += n;
	for(int i = 1; i <= n; i++) read(a[i]), s[i] = s[i-1] + a[i];
	for(int i = 1; i <= n; i++) if(a[i] > 1) v[++num] = i; 
	v[num+1] = n + 1;
	for(int i = 1; i <= num; i++){
		int x = v[i], now = a[x];
		for(int j = i + 1; j <= num; j++){
			int y = v[j]; now *= a[y];
			if(now > (ll)(1e12)) break;
			if(now % k != 0) continue;
			int l = v[i] - v[i-1] - 1, r = v[j+1] - v[j] - 1;
			int det = now / k - s[y] + s[x-1];
			if(det >= 0 && det <= l + r){
				int sl = Min(l, det), dl = Max(0, det - r);
				ans += (sl - dl + 1);
			}
		}		
	}
	cout << ans << endl;
	return 0;
}

