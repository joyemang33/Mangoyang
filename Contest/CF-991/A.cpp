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
int main(){
	ll a, b, c, n;
	read(a), read(b), read(c), read(n);
	if(a >= n || b >= n) return puts("-1"), 0;
	if(c > a || c > b) return puts("-1"), 0;
	if(a + b - c >= n) return puts("-1"), 0;
	if(a + b <= c) return puts("-1"), 0;
	printf("%lld", n - a - b + c);
	return 0;
}
