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
#define F   	first
#define S		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vector<lli,plli >V[201];
vector<lli,plli >V1[201];

lli Prim()
{
    multiset<plli >M;

    M.insert({0,1});

    plli p=*M.begin();
    lli x=p.F,y=p.S;


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

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T;
    cin>>T;

    while(T--)
    {
        lli N,M,i;
        cin>>N>>M;

        lli cnt=0;

        while(M--)
        {
            lli x,y,w;
            cin>>x>>y>>w;

            V[x].pb(mp(y,w));
            V[y].pb(mp(x,w));

            if(!visited[x])
            {
                visited[x]=1;
                cnt++;
            }

            if(!visited[y])
            {
                visited[y]=1;
                cnt++;
            }

            if(cnt==N)
            {
                cout<<Prim();
                cnt++;
            }
            elif(cnt>N)
            {
                cout<<Prim1();
            }
            else
            {
                cout<<-1;
            }
            nl;
        }


    }




 return 0;
}
