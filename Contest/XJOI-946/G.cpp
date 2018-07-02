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
#define N (105)
int d[N][N][4], b[N][N], n, m;
const int cx[4] = {0, 0, 1, -1};
const int cy[4] = {1, -1, 0, 0};
struct Node{ int x, y, f; }; queue<Node> q;
inline bool check(int x, int y){
	if(x >= n || y >= m || x < 1 || y < 1) return 0;
	if(b[x][y] || b[x][y+1]) return 0;
	if(b[x+1][y] || b[x+1][y+1]) return 0; return 1;
}
inline int Gol(int x){
	if(x == 0) return 3; if(x == 1) return 2;
	if(x == 2) return 0; if(x == 3) return 1;
}
inline int Gor(int x){
	if(x == 0) return 2; if(x == 1) return 3;
	if(x == 2) return 1; if(x == 3) return 0;
}
inline void relax(int s, int x, int y, int f){
	if(s >= d[x][y][f]) return;
	d[x][y][f] = s, q.push((Node){x, y, f}); 
}
inline void solve(Node S, int ex, int ey){
	memset(d, 127, sizeof(d));
	q.push(S), d[S.x][S.y][S.f] = 0; 
	while(!q.empty()){
		Node u = q.front(); q.pop();
		int x = u.x, y = u.y, f = u.f, s = d[x][y][f];
		for(int t = 1; t <= 3; t++){
			int nx = x + t * cx[f];
			int ny = y + t * cy[f];
			if(!check(nx, ny)) break;
			relax(s + 1, nx, ny, f);
		}
		relax(s + 1, x, y, Gol(f)), relax(s + 1, x, y, Gor(f));
	}
	int ans = inf;
	for(int i = 0; i < 4; i++) ans = Min(ans, d[ex][ey][i]);
	cout << (ans < inf ? ans : -1) << endl;
}
int main(){
	read(n), read(m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) read(b[i][j]);
	Node s; read(s.x), read(s.y);
	int ex, ey, f; read(ex), read(ey), f = getchar();
	if(f == 'N') s.f = 3; if(f == 'S') s.f = 2;
	if(f == 'E') s.f = 0; if(f == 'W') s.f = 1;
	return solve(s, ex, ey), 0;
}
