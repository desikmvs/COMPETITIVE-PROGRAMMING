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
        lli N,i;
        cin>>N;

        vlli V(N);

        rep(i,0,N)
        {
            cin>>V[i];
        }

        cout<<"Case "<<t++<<": ";
        if(!(N-1))
        {
            cout<<V[0];
            nl;

            continue;
        }

        sort(V.begin(),V.end());

        lli Maximum=V[0];
        rep(i,1,N)
        {
            Maximum=max(Maximum,V[i]-V[i-1]);
        }

        I flag=1;
        lli Maximum1=Maximum;

        rep(i,1,N)
        {
            if(Maximum1==V[i]-V[i-1])
            {
                Maximum1--;
            }
            elif(Maximum1<V[i]-V[i-1])
            {
                flag=0;
            }
        }

        if(flag)
        {
            cout<<Maximum;
        }
        else
        {
            cout<<Maximum+1;
        }
        nl;
    }



 return 0;
}
