/*
문제:
    머쓱이는 행운의 숫자 7을 가장 좋아합니다. 
    정수 배열 array가 매개변수로 주어질 때, 
    7이 총 몇 개 있는지 return 하도록 solution 
    함수를 완성해보세요.

제한 사항:
    1 ≤ array의 길이 ≤ 100
    0 ≤ array의 원소 ≤ 100,000
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(int i=0;i<array.size();i++){
        string intToString= to_string(array[i]);
        for(int j=0;j<intToString.length();j++){
            if(intToString.at(j)=='7')
                answer++;
        }
    }
    return answer;
}

/*
개선 사항:
    숫자 개수 확인하려면 10으로 나누고 
    나머지가 그 숫자와 같으면 그 숫자 있는 것이다.
    즉 if (num%10)==7 -> answer++; num/=10;

배운 점:
    1. string.at()하면 char나와서 여기에 바로 compare()쓰면 오류난다. 
    2. compare() 앞에는 string이 있어야 한다. 
    3. c++에서 int to string은 string 생성자가 아닌 to_string(int) 함수 사용해야 한다. 
    4. string 생성자는 인자로 char[]가 들어가야 한다. 
*/