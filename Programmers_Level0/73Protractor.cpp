/*
문제:
    각에서 0도 초과 90도 미만은 예각, 90도는 직각, 90도 초과 180도 미만은 둔각 180도는 평각으로 분류합니다. 각 angle이 매개변수로 주어질 때 예각일 때 1, 직각일 때 2, 둔각일 때 3, 평각일 때 4를 return하도록 solution 함수를 완성해주세요.
        예각 : 0 < angle < 90
        직각 : angle = 90
        둔각 : 90 < angle < 180
        평각 : angle = 180

제한 사항:
    0 < angle ≤ 180
    angle은 정수입니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    if(angle<90){
        return 1;
    }
    else if(angle==90){
        return 2;
    }
    else if(angle<180){
        return 3;
    }
    else{
        return 4;
    }
}

/*
개선 사항:
    1. 3항 연산자 사용 가능.

배운 점:
    1. 3항 연산자 사용법: 조건 ? true : false ;
*/