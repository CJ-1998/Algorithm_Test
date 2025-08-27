import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static class Coordinate {
		int x;
		int y;

		Coordinate(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int people;
	static Coordinate company;
	static Coordinate home;

	static Coordinate[] coordinates;
	static Coordinate[] selectedCoordinates;
	static boolean[] visited;

	static int minDistance;

	static void permutation(int selectIndex) {

		if (selectIndex == people) {
			int distance = 0;
			distance += (Math.abs(company.x - selectedCoordinates[0].x)
					+ Math.abs(company.y - selectedCoordinates[0].y));
			for (int count = 0; count < people - 1; count++) {
				distance += (Math.abs(selectedCoordinates[count].x - selectedCoordinates[count + 1].x)
						+ Math.abs(selectedCoordinates[count].y - selectedCoordinates[count + 1].y));
			}
			distance += (Math.abs(selectedCoordinates[people - 1].x - home.x)
					+ Math.abs(selectedCoordinates[people - 1].y - home.y));

			if (distance < minDistance) {
				minDistance = distance;
			}

			return;
		} else {
			for (int index = 0; index < people; index++) {
				if (visited[index]) {
					continue;
				}

				visited[index] = true;
				selectedCoordinates[selectIndex] = coordinates[index];
				permutation(selectIndex + 1);
				visited[index] = false;
			}
		}

	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());

		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine().trim());
			people = Integer.parseInt(st.nextToken());

			coordinates = new Coordinate[people];
			selectedCoordinates = new Coordinate[people];
			visited = new boolean[people];

			st = new StringTokenizer(br.readLine().trim());
			for (int count = 0; count < people + 2; count++) {
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());

				if (count == 0) {
					company = new Coordinate(x, y);
				} else if (count == 1) {
					home = new Coordinate(x, y);
				} else {
					coordinates[count - 2] = new Coordinate(x, y);
				}
			}

			minDistance = Integer.MAX_VALUE;
			permutation(0);

			sb.append("#").append(test_case).append(" ").append(minDistance).append("\n");
		}
		System.out.println(sb.toString());

	}
}

// 문제 이해
// 냉장고 고객 N명에게 배달 -> 2~10
// 회사, 집, 고객 위치 (x, y)로 주어짐 
// 0 <= x, y <= 100

// 두 위치 사이 거리 = |x1-x2| + |y1-y2|
// 각 좌표 모두 다름

// 회사 출발 -> N명 모두 -> 집으로 복귀 
// 경로 가장 짧은 것 찾기

// 이동 거리 출력

// 입력
// 회사 좌표, 집 좌표, N명 좌표
// x, y 공백으로 구분되어 제공

// 문제 풀이