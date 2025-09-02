import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int[][] map;
	static final int SIZE = 4;
	static final int SELECT_COUNT = 7;

	static int[] dx = { 0, -1, 0, 1 };
	static int[] dy = { -1, 0, 1, 0 };

	static Map<String, Integer> saveMap;

	static int[] selectedNumber;

	static boolean check(int x, int y) {
		if ((0 <= x && x < SIZE) && (0 <= y && y < SIZE)) {
			return true;
		}
		return false;
	}

	static void find(int x, int y, int selectIndex) {
		if (selectIndex == SELECT_COUNT) {
			String temp = "";
			for (int number : selectedNumber) {
				temp += number;
			}
//			System.out.println(temp);
			saveMap.put(temp, 0);
			return;
		}

		selectedNumber[selectIndex] = map[x][y];

		for (int count = 0; count < SIZE; count++) {
			int newX = x + dx[count];
			int newY = y + dy[count];

			if (check(newX, newY)) {
				find(newX, newY, selectIndex + 1);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());

		for (int test_case = 1; test_case <= T; test_case++) {

			map = new int[SIZE][SIZE];
			saveMap = new HashMap<>();

			for (int row = 0; row < SIZE; row++) {
				st = new StringTokenizer(br.readLine().trim());
				for (int column = 0; column < SIZE; column++) {
					int temp = Integer.parseInt(st.nextToken());
					map[row][column] = temp;
				}
			}

			selectedNumber = new int[SELECT_COUNT];
			for (int row = 0; row < SIZE; row++) {
				for (int column = 0; column < SIZE; column++) {
					find(row, column, 0);
				}
			}
			int numberCount = saveMap.size();
			sb.append("#").append(test_case).append(" ").append(numberCount).append("\n");
		}
		System.out.println(sb.toString());
	}
}

// 문제 이해
// 4*4 크기 격자판
// 각 격자판에 0~9 사이 숫자

// 격자판 임의의 위치에서 시작
// 동서남북 네방향으로 인접한 격자로 총 여섯번 이동
// 각 칸에 적힌 숫자 이어 붙이면 7자리 숫자

// 이동할 때 한번 거친 격자칸 다시 가도 됨
// 0으로 시작하는 수도 만들 수 있음

// 만들 수 있는 서로 다른 일곱자리 수들의 개수 구하기

// 문제 풀이
// 횟수 세면서 동서남북 이동?
// map으로 만들어서 저장?