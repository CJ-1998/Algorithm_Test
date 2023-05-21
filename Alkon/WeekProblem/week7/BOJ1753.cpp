#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int v,e;
    scanf("%d %d",&v,&e);

    int startnode;
    scanf("%d",&startnode);

    vector<pair<int,int>>* arr=new vector<pair<int,int>>[v+1];

    for(int i=1;i<=v;i++){
        vector<pair<int,int>> temp;
        arr[i]=temp;
    }

    for(int i=0;i<e;i++){
        int start,end,a;
        scanf("%d %d %d",&start,&end,&a);

        pair<int,int> p;
        p=make_pair(end,a);
        arr[start].push_back(p);
    }

    return 0;
}