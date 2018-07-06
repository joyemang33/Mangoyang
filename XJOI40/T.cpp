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
#define N (1000005)
set<int> s;
int a[N], n;
int main(){
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++){
		int x = a[i], y = 0; 
		s.insert(x);
		for(int j = i + 1; j <= n; j++){
			x |= a[j], y |= a[j];
			s.insert(x);
			if(x == y) break;
		}
	}
	cout << s.size() << endl;
	return 0;
}
