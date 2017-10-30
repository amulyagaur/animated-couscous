#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, pair<int,int> > &a,const pair<int, pair<int,int> > &b)
{
    if(a.first < b.first)
    return true;
    if(a.first == b.first)
    return (a.second.first>b.second.first);
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue< pair<int, pair<int,int> >,vector< pair<int, pair<int,int> > >, std::function<bool(pair<int, pair<int,int> > ,pair<int, pair<int,int> > )>  > pq(cmp);
    
    
    while(!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
        pq.pop();
    }
    return 0;
}
