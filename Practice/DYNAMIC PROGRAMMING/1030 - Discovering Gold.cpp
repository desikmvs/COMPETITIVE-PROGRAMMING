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
#define sl          cout<<' '
#define ps          printf(" ")

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
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

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

    /*#ifndef ONLINE_JUDGE
    freopen("Discovering_Gold.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,j;
        cin>>N;

        vlli V(N+1);
        vlli dp(N+1);
        vlli dp1(N+1);

        rep(i,1,N+1)
        {
            cin>>V[i];
            dp[i]=0;
        }

        cout<<"Case "<<t++<<": ";

        dp1[0]=0;
        dp1[1]=1;

        rep(i,2,N+1)
        {
            lli x=max(i-7LL,0LL);
            repr(j,i-1,x)
            {
                dp1[i]+=dp1[j];
            }
        }

        dp[1]=V[1];
        rep(i,2,N+1)
        {
            lli x=max(i-7LL,0LL);
            repr(j,i-1,x)
            {
                dp[i]+=dp[j];
            }
            dp[i]+=dp1[i]*V[i];
        }

        cout<<setprecision(10)<<fixed<<(dp[N]*1.0)/(dp1[N]);
        nl;
    }



 return 0;
}
