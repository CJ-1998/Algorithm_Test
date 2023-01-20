/*
문제:
    외과의사 머쓱이는 응급실에 온 환자의 응급도를 기준으로 진료 순서를 정하려고 합니다. 정수 배열 emergency가 매개변수로 주어질 때 응급도가 높은 순서대로 진료 순서를 정한 배열을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    중복된 원소는 없습니다.
    1 ≤ emergency의 길이 ≤ 10
    1 ≤ emergency의 원소 ≤ 100
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> temp=emergency;
    
    sort(temp.begin(),temp.end(),greater<int>());
    
    for(int i=0;i<emergency.size();i++){
        for(int j=0;j<temp.size();j++){
            if(emergency[i]==temp[j]){
                answer.push_back(j+1);
            }
        }
    }
    
    return answer;
}

/*
개선 사항:
    1. map 사용할 수 도 있다. 

배운 점:
    1. map 사용법
    2. sort에서 내림차순 사용법
*/