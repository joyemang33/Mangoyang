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
int point[1010][10],n,cnt = 0,ans[20],dis[20][10],flag;  
int main(){  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%d",&point[i][j]);  
    if(n>11) {printf("0\n"); return 0;}  
    for(int i=1;i<=n;i++){  
       memset(dis,0,sizeof dis);  
       flag = 1;  
       for(int j=1;j<=n;j++){  
          if(j==i) continue;  
          for(int k=1;k<=5;k++) dis[j][k] = point[j][k] - point[i][k];
          for(int k=1;k<j;k++){  
              if(k==i) continue;  
              int sum = 0;
              for(int l=1;l<=5;l++) sum+=dis[k][l]*dis[j][l];  
                  if(sum<=0) continue;
                  else {flag = 0; break;}  
              }  
              if(!flag) break;  
          }  
          if(flag) ans[++cnt] = i;  
      }  
      printf("%d\n",cnt);  
      for(int i=1;i<=cnt;i++) printf("%d\n",ans[i]);  
      return 0;  
 }  
