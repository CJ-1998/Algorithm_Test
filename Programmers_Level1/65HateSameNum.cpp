/*
문제:
    배열 arr가 주어집니다. 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다. 이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다. 단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다. 예를 들면,
        arr = [1, 1, 3, 3, 0, 1, 1] 이면 [1, 3, 0, 1] 을 return 합니다.
        arr = [4, 4, 4, 3, 3] 이면 [4, 3] 을 return 합니다.
    배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.

제한 사항:
    배열 arr의 크기 : 1,000,000 이하의 자연수
    배열 arr의 원소의 크기 : 0보다 크거나 같고 9보다 작거나 같은 정수
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> answer;
    
    for(int i=0;i<arr.size();i++){
        if(answer.empty()){
            answer.push(arr[i]);
        }
        else{
            if(answer.top()!=arr[i]){
                answer.push(arr[i]);
            }
        }
    }
    
    vector<int> ans;
    int len=answer.size();
    for(int i=0;i<len;i++){
        ans.push_back(answer.top());
        answer.pop();
    }
    
    reverse(ans.begin(),ans.end());

    return ans;
}

/*
개선 사항:
    1. erase랑 unique sort 안해도 사용할 수 있다. 

배운 점:
    1. 벡터 중복 원소 삭제는 erase, unique 함수 사용하면 된다. 
    2. stack은 벡터처럼 사용하면 되고 push, pop, top, empty 등 함수 있다. 
    3. 벡터 뒤집으려면 reverse 함수 사용하면 된다.
*/