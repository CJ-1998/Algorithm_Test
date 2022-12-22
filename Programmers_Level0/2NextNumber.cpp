/*
문제: 
    등차수열 혹은 등비수열 common이 매개변수로 주어질 때, 
    마지막 원소 다음으로 올 숫자를 return 하도록 solution 함수를 완성해보세요.

제한사항:
    2 < common의 길이 < 1,000
    -1,000 < common의 원소 < 2,000
    등차수열 혹은 등비수열이 아닌 경우는 없습니다.
    공비가 0인 경우는 없습니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    bool isArithmetic=false;
    int a=common[0];
    int b=common[1];
    int c=common[2];
    
    int commonSize=common.size()-1;
    int arithmetic=0;
    int geometric=0;
    
    if(b-a==c-b){
        isArithmetic=true;
        arithmetic=b-a;
    }
    else{
        if(a!=0&&b!=0&&c!=0){
            if(b/a==c/b){
                isArithmetic=false;
                geometric=b/a;
            }
        }
    }
    
    if(isArithmetic){
        answer=common[commonSize]+arithmetic;
    }
    else{
        answer=common[commonSize]*geometric;
    }
    return answer;
}

/*
실패 이유:
    1. 원소에 0이 있으면 나머지 연산시 오류가 생김
    2. 등차이면서 등비인 것이 있을 수도 있음을 간과

개선할 것:
    1. 등차 혹은 등비 아닌 경우 없으니 그냥 if, else로 해도 됨
    2. 등차, 등비 결정 되었으면 바로 answer 정해서 아래 42~47 코드 제거 가능
*/