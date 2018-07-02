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
#define N (200005)
char a[N];
map<int, int> mp;
int s[2][N], n, ans;
int main(){
	read(n);
	scanf("%s", a + 1);
	for(int i = 1; i <= n; i++){
		s[a[i]-'0'][i]++, 
		s[0][i] += s[0][i-1];
		s[1][i] += s[1][i-1];
	}
	mp[0] = 0;
	for(int i = 1; i <= n; i++){
		int k = s[0][i] - s[1][i];
		if(!k) ans = Max(ans, i);
		else if(mp[k]) ans = Max(ans, i - mp[k]);
		if(!mp[k]) mp[k] = i;
	}
	cout << ans << endl;
	return 0;
}
