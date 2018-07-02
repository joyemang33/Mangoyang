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
int	n, a[1000005];
int main(){
	read(n), n *= 2;
	for(int i = 1; i <= n; i++) read(a[i]);
	int res = 0;
	for(int i = 1; i <= n; i += 2){
		if(a[i] == a[i+1]) continue;
		int j = i + 1;
		while(a[j] != a[i]) j++;
		while(j > i + 1) swap(a[j], a[j-1]), j--, res++;
	}
	cout << res << endl;
	return(0);
}
