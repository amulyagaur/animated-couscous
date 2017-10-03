// implementation of Dijkstra algorithm using multi set(Same as min priority queue)
#include <bits/stdc++.h>
using namespace std;
void djikstra(vector< vector< pair<int,int> > > &v,vector<bool> &visit,vector<int> &distance)
{
  multiset< pair<int,int> > s;
  s.insert(make_pair(0,1));
  distance[1]=0;
  while(!s.empty())
  {
    pair<int,int> p=*s.begin();
    int node=p.second;
    int weight = p.first;
    s.erase(s.begin());
    if(visit[node]==true)
    continue;
    visit[node]=true;
    for(int i=0;i<v[node].size();i++)
    {
      if(distance[v[node][i].second]> distance[node]+v[node][i].first)
      {
        distance[v[node][i].second]= distance[node]+v[node][i].first;
        s.insert(make_pair(distance[v[node][i].second],v[node][i].second));
      }
    }
  }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector< vector< pair<int,int> > > v(10001);
    vector<bool> visit(10001,false);
    vector<int> distance(10001,INT_MAX);
    while(m--)
    {
      int x,y,w;
      cin>>x>>y>>w;
      v[x].push_back(make_pair(w,y));
      v[y].push_back(make_pair(w,x));
    }
    djikstra(v,visit,distance);
    for(int i=2;i<=n;i++)
    cout<<distance[i]<<" ";
    return 0;
}
