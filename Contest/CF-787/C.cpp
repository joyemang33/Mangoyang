/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (200005)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
const int win = 1, lose = 2;
vector<int> s[2];
int f[N][2], num[N][2], n;
inline void solve(int u, int t, int now){
	if(f[u][t]) return; f[u][t] = now;
	//cout << t << " " << u << " " << now << endl;
	for(int i = 0; i < s[t^1].size(); i++){
		int x = s[t^1][i];
		int nxt = u - x >= 1 ? u - x : u - x + n;
		if(now == lose) solve(nxt, t ^ 1, win);
		else{
			num[nxt][t^1]--;
			//cout << nxt << " " << num[nxt][t^1] << endl;
			if(!num[nxt][t^1]) solve(nxt, t ^ 1, lose);
		}
	}
}
int main(){
	read(n);
	int s0; read(s0);
	for(int i = 1, x; i <= s0; i++) 
		read(x), s[0].push_back(x);
	int s1; read(s1);
	for(int i = 1, x; i <= s1; i++) 
		read(x), s[1].push_back(x);
	for(int i = 1; i <= n; i++) 
		num[i][0] = s0, num[i][1] = s1;
	f[1][0] = lose, f[1][1] = lose;
	for(int i = 0; i < s[0].size(); i++){
		int x = s[0][i];
		int nxt = 1 - x >= 1 ? 1 - x : 1 - x + n;
		solve(nxt, 0, win);
	}
	for(int i = 0; i < s[1].size(); i++){
		int x = s[1][i];
		int nxt = 1 - x >= 1 ? 1 - x : 1 - x + n;
		solve(nxt, 1, win);
	}
	for(int i = 2; i <= n; i++){
		if(f[i][0] == win) printf("Win ");
		else if(f[i][0] == lose) printf("Lose ");
		else printf("Loop ");
	}
	putchar('\n');
	for(int i = 2; i <= n; i++){
		if(f[i][1] == win) printf("Win ");
		else if(f[i][1] == lose) printf("Lose ");
		else printf("Loop ");
	}
	return 0;
}
