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
int a[1000005], n, m;
int main(){
	read(n), read(m);
	for(int i = 1; i <= n + m; i++) read(a[i]);
	sort(a + 1, a + n + m + 1);
	for(int i = 1; i <= n + m; i++) printf("%d ", a[i]);
	return 0;
}
