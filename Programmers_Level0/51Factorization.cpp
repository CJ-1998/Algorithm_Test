/*
문제:
    소인수분해란 어떤 수를 소수들의 곱으로 표현하는 것입니다. 예를 들어 12를 소인수 분해하면 2 * 2 * 3 으로 나타낼 수 있습니다. 따라서 12의 소인수는 2와 3입니다. 자연수 n이 매개변수로 주어질 때 n의 소인수를 오름차순으로 담은 배열을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    2 ≤ n ≤ 10,000
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int temp=2;
    bool check=true;
    while(true){
        if(n==1){
            break;
        }
        else{
            if(n%temp==0){
                if(check){
                    answer.push_back(temp);
                    check=false;
                }
                n/=temp;
            }
            else{
                temp++;
                check=true;
            }
        }
    }
    return answer;
}

/*
개선 사항:
    1. break문을 while의 조건에 넣으면 좋다. 
    2. 벡터 중복 제거는 sort, unique, erase로 하면 된다. 

배운 점:
    1. unique는 연속된 중복 원소를 뒷부분으로 보내는 함수다. 
    2. unique의 반환 값은 중복 원소의 첫번째 위치다. 
    3. sort하고 unique해야 효과를 볼 수 있다. 
    4. 그래서 중복 원소 지우는 방법은 아래와 같다. 
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
*/