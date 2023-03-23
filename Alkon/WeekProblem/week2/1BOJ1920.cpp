/*
문제:
    N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력:
    첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

출력:
    M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n=0;
    scanf("%d", &n);

    vector<int> v;
    for(int i=0;i<n;i++){
        int temp=0;
        scanf("%d", &temp);
        v.push_back(temp);
    }

    int m=0;
    scanf("%d", &m);

    vector<int> v2;
    for(int i=0;i<m;i++){
        int temp=0;
        scanf("%d", &temp);
        v2.push_back(temp);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<m;i++){
        int answer=0;

        int start=0;
        int end=v.size()-1;

        int num=v2[i];

        while(true){
            int mid=(start+end)/2;
            if(v[mid]>num){
                end=mid;
            }
            else if(v[mid]<num){
                start=mid;
            }
            else{
                answer=1;
                break;
            }
            if(start+1==end){
                if(v[start]==num||v[end]==num){
                    answer=1;
                    break;
                }
                else{
                    break;
                }
            }
        }
        printf("%d \n", answer);
    }

    return 0;
}

/*
개선 사항:
    1. 이진 탐색의 while문 조건문은 start≤end이다. 그리고 왼쪽에 값이 있으면 end를 mid-1로 바꾸고 오른쪽에 값이 있으면 start를 mid+1로 바꾼다. 
    2. 나는 그냥 start, end 모두 mid로 바꿨다. 그러면 문제가 값이 오른쪽 끝에 있으면 찾을 수가 없었다. 그래서 나는 마지막에 start+1==end인 경우 start와 end index에 값이 있는지 확인했다.

배운 점:
    1. 이진 탐색 사용법. 
    2. while문 조건문은 start≤end.
    3. mid로 바꿀 때에는 end는 mid-1, start는 mid+1. 안 그러면 끝의 값 확인 못함 (2로 나눈 정수가 mid여서)
    4. 함수 호출의 overhead 꽤 있다. 시간 아슬아슬하면 함수 사용 못한다.
*/