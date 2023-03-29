/*
문제:
    집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.
    이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다. 예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)
    편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자. 그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

입력:
    첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 그리고 항상 K ≦ N 이다. 그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 231-1보다 작거나 같은 자연수이다.

출력:
    첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long answer=0;

    int k=0;
    int n=0;

    scanf("%d",&k);
    scanf("%d",&n);

    vector<int> v;
    for(int i=0;i<k;i++){
        int temp=0;
        scanf("%d",&temp);
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    long long small=v[0];
    long long big=v[v.size()-1];

    //printf("%lld %lld\n",small, big);

    long long start=1;
    long long end=big;

    while(start<=end){
        //printf("%d %lld %lld\n", answer, start, end);
        long long sum=0;
        long long mid=(start+end)/2;
        for(int i=0;i<v.size();i++){
            long long temp=(long long)v[i]/mid;
            sum+=temp;
        }

        if(sum>=n){
            answer=mid;
            start=mid+1;
            // break;
        }
        else if(sum>n){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    printf("%lld",answer);

    return 0;
}

/*
배운 점:
    1. 매개변수 탐색은 같으면 끝내는 것이 아니고 start를 계속 가면서 찾는 것 같다. 
*/