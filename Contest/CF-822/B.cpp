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
char s[2005], t[2005];
int n, m;
int main(){
	int n, m; read(n), read(m);
	scanf("%s", s + 1), scanf("%s", t + 1);
	int maxnum = -1, maxpos = 0;
	for(int i = 1; i <= m - n + 1; i++){
		int num = 0;
		for(int j = 1; j <= n; j++) if(s[j] == t[i+j-1]) num++;
		if(num > maxnum) maxnum = num, maxpos = i;
	}
	cout << n - maxnum << endl;
	for(int i = 1; i <= n; i++) 
		if(s[i] != t[maxpos+i-1]) cout << i << " ";
	return 0;
}
