/*
문제:
    함수 solution은 정수 n을 매개변수로 입력받습니다. n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴해주세요. 예를들어 n이 118372면 873211을 리턴하면 됩니다.

제한 사항:
    n은 1이상 8000000000 이하인 자연수입니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string num=to_string(n);
    sort(num.begin(),num.end(),greater<int>());
    answer=stoll(num);
    return answer;
}

/*
개선 사항:
    1. 자리수 구해서 sort한 다음에 다시 10씩 곱하는 방법이다. 내 방법이 더 좋은 것 같다. 

배운 점:
    1. 숫자를 string으로 바꿀 때에는 to_string(숫자); 하면 된다. 
    2. 내림차순으로 정렬할 때 greater<>() 이렇게 타입 생략해도 된다고 한다. 
    3. string을 다시 숫자로 바꿀 때에는 stoi, stol, stoll 이런 함수 사용하면 된다.
*/