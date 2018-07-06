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
#define N (200005)
vector<int> v[N];
int n;
struct Node{int x, id; } a[N];
inline bool cmp(Node x, Node y){ return x.x > y.x; }
int main(){
	read(n); int mx = 0;
	for(int i = 1; i <= n; i++) read(a[i].x), a[i].id = i;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		mx = max(mx, a[i].id);
		v[mx].push_back(a[i].x);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < v[i].size(); j++) printf("%d ", v[i][j]);
		putchar('\n');
	}
	return 0;
}
