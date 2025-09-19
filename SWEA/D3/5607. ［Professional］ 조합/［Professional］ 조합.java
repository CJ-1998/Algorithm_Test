import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static final long NUM = 1234567891;

	static long power(long c, long n) {
		long result = 1;
		long base = c;
		while (n > 0) {
			if (n % 2 == 1) {
				result = (result * base) % NUM;
			}
			base = (base * base) % NUM;
			n /= 2;
		}
		return result;
	}

	static long factorial(long n) {
		long result = 1;
		for (int i = 1; i <= n; i++) {
			result = (result * i) % NUM;
		}
		return result;
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine().trim());
			int n = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());

			long numerator = factorial(n); // n!
			long denominator = (factorial(r) * factorial(n - r)) % NUM; // (r! * (n-r)!) % NUM
			long answer = (numerator * power(denominator, NUM - 2)) % NUM; // 페르마 소정리 이용

			sb.append("#").append(test_case).append(" ").append(answer).append("\n");
		}
		System.out.println(sb.toString());
	}
}

// 문제 이해
// N, R 주어짐
// nCr 값을 1234567891로 나눈 나머지 출력

// 제약 사항 
// TC = 1~20 -> 2초 -> 1개당 천만
// N, R = 1~1,000,000 = 10^6 -> 천만

// 문제 풀이
// DP?
// nCr = n-1Cr + n-1Cr-1 

// DP 테이블 다 채우려면 10^6 * 10^6 = 10^12?

// 페르마 소정리
// p가 소수일 때
// a^p % p == a % p

// a가 p의 배수 아니면 
// a^p-1 % p == 1 % p

// 조합 페르마 소정리로 빠르게 구하기
// 조합 숫자 커지면 DP로 못 구함
// nCr = n! / (n-r)! * r!

// (n-r)! * r! 는 p의 배수가 아님 (p는 소수)
// 그래서 (n-r)! * r! ^ p-1 == 1 % p 

// ((n-r)! * r!) * ((n-r)! * r! ^ p-2) == 1 % p

// n! * (((n-r)! * r!) ^ p-2) % p = n! / ((n-r)! * r!) % p
// => n! * (((n-r)! * r!) ^ p-2) % p = nCr % p

// 분할 정복을 사용한 거듭 제곱
// 원래 거듭 제곱 = O(n) = x^n

// n이 짝수면 
// c^n = c^n/2 * c^n/2 

// n이 홀수면 
// c^n = c^n-1/2 * c^n-1/2 * c

// 거듭 제곱 합수
// n이 0보다 큰 동안 반복
// 홀수이면 결과에 c 한번 곱합
// c를 제곱하고 n을 절반으로 줄임
// n이 줄어드는 동안 제곱
