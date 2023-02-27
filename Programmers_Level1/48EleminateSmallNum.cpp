/*
문제:
    정수를 저장한 배열, arr 에서 가장 작은 수를 제거한 배열을 리턴하는 함수, solution을 완성해주세요. 단, 리턴하려는 배열이 빈 배열인 경우엔 배열에 -1을 채워 리턴하세요. 예를들어 arr이 [4,3,2,1]인 경우는 [4,3,2]를 리턴 하고, [10]면 [-1]을 리턴 합니다.

제한 사항:
    arr은 길이 1 이상인 배열입니다.
    인덱스 i, j에 대해 i ≠ j이면 arr[i] ≠ arr[j] 입니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int index=min_element(arr.begin(),arr.end())-arr.begin();
    arr.erase(arr.begin()+index);
    if(arr.size()==0){
        answer.push_back(-1);
        return answer;
    }
    else{
        return arr;
    }
}

/*
배운 점:
    1. min_element(v.begin(), v.end()); 하면 최소 값의 포인터가 나온다. 
    2. 그래서 최소 값을 구하려면 *min_element(v.begin(), v.end()); 하면 된다. 
    3. 그리고 최소 값의 index를 구하려면 min_element(v.begin(), v.end())-v.begin(); 하면 되는 것이다.
*/