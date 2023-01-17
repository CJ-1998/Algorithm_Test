/*
문제:
    정수가 담긴 배열 numbers와 문자열 direction가 매개변수로 주어집니다. 배열 numbers의 원소를 direction방향으로 한 칸씩 회전시킨 배열을 return하도록 solution 함수를 완성해주세요.

제한 사항:
    3 ≤ numbers의 길이 ≤ 20
    direction은 "left" 와 "right" 둘 중 하나입니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    int cnt=numbers.size()-1;
    if(!direction.compare("right")){
        int temp=numbers[cnt];
        answer.push_back(temp);
        for(int i=0;i<cnt;i++){
            answer.push_back(numbers[i]);
        }
    }
    else{
        int temp=numbers[0];
        for(int i=1;i<cnt+1;i++){
            answer.push_back(numbers[i]);
        }
        answer.push_back(temp);
    }
    return answer;
}

/*
개선 사항:
    1. rotate 함수 사용하면 빠르다. 

배운 점:
    1. rotate 함수는 algorithm 라이브러리에 있다. 
    2. rotate(v.begin(), v.begin()+n, v.end()); 하면 왼쪽으로 n칸씩 회전된다. 
    3. rotate(v.begin(), v.end()-n, v.end()); 하면 오른쪽으로 n칸씩 회전된다.
*/