/*
문제:
    N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.
    N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.  
    수의 위치가 다르면 값이 같아도 다른 수이다.

입력:
    첫째 줄에는 수의 개수 N(1 ≤ N ≤ 2,000), 두 번째 줄에는 i번째 수를 나타내는 Ai가 N개 주어진다. (|Ai| ≤ 1,000,000,000, Ai는 정수)

출력:
    좋은 수의 개수를 첫 번째 줄에 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int cnt=0;
    cin>>cnt;

    vector<int> v;

    for(int i=0;i<cnt;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    int answer=0;

    for(int i=0;i<cnt;i++){
        int start=0;
        int end=cnt-1;
        
        while(true){
            // cout<<i<<" "<<start<<" "<<end<<endl;
            if(start==end){
                break;
            }

            if(i==start){
                start++;
                continue;
            }
            if(i==end){
                end--;
                continue;
            }

            if(v[start]+v[end]==v[i]){
                answer++;
                break;
            }
            if(v[start]+v[end]>v[i]){
                end--;
                continue;
            }

            if(v[start]+v[end]<v[i]){
                start++;
                continue;
            }
        }
    }

    cout<<answer<<endl;

    return 0;
}

/*
배운 점:
    1. 투 포인터 알고리즘이랑 이진 탐색을 섞을 수도 있다. 
    2. 벡터 중복 제거는 정렬한 후 v.erase(unique(v.begin(), v.end()),v.end());
    3. 벡터에서 특정 값 찾는데 시간 초과 난다? → 이진 탐색
    4. 이진 탐색은 정렬이 되어 있어야 한다.
*/