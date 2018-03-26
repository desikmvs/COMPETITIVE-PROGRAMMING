/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li      int32_t
#define lli     long long
#define ulli unsigned long long

#define pn          printf("\n")
#define nl          cout<<'\n'
#define sf(N)       scanf("%lld",&N)
#define pf(N)       printf("%lld",N)

#define rep(i,a,b)  for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define elif        else if
#define mset(a,b)   memset(a,b,sizeof(a))

#define pb      push_back
#define pob     pop_back
#define itr     iterator
#define sz()    size()
#define szof    sizeof
#define lb      lower_bound
#define ub      upper_bound
#define mp      make_pair
#define vlli    vector<lli>
#define plli    pair<lli,lli>
#define vplli   vector<plli >
#define Frst    first
#define Sec     second

#define Inf     100000000000
#define mod     1000000007
using namespace std;

vector<lli>V[10001];
bool visited[10001];
stack<lli>S;
lli N;

void Toposort(lli x)
{
    visited[x]=1;

    lli i;

    rep(i,0,V[x].sz())
    {
        if(!visited[V[x][i]])
        {
            Toposort(V[x][i]);
        }
    }

    S.push(x);
}

void dfs(lli x)
{
    visited[x]=1;

    lli i;

    rep(i,0,V[x].sz())
    {
        if(!visited[V[x][i]])
        {
            dfs(V[x][i]);
        }
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

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli M,i;
        cin>>N>>M;

        while(M--)
        {
           lli x,y;
           cin>>x>>y;

           V[x].pb(y);
        }

        rep(i,1,N+1)
        {
            if(!visited[i])
            {
                Toposort(i);
            }
        }

        memset(visited,0,szof(visited));

        lli cnt=0;

        while(!S.empty())
        {
            lli x=S.top();

            if(!visited[x])
            {
                dfs(S.top());
                cnt++;
            }

            S.pop();
        }

        cout<<"Case "<<t++<<": ";
        cout<<cnt;
        nl;

        rep(i,1,N+1)
        {
            V[i].clear();
            visited[i]=0;
        }
}




 return 0;
}
