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
map<int, int> mp;
int n, m, a[300005];
int main(){
	read(n), read(m);
	for(int i = 1; i <= m; i++){
		int num, flag = 0; read(num);
		for(int i = 1; i <= num; i++) read(a[i]), mp[a[i]] = 1;
		for(int i = 1; i <= num; i++) if(mp[-a[i]]) flag = 1;
		if(!flag) return puts("YES"), 0;
		for(int i = 1; i <= num; i++) mp[a[i]] = 0;
	}
	puts("No");
	return 0;
}
