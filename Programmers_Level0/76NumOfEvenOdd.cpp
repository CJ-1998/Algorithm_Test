/*
문제:
    정수가 담긴 리스트 num_list가 주어질 때, num_list의 원소 중 짝수와 홀수의 개수를 담은 배열을 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    1 ≤ num_list의 길이 ≤ 100
    0 ≤ num_list의 원소 ≤ 1,000
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int even=0;
    int odd=0;
    for(int i=0;i<num_list.size();i++){
        if(num_list[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    answer.push_back(even);
    answer.push_back(odd);
    return answer;
}

/*
개선 사항:
    1. 나머지 연산 결과를 index로 해서 벡터에 값 증가 시키면 된다.

배운 점:
    1. vector 초기화할 때 vector<int> name(개수, 초기화 값); 하면 개수개의 초기화 값 가지는 벡터 만들어준다. 
*/