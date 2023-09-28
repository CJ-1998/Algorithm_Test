/*
문제:
    2차원 평면 위의 점 N개가 주어진다. 
    좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력:
    첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 
    둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. 
    (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

출력:   
    첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){

    vector<pair<int, int>> arr;

    int cnt=0;
    cin>>cnt;

    for(int i=0;i<cnt;i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        pair<int, int> temp=make_pair(temp1,temp2);
        arr.push_back(temp);
    }

    sort(arr.begin(),arr.end());

    for(int i=0;i<cnt;i++){
        cout<<arr[i].first<<" "<<arr[i].second<<"\n";
    }

    return 0;
}

/*
배운 점:
    1. pair 사용하려면 utility 라이브러리 include해야 한다. 
    2. pair 만들려면 make_pair 함수 사용
    3. pair 조회는 .first, .second 사용한다. 
    4. pair sort는 first를 기준으로 한다. 
*/