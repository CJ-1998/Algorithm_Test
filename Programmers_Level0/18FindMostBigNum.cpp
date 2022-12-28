/*
문제:
    정수 배열 array가 매개변수로 주어질 때, 
    가장 큰 수와 그 수의 인덱스를 담은 배열을 return 하도록 
    solution 함수를 완성해보세요.

제한 사항:
    1 ≤ array의 길이 ≤ 100
    0 ≤ array 원소 ≤ 1,000
    array에 중복된 숫자는 없습니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    
    int max = *max_element(array.begin(), array.end());
    int max_index = max_element(array.begin(), array.end()) - array.begin();
    
    answer.push_back(max);
    answer.push_back(max_index);
    return answer;
}

/*
배운 점:
    1. 벡터의 가장 큰 값을 찾는 함수인 max_element 함수
        1.1. 인자로 벡터.begin(), 벡터.end() 넣으면 주소가 나오는데 거기에 * 연산자를 사용하면 가장 큰 값을 반환해준다. 
        1.2. *max_element(v.begin(),v,end());
        1.3. max_element(v.begin(), v.end()) - v.begin() 하면 가장 큰 값의 index를 반환해준다.
*/