
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static class Coordinate {
		int x;
		int y;

		public Coordinate(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int coordinateCount;
	static Coordinate[] coordinates;

	static long calculateVectorSum;
	static long minVectorSum;

	static boolean[] selected;

	static void combination(int selectedIndex, int elementIndex) {
		if (selectedIndex == coordinateCount / 2) {
			long xVectorSum = 0;
			long yVectorSum = 0;
			for (int count = 0; count < coordinateCount; count++) {
				if (selected[count]) {
					xVectorSum += coordinates[count].x;
					yVectorSum += coordinates[count].y;
				} else {
					xVectorSum -= coordinates[count].x;
					yVectorSum -= coordinates[count].y;
				}
			}

			// calculateVectorSum = (xVectorSum * xVectorSum) + (yVectorSum * yVectorSum);
			minVectorSum = Math.min(minVectorSum, (xVectorSum * xVectorSum) + (yVectorSum * yVectorSum));
		}
		if (elementIndex == coordinateCount) {
			return;
		}

		selected[elementIndex] = true;
		combination(selectedIndex + 1, elementIndex + 1);

		selected[elementIndex] = false;
		combination(selectedIndex, elementIndex + 1);
	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine().trim());
			coordinateCount = Integer.parseInt(st.nextToken());

			coordinates = new Coordinate[coordinateCount];
			selected = new boolean[coordinateCount];

			for (int count = 0; count < coordinateCount; count++) {
				st = new StringTokenizer(br.readLine().trim());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				coordinates[count] = new Coordinate(x, y);
			}

			calculateVectorSum = 0;
			minVectorSum = Long.MAX_VALUE;
			combination(0, 0);
			sb.append("#").append(test_case).append(" ").append(minVectorSum).append("\n");
		}
		System.out.println(sb.toString());
	}

}

// 문제 풀이
// 지렁이 친구 N마리
// 소개팅 주선

// 주선 방법
// 지렁이 두마리 매칭
// 한 지렁이에게 다른 지렁이가 있는 곳으로 가게 하기

// 지렁이들이 움직인 벡터 합 크기 작게하기
// 벡터 = |x*x + y*y|

// 모든 지렁이들을 소개팅 주선
// 각 지렁이 움직인 벡터 최소화

// 입력
// 지렁이 수 N = 2~20
// 지렁이들 좌표
// 좌표 = -10만 ~ 10만

// 문제 풀이
// 벡터 long? 10만 * 10만 = 10^10 = 백억?

// 벡터 
// A = x1, y1 / B = x2, y2
// AB = x2-x1 , y2-y1

// 벡터 합
// AB = x1, y1 CD = x2, y2
// 벡터 합 = x1+x2, y1+y2

// 벡터 크기가 
// x*x + y*y

// 10개 쌍 만들기
// 20개 나열 = 20!
// 각 쌍 내 두명 순서 바뀌는 중복 제거 = /2^10
// 10쌍 순서 중복 제거 = /10!
// = 20!/2^10*10! = 6억5천?;;

// 10개 쌍
// a b이면
// a가 가는 것, b가 가는 것 2개
// 전체 조합 = 2^10

// 전체 시간
// = 6억5천 * 1024 = 6500억?;;;

// 100개 5초면
// 1개에 500백만

// 각 점에서 다른 점으로 모든 벡터 구해 놓기
// 20*20 = 400

// 10개 점 고름 = 20C10 = 18만
// 각 점에서 나가는 벡터들 선택 (10개 점에 있는 것 제외)
// ex : 1 2 4 5 ....
// 벡터 선택 : 1->2(x), 1->3(O)
// -> 10*10 = 100?
// -> 지금 선택할 점이 10개 안에 들어있는지 매번 확인 -> 10
// -> 10*10*10 = 1000

// 총 시간 복잡도
// = 1억8000만? 

// 20C10 하고 
// 선택된 점 x, y는 더하고
// 선택 안된 점 x, y는 뺌 
// 벡터 AB = x1-x2 , y1-y2
// 이런 벡터들 더하는거라 그런듯;;;
