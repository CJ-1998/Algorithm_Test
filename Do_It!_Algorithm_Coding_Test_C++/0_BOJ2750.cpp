/*
문제:
    N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력:
    첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력:
    첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num=0;
    cin>>num;

    vector<int> vec;
    for(int i=0;i<num;i++){
        int temp=0;
        cin>>temp;
        vec.push_back(temp);
    }

    sort(vec.begin(),vec.end());
    for(int i=0;i<num;i++){
        cout<<vec[i]<<endl;
    }

    return 0;
}

/*
배운 점:
    1. 시간 제한 2초이니 2억번 이하 연산 횟수로 문제 해결해야 한다. 연산 횟수는 1초에 1억번.
    2. 시간 복잡도는 항상 데이터 크기 가장 클 때로 생각.
    3. 문제에서 주어진 시간 제한과 데이터 크기 바탕으로 어떤 정렬 알고리즘 사용할지 판단.
    4. 시간 복잡도 도출 기준은 1: 상수는 시간 복잡도 계산서 제외된다. 2: 가장 많이 중첩된 반복문의 수행 횟수가 시간 복잡도 기준이 된다. 
    5. 시간 복잡도 생각과 sort 함수 사용
*/