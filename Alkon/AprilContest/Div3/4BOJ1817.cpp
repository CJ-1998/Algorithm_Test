#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int answer=0;

    int num=0;
    int max=0;
    scanf("%d %d",&num,&max);

    if(num==0){
        printf("0");
        return 0;
    }

    queue<int> q;

    for(int i=0;i<num;i++){
        int temp=0;
        scanf("%d",&temp);
        q.push(temp);
    }

    int box=0;
    for(int i=0;i<num;i++){
        int temp=q.front();
        box+=temp;
        q.pop();
        if(box==max){
            answer++;
            box=0;
        }
        else if(box>max){
            answer++;
            box=temp;
        }
    }

    if(q.empty()){
        if(box!=0){
            answer++;
        }
    }

    printf("%d",answer);

    return 0;
}