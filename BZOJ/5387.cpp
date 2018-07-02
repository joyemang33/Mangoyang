/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (1000005)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
#define double long double
const double pi = acos(-1);
int rev[N], b[N], prime[N], ans[N], n, m, len, lg, tot;
struct Point{
	double a, b;
	Point operator + (const Point &A){ return (Point){a + A.a, b + A.b}; }
	Point operator - (const Point &A){ return (Point){a - A.a, b - A.b}; }
	Point operator * (const Point &A){ return (Point){a * A.a - b * A.b, a * A.b + b * A.a}; }
}a[N];
inline void FFT(Point *A, int len, int type){
	for(register int i = 0; i < len; i++) if(i < rev[i]) swap(A[i], A[rev[i]]);
	for(register int k = 2; k <= len; k <<= 1){
		Point w = (Point){cos(2 * pi / k), sin(2 * pi / k) * type};
		for(int i = 0; i < len; i += k){
			Point now = (Point){1.0, 0.0};
			for(int j = i; j < i + (k >> 1); j++){
				Point x = A[j], y = now * A[j+(k>>1)];
				A[j] = x + y, A[j+(k>>1)] = x - y, now = now * w;
			}
		}
	}
	if(type == -1){ for(register int i = 0; i < len; i++) A[i].a /= len; }
}
main(){
	freopen("dbiao.cpp", "w", stdout);
	read(n); 
	for(register int i = 2; i < 150001; i++){
		if(!b[i]) prime[++tot] = i, a[i].a = 1.0;
		else a[i].a = 0.0;
		for(register int j = 1; i * prime[j] < N && j <= tot; j++){
			b[i*prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	for(len = 1; len <= 400001; len <<= 1) lg++;
	for(register int i = 0; i < len; i++) rev[i] = (rev[i>>1] >> 1) | ((i & 1) << (lg - 1));
	FFT(a, len, 1);
	for(register int i = 0; i < len; i++) a[i] = a[i] * a[i];
	FFT(a, len, -1);
	for(register int i = 200000; i < len; i++) a[i].a = a[i].b = 0;
	FFT(a, len, 1);
	for(register int i = 0; i < len; i++) a[i] = a[i] * a[i];
	FFT(a, len, -1);
	for(int i = 1; i <= 150000; i++){
		printf("%lld,", (ll) (a[i].a + 0.5));
		if(i % 20 == 0) putchar('\n'); 
	}
	return 0;
}
