#include<bits/stdc++.h>
using namespace std;
vector<int>v[100002];
bool visited[100002];
void dfs(int s)
{
    visited[s]=true;
    for(int i=0;i<v[s].size();i++)
    {
        if(visited[ v[s][i] ]==false )
            {
                dfs(v[s][i]);
            }
    }
}

int main()
{

    int node,edge,x,y,s;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>s;
    for(int i=0;i<=node;i++)
    {
        visited[i]=false;
    }
    dfs(s);
    int c=0;
    for(int i=1;i<=node;i++)
    {
        if(visited[i]==false)
            c++;
    }
    cout<<c;




}
