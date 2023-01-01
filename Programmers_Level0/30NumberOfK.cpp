/*
문제:
    1부터 13까지의 수에서, 1은 1, 10, 11, 12, 13 
    이렇게 총 6번 등장합니다. 
    정수 i, j, k가 매개변수로 주어질 때, 
    i부터 j까지 k가 몇 번 등장하는지 
    return 하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ i < j ≤ 100,000
    0 ≤ k ≤ 9
*/

#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    string Knum=to_string(k);
    for(int start=i;start<=j;start++){
        string num=to_string(start);
        for(int index=0;index<num.length();index++){
            if(num[index]==Knum[0]){
                answer++;
            }
        }
    }
    return answer;
}

/*
배운 점:
    1. char형 숫자를 int로 바꾸려면 -’0’하면 된다.
*/