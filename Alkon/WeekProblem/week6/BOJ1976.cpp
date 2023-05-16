#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int parent[201];
int nodesize[201];

int findnode(int node){
    if(parent[node]==node){
        return node;
    }

    parent[node]=findnode(parent[node]);
    return parent[node];
}

void merge(int a, int b){

    int tempa, tempb;
    tempa=findnode(a);
    tempb=findnode(b);

    // if(tempa==tempb){
    //     return;
    // }

    if(nodesize[tempa]>nodesize[tempb]){
        nodesize[tempa]+=nodesize[tempb];
        parent[tempb]=tempa;
    }
    else{
        nodesize[tempb]+=nodesize[tempa];
        parent[tempa]=tempb;
    }

}

int main(){

    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        parent[i]=i;
        nodesize[i]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp;
            scanf("%d",&temp);
            
            if(i==j){
                continue;
            }

            if(temp==1){
                merge(i,j);
            }
        }
    }

    vector<int> v;
    for(int i=0;i<m;i++){
        int temp;
        scanf("%d",&temp);

        v.push_back(temp);
    }

    string answer="YES";

    for(int i=1;i<m;i++){
        if(findnode(v[i-1])!=findnode(v[i])){
            answer="NO";
            break;
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout<<parent[i]<<endl;
    // }

    cout<<answer<<endl;

    return 0;
}