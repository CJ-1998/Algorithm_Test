/*
문제:
    정수 num과 k가 매개변수로 주어질 때, 
    num을 이루는 숫자 중에 k가 있으면 
    num의 그 숫자가 있는 자리 수를 return하고 없으면 
    -1을 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    0 < num < 1,000,000
    0 ≤ k < 10
    num에 k가 여러 개 있으면 가장 처음 나타나는 자리를 return 합니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = -1;
    string number=to_string(num);
    for(int i=0;i<number.size();i++){
        if(number[i]==k+48){
            return i+1;
        }
    }
    return answer;
}

/*
개선 사항:
    1. char를 int로 바꿀 때 -'0'하는 것이 좀 더 직관적 같다. 

배운 점:
    1. int를 string으로 바꿀 때에는 to_string을 사용하면 된다. 
    2. int를 char로 바꾸려면 +48하면 된다. 
    3. 또는 char를 int로 바꾸려면 -’0’하면 된다.
*/