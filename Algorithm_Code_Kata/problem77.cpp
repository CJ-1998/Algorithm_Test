/*
제목
    n^2 배열 자르기

문제 설명
    정수 n, left, right가 주어집니다. 
    다음 과정을 거쳐서 1차원 배열을 만들고자 합니다.
        n행 n열 크기의 비어있는 2차원 배열을 만듭니다.
        i = 1, 2, 3, ..., n에 대해서, 다음 과정을 반복합니다.
        1행 1열부터 i행 i열까지의 영역 내의 모든 빈 칸을 숫자 i로 채웁니다.
        1행, 2행, ..., n행을 잘라내어 모두 이어붙인 새로운 1차원 배열을 만듭니다.
        새로운 1차원 배열을 arr이라 할 때, arr[left], arr[left+1], ..., arr[right]만 남기고 나머지는 지웁니다.

    정수 n, left, right가 매개변수로 주어집니다. 
    주어진 과정대로 만들어진 1차원 배열을 return 하도록 solution 함수를 완성해주세요.

제한사항
    1 ≤ n ≤ 10^7
    0 ≤ left ≤ right < n^2
    right - left < 10^5

입출력 예
    n	left	right	result
    3	2	    5	    [3,2,2,3]
    4	7	    14	    [4,3,3,3,4,4,4,4]
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int start = 0; 
    int end = 0;
    
    for(int i=0;i<n;i++){
        if(n*i<=left&&left<n*(i+1)){
            start=i;
        }
        
        if(n*i<=right&&right<n*(i+1)){
            end=i;
        }
    }
    
    int a1=start;
    int a2=left-(n*start);
    int b1=end;
    int b2=right-(n*end);
    
    int x=a1;
    int y=a2;
    
    for(int i=0;i<=right-left;i++){
        if(x==0||y==0){
            answer.push_back(x+y+1);
        }
        else if(x>=1&&y>=1){
            if(x==1||y==1){
                answer.push_back(x+y);
            }
            else{
                int minus=min(x,y)-1;
                answer.push_back(x+y-minus);
            }
        }
        
        y++;
        if(y==n){
            y=0;
            x++;
        }
    }
    
    return answer;
}
    
// 1 2 3 4 5
// 2 2 3 4 5
// 3 3 3 4 5
// 4 4 4 4 5
// 5 5 5 5 5

// 00 01 02 03 04
// 10 11 12 13 14
// 20 21 22 23 24
// 30 31 32 33 34
// 40 41 42 43 44