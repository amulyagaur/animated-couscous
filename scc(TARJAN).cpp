#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > v(100001);
vector<bool> visit(100001,false);
vector<int> disc(100001,-1);
vector<int> low(100001,0);
int ti=0,num=0;
stack<int> s;

void tarjan(int u)
{
  disc[u]=low[u]=(ti++);
  visit[u]=true;
  s.push(u);
  for(int i=0;i<v[u].size();i++)
  {
    if(disc[v[u][i]]==-1)
    tarjan(v[u][i]);
    if(visit[v[u][i]]==true)
    low[u]=min(low[u],low[v[u][i]]);
  }
  if(disc[u]==low[u])
  {
    num++;
    while(1)
    {
      int vv = s.top();
      s.pop();
      visit[vv]=false;
      //cout<<vv<<" ";
      if(vv==u)
      break;
    }
    //cout<<endl;
  }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    while(m--)
    {
      int x,y;
      cin>>x>>y;
      v[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
      if(disc[i]==-1)
      tarjan(i);
    }
    cout<<num<<endl;
    return 0;
}
