//Implementation of 0-1 BFS
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int node,edge;
    cin>>node>>edge;
    std::vector< vector< pair<int,int> > > v(node);
    for(int i=0;i<edge;i++)
    {
    	int x,y,w;
    	cin>>x>>y>>w;
    	v[x].push_back(make_pair(y,w));
    	v[y].push_back(make_pair(x,w));
    }
    
    deque<int> dq;
    vector<int> distance(node);
    for(int i=0;i<node;i++)
    	distance[i]=INT_MAX;
    distance[0]=0;
    dq.push_back(0);
    while(!dq.empty())
    {
    	int Node=dq.front();
    	dq.pop_front();
    	cout<<Node<<endl;
    	for(int i=0;i<v[Node].size();i++)
    	{
    		if(distance[v[Node][i].first]>distance[Node]+v[Node][i].second)
    		{
    			distance[v[Node][i].first]=distance[Node]+v[Node][i].second;
    		if(v[Node][i].second==0)
    			dq.push_front(v[Node][i].first) ;
    		else
    			dq.push_back(v[Node][i].first);
    		}	
    			
    	}
    }
    //printing distance
    for(int i=0;i<node;i++)
    	cout<<i<<" "<<distance[i]<<endl;
	return 0;

}
