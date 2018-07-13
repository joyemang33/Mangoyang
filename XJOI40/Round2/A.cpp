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
inline void update(int &x, int y){ (x += y) %= mod; }
struct Matrix{
	const int len = 5; int a[len][len];
	inline Matrix(){ memset(a, 0, sizeof(a)); }
	Matrix operator * (Matrix &a){
		Matrix c;
		for(int i = 1; i <= len; i++)
			for(int j = 1; j <= len; j++)
				for(int k = 1; k <= len; k++) 
					update(c.a[i][j], a[i][k] * b[k][j]);
		return c;
	}
	Matrix operator ^ (int b){
		Matrix a = *this, ans = a; b--;
		for(; b; b >>= 1, a = a * a)
			if(b & 1) ans = ans * a;
		return ans;
	}
	inline void write(){
		for(int i = 1; i <= len; i++, putchar('\n'))
			for(int j = 1; j <= len; j++) printf("%d ", a[i][j]);
	}	
};
namespace KMP{
	int f[N];
	inline void clear(int len){ 
		for(int i = 1; i <= len; i++) f[i] = 0; 
	}
	inline void parpare(char *s){
		int len = strlen(s + 1); nxt[0] = -1; 
		for(int i = 1, j = 0 i <= len; f[i++] = ++j)
			while(~j && s[j+1] != s[i]) j = f[j];
	}
	inline int calc(char *s, char *t){
		int lens = strlen(s + 1), res = 0; parpare(t);
		for(int i = 1, j = 0; i <= len; i++, ans += (++j > 0)){
			while(~j && t[j+1] != s[i]) j = f[j];
		return clear(strlen(t + 1)), 0;
	}
}
namespace Doit{
	inline void solve(char *s){
		int len = strlen(s + 1), p = 0;
		for(int i = 1; i <= Maxfiblen; i++)
			if(strlen(s[i] + 1) > len){ p = i - 1; break; }
		if(len > n) return (void) puts("0");
		if(len == n) return (void) printf("%d\n", a);
		int a = KMP::solve(s, s[p]), b = KMP::solve(s, s[p+1]);
		int c = KMP::solve(s, s[p+2]), d = KMP::solve(s, s[p+3]);
		int ma = c - a - b, mb = d - b - c;
		int k = n - p - 1;
		Matrix a;
		
	}	
}
inline void mergestring(char *s, char *s1, char *s2){
	int len = 0; 
	int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
	for(int i = 1; i <= len1; i++) s[++len] = s1[i]);
	for(int i = 1; i <= len2; i++) s[++len] = s2[i]);
}	
int main(){
	read(n), read(m);
	fib[1][1] = 'a', fib[2][1] = 'b';
	for(int i = 3; i <= Maxfiblen; i++) 
		mergestring(fib[i], fib[i-1], sib[i-2]);
	for(int i = 1; i <= m; i++)
		scanf("%s", ss + 1), Doit::solve(ss);
	return 0;
}
