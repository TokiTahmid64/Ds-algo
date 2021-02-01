        #include<bits/stdc++.h>
        #define pii pair<int,int>
        using namespace std;
        bool connected(string s,string t)
        {
            int c=0;
            if(s.size()!=t.size())
                return false;
            else{
                for(int k=0;k<s.size();k++)
                {
                    if(s[k]!=t[k])
                    {
                        c++;
                    }
                }
                if(c>1)
                    return false;
                else return true;
            }
        }
        int main()
        {
            int t;
            cin>>t;
            while(t--){
            vector<string>v;

           // vector<int>num;// this is for mapping with the dictionary
            string s;
            int i=1;
            while(1)
            {
                cin>>s;
                if(s.compare("*")==0)break;
                else
                {
                    v.push_back(s);
                    //num.push_back(i);
                    //i++;
                }

            }


            vector<int>edge[220];
            for(int i=0;i<=v.size();i++)
            {
                for(int j=i+1;j<v.size();j++)
                {
                    if(connected(v[i],v[j]))
                    {
                        edge[i].push_back(j);
                        edge[j].push_back(i);
                    }
                }
            }


            string start,end_;
            int s_,e;
            while(cin>>start>>end_){
           // cin>>start>>end_;
            for(int i=0;i<v.size();i++)
            {
                if(v[i].compare(start)==0)
                {
                    s_=i;
                    break;
                }
            }

            queue<int>q;
           // cout<<v.size()<<endl;
            bool visited[v.size()];
            int level[v.size()];
            for(int i=0;i<=v.size();i++)
            {
                visited[i]=false;
                level[i]=0;
            }

            q.push(s_);
            visited[s_]=true;
            level[s_]=0;
            while(!q.empty())
            {
                int p=q.front();
                q.pop();
                for(int i=0;i<edge[p].size();i++)
                {
                    if(visited[ edge[p][i] ] == false)
                    {
                        visited[edge[p][i]]=true;
                        level[ edge[p][i] ]=level[p] +1;
                        q.push(edge[p][i]);
                    }
                }
            }


           for(int i=0;i<=v.size();i++)
            {
                if(v[i].compare(end_)==0)
                {
                    cout<<start<<" "<<end_<<" "<<level[i]<<endl;
                }
            }
            }
            cout<<endl<<endl;
            }





        }
