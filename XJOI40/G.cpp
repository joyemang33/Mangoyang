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
char s[100005];
int main(){
	scanf("%s", s + 1); int n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
		if(s[i] == '8' || s[i] == '0') return puts("YES"), putchar(s[i]), 0;  
	for(int i = 1; i <= n - 1; i++)
		for(int j = i + 1; j <= n; j++) if(s[i] != '0'){
			int now = (s[i] - 48) * 10 + s[j] - 48;
			if(now % 8 == 0) return puts("YES"), putchar(s[i]), putchar(s[j]), 0;
		}
	for(int i = 1; i <= n - 2; i++)
		for(int j = i + 1; j <= n - 1; j++)
			for(int k = j + 1; k <= n; k++) if(s[i] != '0'){
				int now = (s[i] - 48) * 100 + (s[j] - 48) * 10 + s[k] - 48;
				if(now % 8 == 0) return puts("YES"), putchar(s[i]), putchar(s[j]), putchar(s[k]), 0;
			}
	puts("NO");
	return 0;
}
