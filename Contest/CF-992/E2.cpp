/*program by mangoyang*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
namespace fast_IO {
    inline char read() {
        static const int IN_LEN = 1000000;
        static char buf[IN_LEN], *s, *t;
        if (s == t) {
            t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
            if (s == t) return -1;
        }
        return *s++;
    }
    template<class T>
    inline void read(T &x) {
        static bool iosig;
        static char c;
        for (iosig = false, c = read(); !isdigit(c); c = read()) {
            if (c == '-') iosig = true;
            if (c == -1) return;
        }
        for (x = 0; isdigit(c); c = read())
            x = ((x + (x << 2)) << 1) + (c ^ '0');
        if (iosig) x = -x;
    }
    const int OUT_LEN = 10000000;
    char obuf[OUT_LEN], *ooh = obuf;
    inline void print(char c) {
        if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
        *ooh++ = c;
    }
    template<class T>
    inline void print(T x) {
        static int buf[30], cnt;
        if (x == 0) {
            print('0');
        }
        else {
            if (x < 0) print('-'), x = -x;
            for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
            while (cnt) print((char)buf[cnt--]);
        }
    }
    inline void flush() {
        fwrite(obuf, 1, ooh - obuf, stdout);
    }
}
using namespace fast_IO;
#define N (300005)
#define int ll
struct Node{ ll x, id; } s[N], d[N], e[N], f[N];
int a[N], b[N], be[N], st[N], en[N], n, q;
inline bool cmp(const Node &A, const Node &B){ return A.x < B.x; }
main(){
	read(n), read(q);
	for(int i = 1, x = 0; i <= n; i++) 
		read(a[i]), s[i].x = a[i] - x, s[i].id = i, x += a[i];
	int block = 800, num = 0;
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
		ll det = y - a[x], c = be[x], flag = 0; 
		a[x] = y; int cnt = 0, cnt2 = 0;
		for(int i = st[c]; i <=	en[c]; i++){
			if(s[i].id > x) s[i].x -= det, d[++cnt] = s[i]; 
			if(s[i].id == x) s[i].x += det, y = s[i].x;
			if(s[i].id < x) e[++cnt2] = s[i];
		} 
		int pos = 1; d[0].x = -inf, d[cnt+1].x = inf;
		for(int i = 1; i <= cnt + 1; i++) 
			if(d[i].x >= y && d[i-1].x <= y){ pos = i; break; }
		for(int i = cnt; i >= pos; i--) d[i+1] = d[i]; 
		cnt++, d[pos] = (Node){y, x};
		int p = 1, q = 1, tmp = 0;
		while(p <= cnt || q <= cnt2){
			if(p <= cnt && (d[p].x <= e[q].x || q > cnt2)) f[++tmp] = d[p++];
			if(q <= cnt2 && (e[q].x <= d[p].x || p > cnt)) f[++tmp] = e[q++];
		}
		for(int i = st[c]; i <= en[c]; i++) s[i] = f[i-st[c]+1];
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
				print(s[tmp].id), print('\n');
				flag = 1; break;
			}
		}
		if(!flag) print(-1), print('\n');	
	}
	flush();
	return 0;
}
