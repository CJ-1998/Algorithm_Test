/*
문제:
    최빈값은 주어진 값 중에서 가장 자주 나오는 값을 의미합니다. 정수 배열 array가 매개변수로 주어질 때, 최빈값을 return 하도록 solution 함수를 완성해보세요. 최빈값이 여러 개면 -1을 return 합니다.

제한 사항: 
    0 < array의 길이 < 100
    0 ≤ array의 원소 < 1000
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    vector<int> temp(1000,0);
    for(int i=0;i<array.size();i++){
        temp[array[i]]++;
    }
    int max_index = max_element(temp.begin(), temp.end()) - temp.begin();
    answer=max_index;
    
    auto it=temp.begin();
    while(it!=temp.end()){
        it=find(it,temp.end(),temp[max_index]);
        
        if(it!=temp.end()){
            if(it-temp.begin()!=max_index){
            answer=-1;
            break;
        }
            it++;
        }
    }
    
    return answer;
}

/*
개선 사항:
    map을 사용하면 간단히 풀 수 있다.
    map의 key를 나온 값으로 하고 value를 횟수로 해서 value가 최댓값인데 같은 것 있으면 -1로 하면 된다.

배운 점:
    1. 배열 최댓값 찾기: int max = *max_element(temp.begin(), temp.end());
    2. 배열 최댓값 index 찾기: int max_index = max_element(temp.begin(), temp.end()) - temp.begin();
    3. 배열 값 찾기: find(v.begin(),v.end(), num); → num 찾기. 반환 값은 찾은 그 iterator. 
    4. find했는데 반환 값이 v.end()이면 찾지 못한 것이다. 
    5. 찾은 그 값의 index는 반환 값-v.begin()하면 된다.
*/