/*
문제:
    양의 정수 x가 하샤드 수이려면 x의 자릿수의 합으로 x가 나누어져야 합니다. 예를 들어 18의 자릿수 합은 1+8=9이고, 18은 9로 나누어 떨어지므로 18은 하샤드 수입니다. 자연수 x를 입력받아 x가 하샤드 수인지 아닌지 검사하는 함수, solution을 완성해주세요.

제한 사항:
    x는 1 이상, 10000 이하인 정수입니다.
*/

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int nx=x;
    int sum=0;
    int temp=10000;
    for(int i=0;i<5;i++){
        sum+=x/temp;
        x=x%temp;
        temp/=10;
    }
    if(nx%sum!=0){
        answer=false;
    }
    return answer;
}

/*
개선 사항:
    1. 10씩 계속 나누면서 아래 자리 수부터 더한다. 그리고 원래 값을 10으로 나누면 된다. 
*/