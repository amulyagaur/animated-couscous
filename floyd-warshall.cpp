#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,m;
    cin>>n>>m;
    long long int adj_m[n+1][n+1];
    for(long long int i=1;i<=n;i++)
      for(long long int j=1;j<=n;j++)
      {
        //if(i==j)
      //  adj_m[i][j]=0;
      //  else
        adj_m[i][j]=INT_MAX;
      }

    while(m--)
    {
      int x,y,w;
      cin>>x>>y>>w;
      adj_m[x][y]=min(adj_m[x][y],w);
      adj_m[y][x]=adj_m[x][y];
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      cout<<adj_m[i][j]<<" ";
      cout<<endl;
    }
    cout<<endl;
    // Floyd Warshell algorithm starts.....***************............
    long long  dist[n+1][n+1];
    for(long long int i=1;i<=n;i++)
    {
      for(long long int j=1;j<=n;j++)
      {
        if(i==j)
        dist[i][j]=0;
        else
        dist[i][j]=adj_m[i][j];
      }
    }
    for(long long int k=1;k<=n;k++)
    {
      for(long long int i=1;i<=n;i++)
      {
        for(long long int j=1;j<=n;j++)
        {
          dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
      }
    }
    //printing min distance matrix.........*********>>>>>>>>>>>>>
    bool flag=false;                              //flag for checking negative cycle
    cout<<"The min distances are"<<endl;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      cout<<dist[i][j]<<" ";
      cout<<endl;
    }
    /*
    for(int i=1;i<=n;i++)
      if(dist[i][i]<0)
      flag=true;

    if(flag==true)
    cout<<"Negative cycle exists"<<endl;
    else
    cout<<"No negative cycle exists"<<endl;
    */
    return 0;
}
