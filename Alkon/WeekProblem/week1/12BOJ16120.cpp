/*
문제:
    bryan은 PPAP를 좋아한다. bryan은 어떻게 하면 사람들에게 PPAP를 전파할 수 있을까 고민하던 중 PPAP 문자열이라는 것을 고안하게 되었다.
    PPAP 문자열은 문자열 P에서 시작하여, 문자열 내의 P를 PPAP로 바꾸는 과정을 반복하여 만들 수 있는 문자열로 정의된다. 정확하게는 다음과 같이 정의된다.
        P는 PPAP 문자열이다.
        PPAP 문자열에서 P 하나를 PPAP로 바꾼 문자열은 PPAP 문자열이다.
    예를 들어 PPAP는 PPAP 문자열이다. 또한, PPAP의 두 번째 P를 PPAP로 바꾼 PPPAPAP 역시 PPAP 문자열이다.
    문자열이 주어졌을 때, 이 문자열이 PPAP 문자열인지 아닌지를 알려주는 프로그램을 작성하여라.

입력:
    첫 번째 줄에 문자열이 주어진다. 문자열은 대문자 알파벳 P와 A로만 이루어져 있으며, 문자열의 길이는 1 이상 1,000,000 이하이다.

출력:
    첫 번째 줄에 주어진 문자열이 PPAP 문자열이면 PPAP를, 아닌 경우 NP를 출력한다.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    string p;
    cin>>p;

    stack<char> s;

    for(int i=0;i<p.length();i++){
        if(p[i]=='P'){
            if(!s.empty()){
                if(s.top()=='A'){
                    char one='A';
                    s.pop();
                    if(!s.empty()&&s.top()=='P'){
                        char two='P';
                        s.pop();

                        if(!s.empty()&&s.top()=='P'){
                            s.pop();
                            s.push('P');
                        }
                        else{
                            s.push(two);
                            s.push(one);
                            s.push(p[i]);
                        }
                    }
                    else{
                        s.push(one);
                        s.push(p[i]);
                    }
                }
                else{
                    s.push(p[i]);
                }
            }
            else{
                s.push(p[i]);
            }
        }
        else{
            s.push(p[i]);
        }

    }

    string answer;

    if(s.top()=='P'&&s.size()==1){
        answer="PPAP";
    }
    else{
        answer="NP";
    }

    cout<<answer<<endl;

    return 0;
}

/*
개선 사항:
    1. AP의 개수와 PP의 개수를 세서 이게 맞는 경우에 PPAP를 빼고 P를 넣는 것이다. 

배운 점:
    1. stack 사용법
*/