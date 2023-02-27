/*
문제:
    정수를 담고 있는 배열 arr의 평균값을 return하는 함수, solution을 완성해보세요.

제한 사항:
    arr은 길이 1 이상, 100 이하인 배열입니다.
    arr의 원소는 -10,000 이상 10,000 이하인 정수입니다.
*/

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    double sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=(double)arr[i];
    }
    answer=sum/(double)arr.size();
    return answer;
}

/*
개선 사항:
    1. accumulate 함수 사용하면 된다.

배운 점:
    1. accumulate 함수는 numeric 라이브러리에 있고 accumulate(vec.begin(), vec.end(), 0); 하면 전체 벡터 합 구할 수 있다. 
*/