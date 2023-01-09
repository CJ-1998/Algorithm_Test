/*
문제:
    3x 마을 사람들은 3을 저주의 숫자라고 생각하기 때문에 3의 배수와 숫자 3을 사용하지 않습니다. 3x 마을 사람들의 숫자는 다음과 같습니다.

        10진법	3x 마을에서 쓰는 숫자	10진법	3x 마을에서 쓰는 숫자
        1	    1	                    6	    8
        2	    2	                    7	    10
        3	    4	                    8	    11
        4	    5	                    9	    14
        5	    7	                    10	    16
    정수 n이 매개변수로 주어질 때, n을 3x 마을에서 사용하는 숫자로 바꿔 return하도록 solution 함수를 완성해주세요.
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i=1;i<n;i++){
        if(answer%3==0){
            answer++;
        }
        else{
            string temp=to_string(answer);
            for(int j=0;j<temp.length();j++){
                if(temp[j]=='3'){
                    answer++;
                    break;
                }
            }
        }
        answer++;
        while(true){
            if(answer%3==0){
                answer++;
                continue;
            }
            else{
                bool check=false;
                string temp1=to_string(answer);
                for(int j=0;j<temp1.length();j++){
                    if(temp1[j]=='3'){
                        answer++;
                        check=true;
                        break;
                    }
                }
                if(check){
                    continue;
                }
            }
            break;
        }
    }
    return answer;
}

/*
개선 사항:
    1. 걸리지 않는 것들을 다 넣어 두고 거기서 찾는 방법도 있다.
*/