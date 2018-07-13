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
#define N (300005)
map<int, int> mp;
int a[N], s[N], d[N], n, ans;
main(){
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++)
		if(!mp[a[i]]) mp[a[i]] = 1, s[i] = 1;
	//for(int i = 1; i <= n; i++) cout << s[i] << " "; cout << endl;
	mp.clear();
	for(int i = n; i >= 1; i--)
		if(!mp[a[i]]) mp[a[i]] = 1, d[i] = 1;
	for(int i = n; i >= 1; i--) d[i] += d[i+1];
	//for(int i = 1; i <= n; i++) cout << d[i] << " "; cout << endl;
	for(int i = 1; i <= n; i++) ans += s[i] * d[i+1];
	cout << ans << endl; 
	return 0;
}
