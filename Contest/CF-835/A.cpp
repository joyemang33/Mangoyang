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
  ll s, v1, v2, t1, t2;
  read(s), read(v1), read(v2), read(t1), read(t2);
  ll res1 = s * v1 + 2ll * t1;
  ll res2 = s * v2 + 2ll * t2;
  if(res1 == res2) return puts("Friendship"), 0;
  if(res1 < res2) return puts("First"), 0;
  puts("Second");
  return 0;
}
