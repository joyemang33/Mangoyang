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
const int N = 20005;
const int Mod = 100000007;
char s[3][N]; 
int a[4][N], f[N][2][2][2], n, px, py;
inline void update(int &x, int y){ (x += y) %= Mod; }
inline void prepare(){
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= n; j++) if(s[i][j] == '.') a[i][j] = 1;
}

namespace Doit{
	inline int solve(){
		memset(f, 0, sizeof(f)), f[0][1][1][1] = 1;
		//for(int i = 1; i <= 3; i++, putchar('\n'))
		//	for(int j = 1; j <= n; j++) cout << a[i][j] << " ";
		for(int i = 1; i <= n; i++){
			update(f[i][0][0][0], f[i-1][1][1][1]);
			if(a[1][i]) update(f[i][1][0][0], f[i-1][0][1][1]);
			if(a[2][i]) update(f[i][0][1][0], f[i-1][1][0][1]);
			if(a[3][i]) update(f[i][0][0][1], f[i-1][1][1][0]);
			if(a[1][i] && a[3][i]) update(f[i][1][0][1], f[i-1][0][1][0]);
			if(a[1][i] && a[2][i]){
				update(f[i][1][1][0], f[i-1][1][1][1]);
				update(f[i][1][1][0], f[i-1][0][0][1]);
			}
			if(a[2][i] && a[3][i]){
				update(f[i][0][1][1], f[i-1][1][1][1]);
				update(f[i][0][1][1], f[i-1][1][0][0]);
			}
			if(a[1][i] && a[2][i] && a[3][i]){
				update(f[i][1][1][1], f[i-1][0][0][0]);
				update(f[i][1][1][1], f[i-1][1][1][0]);
				update(f[i][1][1][1], f[i-1][0][1][1]);
			}
		}
		cout << "2 1 0 0 = " << f[2][0][0][1] << endl;
		return f[n][1][1][1];
	}
	inline int Modify(int sgn){
		if(sgn == 1){
			if(px == 3 && a[px-1][py] && a[px-2][py])
			return a[px-1][py] = 0, a[px-2][py] = 0, 1;
			return 0;
		}
		if(sgn == 2){
			if(px == 1 && a[px+1][py] && a[px+2][py])
			return a[px+1][py] = 0, a[px+2][py] = 0, 1;
			return 0;
		}	
		if(sgn == 3){
			if(py > 2 && a[px][py-1] && a[px][py-2])
			return a[px][py-1] = 0, a[px][py-2] = 0, 1;
			return 0;
		}
		if(sgn == 4){
			if(py < n - 1 && a[px][py+1] && a[px][py+2]){
				//cout << "OK" << endl;
				a[px][py+1] = 0, a[px][py+2] = 0;
				//for(int i = 1; i <= 3; i++, putchar('\n'))
				//	for(int j = 1; j <= n; j++) cout << a[i][j] << " ";
				return 1;
			
			}
			return 0;
		}
	}
	inline int realmain(){
		int ans = 0; prepare();
		//for(int i = 1; i <= 3; i++, putchar('\n'))
			//for(int j = 1; j <= n; j++) cout << a[i][j] << " ";
		for(int i = 1; i <= 4; i++){
			prepare();
			if(Modify(i)){
				//for(int x = 1; x <= 3; x++, putchar('\n'))
					//for(int y = 1; y <= n; y++) cout << a[x][y] << " ";
				ans += solve();
			}
		}
		for(int i = 1; i <= 4; i++)
			for(int j = i + 1; j <= 4; j++){
			prepare();
			if(Modify(i) && Modify(j)) ans -= solve();	
		}
		for(int i = 1; i <= 4; i++)
			for(int j = i + 1; j <= 4; j++)
				for(int k = j + 1; k <= 4; k++){
					prepare();
					if(Modify(i) && Modify(j) && Modify(k)) ans += solve();
				}
		return ans;
	}
}
main(){
	read(n);
	for(int i = 1; i <= 3; i++) scanf("%s", s[i] + 1);
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= n; j++) 
			if(s[i][j] == 'O') px = i, py = j;
	cout << px << " " << py << endl;
	cout << Doit::realmain();
	return 0;
}
