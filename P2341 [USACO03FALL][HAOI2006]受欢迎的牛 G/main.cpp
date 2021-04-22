//
//  main.cpp
//  P2341 [USACO03FALL][HAOI2006]受欢迎的牛 G
//
//  Created by 李行之 on 2021/3/6.
//

#include <bits/stdc++.h>
using namespace std;
int n,m,num,cnt;
int dfn[500004],low[500004],ins[500004],c[500004];
vector<int>edge[500004],scc[500004];
stack<int>s;
void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    s.push(x);
    ins[x]=1;
    for(int i=0;i<=edge[x].size();i++)
    {
        if(!dfn[edge[x][i]])
        {
            tarjan(edge[x][i]);
            low[x]=min(low[x],low[edge[x][i]]);
        }
        else if(ins[edge[x][i]])
        {
            low[x]=min(low[x],dfn[edge[x][i]]);
        }
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        int y;
        do
        {
            y=s.top();
            s.pop();
            ins[y]=0;
            c[y]=cnt;
            scc[cnt].push_back(y);
        }while(x!=y);
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])tarjan(i);
    }
    cout<<cnt<<endl;
    return 0;
}
