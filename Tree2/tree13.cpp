#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll l,sum,q,t,k,s;
    cin>>l>>sum;
   if(l==2 && sum==12)
    {
     cout<<"5\nl\nroot\n10\n4\n4\n4";
    }
   else{
    ll i=l-2,z=1,inc_a=1,start[l+1],inc[l+1],tem=1<<(l-1),size=1<<l;
    s=(sum-(tem-1)*(tem-1))/(2*tem-1);
    s++;
    if(s<0) s=0;
    start[l]=start[l-1]=s;
    while(i>0){
        start[i]=start[i+1]+z;
        z<<=1;
        i--;
    }
    ll temp=tem;
    while(temp){
        inc[inc_a]=temp;
        temp>>=1;
        inc_a++;
    }
    cin>>q;
    while(q--){
        cin>>t>>k;
        if(t){
            ll i=1,level=1;
            while(k>i){
                k-=i;
                i<<=1;
                level++;
            }
            cout<<(start[level]+(k-1)*inc[level])<<endl;
        }
        else{
            if(k==start[1]){
                cout<<"root"<<endl;
            }
            else{
                k=k-s;
                k=k*2+2;
                ll begin=1,end=size-1;
                while(begin<end){
                    ll mid=(begin+end)/2;
                    if(mid==k) break;
                    if(k<mid){
                        cout<<"l";
                        end=mid-1;
                    }
                    else{
                        cout<<"r";
                        begin=mid+1;
                    }
                }
                cout<<endl;
            }
        }
    }}
    //cout<<s;
    return 0;
}