/*
문제:
    정수 n이 매개변수로 주어질 때, 
    n의 약수를 오름차순으로 담은 배열을 
    return하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ n ≤ 10,000
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            answer.push_back(i);
        }
    }
    return answer;
}
/*
배운 점:
    주어진 숫자보다 작은 숫자들로 나눴을 때 나머지가 0이면 약수이다. 
*/