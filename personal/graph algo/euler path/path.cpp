    #include<bits/stdc++.h>
    using namespace std;
    stack<int>s;
    vector<int>v[100];
    int p;
    void find_circuit(int u)
    {
        for(int i=0;i<v[u].size();)
        {
            p=v[u][i];
            v[u].erase(v[u].begin()+i);
           //p.erase(p.begin()+i);
            find_circuit(p);
        }
        s.push(u);
        //return;
    }
    int main()
    {

        int node,edge,x,y;
        cin>>node>>edge;
        int in[node+1];
        int out[node+1];

        for(int i=1;i<=node;i++)
        {
            in[i]=0;
            out[i]=0;
        }
        for(int i=0;i<edge;i++)
        {
            cin>>x>>y;
            v[x].push_back(y);
            out[x]++;
            in[y]++;
        }

        /*for(int i=1;i<=node;i++)
        {
            cout<<"Indegree of "<<i<<"="<<in[i]<<","<<"outdegree of "<<i<<"="<<out[i]<<endl;
        }*/
        int equal_degree=0,in_degree=0,out_degree=0;
        int out_node;
        for(int i=1;i<=node;i++)
        {
            if(in[i]==out[i])
                equal_degree++;
            else if(in[i]-out[i]==1)
                in_degree++;
            else if(out[i]-in[i]==1)
                {out_degree++;
                out_node=i;}
        }
        bool ache=true;
        if(out_degree==1 && in_degree==1 && equal_degree==(node-2))
            ache=true;

        if(ache)
        {
        find_circuit(out_node);
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }}

    }
