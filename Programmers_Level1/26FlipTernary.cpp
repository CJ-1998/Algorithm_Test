/*
문제:
    자연수 n이 매개변수로 주어집니다. n을 3진법 상에서 앞뒤로 뒤집은 후, 이를 다시 10진법으로 표현한 수를 return 하도록 solution 함수를 완성해주세요.

제한 사항:
    n은 1 이상 100,000,000 이하인 자연수입니다
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> three;
    
    while(n!=0){
        three.push_back(n%3);
        n/=3;
    }
    
    int temp=0;
    for(int i=three.size()-1;i>=0;i--){
        answer+=three[temp++]*pow(3,i);
    }
    
    return answer;
}

/*
개선 사항:
    1. 3의 제곱 pow 안쓰고 그냥 loop 돌 때마다 3 곱해도 된다.

배운 점:
    1. pow(n, m); = n^m 사용법, cmath 라이브러리에 있다.
    2. 벡터에 나머지 넣고 역 for문 넣고 그대로 i부터 하면 n진법 to 10진법 구할 수 있다. 
        2-1. 아래처럼 하면 m진법 to 10진법 값 바로 나온다. 
            
            while(n!=0){
                three.push_back(n%m);
                n/=m;
            }
    
            for(int i=three.size()-1;i>=0;i--){
                answer+=three[i]*pow(m,i);
            }
*/