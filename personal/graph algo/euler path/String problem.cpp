        #include<bits/stdc++.h>
        using namespace std;



        stack<int>st;
        vector<int>v[26];
        vector< pair<int,string> >nodes[26];
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
            st.push(u);
            //return;
        }


        int main()
        {


            for(int i=0;i<26;i++)
            {
                v[i].clear();
                nodes[i].clear();
            }

            int in[26];
            int out[26];

            for(int i=0;i<26;i++)
            {
                in[i]=0;
                out[i]=0;
            }
            int t;
            cin>>t;
            for(int test=1;test<=t;test++){

            int n;
            cin>>n;
            string s;
            int l;
            char c1,c2;
            int i1,i2;
            for(int i=0;i<n;i++)
            {
                cin>>s;
               // given.push_back(s);
                l=s.size()-1;
                c1=s[0];
                c2=s[l];
                i1=c1-'a';
                i2=c2-'a';
                nodes[i1].push_back(make_pair(i2,s));
                v[i1].push_back(i2);
                out[i1]++;
                in[i2]++;



            }

            int equal_degree=0,in_degree=0,out_degree=0;
            int out_node;
            for(int i=0;i<26;i++)
            {
                if(in[i]==out[i])
                    equal_degree++;
                else if(in[i]-out[i]==1)
                    in_degree++;
                else if(out[i]-in[i]==1)
                    {out_degree++;
                    out_node=i;}
            }


            cout<<"Case "<<test<<": ";
            bool ache=false;
            if(out_degree==1 && in_degree==1 && equal_degree==(24))
                ache=true;

            vector<int>solve;
            if(ache)
            {
                cout<<"Yes"<<endl;

            find_circuit(out_node);
            int a;
            while(!st.empty())
            {
                a=st.top();
                //cout<<(char)('a'+a)<<" ";
                st.pop();
                solve.push_back(a);

               // cout<< nodes[solve[i]][solve[i+1]].first<<" ";
            }
            int j;
            for(int i=0;i<solve.size()-1;i++)
            {

                for(int j=0;j<  nodes[ solve[i] ].size() ;j++)
                {
                    if(j==(nodes[ solve[i] ].size())-1){

                    if( nodes[ solve[i] ][j].first == solve[i+1] )
                    {
                        cout<<nodes[ solve[i] ][j].second<<" ";
                    }
                    }
                    else
                    {
                        if( nodes[ solve[i] ][j].first == solve[i+1] )
                    {
                        cout<<nodes[ solve[i] ][j].second;
                    }
                    }

                }
            }
            cout<<endl;
            }
            else
                cout<<"No"<<endl;







            }


        }
