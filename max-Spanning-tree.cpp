#include <bits/stdc++.h>
using namespace std;
int prim(int s,vector<bool> &visited,vector< vector< pair<int,int> > > &v)
{
	priority_queue< pair<int,int> > pq;
	pq.push(make_pair(0,s));
	long long max_cost =0;
	while(pq.empty()==false)
	{
		pair<int,int> p = pq.top();
		pq.pop();
		if(visited[p.second]==true)
		{
			continue;
		}
		visited[p.second]=true;
		max_cost+=p.first;
		for(int i=0;i<v[p.second].size();i++)
		{
			if(visited[v[p.second][i].second]==false)
				pq.push(v[p.second][i]);
		}
	}
	return max_cost;
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
      vector< vector< pair<int,int> > > v(5001);
      vector<bool> visited(5001,false);
      while(m--)
      {
        int x,y,w;
        cin>>x>>y>>w;
        v[x].push_back(make_pair(w,y));
        v[y].push_back(make_pair(w,x));
      }
      cout<<prim(1,visited,v)<<endl;
    }
    return 0;
}
