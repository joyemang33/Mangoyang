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
int n;
inline void dfs(int n, int a, int b, int c){
	if(n == 1) return (void) (cout << a << "->" << c << endl);
	dfs(n - 1, a, c, b);
	cout << a << "->" << c << endl;
	dfs(n - 1, b, a, c);
}
int main(){
	read(n);
	dfs(n, 1, 2, 3);
	cout << "tot=" << (1 << n) - 1;
	return 0;
}
