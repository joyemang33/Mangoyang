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
#define int ll
int f[1<<21], n, m;
struct Point{ int x, y, z; }; 
struct Cublod{
	Point l, r;
	inline void update(){ if(l.x > r.x) swap(l, r); }
	inline int volume(){ 
		return (r.x - l.x) * (r.y - l.y) * (r.z - l.z); 
	}
}a[30];
inline int checkcross(Cublod A, Cublod B){
	if(A.r.x < B.l.x || A.l.x > B.r.x) return 0;
	if(A.r.y < B.l.y || A.l.y > B.r.y) return 0;
	if(A.r.z < B.l.z || A.l.z > B.r.z) return 0;
	return 1;
}
inline Cublod getcross(Cublod A, Cublod B){
	Cublod C; A.update(), B.update();
	C.l.x = max(A.l.x, B.l.x), C.r.x = min(A.r.x, B.r.x);
	C.l.y = max(A.l.y, B.l.y), C.r.y = min(A.r.y, B.r.y);
	C.l.z = max(A.l.z, B.l.z), C.r.z = min(A.r.z, B.r.z);
	return C.update(), C;
}
inline void repulsion(Cublod now, int mask, int last, int si){
	if(mask) f[mask] = now.volume() * si;
	for(int i = last + 1; i <= n; i++) if(!mask || checkcross(now, a[i]))
		repulsion((!mask) ? a[i] : getcross(now, a[i]), mask|(1<<i-1), i, -si);
}
main(){
	read(n), read(m);
	for(int i = 1; i <= n; i++){
		Point l, r;
		read(l.x), read(l.y), read(l.z);
		read(r.x), read(r.y), read(r.z);
		a[i] = (Cublod){l, r}, a[i].update();
	}
	repulsion(a[1], 0, 0, -1);
	for(int j = 0; j < n; j++)
		for(int i = 1; i < (1 << n); i++)
			if(i & (1 << j)) f[i] += f[i^(1<<j)];
	while(m--){
		int mask = 0, num; read(num);
		for(int i = 1, x; i <= num; i++) 
			read(x), mask |= 1 << x - 1;
		printf("%lld\n", f[mask]); 
	}
	return 0;
}
