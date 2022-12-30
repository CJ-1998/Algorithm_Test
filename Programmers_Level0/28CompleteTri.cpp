/*
문제:
    선분 세 개로 삼각형을 만들기 위해서는 
    다음과 같은 조건을 만족해야 합니다.
        가장 긴 변의 길이는 다른 두 변의 길이의 
        합보다 작아야 합니다.
    삼각형의 세 변의 길이가 담긴 배열 sides이 
    매개변수로 주어집니다. 
    세 변으로 삼각형을 만들 수 있다면 1, 
    만들 수 없다면 2를 return하도록 
    solution 함수를 완성해주세요.

제한 사항:
    sides의 원소는 자연수입니다.
    sides의 길이는 3입니다.
    1 ≤ sides의 원소 ≤ 1,000
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int max_index=max_element(sides.begin(),sides.end())-sides.begin();
    
    int othersides=0;
    for(int i=0;i<sides.size();i++){
        if(i!=max_index){
            othersides+=sides[i];
        }
    }
    
    if(othersides>sides[max_index]){
        return 1;
    }
    else{
        return 2;
    }
}

/*
개선 사항:
    1. 그냥 sort하고 더하면 더 편하다. 

배운 점:
    1. max_element 사용법
    2. 가장 큰 수, 작은 수 이런 것은 sort하면 더 편하다.
*/