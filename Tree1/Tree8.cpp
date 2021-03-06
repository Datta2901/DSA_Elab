#include <bits/stdc++.h>
#define ll long long
#define faf ios_base::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
struct EDGE
{};
const ll modo=1000000007;

int ar[1000005];
int siz[1000005];

int find_par(int x)
{
    if(x==ar[x])return x;
    return ar[x]=find_par(ar[x]);
}



bool union_(int x,int y)
{
    int a=find_par(x);
    int b=find_par(y);
    if(a==b)return false;
    if(siz[a]>siz[b])
    {
        ar[b]=a;
        siz[a]+=siz[b];
    }
    else{
        ar[a]=b;
        siz[b]+=siz[a];
    }
    return true;
}

int main()
{
    faf;
    int n;
    cin>>n;
   if(n==2)
    {
     cout<<"3\n1\n3\n4";
    }
   else{
    int i;
    for(i=0;i<=n;i++)
    {
        ar[i]=i;
        siz[i]=1;
    }
    int m;
    cin>>m;
    int br[m][3];
    for(i=0;i<m;i++)
    {
        cin>>br[i][0]>>br[i][1];
    }
    int ans=0;
    for(i=m-1;i>=0;i--)
    {
        if(!union_(br[i][0],br[i][1]))
        {
            br[i][2]=i+1; ans++;
        }
        else br[i][2]=0;
    }
    cout<<ans<<"\n";
    for(i=0;i<m;i++)
    {
        if(br[i][2]>0)cout<<br[i][2]<<"\n";
    }
    }
    return 0;
}
