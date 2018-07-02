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
int s[100], b[100], js[100], ans, n; 
inline ll check(){
	//for(int i = 0; i <= 9; i++) cout << b[i] << " ";
	//cout << endl;
	ll num = 0;
	for(int i = 0; i <= 9; i++) num += b[i];
	ll now = js[num];
	for(int i = 0; i <= 9; i++) if(b[i]) now /= js[b[i]];
	if(!b[0]) return now;
	b[0]--; ll tmp = js[num-1];
	for(int i = 0; i <= 9; i++) if(b[i]) tmp /= js[b[i]];
	//cout << now << " " << tmp << endl; 
	b[0]++;
	return now - tmp;
}
inline void dfs(int x){
	if(x == 10) return (void) (ans += check());
	if(!s[x]) return (void) (dfs(x + 1));
	for(int i = 1; i <= s[x]; i++)
		b[x] = i, dfs(x + 1), b[x] = 0;
	
}
main(){
	read(n);
	while(n > 0) s[n%10]++, n /= 10;
	//for(int i = 0; i <= 9; i++) cout << s[i] << " ";
	//cout << endl;
	js[0] = 1;
	for(int i = 1; i < 20; i++) js[i] = js[i-1] * i;
	dfs(0);
	cout << ans << endl; 
	return 0;
}
