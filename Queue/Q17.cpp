// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std;

// int main(){


//     return 0;
// }
// find the maximum and minimum sum of the subarray having the sizek;
#include <iostream>
#include <deque>
using namespace std;
int SumOfKsubArray(int arr[] , int n , int k)
{
    int sum=0;
    deque<int> S(k),G(k);
    int i=0;
    for(i=0;i<k;i++)
    {
        while((!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back();
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back();
        G.push_back(i);
        S.push_back(i);
    }
    for (;i<n;i++)
    {
        sum+=arr[S.front()]+arr[G.front()];
        while(!S.empty() && S.front()<=i-k)
            S.pop_front();
        while(!G.empty() && G.front()<=i-k)
            G.pop_front();
        while((!S.empty()) && arr[S.back()]>=arr[i])
            S.pop_back();
        while((!G.empty()) && arr[G.back()]<=arr[i])
            G.pop_back();
        G.push_back(i);
        S.push_back(i);
    }
    sum+=arr[S.front()]+arr[G.front()];
    return sum;
}

int main()
{
    int arr[100],n,k;
   cin>>n;
   for(int i=0;i<n;i++)
       cin>>arr[i];
    cin>>k;
    cout<<SumOfKsubArray(arr,n,k) ;
    return 0;
} 