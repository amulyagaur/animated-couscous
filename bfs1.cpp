//adjacency list representation of graph
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	int node,edge,s;
    cin>>node>>edge;
    std::vector< vector<int> > v(1001);
    for(int i=0;i<edge;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    /*
    for(int i=0;i<node;i++)
    {
    	cout<<i<<"->>> ";
    	for(int j=0;j<v[i].size();j++)
    	{
    		cout<<v[i][j]<<" ";
    	}
    	cout<<endl;
    }
    */
    cin>>s;
    //Code for Breadth First Search in Undirected Graph  ********************
    

    queue<int> q;
    q.push(s);
    bool visit[1001];
    vector<int> distance(1001,0);
    vector<int> parent(1001,0);
    parent[s]=-1;                                            //******** No parent for root
    for(int i=1;i<=node;i++)
    	visit[i]=false;
    visit[s]=true;
    while(!q.empty())
    {
    	int Node=q.front();
    	q.pop();
    	for(int i=0;i<v[Node].size();i++)
    	{
    		if(visit[v[Node][i]]==false)
    		{
    			q.push(v[Node][i]);
    			visit[v[Node][i]]=true;
    			distance[v[Node][i]]=distance[Node]+6;	
    			parent[v[Node][i]]=Node;
    		}
    	}
    	//cout<<Node<<" ->";
    }
    //cout<<endl;
    for(int i=1;i<=node;i++)
    	if(i!=s)
    	{
    	if(distance[i]!=0 )
    	cout<<distance[i]<<" ";
    else
    	cout<<-1<<" ";
}
cout<<endl;
    }
    
    //************_______________********************
	return 0;
}