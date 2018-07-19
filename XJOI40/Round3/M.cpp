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
#define N (1000005)
#define int ll
const int Mod = 1000000009;
char s[N];
int f[N][2][2], a[N], b[N], c[N], mxlen;
#define max MAx
inline int MAx(int a, int b){ return a > b ? a : b; }
inline int getstring(int *a){
	scanf("%s", s + 1); int len = strlen(s + 1);
	for(int i = 1; i <= len; i++)
		if(s[i] == '?') a[i] = -1; else a[i] = s[i] - 'a' + 1; 
	return len;
}
inline void init(){
	for(int i = 0; i <= mxlen; i++){
		a[i] = b[i] = c[i] = 0;
		f[i][0][0] = f[i][1][1] = 0;
		f[i][1][0] = f[i][0][1] = 0;
	}
	f[0][0][0] = 1, mxlen = 0;
	mxlen = max(mxlen, getstring(a));
	mxlen = max(mxlen, getstring(b));
	mxlen = max(mxlen, getstring(c));
}
inline int calc0(int a, int b){
	if(~a && ~b) return a == b;
	if(a == -1 && b == -1) return 26; else return (a * b != 0); 
}
inline int calc1(int a, int b){
	if(~a && ~b) return a < b;
	if(a == -1 && b == -1) return 325;
	if(a == -1) return max(b - 1, 0);
	if(b == -1) return 26 - a; 
}
inline int calc00(int a, int b, int c){
	if(!a || !b || !c) return 0;
	if(~a && ~b && ~c) return a == b && b == c;
	if(a == -1 && b == -1 && c == -1) return 26;
	if(a == -1 && b == -1) return 1;
	if(b == -1 && c == -1) return 1;
	if(a == -1 && c == -1) return 1;
	if(a == -1) return b == c;
	if(b == -1) return a == c;
	if(c == -1) return a == b;
}
inline int calc11(int a, int b, int c){
	if(~a && ~b && ~c) return a < b && b < c;
	if(a == -1 && b == -1 && c == -1) return 2600;
	if(a == -1 && b == -1) return max((c - 1) * (c - 2) / 2, 0);
	if(a == -1 && c == -1) return max((b - 1) * (26 - b), 0);
	if(b == -1 && c == -1) return max((26 - a) * (26 - a -1) / 2, 0);
	if(a == -1) return b < c ? max(b - 1, 0) : 0;
	if(b == -1) return a < c ? c - a - 1: 0;
	if(c == -1) return a < b ? 26 - b : 0;
}
inline int calc10(int a, int b, int c){
	if(~a && ~b && ~c) return a < b && b == c;
	if(a == -1 && b == -1 && c == -1) return 325;
	if(a == -1 && b == -1) return max(c - 1, 0);
	if(a == -1 && c == -1) return max(b - 1, 0);
	if(b == -1 && c == -1) return 26 - a;
	if(a == -1) return b == c ? max(b - 1, 0) : 0;
	if(b == -1) return a < c;
	if(c == -1) return a < b;
}	
inline int calc01(int a, int b, int c){
	if(~a && ~b && ~c) return a == b && b < c;
	if(a == -1 && b == -1 && c == -1) return 325;
	if(a == -1 && b == -1) return max(c - 1, 0);
	if(a == -1 && c == -1) return 26 - b;
	if(b == -1 && c == -1) return 26 - a;
	if(a == -1) return b < c;
	if(b == -1) return a < c;
	if(c == -1) return a == b ? 26 - a : 0;
}
inline void update(int &x, int y){ (x += y) %= Mod; }
inline void solve(){
	for(int i = 1; i <= mxlen; i++){
		update(f[i][0][0], f[i-1][0][0] * calc00(a[i], b[i], c[i]));
		update(f[i][1][0], f[i-1][1][0] * calc0(b[i], c[i]) * (~a[i] ? 1 : 26));
		update(f[i][1][0], f[i-1][0][0] * calc10(a[i], b[i], c[i]));
		update(f[i][0][1], f[i-1][0][1] * calc0(a[i], b[i]) * (~c[i] ? 1 : 26));
		update(f[i][0][1], f[i-1][0][0] * calc01(a[i], b[i], c[i]));
		update(f[i][1][1], f[i-1][0][0] * calc11(a[i], b[i], c[i]));
		update(f[i][1][1], f[i-1][1][0] * calc1(b[i], c[i]) * (~a[i] ? 1 : 26));
		update(f[i][1][1], f[i-1][0][1] * calc1(a[i], b[i]) * (~c[i] ? 1 : 26));
		update(f[i][1][1], f[i-1][1][1] * (~a[i] ? 1 : 26) * (~b[i] ? 1 : 26) * (~c[i] ? 1 : 26));
	}
	int ans = f[mxlen][1][1]; printf("%lld\n", ans);
}
main(){
	int T; read(T);
	while(T--) init(), solve();	
	return 0;
}
