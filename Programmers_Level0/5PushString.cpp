/*
문제: 
    문자열 "hello"에서 각 문자를 오른쪽으로 한 칸씩 밀고 
    마지막 문자는 맨 앞으로 이동시키면 "ohell"이 됩니다. 
    이것을 문자열을 민다고 정의한다면 
    문자열 A와 B가 매개변수로 주어질 때, 
    A를 밀어서 B가 될 수 있다면 몇 번 밀어야 하는지 횟수를 
    return하고 밀어서 B가 될 수 없으면 -1을 return 하도록 
    solution 함수를 완성해보세요.

제한 사항: 
    0 < A의 길이 = B의 길이 < 100
    A, B는 알파벳 소문자로 이루어져 있습니다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    int len=A.length();
    string* allString = new string[len];
    char* allChar=new char[len];
    
    for(int index=0;index<len;index++){
        allChar[index]=A.at(index);
    }
    
    string charArr="";
    for(int i=0;i<len;i++){
        charArr+=allChar[i];
    }
    allString[0]=charArr;
    
    // string charArr(allChar);
    // allString[0]=charArr;
    
    for(int rotate=1;rotate<len;rotate++){
        char lastChar=allChar[len-1];
        for(int change=len-2;change>-1;change--){
            allChar[change+1]=allChar[change];
        }
        allChar[0]=lastChar;
        
        string charToString="";
        for(int i=0;i<len;i++){
            charToString+=allChar[i];
        }
        allString[rotate]=charToString;
        
        // string charToString(allChar);
        // allString[rotate]=charToString;
    }
    
    for(int index=0;index<len;index++){
        if(allString[index].compare(B)==0){
            return index;
        }
    }
    
    answer=-1;
    
    return answer;
}

/*
개선 사항:
    1. B+=B; 하고 find() 사용하는 방법 있을 수 있다. 
    2. rotate() 함수로 간단하게 돌릴 수 있다. 
    3. substr()로 문자열 간단하게 밀 수 있다. 

배운 점:
    1. string.length()로 string 길이 구하기
    2. string.at(index)로 string의 특정 index char 구하기
    3. string.compare(string1)로 string 비교. 이때 0이여야 같은 값
    4. char -> string에서 string 생성자로 바꾸면 널문자 추가됨
    5. 그래서 for문으로 하나하나 더해서 바꿔야 함
    6. find(), rotate(), substr() 함수
*/