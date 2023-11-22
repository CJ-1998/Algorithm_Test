#include<iostream>
#include<vector> 
#include<algorithm>
#include<string>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> check;
int num;

int cal(int x, int y){
    if(check[x][y]==1){
        return 0;
    }
    if(graph[x][y]==0){
        return 0;
    }

    check[x][y]=1;

    int answer=1;
    // cout<<x<<" "<<y<<endl;
    if(y-1>=0){
        answer+=cal(x,y-1);
    }
    if(y+1<num){
        answer+=cal(x,y+1);
    }
    if(x-1>=0){
        answer+=cal(x-1,y);
    }
    if(x+1<num){
        answer+=cal(x+1,y);
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>num;

    for(int i=0;i<num;i++){
        vector<int> temp;
        vector<int> temp2;
        string t="";
        cin>>t;
        for(int j=0;j<num;j++){
            temp.push_back(t[j]-'0');
            temp2.push_back(0);
        }
        graph.push_back(temp);
        check.push_back(temp2);
    }

    int answer=0;
    vector<int>area;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            int ret=cal(i,j);
            if(ret!=0){
                answer++;
                area.push_back(ret);
            }
        }
    }

    sort(area.begin(),area.end());

    cout<<answer<<endl;
    for(int i=0;i<area.size();i++){
        cout<<area[i]<<" ";
    }

    
    return 0;
}