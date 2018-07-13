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
#define int ll
struct Point{ int x, id; } e[N];
int a[N], buf[N], Ans[N], n, col, f0;
inline bool cmp(Point A, Point B){ return A.x < B.x; }
inline int change(int x){
	int res = x;
	for(int i = 2; i * i <= abs(x); i++)
		while(res % (i * i) == 0) res /= i * i;
	return res;
}
main(){
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]), a[i] = change(a[i]);
	for(int i = 1; i <= n; i++) e[i].x = a[i], e[i].id = i;
	sort(e + 1, e + n + 1, cmp);
	a[e[1].id] = ++col; if(e[1].x == 0) f0 = 1;
	for(int i = 2; i <= n; a[e[i++].id] = col){
		if(e[i].x > e[i-1].x) col++;
		if(e[i].x == 0) f0 = col;	
	}
	for(int i = 1; i <= n; i++){
		int res = 0;
		for(int j = i; j <= n; j++){
			if(!buf[a[j]] && a[j] != f0) res++;
			buf[a[j]]++;
			if(!res) Ans[1]++; else Ans[res]++;
		}
		for(int j = i; j <= n; j++) buf[a[j]]--;
	}
	for(int i = 1; i <= n; i++) cout << Ans[i] << " ";
	return 0;
}
