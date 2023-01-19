/*
문제:   
    사분면은 한 평면을 x축과 y축을 기준으로 나눈 네 부분입니다. 사분면은 아래와 같이 1부터 4까지 번호를매깁니다.
        x 좌표와 y 좌표가 모두 양수이면 제1사분면에 속합니다.
        x 좌표가 음수, y 좌표가 양수이면 제2사분면에 속합니다.
        x 좌표와 y 좌표가 모두 음수이면 제3사분면에 속합니다.
        x 좌표가 양수, y 좌표가 음수이면 제4사분면에 속합니다.
    x 좌표 (x, y)를 차례대로 담은 정수 배열 dot이 매개변수로 주어집니다. 좌표 dot이 사분면 중 어디에 속하는지 1, 2, 3, 4 중 하나를 return 하도록 solution 함수를 완성해주세요.

제한 사항:
    dot의 길이 = 2
    dot[0]은 x좌표를, dot[1]은 y좌표를 나타냅니다
    -500 ≤ dot의 원소 ≤ 500
    dot의 원소는 0이 아닙니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int answer = 0;
    if(dot[0]>0&&dot[1]>0){
        answer=1;
    }
    else if(dot[0]<0&&dot[1]>0){
        answer=2;
    }
    else if(dot[0]<0&&dot[1]<0){
        answer=3;
    }
    else{
        answer=4;
    }
    return answer;
}

/*
개선 사항:
    1. 3항 연산자로도 풀 수 있다. 

배운 점:
    1. 3항 연산자: 조건 ? 참 : 거짓
*/