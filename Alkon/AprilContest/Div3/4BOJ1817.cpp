/*
문제:
    숌은 짐을 챙겨서 겨울캠프에서 집으로 가려고 한다. 근데 숌은 공부를 많이 하러 캠프에 온 것이기 때문에 책을 엄청나게 많이 가지고 왔다. 숌은 이 책을 방에 탑처럼 쌓아 놨다.
    숌은 책을 박스에 차곡차곡 넣어서 택배로 미리 보내려고 한다. 책은 탑처럼 차곡차곡 쌓여있기 때문에, 차례대로 박스에 넣을 수밖에 없다.
    각각의 책은 무게가 있다. 그리고 박스는 최대 넣을수 있는 무게가 있다. 숌이 필요한 박스의 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 책의 개수 N과 박스에 넣을 수 있는 최대 무게 M이 주어진다. N은 0보다 크거나 같고 50보다 작거나 같은 정수이고, M은 1,000보다 작거나 같은 자연수이다. N이 0보다 큰 경우 둘째 줄에 책의 무게가 공백을 사이에 두고 주어진다. 책의 무게는 M보다 작거나 같은 자연수이다.

출력:
    첫째 줄에 필요한 박스의 개수의 최솟값을 출력한다.
*/

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