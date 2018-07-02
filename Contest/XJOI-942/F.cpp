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
struct Node{ int l, r; } a[100005];
inline bool cmp(Node A, Node B){ return A.r < B.r; }
int main(){
	int n, ans = 0; read(n);
	for(int i = 1; i <= n; i++)
		read(a[i].l), read(a[i].r);
	sort(a + 1, a + n + 1, cmp);
	int last = 0;
	for(int i = 1; i <= n; i++)
		if(a[i].l >= last) ans++, last = a[i].r;
	cout << ans;
	return 0;
}
