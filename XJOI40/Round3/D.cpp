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
const int Lim = 100000;
char s[100];
int ch[5000005][11], val[5000005], n, cnt;
struct Bigint{
	int a[104], len;
	inline Bigint(){ memset(a, 0, sizeof(a)), len = 1; }
	Bigint operator + (const Bigint &A) const{
		Bigint ans; ans.len = Max(len, A.len);
		for(int i = 1; i <= ans.len; i++){
			ans.a[i] += a[i] + A.a[i];
			ans.a[i+1] = ans.a[i] / 10;
			ans.a[i] = ans.a[i] % 10;  
		}
		while(ans.a[ans.len+1] > 0) ans.len++;	 
		return ans;
	}
	inline void show(){
		for(int i = len; i >= 1; i--) cout << a[i];
		cout << endl;
	}
};
inline void Ins(Bigint A, int k){
	int len = A.len, p = 1;
	for(int i = len; i >= max(len - 40 + 1, 1); i--){
		int c = A.a[i];
		if(!ch[p][c]) ch[p][c] = ++cnt, val[ch[p][c]] = k;
		p = ch[p][c]; 
	}
}	
inline int find(char *s){
	int len = strlen(s), p = 1;
	for(int i = 0; i < len; i++){
		int c = s[i] - '0';
		if(!ch[p][c]) return -1;
		p = ch[p][c];		
	}
	return val[p];
}
int main(){
	cnt = 1; 
	Bigint f0, f1; f0.a[1] = f1.a[1] = 1;
	Ins(f0, 0);
	for(int i = 2; i < Lim; i++){
		Bigint tmp = f1;
		f1 = f0 + f1; f0 = tmp;
		if(f0.len > 60 || f1.len > 60){
			int mx = Max(f0.len - 60 + 1, f1.len - 60 + 1);
			for(int i = mx; i <= mx + 60 - 1; i++){
				f0.a[i-mx+1] = f0.a[i];
				f1.a[i-mx+1] = f1.a[i];
			}
			f0.len -= mx - 1, f1.len -= mx - 1;
		}
		Ins(f1, i);
	}
	int Case = 0; read(n);
	for(int i = 1; i <= n; i++)
		scanf("%s", s), printf("Case #%d: %d\n", ++Case, find(s)); 
	return 0;
}
