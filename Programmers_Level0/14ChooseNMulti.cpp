/*
문제:
    정수 n과 정수 배열 numlist가 매개변수로 주어질 때,
    numlist에서 n의 배수가 아닌 수들을 제거한 배열을 return하도록 
    solution 함수를 완성해주세요.

제한 사항:
    1 ≤ n ≤ 10,000
    1 ≤ numlist의 크기 ≤ 100
    1 ≤ numlist의 원소 ≤ 100,000
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    for(int i=0;i<numlist.size();i++){
        if(numlist[i]%n==0){
            answer.push_back(numlist[i]);
        }
    }
    return answer;
}

/*
개선 사항:
    1. erase 함수 사용해도 되지만 좀 더 불편할 것 같다. 

배운 점:
    1. 특정 index에 있는 원소를 지우고 싶으면 erase 함수를 사용하면 된다. 
    2. vector.erase(vector.begin()+ index); 하면 지워진다. 
    3. 연속적으로 지우려면 index—;해야 그 다음 원소 지울 것이다. 왜냐하면 한 원소가 빠졌기 때문.
*/