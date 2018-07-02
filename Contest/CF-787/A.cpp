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
int main(){
	ll a, b, c, d;
	read(b), read(a), read(d), read(c);
	for(int i = 0; i <= 1000000; i++){
		int now = a + i * b - c;
		if(now >= 0 && now % d == 0) return cout << a + i * b, 0; 
	}
	puts("-1");
	return 0;
}
