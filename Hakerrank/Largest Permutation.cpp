#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<functional>
#include<complex>

using namespace std;
#define BET(a,b,c) ((a)<=(b)&&(b)<(c))
#define FOR(i,n) for(int i=0,i##_end=(int(n));i<i##_end;i++)
#define SZ(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define CLS(x,val) memset((x) , val , sizeof(x)) 
#define FOR_EACH(it,v) for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++)
typedef long long ll_t;
typedef long double ld_t;
typedef vector<int> VI;
typedef vector<VI> VVI;

typedef complex<int> xy;

int P[100000+10];
int IndexFromValue[100000+10];
int main()
{
    int N,K;
    cin>>N>>K;
    FOR(i,N) scanf("%d",&P[i]);
    FOR(i,N) IndexFromValue[P[i]] = i;
    for(int i=N;i>=1 && K > 0;i--){
        int bestPos = N - i;
        if(bestPos == IndexFromValue[i]) continue;
        int p = IndexFromValue[i];
        swap(IndexFromValue[i], IndexFromValue[P[bestPos]]);
        swap(P[bestPos], P[p]);
        
        K--;
    }
    FOR(i,N) printf("%s%d", i?" ":"", P[i]);
    return 0;
}
