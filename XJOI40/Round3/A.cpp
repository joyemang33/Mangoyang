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
const int MAXN = 1e6 + 5;
int dark, fantasy, deep;
char SS[MAXN], TT[MAXN];
inline bool idx(char ch){ return ch == 32 || ch == 9 || ch == 10; }
inline bool Doit(){
    if(gets(TT))
        return fantasy = 0, dark = strlen(TT), 1;
    return 0;
}
inline bool Cleartext () {
    while(fantasy < dark && idx(TT[fantasy])) fantasy++;
    if (fantasy >= dark) return Doit();
    return 1;
}
inline bool mm(char ch) {
    if(!Cleartext()) return 0;
    if(TT[fantasy] == ch){
        SS[deep++] = TT[fantasy++];
        return 1;
    }
    return 0;
}
inline void add(){ if(deep && SS[deep-1] != ' ') SS[deep++] = ' '; }
int solve(){
    if (fantasy >= dark) Doit();
    deep = 0;
    bool istag = mm('<'), isend = mm('/');
    if(istag){
        bool space = false;
        while (TT[fantasy] != '>') {
            if (fantasy == 0 && space) SS[deep++] = ' ';
            SS[deep++] = TT[fantasy++];
            if (fantasy >= dark && !Doit()) break;
            space = true;
        }
    } 
    else {
        bool space = false;
        while (TT[fantasy] != '<') {
            if (fantasy == 0 && space) add();
            if (idx(TT[fantasy])) add();
            else SS[deep++] = TT[fantasy];
            fantasy++;
            if (fantasy >= dark && !Doit()) break;
            space = true;
        }
        while (deep && SS[deep-1] == ' ') deep--;
    }
    bool bo = SS[deep-1] == '/';
    mm('>');
    SS[deep] = '\0';
    if (istag && isend && !bo) return -1;
    if (istag && !bo) return 1;
    return 0;
}

int main () {
    int T, cnt = 0; read(T);
    for(int Case = 1; Case <= T; Case++){
        printf("Case #%d:\n", Case);
        cnt = solve(), puts(SS);
        while(cnt){
            int tmp = solve();
            if(SS[0] == '\0') continue;
            if(tmp < 0)
                for(int i = 0; i < cnt-1; i++) printf(" ");
            else
                for(int i = 0; i < cnt; i++) printf(" ");
            cnt += tmp;
            puts(SS);
        }
    }
    return 0;
}
