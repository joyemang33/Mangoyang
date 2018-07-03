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
int lim[N], nxt[N], lim2[N], ans;
char s1[N], s2[N], s3[N];
struct SuffixAutomaton{
	int ch[N][30], dep[N], fa[N], size, tail;
	inline SuffixAutomaton(){ tail = size = 1; }
	inline int newnode(int x){ dep[++size] = x; return size; }
	inline void ins(int c){
		int p = tail, np = newnode(dep[p] + 1);
		for(; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
		if(!p) return (void) (fa[np] = 1, tail = np);
		int q = ch[p][c];
		if(dep[q] == dep[p] + 1) fa[np] = q;
		else{
			int nq = newnode(dep[p] + 1);
			fa[nq] = fa[q], fa[q] = fa[np] = nq;
			for(int i = 0; i < 26; i++) ch[nq][i] = ch[q][i];
			for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
		}tail = np;
	}
	inline void find(char *s){
		int len = strlen(s + 1); int p = 1, now = 0;
		for(int i = 1; i <= len; i++){
            int c = s[i] - 'a';
            if(ch[p][c]) now++, p = ch[p][c];
            else{
                for(; p && !ch[p][c]; p = fa[p]);
                if(p) now = dep[p] + 1, p = ch[p][c]; else p = 1, now = 0;  
            }
            lim[i] = now; 
        }
	}
}van;
int main(){
	scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
	int len1 = strlen(s1 + 1);
	int len2 = strlen(s2 + 1);
	int len3 = strlen(s3 + 1);
	for(int i = 1; i <= len1; i++) van.ins(s1[i] - 'a');
	van.find(s2); int j = 0, ans = 0; nxt[0] = -1;
	for(int i = 2; i <= len3; i++){
		while(s3[i] != s3[j+1] && ~j) j = nxt[j];
		nxt[i] = ++j;
	}
	j = 0;
	memset(lim2, 127, sizeof(lim2));
	for(int i = 1; i <= len2; i++){
		while(s2[i] != s3[j+1] && ~j) j = nxt[j];
		if((++j) == len3) lim2[i] = len3 - 1;
	}
	for(int i = 1; i <= len2; i++){
		lim2[i] = Min(lim2[i], lim2[i-1] + 1);
		ans = Max(ans, Min(lim2[i], lim[i]));
	}	
	cout << ans;
	return 0;
}
