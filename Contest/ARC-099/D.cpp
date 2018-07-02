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
int main(){
	int k; read(k); int t = 1, num = 0, i = 1;
	while(i <= k){
		if(t == 10){
			num++;
			if(num >= 4){
				printf("10");
				for(int j = 1; j < num; j++) printf("9");
				putchar('\n');
				i++;
			}
			t = 1;
		}
		if(i == k) break;
		printf("%d", t), t++; 
		for(int j = 1; j <= num; j++) printf("9");
		putchar('\n');	
		i++;
	}
	return 0;
}
