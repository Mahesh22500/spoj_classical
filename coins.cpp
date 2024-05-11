#include<bits/stdc++.h>
using namespace std;


int main(){


int n;
cin>>n;

map<int,int>mp;


function<int(int)> solve=[&](int n){

    if(n==1)
    return 1;

    if(n==2)
    return 2;

    if(n==3)
    return 3;

    if(n==4)
    return 4;

    if(mp[n])
    return mp[n];

    int op1=solve(n/2)+solve(n/3)+solve(n/4);
    return mp[n]=max(n,op1);
};



int ans=solve(n);
cout<<ans<<"\n";


}