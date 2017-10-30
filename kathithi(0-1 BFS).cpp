#include <bits/stdc++.h>
using namespace std;
int dis[1001][1001];
int r,c;
bool bounds(int x,int y)
{
  if(x<0 || x>=r || y<0 || y>=c)
  return false;
  return true;
}
void bfs(vector<string> &v)
{
  deque< pair<int,int> > dq;
  dq.push_front(make_pair(0,0));
  dis[0][0]=0;
  while(!dq.empty())
  {
    pair<int,int> p=dq.front();
    dq.pop_front();
    int x= p.first,y=p.second;

    if(bounds(x+1,y))
    {
      if(v[x+1][y]==v[x][y] )
      {

        if(dis[x+1][y]>dis[x][y])
        {
          dis[x+1][y]=dis[x][y];
          dq.push_front(make_pair(x+1,y));
        }

      }
      else
      {


        if(dis[x+1][y]>dis[x][y]+1)
        {
        dis[x+1][y]=dis[x][y]+1;
        dq.push_back(make_pair(x+1,y));
      }
      }
    }

    if(bounds(x-1,y))
    {
      if(v[x-1][y]==v[x][y] )
      {

        if(dis[x-1][y]>dis[x][y])
        {
          dis[x-1][y]=dis[x][y];
          dq.push_front(make_pair(x-1,y));
        }

      }
      else
      {


        if(dis[x-1][y]>dis[x][y]+1)
        {
        dis[x-1][y]=dis[x][y]+1;
        dq.push_back(make_pair(x-1,y));
      }
      }
    }

    if(bounds(x,y+1))
    {
      if(v[x][y+1]==v[x][y] )
      {

        if(dis[x][y+1]>dis[x][y])
        {
          dis[x][y+1]=dis[x][y];
          dq.push_front(make_pair(x,y+1));
        }

      }
      else
      {


        if(dis[x][y+1]>dis[x][y]+1)
        {
        dis[x][y+1]=dis[x][y]+1;
        dq.push_back(make_pair(x,y+1));
      }
      }
    }

    if(bounds(x,y-1))
    {
      if(v[x][y-1]==v[x][y] )
      {

        if(dis[x][y-1]>dis[x][y])
        {
          dis[x][y-1]=dis[x][y];
          dq.push_front(make_pair(x,y-1));
        }

      }
      else
      {


        if(dis[x][y-1]>dis[x][y]+1)
        {
        dis[x][y-1]=dis[x][y]+1;
        dq.push_back(make_pair(x,y-1));
      }
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
      cin>>r>>c;
      vector<string> v(r);
      for(int i=0;i<r;i++)
      cin>>v[i];
      for(int i=0;i<=1000;i++)
      {
        for(int j=0;j<=1000;j++)
        {
          dis[i][j]=INT_MAX;
        }
      }
      bfs(v);
      cout<<dis[r-1][c-1]<<endl;
    }
    return 0;
}
