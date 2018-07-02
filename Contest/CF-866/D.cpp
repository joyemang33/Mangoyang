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
#define int ll
priority_queue<int> pq;
main(){
	int n, ans = 0; read(n);
	for(int i = 1, x; i <= n; i++){
		read(x), pq.push(-x), pq.push(-x);
		ans += x + pq.top(), pq.pop();
	}
	cout << ans;
	return 0;
}
