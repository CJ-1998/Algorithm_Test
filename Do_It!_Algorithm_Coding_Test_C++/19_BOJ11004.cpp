/*
문제:
    수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에 N(1 ≤ N ≤ 5,000,000)과 K (1 ≤ K ≤ N)이 주어진다.
    둘째에는 A1, A2, ..., AN이 주어진다. (-10^9 ≤ Ai ≤ 10^9)

출력:
    A를 정렬했을 때, 앞에서부터 K번째 있는 수를 출력한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num=0;
    int cnt=0;

    cin>>num>>cnt;

    vector<int> arr(num);
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    cout<<arr[cnt-1];

    return 0;
}