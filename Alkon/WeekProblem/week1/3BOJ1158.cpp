/*
문제:
    요세푸스 문제는 다음과 같다.
    1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
    N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000)

출력:
    예제와 같이 요세푸스 순열을 출력한다.
*/

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int cnt=0;
    scanf("%d",&cnt);
    
    int term=0;
    scanf("%d",&term);

    queue<int> q;

    for(int i=1;i<=cnt;i++){
        q.push(i);
    }

    vector<int> v;
    
    while(!q.empty()){
        for(int i=0;i<term-1;i++){
            int temp=0;
            temp=q.front();
            q.pop();
            q.push(temp);
        }
        v.push_back(q.front());
        q.pop();
    }

    printf("<");
    for(int i=0;i<v.size();i++){
        if(i<v.size()-1)
            printf("%d, ",v[i]);
        else
            printf("%d",v[i]);
    }
    printf(">");

    return 0;
}

/*
개선 사항:
    1. queue에서 앞에서 빼고 뒤에 넣는 것을 하고 출력한 다음에 pop 하면 반복문 하나 줄일 수 있다. 

배운 점:
    1. queue 사용법
*/