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
char s[2005];
int a[20005];
int main(){
	int n; read(n);
	scanf("%s", s + 1);	
	for(int i = 1; i <= n; i++) a[i] = s[i] - '0';
	a[1]++;
	for(int i = 1; i <= n; i++)
		if(a[i] == 2) a[i] = 0, a[i+1]++;
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(s[i] - '0' != a[i]) ans++;
	cout << ans << endl;
	return 0;
}
