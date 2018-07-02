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
struct Node{ int s, a, b; }c[N];
inline bool cmp(Node A, Node B){ return A.a - A.b > B.a - B.b; }
int main(){
	read(n), read(m), s1 = s2 = m;
	for(int i = 1; i <= n; i++)
		read(c[i].s), read(c[i].a), read(c[i].b);
	sort(c + 1, c + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		if(c[i].s <= s1){
			s1 -= c[i].s;
			ans += c[i].s * c[i].
		}
	}
	return 0;
}
