/*
문제:
    첫 번째 분수의 분자와 분모를 뜻하는 numer1, denom1, 두 번째 분수의 분자와 분모를 뜻하는 numer2, denom2가 매개변수로 주어집니다. 두 분수를 더한 값을 기약 분수로 나타냈을 때 분자와 분모를 순서대로 담은 배열을 return 하도록 solution 함수를 완성해보세요.

제한 사항:
    0 <numer1, denom1, numer2, denom2 < 1,000
*/

#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int lcm=std::lcm(denom1, denom2);
    
    answer.push_back(numer1*(lcm/denom1)+numer2*(lcm/denom2));
    answer.push_back(lcm);
    
    int gcd=std::gcd(answer[0],answer[1]);
    
    if(gcd!=1){
        answer[0]/=gcd;
        answer[1]/=gcd;
    }
    
    
    
    return answer;
}

/*
개선 사항:
    1. 분모 통일 안하고 그냥 진행하고 마지막에 약분만 하면 된다. 

배운 점:
    1. gcd, lcm 함수는 numeric 라이브러리에 있다. 
*/