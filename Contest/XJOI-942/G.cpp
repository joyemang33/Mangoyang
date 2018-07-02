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
int f[105][100005], n;
struct Node{ int x, y; } a[10005];
inline bool cmp(Node A, Node B){ return A.x < B.x; }
inline void chkmax(int &x, int y){ if(y > x) x = y; }
int main(){
	read(n);
	for(int i = 1; i <= n; i++) read(a[i].x);
	for(int i = 1; i <= n; i++) read(a[i].y);
	sort(a + 1, a + n + 1, cmp); 
	int Lim = a[n].x;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= Lim; j++){
			f[i][j] = Max(f[i][j-1], f[i-1][j]);
			if(j <= a[i].x) chkmax(f[i][j], f[i-1][j-1] + a[i].y);
		}
	cout << f[n][Lim];
	return 0;
}
