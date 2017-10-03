#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int node,edge;
    cin>>node>>edge;
    std::vector< vector<int> > v(node);
    for(int i=0;i<edge;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    stack<int> s;
    vector<bool> visit(node,false);
    s.push(0);
    visit[0]=true;
    while(!s.empty())
    {
    	int Node = s.top();
    	s.pop();
    	for(int i=0;i<v[Node].size();i++)
    	{
    		if(visit[v[Node][i]]==false)
    		{
    			s.push(v[Node][i]);
    			visit[v[Node][i]]=true;
    		}
    	}
    	cout<<Node<<"->> "; 
    }
    cout<<endl;
	return 0;
}