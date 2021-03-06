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

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vector<lli>V[101];
lli Graph[101][101];
bool visited[101];
vlli V1,V2;

void dfs(lli x)
{
    visited[x]=1;
    V1.pb(x);
    V2.pb(x);

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

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,N1,i,j;
        cin>>N;

        N1=N;
        lli Sum=0;

        lli cnt=0;

        while(N1--)
        {
            lli x,y,w;
            cin>>x>>y>>w;

            Graph[x][y]=w;
            Sum+=w;

            if(x==1 or y==1)
            {
                cnt++;

                if(cnt==2)
                {
                    continue;
                }
            }
            V[x].pb(y);
            V[y].pb(x);

        }

        cout<<"Case "<<t++<<": ";

        /*rep(i,1,N+1)
        {
            cout<<i<<' ';
            rep(j,0,V[i].sz())
            {
                cout<<V[i][j]<<' ';
            }
            nl;
        }*/


        dfs(1);

        lli Sum1=0;

        rep(i,1,V1.sz())
        {
            if(!Graph[V1[i]][V1[i-1]])
            {
                Sum1+=Graph[V1[i-1]][V1[i]];
            }
        }

        if(!Graph[V1[0]][V1.back()])
        {
            Sum1+=Graph[V1.back()][V1[0]];
        }

        cout<<min(Sum1,Sum-Sum1);
        nl;

        rep(i,1,N+1)
        {
            V[i].clear();
            visited[i]=0;
        }

        rep(i,0,N+1)
        {
            rep(j,0,N+1)
            {
                Graph[i][j]=0;
            }
        }

        V1.clear();
    }



 return 0;
}
