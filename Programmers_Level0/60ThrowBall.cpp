/*
문제:
    머쓱이는 친구들과 동그랗게 서서 공 던지기 게임을 하고 있습니다. 공은 1번부터 던지며 오른쪽으로 한 명을 건너뛰고 그다음 사람에게만 던질 수 있습니다. 친구들의 번호가 들어있는 정수 배열 numbers와 정수 K가 주어질 때, k번째로 공을 던지는 사람의 번호는 무엇인지 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    2 < numbers의 길이 < 100
    0 < k < 1,000
    numbers의 첫 번째와 마지막 번호는 실제로 바로 옆에 있습니다.
    numbers는 1부터 시작하며 번호는 순서대로 올라갑니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int index=0;
    for(int i=0;i<k-1;i++){
        index+=2;
        if(index>=numbers.size()){
            index-=numbers.size();
        }
    }
    return numbers[index];
}

/*
개선 사항 & 배운 점:
    1. 다시 돌아오는 것은 나머지 연산하면 빠르게 할 수 있다. 
*/