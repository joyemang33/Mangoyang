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
vector<int> v[105];
int a[105][105], f[105][100005], n, m, s;
int main(){
	read(n), read(m), read(s);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) read(a[i][j]);
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n;j++) if(a[j][i]){
			int num = 0;
			for(int k = j; k <= Min(n, j + s - 1); k++)
				num += a[k][i];
			v[i].push_back(num);
		}
	}	
	//for(int i = 1; i <= m; i++)
	//	for(int j = 0; j < v[i].size(); j++) cout << v[i][j] << endl;
	int ans = 0, tot = 0, lim = 0;
	for(int i = 1; i <= m; i++) lim += v[i].size();
	for(int i = 1; i <= m; i++)
		for(int j = 0; j <= lim; j++){
			f[i][j] = f[i-1][j];
			for(int k = 0; k < v[i].size(); k++) 
				if(j >= k) f[i][j] = Max(f[i][j], f[i-1][j-k] + v[i][k]);
			if(f[i][j] > ans || f[i][j] == ans && j < tot) ans = f[i][j], tot = j;
		}
	cout << ans << " " << tot;	
	return 0;
}
