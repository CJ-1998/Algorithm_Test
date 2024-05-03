/*
문제
    세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 
    그리고 나서 세준이는 괄호를 모두 지웠다.
    그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
    괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
    첫째 줄에 식이 주어진다. 
    식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 
    그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 
    수는 0으로 시작할 수 있다. 
    입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
    첫째 줄에 정답을 출력한다.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str="";
    cin>>str;

    vector<int> numbers;
    vector<char> operators;

    string temp="";

    for(int i=0;i<str.size();i++){
        if(i==str.size()-1){
            temp+=str[i];
            numbers.push_back(stoi(temp));
            temp="";
        }

        if(str[i]=='+' || str[i]=='-'){
            numbers.push_back(stoi(temp));
            temp="";
            operators.push_back(str[i]);
        }
        else{
            temp+=str[i];
        }
    }

    int plusNum=numbers[0];
    int minusNum=0;
    int result=0;

    for(int i=0;i<operators.size();i++){
        if(operators[i]=='-'){
            minusNum+=numbers[i+1];
            for(int j=i+1;j<operators.size();j++){
                if(operators[j]=='+'){
                    minusNum+=numbers[j+1];
                    i++;
                }
                else{
                    break;
                }
            }
        }
        else{
            plusNum+=numbers[i+1];
        }
    }

    result=plusNum+(-1*minusNum);

    cout<<result<<endl;

    return 0;
}

/*
배운 점:
    1. 문자열을 숫자로 변환할 때 stoi() 함수를 사용한다.
    2. 문제를 제대로 파악하는 것이 중요하다. (어떻게 괄호를 치는지 이해하는데 오래 걸림)
    3. 문제를 보고 규칙을 파악하고 가장 작을 것 같은 로직을 찾아야 한다. (-이면 음수가 되므로 뒤에 +면 더하고 -면 따로 빼야 한다.)

걸린 시간: 
    21m29s
*/