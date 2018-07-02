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
char s[10005];
int n, p;
int main(){
	read(n), read(p), scanf("%s", s + 1);
	if(p == 1) return puts("NO"), 0; 
	if(p == 2){
		if(n == 1){
			if(s[1] == 'a') puts("b");
			else puts("NO"); return 0;
		}
		if(s[1] == 'a') puts("ba");
		else puts("NO"); return 0;
	}
	int en = 'a' + p - 1;
	for(int i = s[n] + 1; i <= en; i++){
		if(n > 1 && i == s[n-1]) continue;
		if(n > 2 && i == s[n-2]) continue;
		s[n] = i;
		for(int i = 1; i <= n; i++) putchar(s[i]);
		return 0; 
	}
	for(int i = n - 1; i >= 1; i--)
		for(int s1 = s[i] + 1; s1 <= en; s1++){
			if(i > 1 && s1 == s[i-1]) continue;
			if(i > 2 && s1 == s[i-2]) continue;
			for(int s2 = 'a'; s2 <= en; s2++){
				if(s2 == s1) continue;
				if(i > 1 && s2 == s[i-1]) continue;
				s[i] = s1, s[i+1] = s2;
				for(int j = i + 2; j <= n; j++)
					for(int c = 'a'; c <= en; c++){
						if(c == s[j-1] || c == s[j-2]) continue;
						s[j] = c; break;
					}
				for(int j = 1; j <= n; j++) putchar(s[j]);
				return 0;
			}
		}
	puts("NO");
	return 0;
}
/*将一个后缀改成一个新的合法串且不与原来的合法串产生任何回文
因为原来这个是合法串 -> 他的所有子串都合法串 -> 原有的那部分是合法串
假设有新的不合法串为(k1 + k2) 那么 Min(k1, k2) = 1
对于新构造的那个后缀，[m, m + 1] [m, m + 2] [m - 1, m + 1]是不是合法就可以了
要使得字典序最小
那么就先考虑改最后一位
m m + 1, m + 2
从右到左枚举m
枚举m + 1枚举m + 2
判断是否合法
如果合法 m + 1, m + 2
构造一个合法串由m + 1和 m + 2
m + i m + i + 1 m + i m + i -1
m
p = 1 特判
p = 2 判断最后一位，然后特判
*/
