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
#define N (300005)
struct Node{ int x, id; } s[N];
int a[N], b[N], be[N], st[N], en[N], n, q;
inline bool cmp(const Node &A, const Node &B){ return A.x < B.x; }
int main(){
	read(n), read(q);
	for(int i = 1, x = 0; i <= n; i++) 
		read(a[i]), s[i].x = a[i] - x, s[i].id = i, x += a[i];
	int block = 750, num = 0;
	for(int i = 1; i <= n; i++) be[i] = (i - 1) / block + 1;
	for(int i = 1; i <= n; i++){
		if(be[i] != be[i-1]) st[be[i]] = i;
		if(be[i] != be[i+1]) en[be[i]] = i;
	}
	num = be[n];
	for(int i = 1; i <= num; i++)
		sort(s + st[i], s + en[i] + 1, cmp);
	while(q--){
		int x, y; read(x), read(y);
		int det = y - a[x], c = be[x], flag = 0; a[x] = y;
		for(int i = st[c]; i <=	en[c]; i++){
			if(s[i].id > x) s[i].x -= det;
			if(s[i].id == x) s[i].x += det;
		} 
		sort(s + st[c], s + en[c] + 1, cmp);
		for(int i = c + 1; i <= num; i++) b[i] -= det;
		for(int i = 1; i <= num; i++){
			int l = st[i], r = en[i], tmp = 0;
			while(l <= r){
				int mid = l + r >> 1;
				if(s[mid].x + b[i] <= 0) 
					tmp = mid, l = mid + 1;
				else r = mid - 1;
			}
			if(tmp && s[tmp].x + b[i] == 0){
				printf("%d\n", s[tmp].id);
				flag = 1; break;
			}
		}
		if(!flag) printf("-1\n");	
	}
	return 0;
}
