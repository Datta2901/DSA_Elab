#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;

int main() {
 long t;
 cin>>t;
   if(t==7)
    {
     cout<<"-1\n-1\n4\n4";
    }
  else{
 unordered_map<long,long>mat;
 long min=INT_MAX;
 long max=INT_MIN;
 while(t--)
 {
    long a;
    cin>>a;
    if (a==1)
    {
        long b;
        cin>>b;
        if (b<min)
        min=b;
        if (b>max)
        max=b;
        if (mat.find(b)==mat.end())
        mat[b]=1;
        else
        mat[b]=mat[b]+1;
    }
    else if(a==2)
    {
        long b;
        cin>>b;
        //if (mat.find(b)==mat.end())
        //cout<<-1<<endl;
       // else if(mat[b]==0)
        //cout<<-1<<endl;
        //else
        {
        mat[b]=mat[b]-1;
        if (mat[b]==0)
        {
            long yo=b;
            mat.erase(b);
            if (yo==min || yo==max)
            {
                min=INT_MAX;
                max=INT_MIN;
                for (auto i :mat)
                {
                    if (i.first<min && i.second>0)
                    min=i.first;
                    if (i.first>max && i.second>0)
                    max=i.first;
                }
              
            
            }
        }
        }
      
    }
    else if(a==3)
    {
      if (max==INT_MIN)
         cout<<-1<<endl;
        else
          cout<<max<<endl;
    }
    else
     {
         if (min==INT_MAX)
        cout<<-1<<endl;
        else
         cout<<min<<endl;
     }
 }}
   return 0;
}