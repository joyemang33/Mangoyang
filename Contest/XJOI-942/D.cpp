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
#define N (100005)
int pre[N], nxt[N], n, k;
int main(){
	read(n), read(k);
	if(n == 1) return puts("1"), 0;
	for(int i = 1; i <= n; i++) 
		nxt[i] = i + 1, pre[i] = i - 1;
	int tot = n, now = 1;
	pre[1] = n, nxt[n] = 1;
	while(tot > 1){
		for(int i = 1; i <= k - 1; i++) now = nxt[now];
		tot--, nxt[pre[now]] = nxt[now], pre[nxt[now]] = pre[now], now = nxt[now];
	}
	cout << now;
	return 0;
}
