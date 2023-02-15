/*
문제:
    정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.

제한 사항:
    numbers의 길이는 2 이상 100 이하입니다.
        numbers의 모든 수는 0 이상 100 이하입니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    sort(numbers.begin(), numbers.end());
    for(int i=0;i<numbers.size();i++){
        for(int j=i;j<numbers.size();j++){
            if(i!=j){
                answer.push_back(numbers[i]+numbers[j]);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
    
    return answer;
}

/*
개선 사항:
    1. set은 중복 허용 아니니 set에다가 더한 값들을 넣으면 된다. 
    2. 합을 index로 하는 벡터 만들어서 있는지 체크하는 것이다. 

배운 점:
    1. 벡터 중복 제거 방법: answer.erase(unique(answer.begin(),answer.end()),answer.end());
    2. set 사용법: set 라이브러리에 있다. set<자료형> 이름; 이렇게 선언한다. set.insert(값); 으로 값 넣는다.
*/