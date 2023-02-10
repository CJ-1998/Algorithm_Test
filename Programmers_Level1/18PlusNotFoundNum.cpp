/*
문제:
    0부터 9까지의 숫자 중 일부가 들어있는 정수 배열 numbers가 매개변수로 주어집니다. numbers에서 찾을 수 없는 0부터 9까지의 숫자를 모두 찾아 더한 수를 return 하도록 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ numbers의 길이 ≤ 9
        0 ≤ numbers의 모든 원소 ≤ 9
        numbers의 모든 원소는 서로 다릅니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int size=numbers.size();
    sort(numbers.begin(),numbers.end());
    int arr[10]={0};
    for(int i=0;i<size;i++)
    {
        arr[numbers[i]]=1;
    }
    for(int i=0;i<10;i++)
    {
        if(arr[i]!=1)
        {
            answer+=i;
        }
    }
    return answer;
}

/*
개선 사항:
    1. 전체에서 빼면 된다. 

배운 점:
    1. accumulate(시작점, 끝점, 합 초기값) 함수 사용법
        1-1. numeric 라이브러리에 있다.
*/