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
#define N (100005)
double sn[N];
char s[N], sc[N]; int ff[N], n, p, tc, tn;
inline double getnum(){
	double l = 0.0, r = 0.0; int f = 0;
	while(isdigit(s[p+1]) || s[p+1] == '.'){
		if(s[p+1] == '.') f = 1;
		else{
			if(f) r = r * 10 + s[p+1] - 48;
			else l = l * 10 + s[p+1] - 48;
 		} p++;
	}
	while(r >= 1.0) r /= 10.0; return l + r;  
}
inline void pop(){
	char c = sc[tc--];
	double b = sn[tn--], a = sn[tn--], now = 0.0;
	if(c == '^') now = pow(a, b);
	if(c == '+') now = a + b;
	if(c == '-') now = a - b;
	if(c == '*') now = a * b;
	if(c == '/') now = a / b; sn[++tn] = now;
}
inline void solve(char c){
	if(c == '(') return (void) (sc[++tc] = c);
	if(c == ')'){
		while(sc[tc] != '(' && tc) pop();
		return (void) (tc--);
	}
	while(tc && ff[c] <= ff[sc[tc]]) pop(); sc[++tc] = c;
}
int main(){
	ff['('] = 0, ff['+'] = 1, ff['-'] = 1;
	ff['*'] = 2, ff['/'] = 2, ff['^'] = 3, ff['@'] = 0;
	scanf("%s", s + 1), n = strlen(s + 1), s[++n] = '@';
	while(p < n){
		if(!isdigit(s[p+1])) solve(s[++p]);
		else sn[++tn] = getnum();
	}
	return printf("%.2lf", sn[1]), 0;
}
}
