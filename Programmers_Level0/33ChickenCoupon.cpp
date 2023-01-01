/*
문제:
    프로그래머스 치킨은 치킨을 시켜먹으면 한 마리당 쿠폰을 
    한 장 발급합니다. 쿠폰을 열 장 모으면 치킨을 한 마리 
    서비스로 받을 수 있고, 서비스 치킨에도 쿠폰이 발급됩니다.
    시켜먹은 치킨의 수 chicken이 매개변수로 주어질 때 
    받을 수 있는 최대 서비스 치킨의 수를 return하도록 
    solution 함수를 완성해주세요.

제한 사항:
    chicken은 정수입니다.
    0 ≤ chicken ≤ 1,000,000
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int coupon=0; 
    while(chicken>0){
        answer+=chicken/10;
        coupon+=chicken%10;
        chicken/=10;
    }
    
    int lastCoupon=0;
    while(coupon>0){
        answer+=coupon/10;
        lastCoupon+=coupon%10;
        coupon/=10;
    }
    answer+=lastCoupon/10;
    return answer;
}

/*
개선 사항:
    1. 남은 쿠폰을 따로 계산해 줬는데 그냥 다시 치킨에 더하면 된다. 
*/