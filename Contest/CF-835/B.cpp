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
#define N (300005)
char s[N];
int a[N], n, k, ans, sum;
int main(){
	read(k), scanf("%s", s), n = strlen(s);
	for(int i = 0; i < n; i++) a[i+1] = s[i] - 48;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum += a[i];
	for(int i = 1; i <= n; i++){
		if(sum >= k) return printf("%d", ans), 0;
		sum += 9 - a[i], ans++;
	}
	if(sum >= k) return printf("%d", ans), 0;
	return 0;
}
