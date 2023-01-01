/*
문제:
    문자열 before와 after가 매개변수로 주어질 때, 
    before의 순서를 바꾸어 after를 만들 수 있으면 1을, 
    만들 수 없으면 0을 return 하도록 
    solution 함수를 완성해보세요.

제한 사항:
    0 < before의 길이 == after의 길이 < 1,000
    before와 after는 모두 소문자로 이루어져 있습니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string before, string after) {
    sort(before.begin(),before.end());
    sort(after.begin(),after.end());
    if(!before.compare(after)){
        return 1;
    }
    return 0;
}

/*
개선 사항:
    1. true면 1, false면 0이니 비교하는 것을 반환해도 된다. 

배운 점:
    1. 문자열이 섞여 있거나 이러면 sort가 중요한 역할 한다.
*/