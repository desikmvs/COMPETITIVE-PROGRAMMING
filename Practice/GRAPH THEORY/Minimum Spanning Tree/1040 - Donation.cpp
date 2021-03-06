/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			printf("\n")
#define nl			cout<<'\n'

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

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vector<pair<lli,pair<lli,lli> > >V;
vector<lli>V1[51];
bool visited[51];
vlli id;
vlli Size;
lli N;
lli a[51][51];

void initialize()
{
    lli i;

    id.pb(0);
    Size.pb(1);

    rep(i,1,N+1)
    {
        id.pb(i);
        Size.pb(1);
    }
}

lli root(lli x)
{
    while(id[x]!=x)
    {
        x=id[id[x]];
    }

 return x;
}

void Union(lli x,lli y)
{
    lli p=root(x);
    lli q=root(y);

    if(Size[p]>Size[q])
    {
        id[q]=p;
        Size[p]+=Size[q];
    }
    else
    {
        id[p]=q;
        Size[q]+=Size[p];
    }
}

lli Kruskal()
{
    lli Cost=0;

    lli i;

    rep(i,0,V.sz())
    {
        lli w=V[i].F;
        lli x=V[i].S.F;
        lli y=V[i].S.S;

        if(root(x)!=root(y))
        {
            Cost+=w;
            Union(x,y);
        }
    }

 return Cost;
}

void dfs(lli x)
{
    visited[x]=1;

    lli i;

    rep(i,0,V1[x].sz())
    {
        if(!visited[V1[x][i]])
        {
            dfs(V1[x][i]);
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
        lli i,j;
        cin>>N;

        lli Sum=0;

        rep(i,1,N+1)
        {
            rep(j,1,N+1)
            {
                cin>>a[i][j];

                Sum+=a[i][j];

                if(i!=j)
                {
                    if(a[i][j])
                    V.pb(mp(a[i][j],mp(i,j))),V1[i].pb(j),V1[j].pb(i);
                }
            }
        }

        cout<<"Case "<<t++<<": ";

        I flag=1;
        dfs(1);

        rep(i,1,N+1)
        {
            if(!visited[i])
            {
                flag=0;
            }
        }

        if(flag)
        {
            sort(V.begin(),V.end());

            initialize();

            cout<<Sum-Kruskal();
        }
        else
        {
            cout<<"-1";
        }

        nl;

        V.clear();
        id.clear();
        Size.clear();

        rep(i,1,N+1)
        {
            V1[i].clear();
            visited[i]=0;
        }
    }



 return 0;
}
