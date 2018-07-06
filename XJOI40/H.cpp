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
vector<int> g[100005]; int m, k;
inline void makemid(int type){
	int rt = 1 + type;
	for(int i = 1; i < k; i++) g[rt].push_back(rt + i), m++;//, cout << i << " " << rt + i << endl;
	for(int i = rt + 1; i < rt + k; i++)
		for(int j = rt + k; j < rt + 2 * k - 1; j++) g[i].push_back(j), m++;//, cout << i << " " << j << endl;
	for(int j = rt + k; j < rt + 2 * k - 1; j += 2) g[j].push_back(j + 1), m++;// cout << j << " " << j + 1 << endl;
}
int main(){
	read(k);
	if(k % 2 == 0) return puts("NO"), 0;
	makemid(0), makemid(2 * k - 1); g[1].push_back(2 * k), m++;
	puts("YES");
	cout << 4 * k - 2 << " " << m << endl;
	for(int i = 1; i <= 4 * k - 2; i++)
		for(int j = 0; j < g[i].size(); j++) cout << i << " " << g[i][j] << endl;
	return 0;
}

