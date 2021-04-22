//
//  main.cpp
//  C_Coding3
//
//  Created by 李行之 on 2021/3/6.
//

#include<bits/stdc++.h>
using namespace std;
int ex[500005];
int lst[500005],cnt[500005];
int n,a;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>lst[i];
        cnt[lst[i]]++;
        int cc=0,now=0;
        while(now<=500000)
        {
            cc++;
            now=lst[i]*cc;
            ex[now]++;
        }
        
    }
    for(int i=1;i<=n;i++)
    {
        
        
        a+=ex[lst[i]]-cnt[lst[i]];
    }
    cout<<a;
    
}
