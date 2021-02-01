#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
bool visited[5][5];
int fx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int fy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<pair
void dfs(pii s)
{
    visited[s]=true;
    for(int i=0;i<v[s].size();i++)
    {
        if(visited [ v[s][i] ]==false)
            //dfs( v[s][i] );
    }
}
int main()
{

    int mat[5][5] ={{1, 1, 0, 0, 0},
               {0, 1, 0, 0, 1},
               {1, 0, 0, 1, 1},
               {0, 0, 0, 0, 0},
               {1, 0, 1, 0, 1}};

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            visited[i][j]=false;
    }






}
