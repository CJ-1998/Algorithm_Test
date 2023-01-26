/*
문제:
    정수 배열 numbers가 매개변수로 주어집니다. numbers의 원소의 평균값을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    0 ≤ numbers의 원소 ≤ 1,000
    1 ≤ numbers의 길이 ≤ 100
    정답의 소수 부분이 .0 또는 .5인 경우만 입력으로 주어집니다.
*/

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    int sum=0;
    for(int i=0;i<numbers.size();i++){
        sum+=numbers[i];
    }
    answer=(double)sum/(double)numbers.size();
    return answer;
}

/*
개선 사항:
    1. accumulate 함수를 사용하면 간단히 배열의 합을 구할 수 있다. 

배운 점:
    1. accumulate 함수는 numeric 라이브러리에 있다. 
    2. 각 인자로는 first iterator, last iterator, 합의 초기값을 주면 된다.
*/
