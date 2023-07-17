/*
문제:
    Finn은 요즘 수학공부에 빠져 있습니다. 
    수학 공부를 하던 Finn은 자연수 n을 연속한 자연수들로 표현 하는 방법이 여러개라는 사실을 알게 되었습니다. 
    예를들어 15는 다음과 같이 4가지로 표현 할 수 있습니다.
        1 + 2 + 3 + 4 + 5 = 15
        4 + 5 + 6 = 15
        7 + 8 = 15
        15 = 15
    자연수 n이 매개변수로 주어질 때, 연속된 자연수들로 n을 표현하는 방법의 수를 return하는 solution를 완성해주세요.

제한 사항:
    n은 10,000 이하의 자연수 입니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(int a) {
    int answer = 0;
    int sum=0;
    int n=1;
    while(true){
        int temp=0;
        int tempa=a;
        for(int i=1;i<=sum;i++){
            temp+=i;
        }
        tempa-=temp;
        
        if(tempa/n==0)
            break;
        
        if(tempa%n==0)
            answer++;
        
        sum++;
        n++;
    }
    return answer;
}

/*
개선 사항:
    2중 for문 돌면서 더하다가 값 넘어가면 break하고 값이 되면 answer++하는 것이다. 
*/