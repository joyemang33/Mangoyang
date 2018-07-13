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
inline int GetLoop(int u, int fa){
	if(vis[u]) return rt = u, 1; vis[u] = 1;
	for(int p ) if(a[p] != fa){
		int v = a[p], res = getloop(v, u);
		if(!res) continue;
		if(res == 1) c.push_back(u), inc[u] = 1;
		return (res > 1 || u != rt) ? 2 : 1;
	}
}
inline void SolveTree(int u, int fa){
	
}
inline void SolveLoop(){

}
int main(){
	
	return 0;
}
