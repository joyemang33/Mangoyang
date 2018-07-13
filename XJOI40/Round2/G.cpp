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
struct Point{
	int x, id;
	bool operator < (const Point &A) const{ return x > A.x; }; 
};
priority_queue<Point> v0, v1;
struct Edge{ int x, y; }; vector<Edge> g[100005];
int main(){
	int n; read(n);
	for(int i = 1, x, y; i <= n; i++){
		read(x), read(y);
		if(x == 0) v0.push((Point){y, i});
		if(x == 1) v1.push((Point){y, i});
	}
	int tot = 1; 
	while(v0.size() + v1.size() > 1){
		if(!v0.size() || !v1.size()) return puts("-1"), 0;
		Point c0 = v0.top(), c1 = v1.top(); 
		v0.pop(), v1.pop();
		if(c0.x < c1.x || (c0.x == c1.x && v0.size() > v1.size())){
			c1.x -= c0.x, v1.push(c1);
			g[c1.id].push_back((Edge){c0.id, c0.x});
		}
		else{
			c0.x -= c1.x, v0.push(c0);
			g[c0.id].push_back((Edge){c1.id, c1.x});
		}  
	}
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < g[i].size(); j++) 
			cout << i << " " << g[i][j].x << " " << g[i][j].y << endl;
	return 0;
}


