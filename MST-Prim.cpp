#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector< vector< pair<int,int> > >v(100001);
vector<bool> visited(100001,false);
int prim(int s)
{
	priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > pq;
	pq.push(make_pair(0,s));
	long long min_cost =0;
	while(pq.empty()==false)
	{
		pair<int,int> p = pq.top();
		pq.pop();
		if(visited[p.second]==true)
		{
			continue;
		}
		visited[p.second]=true;
		min_cost+=p.first;
		for(int i=0;i<v[p.second].size();i++)
		{
			if(visited[v[p.second][i].second]==false)
				pq.push(v[p.second][i]);
		}
	}
	return min_cost;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
    	int x,y,w;
    	cin>>x>>y>>w;
    	v[x].push_back(make_pair(w,y));
    	v[y].push_back(make_pair(w,x));
    }
    cout<<prim(1)<<endl;
	return 0;
}
