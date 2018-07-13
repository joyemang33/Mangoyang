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
char str[105]; 
ll dp[105][2], n;
inline void upd(ll &a, ll b){ a += b; } 
inline ll calc(int x){
	memset(dp, 0, sizeof(dp)), dp[0][x] = 1; 
	for (int i = 0; i < n; i++){
		if (str[i] == 'A'){
			upd(dp[i+1][0], dp[i][0]); 
			upd(dp[i+1][0], dp[i][1]); 
			if(str[i+1] == 'B') upd(dp[i + 1][1], dp[i][1]); 
		}
		else{
			upd(dp[i+1][0], dp[i][1]); 
			if(str[i+1] == 'A') upd(dp[i + 1][1], dp[i][0]); 
			else upd(dp[i+1][1], dp[i][1]); 
		}
	}
	return dp[n][x]; 
}
int main(){
	scanf("%s", str); 
	n = strlen(str); 
	str[n] = str[0]; 
	printf("%lld\n", calc(0) + calc(1));
	return 0;
}
