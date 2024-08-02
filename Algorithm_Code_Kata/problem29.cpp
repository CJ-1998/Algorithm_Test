/*
제목
    최대공약수와 최소공배수

문제 설명
    두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수, solution을 완성해 보세요. 
    배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다. 
    예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 [3, 12]를 반환해야 합니다.

제한 사항
    두 수는 1이상 1000000이하의 자연수입니다.

입출력 예
    n	m	return
    3	12	[3, 12]
    2	5	[1, 10]
*/

#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    int c;
    while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n,m));
    answer.push_back(lcm(n,m));
    return answer;
}