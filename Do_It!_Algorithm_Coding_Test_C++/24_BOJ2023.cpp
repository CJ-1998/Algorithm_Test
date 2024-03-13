/*
문제:
	수빈이가 세상에서 가장 좋아하는 것은 소수이고, 취미는 소수를 가지고 노는 것이다. 
	요즘 수빈이가 가장 관심있어 하는 소수는 7331이다.
	7331은 소수인데, 신기하게도 733도 소수이고, 73도 소수이고, 7도 소수이다. 
	즉, 왼쪽부터 1자리, 2자리, 3자리, 4자리 수 모두 소수이다! 수빈이는 이런 숫자를 신기한 소수라고 이름 붙였다.
	수빈이는 N자리의 숫자 중에서 어떤 수들이 신기한 소수인지 궁금해졌다. 
	N이 주어졌을 때, 수빈이를 위해 N자리 신기한 소수를 모두 찾아보자.

입력:
	첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다.

출력:
	N자리 수 중에서 신기한 소수를 오름차순으로 정렬해서 한 줄에 하나씩 출력한다.
*/

#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int cnt;

bool isPrime2(int n) {
	for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
		if (n%i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	//2 ~ n-1까지 약수가 없다면 소수이므로, true return
	return true;
}

void check (int num, int count){
	if(count==cnt){
		if(isPrime2(num)){
			cout << num << endl;
		}
		return ;
	}

	for(int i=1;i<10;i++){
		if(i%2==0){
			continue;
		}
		if(isPrime2(num*10+i)){
			check(num*10+i, count+1);
		}
	}


}

int main(){
	ios_base::sync_with_stdio(true);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> cnt;

	check(2, 1);
	check(3, 1);
	check(5, 1);
	check(7, 1);
 
    return 0;
}

/*
배운 점:
	1. 소수 판별 메서드는 2에서 그 숫자의 제곱근까지 for문 돌려서 나눠 떨어지는 것 있으면 소수 아닌 것이다. 
	2. 함수에 파라미터 넘길 때 num++ 이렇게 넘기면 함수 반환되고 ++ 되어서 넘어갈 때에는 num만 넘어간다. 
	3. 소수 각 자리수 판별할 때에는 먼저 1의 자리수는 2, 3, 5, 7만 된다. 
	4. 그리고 뒤에 자리수 붙일 때에는 짝수 붙으면 무조건 2의 배수라 소수 안되어서 1, 3, 5, 7, 9만 붙여서 소수인지 검사하면 된다. 
*/