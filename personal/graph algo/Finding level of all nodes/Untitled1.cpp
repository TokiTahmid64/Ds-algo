#include<bits/stdc++.h>
using namespace std;

vector<int>v[100];
queue<int>q;

int main()
{
   int node,edge,x,y;
   cin>>node>>edge;
   int visited[node+1];
   int level[node+1];
   for(int i=1;i<=node;i++)
   {
       visited[i]=0;
       level[i]=0;
   }
   for(int i=0;i<edge;i++)
   {
       cin>>x>>y;
       v[x].push_back(y);
       v[y].push_back(x);
   }
   int start,end_;
   //cin>>start>>end_;
   start=1;
   end_=node;

   visited[start]=1;
   level[start]=0;
   q.push(start);


   while(!q.empty())
   {
       int p=q.front();
       q.pop();
       for(int i=0;i<v[p].size();i++)
       {
           if(visited[ v[p][i] ]==0 )
           {
               q.push( v[p][i] );
               visited[ v[p][i] ]=1;
               level[ v[p][i] ]=level[p]+1;
           }
       }
   }

   cout<<"Level of node "<<end_<<": "<<level[end_]<<endl;

  //for(int i=1;i<=node;i++)
    //cout<<"Level of node "<<i<<": "<<level[i]<<endl;





}
