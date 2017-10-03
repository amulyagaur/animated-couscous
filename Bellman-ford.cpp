#include <bits/stdc++.h>
using namespace std;
bool bellman_ford(vector< vector<int> > &v,vector<int> &dis,int n)
{
  dis[1]=0;
  bool neg_cycle=false;
  for(int i = 0; i < n - 1; i++){
        for(int j=0;j<v.size();j++)
        {
            if(dis[v[j][0]] + v[j][2] < dis[v[j][1]] )
                dis[v[j][1]] = dis[v[j][0]] + v[j][2];
        }
    }
    for(int j=0;j<v.size();j++)
    {
        if(dis[v[j][0]] + v[j][2] < dis[v[j][1]] && dis[v[j][j]]!=INT_MAX)
        neg_cycle=true;
            //dis[v[j][1]] = dis[v[j][0]] + v[j][2];
    }
    return neg_cycle;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
      int n,m;
      cin>>n>>m;
      vector< vector<int> > v(m);
      for(int i=0;i<m;i++)
      {
        int x,y,w;
        cin>>x>>y>>w;
        v[i].push_back(x);
        v[i].push_back(y);
        v[i].push_back(w);
      }
      vector<int> dis(n+1,INT_MAX);
      bool neg_cycle=bellman_ford(v,dis,n);
      //for(int i=1;i<=n;i++)
      //cout<<dis[i]<<" ";
      if(neg_cycle)
      cout<<"Yes"<<endl;
      else
      cout<<"No"<<endl;
    }

    return 0;
}
