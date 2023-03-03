/*
문제:
    자연수 N이 주어지면, N의 각 자릿수의 합을 구해서 return 하는 solution 함수를 만들어 주세요.
    예를들어 N = 123이면 1 + 2 + 3 = 6을 return 하면 됩니다.

제한 사항:
    N의 범위 : 100,000,000 이하의 자연수
*/

#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string temp=to_string(n);
    
    for(int i=0;i<temp.length();i++){
        answer+=temp[i]-'0';
    }

    return answer;
}

/*
개선 사항:
    1. 역시 10으로 나눈 나머지로 하면 뒤의 자리부터 구할 수 있다. 

배운 점:
    1. 숫자를 string으로 바꾸려면 to_string(n); 하면 된다. 
*/