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
char s[1000005];
int buf[100], n, ans;
main(){
	scanf("%s", s); n = strlen(s);
	for(int i = 0; i < n; i++){
		int c = s[i] - 'a';
		ans += i - buf[c]; buf[c]++;
	} 
	cout << ans + 1;
	return 0;
}
