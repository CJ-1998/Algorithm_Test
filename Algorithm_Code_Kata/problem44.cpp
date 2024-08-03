/*
제목
    2016년

문제 설명
    2016년 1월 1일은 금요일입니다. 
    2016년 a월 b일은 무슨 요일일까요? 
    두 수 a ,b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, solution을 완성하세요. 
    요일의 이름은 일요일부터 토요일까지 각각 SUN,MON,TUE,WED,THU,FRI,SAT입니다. 
    예를 들어 a=5, b=24라면 5월 24일은 화요일이므로 문자열 "TUE"를 반환하세요.

제한 조건
    2016년은 윤년입니다.
    2016년 a월 b일은 실제로 있는 날입니다. (13월 26일이나 2월 45일같은 날짜는 주어지지 않습니다)

입출력 예
    a	b	result
    5	24	"TUE"
*/

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int day=0;
    for(int i=2;i<=a;i++){
        if(i<=8){
            if(i==3){
                day+=29;
            }
            else if(i%2==0){
                day+=31;
            }
            else{
                day+=30;
            }
        }
        else{
            if(i%2==1){
                day+=31;
            }
            else{
                day+=30;
            }
        }
    }
    
    day+=b;
    day--;
    
    if(day%7==0){
        answer+="FRI";
    }
    else if(day%7==1){
        answer+="SAT";
    }
    else if(day%7==2){
        answer+="SUN";
    }
    else if(day%7==3){
        answer+="MON";
    }
    else if(day%7==4){
        answer+="TUE";
    }
    else if(day%7==5){
        answer+="WED";
    }
    else{
        answer+="THU";
    }
    
    return answer;
}