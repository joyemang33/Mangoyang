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
int a[2000005], n, ans;
int main(){
	read(n); 
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++) 
		if(a[i]) ans += 2 - a[i-1];
	if(ans > 0) ans --; 
	cout << ans << endl;
	return 0;
}

