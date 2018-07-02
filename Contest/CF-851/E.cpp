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
#define N (100005)
map<int, int> f, v, mp;
vector<int> ps;
int b[N], a[N], prime[N], tot, n, result;
inline int DP(int mask){
	if(v[mask]) return f[mask];
	int now = 0;
	for(int i = 1; (1 << i - 1) <= mask; i++){
		int nxt = (mask >> i) | mask & ((1 << i - 1) - 1);
		now |= (1 << DP(nxt));	
	}
	int res = 0;
	for(int i = 0; i <= 30; i++) 
		if(!((1 << i) & now)){ res = i; break; }
	return v[mask] = 1, f[mask] = res, res;	
}
inline void solve(int x){
	int mask = 0; f.clear(), v.clear(), v[0] = 1;
	for(int i = 1; i <= n; i++) if(a[i] % x == 0){
		int now = a[i], num = 0;
		while(now % x == 0) now /= x, num++;
		mask |= 1 << num - 1;
	}
	result ^= DP(mask); 
}
int main(){
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 2; i < N; i++){
		if(!b[i]) prime[++tot] = i;
		for(int j = 1; i * prime[j] < N && j <= tot; j++){
			b[i*prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i = 1; i <= n; i++){
		int now = a[i];
		for(int j = 1; j <= tot; j++) if(now % prime[j] == 0){
			if(!mp[prime[j]]) ps.push_back(prime[j]), mp[prime[j]] = 1;
			while(now % prime[j] == 0) now /= prime[j]; if(now == 1) break;
		}
		if(now > 1 && !mp[now]) mp[now] = 1, ps.push_back(now);
	}
	for(int i = 0; i < ps.size(); i++) solve(ps[i]);
	if(!result) cout << "Arpa"; else cout << "Mojtaba";
	return 0;
}

