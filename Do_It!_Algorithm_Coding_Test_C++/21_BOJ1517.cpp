/*
문제:
    N개의 수로 이루어진 수열 A[1], A[2], …, A[N]이 있다. 
    이 수열에 대해서 버블 소트를 수행할 때, Swap이 총 몇 번 발생하는지 알아내는 프로그램을 작성하시오.
    버블 소트는 서로 인접해 있는 두 수를 바꿔가며 정렬하는 방법이다. 
    예를 들어 수열이 3 2 1 이었다고 하자. 
    이 경우에는 인접해 있는 3, 2가 바뀌어야 하므로 2 3 1 이 된다. 
    다음으로는 3, 1이 바뀌어야 하므로 2 1 3 이 된다. 
    다음에는 2, 1이 바뀌어야 하므로 1 2 3 이 된다. 
    그러면 더 이상 바꿔야 할 경우가 없으므로 정렬이 완료된다.

입력:
    첫째 줄에 N(1 ≤ N ≤ 500,000)이 주어진다.
    다음 줄에는 N개의 정수로 A[1], A[2], …, A[N]이 주어진다. 
    각각의 A[i]는 0 ≤ |A[i]| ≤ 1,000,000,000의 범위에 들어있다.

출력:
    첫째 줄에 Swap 횟수를 출력한다.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> arr(500001);
vector<int> answer(500001);
long long swapCount;

long long merge(int left, int right)
{
    long long swapCnt=0;

	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j]) 
			answer[k++] = arr[i++]; 
		else{
            swapCnt+=(j-k);
			answer[k++] = arr[j++];
        }
	}

	int tmp = i>mid ? j : i;
	
	while(k<=right) answer[k++] = arr[tmp++];

	for (int i=left;i<=right;i++) arr[i] = answer[i];

    return swapCnt;
}

long long partition(int left,int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2; 
		long long a = partition(left, mid);
		long long b= partition(mid + 1, right);
		long long c= merge(left, right);

        return a + b + c;
	}
    else{
        return 0;
    }
}

int main(){

    int n;
    cin >> n;

    swapCount = 0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    swapCount = partition(0, n-1);

    cout<<swapCount<<endl;

    return 0;
}

/*
배운 점
    1. merge sort의 구현 방법

고민할 점
    1. 시간 초과 및 범위 초과에 대한 생각
    2. long long 변수와 int 변수 사용했을 때의 시간 차이
*/