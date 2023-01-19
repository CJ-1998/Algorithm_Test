/*
문제:
    머쓱이는 구슬을 친구들에게 나누어주려고 합니다. 구슬은 모두 다르게 생겼습니다. 머쓱이가 갖고 있는 구슬의 개수 balls와 친구들에게 나누어 줄 구슬 개수 share이 매개변수로 주어질 때, balls개의 구슬 중 share개의 구슬을 고르는 가능한 모든 경우의 수를 return 하는 solution 함수를 완성해주세요.

제한 사항:
    1 ≤ balls ≤ 30
    1 ≤ share ≤ 30
    구슬을 고르는 순서는 고려하지 않습니다.
    share ≤ balls
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

long double factorial(long double num){
    if(num<=1){
        return 1;
    }
    return num*factorial(num-1);
}

int solution(int balls, int share) {
    long double answer = 0;
    long double n=factorial(balls);
    long double m=factorial(share);
    long double nm=factorial(balls-share);
    long double temp=nm*m;
    
    answer=n/temp;
    
    return answer;
}

/*
개선 사항:
    1. 공식 다르게 쓰면 int안에서 해결이 된다. 

배운 점:
    1. factorial 나오면 자료형 생각해야 한다.
*/