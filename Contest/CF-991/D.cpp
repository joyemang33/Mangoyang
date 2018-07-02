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
char s1[1005], s2[1005];
int f[1005][1005];
inline void chkmax(int &x, int y){ if(x < y) x = y; }
int main(){
	scanf("%s", s1 + 1), scanf("%s", s2 + 1);
	int n = strlen(s1 + 1);
	for(int i = 1; i <= n; i++)
		for(int j = i - 1; j <= Min(i + 1, n); j++){
			if(i > 1 && i == j && s1[i] == '0' && s2[j] == '0' && s1[i-1] == '0')
				chkmax(f[i][j], f[i-2][j-1] + 1);
			if(j > 1 && i == j && s1[i] == '0' && s2[j] == '0' && s2[j-1] == '0')
				chkmax(f[i][j], f[i-1][j-2] + 1);
			if(i > 1 && i > j && s1[i] == '0' && s1[i-1] == '0' && s2[j] == '0')
				chkmax(f[i][j], f[i-2][j-1] + 1);
			if(j > 1 && i < j && s2[j] == '0' && s2[j-1] == '0' && s1[i] == '0')
				chkmax(f[i][j], f[i-1][j-2] + 1);
			chkmax(f[i][j], f[i-1][j]);
			chkmax(f[i][j], f[i][j-1]), chkmax(f[i][j], f[i-1][j-1]);
			//cout << i << " " << j << " " << f[i][j] << endl;
			
		}
	cout << f[n][n] << endl;		
	return 0;
}
/*
x00x000
00000x0
00x000
000xx0
/*
000
00
	f[i][0]  X
			 X
	XX
	 X
	f[i][0] = f[
*/
