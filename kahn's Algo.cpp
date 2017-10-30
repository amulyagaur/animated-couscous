#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > v(100000);
vector<bool> visit(100000,false);
vector<int> TS;
vector<int> in_degree(100000,0);

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
      in_degree[y]++;
    }
    multiset<int> ms;
    for(int i=1;i<=n;i++)
    {
      if(in_degree[i]==0)
      {
        visit[i]=true;
        ms.insert(i);
      }
    }
    while (!ms.empty()) {
      int node = *ms.begin();
      ms.erase(ms.begin());
      TS.push_back(node);
      for(int i=0;i<v[node].size();i++)
      {
        if(visit[v[node][i]]==false)
        {
          in_degree[v[node][i]]--;
          if(in_degree[v[node][i]]==0)
          {
            ms.insert(v[node][i]);
            visit[v[node][i]]=true;
          }
        }
      }
    }
    if(TS.size()!=n)
    cout<<"Sandro fails."<<endl;
    else
    {
    for(int i=0;i<TS.size();i++)
    cout<<TS[i]<<" ";
    cout<<endl;
  }
    return 0;
}
