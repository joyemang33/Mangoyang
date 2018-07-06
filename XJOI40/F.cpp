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
#define int ll
int n, k, l, Mod;
const int le = 2;
struct Matrix{
	int a[le+5][le+5];
	inline Matrix(){ memset(a, 0, sizeof(a)); }
	inline void write(){
		for(int i = 1; i <= le; i++, putchar('\n'))
			for(int j = 1; j <= le; j++) cout << a[i][j] << " ";
	}
};
inline Matrix Mult(Matrix A, Matrix B){
	Matrix C;
	for(int i = 1; i <= le; i++)
		for(int j = 1; j <= le; j++)
			for(int k = 1; k <= le; k++)
				(C.a[i][j] += A.a[i][k] * B.a[k][j]) %= Mod;
	return C;
}
inline Matrix Power(Matrix a, int b){
	Matrix ans = a; b--;
	for(; b; b >>= 1, a = Mult(a, a))
		if(b & 1) ans = Mult(ans, a);
	return ans;
}
inline ll Pow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = a * a % Mod)
		if(b & 1) ans = ans * a % Mod;
	return ans; 
}
main(){
	read(n), read(k), read(l), read(Mod);
	if(l < 63 && k >= (1ll << l)) return puts("0"), 0;
	int all = Pow(2, n);
	Matrix A, B;
	A.a[1][1] = A.a[2][1] = 1;
	B.a[1][1] = B.a[1][2] = B.a[2][1] = 1;
	B = Power(B, n), A = Mult(B, A);
	int now = (all - A.a[1][1] + Mod) % Mod, ans = 1 % Mod;
	//cout << A.a[1][1] << endl;
	for(int i = 0; i < l; i++)
		if((1ll << i) & k) (ans *= now) %= Mod;
			else (ans *= A.a[1][1]) %= Mod;
	cout << ans % Mod;
	return 0;
}
