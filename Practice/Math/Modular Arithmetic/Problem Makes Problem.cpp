/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			printf("\n")
#define nl			cout<<'\n'
#define sf(N)       scanf("%lld",&N)
#define pf(N)       printf("%lld",N)

#define rep(i,a,b)	for(i=a;i<b;i++)
#define repr(i,a,b)	for(i=a;i>b;i--)
#define elif		else if
#define mset(a,b)	memset(a,b,sizeof(a))

#define pb		push_back
#define pob		pop_back
#define itr		iterator
#define sz()	size()
#define szof    sizeof
#define lb		lower_bound
#define ub		upper_bound
#define mp		make_pair
#define vlli    vector<lli>
#define plli	pair<lli,lli>
#define vplli	vector<plli >
#define Frst	first
#define Sec		second

#define Inf     100000000000
#define mod		1000000007
using namespace std;

lli Factorial[2000001];

void Solve()
{
    lli i;

    Factorial[0]=1;
    Factorial[1]=1;

    rep(i,2,2000001)
    {
        Factorial[i]=(Factorial[i-1]*i)%mod;
    }
}

lli Power(lli a,lli b)
{
    lli result=1;

    while(b)
    {
        if(b%2)
        {
            result=(result*a)%mod;
        }

        b=b>>1;
        a=(a*a)%mod;
    }

 return result;
 }

int main()
{
    opt;

    Solve();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,K;
        cin>>N>>K;

        cout<<"Case "<<t++<<": ";

        lli Val=(Factorial[N]*Factorial[K-1])%mod;
        cout<<(Factorial[N+K-1]*Power(Val,mod-2))%mod;

        nl;
    }





 return 0;
}
