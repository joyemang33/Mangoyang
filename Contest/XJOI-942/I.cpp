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
double d1, c, d2, ans; int n;
struct Node{ double d, p; } a[23333];
inline bool cmp(Node A, Node B){ return A.d < B.d; }
int main(){
	scanf("%lf%lf%lf%lf%d", &d1, &c, &d2, &a[0].p, &n);
	for(int i = 1; i <= n; i++) scanf("%lf%lf", &a[i].d, &a[i].p);
	n++, a[n].d = d1, sort(a, a + n + 1, cmp); 
	int now = 0; double cc = 0;
	while(now < n){
		int pos = 0, flag = 0;
		for(int i = now + 1; i <= n && c * d2 >= (a[i].d - a[now].d); i++){
			pos = i; if(a[i].p < a[now].p){ flag = 1; break; } 
		}
		if(!pos) return puts("No solution"), 0;
		double dis = a[pos].d - a[now].d, ned = dis / d2;
		if(flag || pos == n){
			if(cc < ned){
				ans += (ned - cc) * a[now].p;
				cc = 0;
			}
			else cc -= ned;
			now = pos;
		}
		else ans += (c - cc) * a[now].p, cc = c - (a[now+1].d - a[now].d) / d2, now++;
	}
	printf("%.2lf", ans);
	return 0;
}
