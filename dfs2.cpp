#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector< vector<int> > v(100);
vector<bool> visited(100,false);
void dfs(int start)
{
	visited[start]=true;
	//cout<<start<<" ->";									uncomment this for printing the output of dfs ;)
	for(int i=0;i<v[start].size();i++)
	{
		if(visited[v[start][i]]==false)
		{
			dfs(v[start][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
    	int x,y;
    	cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    for(int i=1;i<=node;i++)
    {
    	cout<<i<<" ->> ";
    	for(int j=0;j<v[i].size();j++)
    		cout<<v[i][j]<<" ";
    	cout<<endl;
    }
    int c=0;
    for(int i=1;i<=node;i++)
    {
    	if(visited[i]==false)
    	{
    		dfs(i);
    		c++;
    	}
    }
    cout<<"No. of connected components are"<<c<<endl;
	return 0;
}