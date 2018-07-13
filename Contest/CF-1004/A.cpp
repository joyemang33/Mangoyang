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
set<int> s;
int a[1000005], n, d;
inline bool check(int x){
	for(int i = 1; i <= n; i++)
		if(abs(a[i] - x) < d) return 0;
	return 1;
}
main(){
	read(n), read(d);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++){
		if(check(a[i] + d)) s.insert(a[i] + d);
		if(check(a[i] - d)) s.insert(a[i] - d);
	}
	cout << s.size();
	return 0;
}
