/*
문제:
    수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
    예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력:
    첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
    둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력:
    첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n=0;
    scanf("%d",&n);

    vector<int> v;

    for(int i=0;i<n;i++){
        int temp=0;
        scanf("%d",&temp);
        v.push_back(temp);
    }

    vector<int> len;
    for(int i=0;i<n;i++){
        len.push_back(1);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                if(len[i]<=len[j])
                    len[i]=len[j]+1;
            }
        }
    }

    sort(len.begin(),len.end());
    printf("%d",len[len.size()-1]);

    return 0;
}

/*
개선 사항:
    1. 값들을 벡터에 넣는데 새로 추가해야 하는 값이 가장 뒤에 있는 값보다 작거나 같으면 lower_bound 사용해서 추가해야 하는 값이 들어가야 하는 위치 찾아서 거기에 넣어준다. 이렇게 하면 마지막에는 가장 긴 증가하는 수열이 나온다. 

배운 점:
    1. lower_bound(v.begin(), v.end(), n) - v.begin() 하면 n보다 같거나 큰 숫자가 처음 등장하는 index 반환해준다. 
    2. upper_bound(v.begin(), v.end(), n) - v.begin() 하면 n보다 큰 숫자가 처음 등장하는 index 반환해준다. 
    3. 가장 긴 증가하는 부분 수열 구하는 방법 with dynamic programming
*/