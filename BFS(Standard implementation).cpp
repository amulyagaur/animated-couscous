#include <bits/stdc++.h>
using namespace std;
void bfs(int s,vector< vector<int> > &v,vector<bool> &visit,vector<int> &dis)
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
            if(visit[v[n][i]]==false)
            {
                q.push(v[n][i]);
                visit[v[n][i]]=true;
                dis[v[n][i]]=dis[n]+1;
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
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector< vector<int> > v(n+1);
        vector<bool> visit(n+1,false);
        vector<int> dis(n+1,0);
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        bfs(1,v,visit,dis);
        cout<<dis[n]<<endl;
    }
    return 0;
}
