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
#define N (1000005)
#define Debug 0
const double pi = acos(-1);
int a[N], n, x, len;
struct Point{
	double a, b;
	Point operator + (const Point &A){ return (Point){a + A.a, b + A.b}; }
	Point operator - (const Point &A){ return (Point){a - A.a, b - A.b}; }
	Point operator * (const Point &A){ return (Point){a * A.a - b * A.b, a * A.b + b * A.a}; }
}f[N], g[N];
namespace FFT{
	int rev[N]; 
	inline void DFT(Point *A, int len, int type){
		for(int i = 1; i <= len; i++) 
			if(i < rev[i]) swap(A[i], A[rev[i]]);
		for(int k = 2; k <= len; k <<= 1){
			Point w = (Point){cos(2 * pi / k), sin(2 * pi / k) * type};
			for(int i = 0; i < len; i += k){
				Point now = (Point){1.0, 0.0};
				for(int j = i; j < i + (k >> 1); j++){
					Point x = A[j], y = now * A[j+(k>>1)];
					A[j] = x + y, A[j+(k>>1)] = x - y, now = now * w; 
				}
			}
		}
		if(type == -1) for(int i = 0; i < len; i++) A[i].a /= (double) len;
	}
	inline void cov(Point *A, Point *B){
		DFT(A, len, 1), DFT(B, len, 1);
		for(int i = 0; i < len; i++) A[i] = A[i] * B[i]; DFT(A, len, -1);
	} 
	inline void parpare(int tmp){
		int lg = 0;
		for(len = 1; len <= tmp; len <<= 1) lg++;
		for(int i = 0; i < len; i++) 
			rev[i] = (rev[i>>1] >> 1) | (i & 1) << (lg - 1);
	}	
}
int main(){
	read(n), read(x); int num = 0;
	f[num].a += 1, g[n-num].a += 1;
	for(int i = 1; i <= n; i++){
		read(a[i]); if(a[i] < x) num++;
		f[num].a += 1, g[n-num].a += 1;
	}
	FFT::parpare(2 * n + 1); FFT::cov(f, g);
	printf("%lld ", (ll) ((f[n].a + 0.5 - n) / 2.0));
	for(int i = n + 1; i <= 2 * n; i++) printf("%lld ", (ll)(f[i].a + 0.5));
	return 0;
}
