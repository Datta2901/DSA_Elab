#include<bits/stdc++.h>
#define max 100001
using namespace std;

int q[max];
int size[max];
int root (int node);
int root(int x)
{
    while(x!=q[x])
    {
        q[x]=q[q[x]];
        x=q[x];
    }
    return x;
}

void connect(int u,int v)
{
    int rootu=root(u);
    int rootv=root(v);
    if(rootu==rootv)
    return;
    if(size[rootu]<size[rootv])
    {
        q[rootu]=rootv;
        size[rootv]+=size[rootu];
    }
    else
    {
        q[rootv]=rootu;
        size[rootu]+=size[rootv];
    }
}
int main()
{
    int n,m,u,v;
    set<int> s;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        q[i]=i;
        size[i]=1;
    }
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        connect(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        if(s.find(root(i))==s.end())
        {
            s.insert(root(i));
        }
    }
    cout<<s.size()<<endl;
   
}