
#include <bits/stdc++.h>
using namespace std;
void bfs(int s,vector< vector< pair<int,int> > > &v,vector<bool> &visit,vector<int> &dis)
{
    queue<int> q;
    q.push(s);
    visit[s]=true;
    dis[s]=0;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        for(int i=0;i<v[n].size();i++)
        {
            if(visit[v[n][i].first]==false)
            {
                q.push(v[n][i].first);
                visit[v[n][i].first]=true;
                dis[v[n][i].first]=dis[n]+v[n][i].second;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
      int n;
      cin>>n;
      std::vector< vector< pair<int,int> > > v(100001);
      std::vector<bool> visit(100001,false);
      std::vector<int> dis(100001,0);
      for(int i=1;i<n;i++)
      {
        int x,y,w;
        cin>>x>>y>>w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
      }
      bfs(1,v,visit,dis);
      int m_l=-1,m_d=-1;
      for(int i=1;i<=n;i++)
      {
        if(dis[i]>m_d)
        {
          m_d =dis[i];
          m_l =i;
        }
        dis[i]=0;
        visit[i]=false;
      }
      bfs(m_l,v,visit,dis);
      int d =*max_element(dis.begin(),dis.end()),c;
      if(d<=100)
      c=0;
      else
      if(d>10000)
      c=10000;
      else
      if(d>1000)
      c=1000;
      else
      if(d>100)
      c=100;
      cout<<c<<" "<<d<<endl;
    }
    return 0;
}
