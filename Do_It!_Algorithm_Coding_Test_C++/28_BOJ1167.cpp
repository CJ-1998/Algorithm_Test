#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> check;
vector<int> sum;

void bfs(int x){
    queue<int>q;
    q.push(x);

    while(!q.empty()){
        int u = q.front();
        // cout<<"u "<<u<<endl;
        q.pop();

        check[u]=1;

        for(int i=0;i<graph[u].size();i++){
            
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            
            if(check[v]==1)
                continue;

            // cout<<"v "<<v<<endl;

            if(sum[v]==0)
                sum[v]=sum[u]+w;
            else
                sum[v]=max(sum[u]+w,sum[v]);
            
            q.push(v);
        }
    }

}

int main() {
    
    int n=0;
    cin >> n;

    for(int i=0;i<n;i++){
        vector<pair<int,int>>graphTemp;
        graph.push_back(graphTemp);
        check.push_back(0);
        sum.push_back(0);
    }
    
    for(int i=0;i<n;i++){
        int origin=0;
        cin>>origin;

        int temp=0;
        while(true){
            cin>>temp;
            if(temp==-1){
                break;
            }
            else{
                int weight=0;
                cin>>weight;
                graph[origin-1].push_back(make_pair(temp-1,weight));
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<graph[i].size();j++){
    //         cout<<"i: "<<i+1<<" "<<graph[i][j].first+1<<" "<<graph[i][j].second<<" ";
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    bfs(0);

    // for(int i=0;i<n;i++){
    //     cout<<sum[i]<<" ";
    // }

    sort(sum.begin(),sum.end());

    cout<<sum[sum.size()-1]<<endl;


    return 0;
}