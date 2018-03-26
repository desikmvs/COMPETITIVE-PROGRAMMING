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
#define sf2(N1,N2)       scanf("%lld %lld",&N1,&N2)
#define pf2(N1,N2)       printf("%lld %lld",N1,N2)
#define sf3(N1,N2,N3)   scanf("%lld %lld %lld",&N1,&N2,&N3)
#define pf3(N1,N2,N3)       printf("%lld %lld %lld",N1,N2,N3)

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
#define F   	first
#define Sec		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     100000000
#define mod		1000000007
using namespace std;

int phi[1005001];
int Store[1005001];

void PreCompute()
{
    lli N=1005001;

    lli i,j;

    for(i=1;i<=N;i++)
    {
        phi[i]=i;
    }

    phi[1]=1;
    phi[2]=1;

    for(i=2*2;i<=N;i+=2)
    {
        phi[i]/=2;
    }

    for(i=3;i<=N;i+=2)
    {
        if(phi[i]==i)
        {
            phi[i]--;

            for(j=2*i;j<=N;j+=i)
            {
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }

    /*cout<<phi[1000003];
    nl;*/
}

void PreCompute1()
{
    lli i;

    rep(i,1,1005001)
    {
        Store[i]=Inf;
    }

    for(i=2;i<=1005001;i++)
    {
        if(Store[phi[i]]!=Inf)
        {
            continue;
        }

        Store[phi[i]]=i;
    }
}

void PreCompute2()
{
    lli Currmax=Store[1005000],i;
    for(i=1005000;i>=1;i--)
    {
        Store[i]=min(Store[i],Currmax);
        Currmax=Store[i];
    }
}

lli Power(lli a,lli b)
{
    lli result=1;

    while(b)
    {
        if(b%2)
        {
            result=(result*a);
        }

        b=b>>1;
        a=(a*a);
    }

 return result;
}

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("Bishoe_and_Phishoe.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    PreCompute();

    PreCompute1();

    PreCompute2();

    lli T,t=1;
    scanf("%d",&T);

    while(T--)
    {
        lli N,i;
        scanf("%d",&N);

        long long Sum=0;
        rep(i,0,N)
        {
            lli x;
            scanf("%d",&x);

            Sum+=Store[x];
        }

        printf("Case %d: %lld Xukha\n",t++,Sum);
    }




 return 0;
}
