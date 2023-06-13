#include <cstdio>
#include <utility>
#include <vector>

#define INF 999999999

using namespace std;

int v,e;
int start;
vector<pair<int,int>>* arr;
int* dist;
bool* visited;

int small(){
    int min=INF;
    int index=0;

    for(int i=1;i<=v;i++){
        if(dist[i]<min&&!visited[i]){
            min=dist[i];
            index=i;
        }
    }
    return index;
}

void dijkstra(int start){
    for(int i=0;i<arr[start].size();i++){
        dist[arr[start][i].first]=arr[start][i].second;
    }

    dist[start]=0;
    visited[start]=true;

    for(int i=0;i<v-1;i++){
        int s=small();
        visited[s]=true;

        for(int i=0;i<arr[s].size();i++){
            if(dist[arr[s][i].first]>dist[s]+arr[s][i].second){
                dist[arr[s][i].first]=dist[s]+arr[s][i].second;
            }
        }
    }

}


int main(){

    scanf("%d %d %d", &v, &e, &start);
    dist=new int[v+1];
    visited=new bool[v+1];

    for(int i=1;i<=v;i++){
        dist[i]=INF;
        visited[i]=false;
    }

    arr=new vector<pair<int,int>>[v+1];

    for(int i=1;i<=v;i++){
        vector<pair<int,int>> temp;
        arr[i]=temp;
    }


    for(int i=0;i<e;i++){
        int fir, sec, wei;
        scanf("%d %d %d", &fir, &sec, &wei);

        pair<int,int> temp;
        temp=make_pair(sec,wei);

        arr[fir].push_back(temp);
    }

    dijkstra(start);

    for(int i=1;i<=v;i++){
        if(dist[i]==INF)
            printf("INF\n");
        else
            printf("%d\n",dist[i]);
    }

    return 0;
}