/*
문제:
    스마트폰 전화 키패드의 각 칸에 다음과 같이 숫자들이 적혀 있습니다.

    이 전화 키패드에서 왼손과 오른손의 엄지손가락만을 이용해서 숫자만을 입력하려고 합니다.
    맨 처음 왼손 엄지손가락은 * 키패드에 오른손 엄지손가락은 # 키패드 위치에서 시작하며, 엄지손가락을 사용하는 규칙은 다음과 같습니다.
        1. 엄지손가락은 상하좌우 4가지 방향으로만 이동할 수 있으며 키패드 이동 한 칸은 거리로 1에 해당합니다.
        2. 왼쪽 열의 3개의 숫자 1, 4, 7을 입력할 때는 왼손 엄지손가락을 사용합니다.
        3. 오른쪽 열의 3개의 숫자 3, 6, 9를 입력할 때는 오른손 엄지손가락을 사용합니다.
        4. 가운데 열의 4개의 숫자 2, 5, 8, 0을 입력할 때는 두 엄지손가락의 현재 키패드의 위치에서 더 가까운 엄지손가락을 사용합니다.
            4-1. 만약 두 엄지손가락의 거리가 같다면, 오른손잡이는 오른손 엄지손가락, 왼손잡이는 왼손 엄지손가락을 사용합니다.

    순서대로 누를 번호가 담긴 배열 numbers, 왼손잡이인지 오른손잡이인 지를 나타내는 문자열 hand가 매개변수로 주어질 때, 각 번호를 누른 엄지손가락이 왼손인 지 오른손인 지를 나타내는 연속된 문자열 형태로 return 하도록 solution 함수를 완성해주세요.

제한 사항:
    numbers 배열의 크기는 1 이상 1,000 이하입니다.
    numbers 배열 원소의 값은 0 이상 9 이하인 정수입니다.
    hand는 "left" 또는 "right" 입니다.
        "left"는 왼손잡이, "right"는 오른손잡이를 의미합니다.
    왼손 엄지손가락을 사용한 경우는 L, 오른손 엄지손가락을 사용한 경우는 R을 순서대로 이어붙여 문자열 형태로 return 해주세요.
*/

#include <string>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int size=numbers.size();
    pair <int, int> l=make_pair(3,0);
    pair <int, int> r=make_pair(3,2);
    
    for(int i=0;i<size;i++)
    {
        int a, b=0;
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7)
        {
            answer+="L";
            a=(numbers[i]-1)/3;
            b=(numbers[i]-3*a)-1;
            l=make_pair(a,b);
        }
        if(numbers[i]==3||numbers[i]==6||numbers[i]==9)
        {
            answer+="R";
            a=(numbers[i]-1)/3;
            b=(numbers[i]-3*a)-1;
            r=make_pair(a,b);
        }
        if(numbers[i]==2||numbers[i]==5||numbers[i]==8)
        {
            a=(numbers[i]-1)/3;
            b=(numbers[i]-3*a)-1;
            int distanceR= abs(r.first-a)+abs(r.second-b);
            int distanceL= abs(l.first-a)+abs(l.second-b);
            if(distanceR>distanceL)
            {
                answer+="L";
                l=make_pair(a,b);
            }
            else if(distanceR<distanceL)
            {
                answer+="R";
                r=make_pair(a,b);
            }
            else
            {
                if(hand.compare("right")==0)
                {
                    answer+="R";
                    r=make_pair(a,b);
                }
                else
                {
                    answer+="L";
                    l=make_pair(a,b);
                }
            }
        }
        if(numbers[i]==0)
        {
            a=3;
            b=1;
            int distanceR= abs(r.first-a)+abs(r.second-b);
            int distanceL= abs(l.first-a)+abs(l.second-b);
            if(distanceR>distanceL)
            {
                answer+="L";
                l=make_pair(a,b); 
            }
            else if(distanceR<distanceL)
            {
                answer+="R";
                r=make_pair(a,b);
            }
            else
            {
                if(hand.compare("right")==0)
                {
                    answer+="R";
                    r=make_pair(a,b);
                }
                else
                {
                    answer+="L";
                    l=make_pair(a,b);
                }
            }
        }
    }
    return answer;
}

/*
배운 점:
    1. pair 변수 사용법: utility 라이브러리에 있다. pair<자료형, 자료형> 이름; 으로 선언. make_pair(값, 값); 로 초기화 하면 된다. 
    2. 절대값 함수 abs 함수 사용법: cstdlib 라이브러리에 있다. abs(값); 이렇게 사용.
*/