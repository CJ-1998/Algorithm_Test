import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int[] copy(int[] arr) {
		int[] copyArr = new int[arr.length];
		for (int i = 0; i < arr.length; i++) {
			copyArr[i] = arr[i];
		}
		return copyArr;
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[] arr = new int[N + 1];
		int[] copyArr = new int[N + 1];

		for (int i = 0; i < arr.length; i++) {
			arr[i] = i;
			copyArr[i] = i;
		}

//		for (int temp = 1; temp < arr.length; temp++) {
//			System.out.print(arr[temp] + " ");
//		}
//		System.out.println();

		// 100번
		// 100*200 = 20000?
		for (int count = 0; count < M; count++) {
			st = new StringTokenizer(br.readLine().trim());
			int i = Integer.parseInt(st.nextToken());
			int j = Integer.parseInt(st.nextToken());

			int index = i;

			// 100번
			for (int reverse = j; reverse >= i; reverse--) {
				arr[index++] = copyArr[reverse];
			}

			// 100번
			copyArr = copy(arr);
		}

		for (int temp = 1; temp < arr.length; temp++) {
			sb.append(arr[temp]).append(" ");
		}
		System.out.println(sb.toString());
	}
}

// 문제 이해
// 1~N번 책 책장에 일렬로 꽂혀있음
// 사서가 책장 정리 위해 M번에 걸쳐 구간 선택
// 선택한 구간 책 순서 뒤집음

// i~j 주어지면 책 순서 뒤집음
// M번 작업 반복 후 책장 상태 출력

// 제약 사항
// N, M = 1~100
// M개 줄에 i, j 주어짐 

// 문제 풀이
// 처음에 N개 숫자 순서대로 저장하며 초기화 
// 2개의 배열 유지
// i j 들어오면 숫자 반대로 해서 넣음
// 2개 배열 바꿔줌

// 배열 복사 = 100
// 각 턴마다 복사함 = 100*100

// 반대로 넣기 = 최대 100
// 각 턴마다 = 100*100