#include <bits/stdc++.h>
/*sgdaagdasdasgdsasdasddas
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
*/
#define int long long
using namespace std;
const int	N = 30010, MAX = 200000, MOD = 1000000007;
string		fib[N];
int		n, m, len, cnt, lef[N], nex[MAX + 10];
char		tmp[MAX + 10];
string		a, b, c, tp;
struct matrix {
	int mat[3][3];
	matrix()
	{
		memset( mat, 0, sizeof mat );
	}
/*sgdaagdasdasgdsasdasddas
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
*/

	matrix operator *( const matrix & x ) const
	{
		matrix ret = matrix();
		for ( int k = 1; k <= 2; ++k )
			for ( int i = 1; i <= 2; ++i )
				for ( int j = 1; j <= 2; ++j )
					(ret.mat[i][j] += 1ll * mat[i][k] * x.mat[k][j] % MOD) %= MOD;
		return(ret);
	}
};
matrix bas;
matrix power( matrix a, int b )
{
	matrix ret = matrix();
	ret.mat[1][1] = ret.mat[2][2] = 1;
	while ( b )
	{
		if ( b & 1 )
			ret = ret * a;
		a	= a * a;
		b	>>= 1;
	}
	return(ret);
}
/*sgdaagdasdasgdsasdasddas
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
*/

int getfib( int x )
{
	matrix ret = power( bas, x );
	return(ret.mat[1][2]);
}


int getnum()
{
	int ret = 0;
	for ( int i = 0, j = 0; i < (int) tp.length(); ++i )
	{
		while ( j >= 0 && tmp[j + 1] != tp[i] )
			j = nex[j];
		++j;
		if ( j == len )
			++ret, j = nex[j];
	}
	return(ret);
}


int solve()
{
	nex[0] = -1;
	for ( int i = 2, j = 0; i <= len; ++i )
	{
		while ( j >= 0 && tmp[j + 1] != tmp[i] )
			j = nex[j];
		nex[i] = ++j;
	}
	int p = lower_bound( lef + 1, lef + cnt + 1, len ) - lef;
	++p;
	if ( n <= p + 1 )
	{
		tp = fib[n];
		return(getnum() );
	}
	a	= fib[p].substr( 0, len - 1 );
	b	= fib[p].substr( lef[p] - len + 1, len - 1 );
	c	= fib[p + 1].substr( lef[p + 1] - len + 1, len - 1 );
	int nb, nc, n0, n1, pos = n - p, ret = 0;
	/*sgdaagdasdasgdsasdasddas
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
asddasgagdjhdhgasdgdasas
]asdjhasddasasddasjkldaksksljdakljdas
dsavgdasgdasksdajdasasdksdaasdkasdads
asdasdsdadasgdasdasasddaksdasksasdak
*/
	tp								= b + a;
	nb								= getnum();
	tp								= c + a;
	nc								= getnum();
	tp								= fib[p];
	n0								= getnum();
	tp								= fib[p + 1];
	n1								= getnum();
	(ret += 1ll * (getfib( pos ) - (pos & 1) ) * nc % MOD)		%= MOD;
	(ret += 1ll * (getfib( pos - 1 ) - 1 + (pos & 1) ) * nb % MOD)	%= MOD;
	matrix sta = matrix();
	sta.mat[1][1]		= n1;
	sta.mat[1][2]		= sta.mat[2][1] = n0;
	sta			= sta * power( bas, pos );
	(ret += sta.mat[1][2])	%= MOD;
	ret			= (ret % MOD + MOD) % MOD;
	return(ret);
}


main()
{
	fib[1]	= "a";
	fib[2]	= "b";
	for ( int i = 3;; ++i )
	{
		fib[i]	= fib[i - 1] + fib[i - 2];
		lef[i]	= fib[i].length();
		cnt	= i;
		if ( lef[i - 1] >= MAX )
			break;
	}
	bas.mat[1][1] = bas.mat[1][2] = bas.mat[2][1] = 1;
	cin >> n >> m;
	for ( int i = 1; i <= m; ++i )
	{
		scanf( "%s", tmp + 1 );
		len = strlen( tmp + 1 );
		cout << solve() << endl;
	}
	return(0);
}



