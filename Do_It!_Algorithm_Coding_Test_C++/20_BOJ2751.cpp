/*
문제:
    N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력:
    첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 
    둘째 줄부터 N개의 줄에는 수가 주어진다. 
    이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 
    수는 중복되지 않는다.

출력:
    첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int>arr;
vector<int>arr2;

void merge(int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j]) 
			arr2[k++] = arr[i++]; 
		else
			arr2[k++] = arr[j++];
	}

	int tmp = i>mid ? j : i;
	
	while(k<=right) arr2[k++] = arr[tmp++];

	for (int i=left;i<=right;i++) arr[i] = arr2[i];
}

void partition(int left,int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2; 
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main()
{
    int N;
    cin >> N;
	
	for (int i=0;i<N;i++){
        int x;
        cin >> x;
        arr.push_back(x);
        arr2.push_back(0);
    }

	partition(0, N - 1);

	for (int i=0;i<N;i++){
        cout << arr[i] << "\n";
    }
}

/*
배운 점:
    1. sort 알고리즘은 quick sort로 구현되어 있어서 평균 O(nlogn)인데 최악이 O(n^2)이다.
    2. merge sort는 항상 O(nlogn)이다. 
    3. merge sort는 재귀로 분할한다. 분할 함수에서 분할하고 merge가 같이 있다.
*/