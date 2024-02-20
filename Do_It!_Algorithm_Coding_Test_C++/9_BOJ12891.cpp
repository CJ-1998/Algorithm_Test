/*
문제:
    평소에 문자열을 가지고 노는 것을 좋아하는 민호는 DNA 문자열을 알게 되었다. 
    DNA 문자열은 모든 문자열에 등장하는 문자가 {‘A’, ‘C’, ‘G’, ‘T’} 인 문자열을 말한다. 
    예를 들어 “ACKA”는 DNA 문자열이 아니지만 “ACCA”는 DNA 문자열이다. 
    이런 신비한 문자열에 완전히 매료된 민호는 임의의 DNA 문자열을 만들고 만들어진 DNA 문자열의 부분문자열을 비밀번호로 사용하기로 마음먹었다.
    하지만 민호는 이러한 방법에는 큰 문제가 있다는 것을 발견했다. 
    임의의 DNA 문자열의 부분문자열을 뽑았을 때 “AAAA”와 같이 보안에 취약한 비밀번호가 만들어 질 수 있기 때문이다. 
    그래서 민호는 부분문자열에서 등장하는 문자의 개수가 특정 개수 이상이여야 비밀번호로 사용할 수 있다는 규칙을 만들었다.
    임의의 DNA문자열이 “AAACCTGCCAA” 이고 민호가 뽑을 부분문자열의 길이를 4라고 하자. 
    그리고 부분문자열에 ‘A’ 는 1개 이상, ‘C’는 1개 이상, ‘G’는 1개 이상, ‘T’는 0개 이상이 등장해야 비밀번호로 사용할 수 있다고 하자. 
    이때 “ACCT” 는 ‘G’ 가 1 개 이상 등장해야 한다는 조건을 만족하지 못해 비밀번호로 사용하지 못한다. 
    하지만 “GCCA” 은 모든 조건을 만족하기 때문에 비밀번호로 사용할 수 있다.
    민호가 만든 임의의 DNA 문자열과 비밀번호로 사용할 부분분자열의 길이, 
    그리고 {‘A’, ‘C’, ‘G’, ‘T’} 가 각각 몇번 이상 등장해야 비밀번호로 사용할 수 있는지 순서대로 주어졌을 때 
    민호가 만들 수 있는 비밀번호의 종류의 수를 구하는 프로그램을 작성하자. 
    단 부분문자열이 등장하는 위치가 다르다면 부분문자열이 같다고 하더라도 다른 문자열로 취급한다.

입력:
    첫 번째 줄에 민호가 임의로 만든 DNA 문자열 길이 |S|와 비밀번호로 사용할 부분문자열의 길이 |P| 가 주어진다. (1 ≤ |P| ≤ |S| ≤ 1,000,000)
    두 번째 줄에는 민호가 임의로 만든 DNA 문자열이 주어진다.
    세 번째 줄에는 부분문자열에 포함되어야 할 {‘A’, ‘C’, ‘G’, ‘T’} 의 최소 개수가 공백을 구분으로 주어진다. 
    각각의 수는 |S| 보다 작거나 같은 음이 아닌 정수이며 총 합은 |S| 보다 작거나 같음이 보장된다.

출력:
    첫 번째 줄에 민호가 만들 수 있는 비밀번호의 종류의 수를 출력해라.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int length=0;
    int passwordLen=0;
    string password="";
    int A=0;
    int C=0;
    int G=0;
    int T=0;

    cin>>length>>passwordLen>>password>>A>>C>>G>>T;

    int aCnt=0;
    int cCnt=0;
    int gCnt=0;
    int tCnt=0;

    for(int i=0;i<passwordLen;i++){
        if(password[i]=='A') aCnt++;
        else if(password[i]=='C') cCnt++;
        else if(password[i]=='G') gCnt++;
        else if(password[i]=='T') tCnt++;
    }

    int answer=0;
    if(aCnt>=A && gCnt>=G && cCnt>=C && tCnt>=T) answer++;

    int start=0;
    int end=start+passwordLen-1;

    for(int i=0;i<length-passwordLen;i++){
        if(password[start]=='A') aCnt--;
        else if(password[start]=='C') cCnt--;
        else if(password[start]=='G') gCnt--;
        else if(password[start]=='T') tCnt--;

        start++;

        if(password[end+1]=='A') aCnt++;
        else if(password[end+1]=='C') cCnt++;
        else if(password[end+1]=='G') gCnt++;
        else if(password[end+1]=='T') tCnt++;

        end++;

        if(aCnt>=A && gCnt>=G && cCnt>=C && tCnt>=T) answer++;
    }

    cout<<answer<<endl;

    return 0;
}

/*
배운 점:
    1. 슬라이딩 윈도우 개념
*/