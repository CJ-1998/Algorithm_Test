/*
문제:
    머쓱이는 친구들과 369게임을 하고 있습니다. 
    369게임은 1부터 숫자를 하나씩 대며 
    3, 6, 9가 들어가는 숫자는 숫자 대신 
    3, 6, 9의 개수만큼 박수를 치는 게임입니다. 
    머쓱이가 말해야하는 숫자 order가 매개변수로 주어질 때, 
    머쓱이가 쳐야할 박수 횟수를 return 하도록 
    solution 함수를 완성해보세요.

제한 사항:
    1 ≤ order ≤ 1,000,000
*/

#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    string str=to_string(order);
    for(int i=0;i<str.length();i++){
        if(str[i]=='3'||str[i]=='6'||str[i]=='9'){
            answer++;
        }
    }
    return answer;
}

/*
배운 점:
    1. int를 string으로 바꾸려면 to_string 함수 사용하면 된다. 
    2. 숫자를 10으로 나머지 연산하면 끝자리부터 구할 수 있다.
*/