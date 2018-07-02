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
#define sqr(x) ((x) * (x))
int main(){
	ll ax, ay, bx, by, cx, cy;
	read(ax), read(ay), read(bx), read(by), read(cx), read(cy);	
	ll dis1 = sqr(ax - bx) + sqr(ay - by);
	ll dis2 = sqr(bx - cx) + sqr(by - cy);
	long double m1 = 1e18, m2 = 1e18;
	if(ax != bx) m1 = (double) (ay - by) / (ax - bx);
	if(bx != cx) m2 = (double) (by - cy) / (bx - cx);
	if(dis1 == dis2 && m1 != m2) puts("Yes"); else puts("No");
	return 0;
}
