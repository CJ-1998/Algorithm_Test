/*
문제:
    선분 세 개로 삼각형을 만들기 위해서는 다음과 같은 조건을 만족해야 합니다.
        가장 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야 합니다.
    삼각형의 두 변의 길이가 담긴 배열 sides이 매개변수로 주어집니다. 나머지 한 변이 될 수 있는 정수의 개수를 return하도록 solution 함수를 완성해주세요.

제한 사항:
    sides의 원소는 자연수입니다.
    sides의 길이는 2입니다.
    1 ≤ sides의 원소 ≤ 1,000
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int big=0;
    int small=0;
    if(sides[0]<sides[1]){
        big=sides[1];
        small=sides[0];
    }
    else{
        big=sides[0];
        small=sides[1];
    }
    //big이 제일 큰 경우
    int temp=big-small+1;
    for(int i=temp;i<big+1;i++){
        answer++;
    }
    //big보다 큰게 있는 경우
    int sum=big+small;
    for(int i=big+1;i<sum;i++){
        answer++;
    }
    return answer;
}

/*
개선 사항:
    1. 큰 값, 작은 값 찾을 때 if문 말고 sort로 하면 편하다.
    2. 큰 값, 작은 값 찾을 때 if문 말고 swap 함수 사용하면 편하다.

배운 점:
    1. swap(a, b); 하면 두 변수의 값이 바뀐다. 
    2. 삼각형 나머지 한변이 될 수 있는 개수는 2*긴 변 -1이다. 
*/