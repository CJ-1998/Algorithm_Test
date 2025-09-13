import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int[][] graph;
	static List<Integer> startXs;
	static List<Integer> startYs;

	static int endX;
	static int endY;

	static int answerY;

	static boolean[][] visited;

	static final int MAP_SIZE = 100;

	static int[] dx = { 0, 0, 1 };
	static int[] dy = { -1, 1, 0 };

	static boolean checkCoordinate(int x, int y) {
		if ((0 <= x && x < MAP_SIZE) && (0 <= y && y < MAP_SIZE)) {
			return true;
		}
		return false;
	}

	static void findEnd(int x, int y, int startY) {
		// System.out.println("nowX: " + x + " nowY: " + y);
		if (x == endX && y == endY) {
			answerY = startY;
			return;
		}

		if (visited[x][y]) {
			return;
		}

		visited[x][y] = true;

		boolean moveLeftRight = false;
		for (int dir = 0; dir < 3; dir++) {
			int newX = x + dx[dir];
			int newY = y + dy[dir];
			if (checkCoordinate(newX, newY)) {
				// 좌 or 우로 이동 가능
				if (!visited[newX][newY] && graph[newX][newY] == 1) {
					if (dir == 0 || dir == 1) {
						moveLeftRight = true;
					}
				}
				// 좌 or 우로 이동 가능
				if (moveLeftRight) {
					// 아래로는 이동 가능해도 안 감
					if (dir == 2) {
						continue;
					}
				}
				if (graph[newX][newY] == 1 || graph[newX][newY] == 2) {
					if (!visited[newX][newY]) {
						findEnd(newX, newY, startY);
					}
				}
			}
		}

		return;
	}

	public static void main(String[] args) throws Exception {
		int T = 10;
		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine().trim());
			int trash = Integer.parseInt(st.nextToken());
			// 초기화
			startXs = new ArrayList<>();
			startYs = new ArrayList<>();

			answerY = 0;

			graph = new int[MAP_SIZE][MAP_SIZE];

			// 그래프 초기화
			for (int row = 0; row < MAP_SIZE; row++) {
				st = new StringTokenizer(br.readLine().trim());
				for (int column = 0; column < MAP_SIZE; column++) {
					int temp = Integer.parseInt(st.nextToken());
					graph[row][column] = temp;

					// 출발점들 저장
					if (row == 0 && temp == 1) {
						startXs.add(row);
						startYs.add(column);
					}
					// 도착점 저장
					if (temp == 2) {
						endX = row;
						endY = column;
					}
				}
			}

			for (int index = 0; index < startXs.size(); index++) {
				visited = new boolean[MAP_SIZE][MAP_SIZE];
				int x = startXs.get(index);
				int y = startYs.get(index);
				findEnd(x, y, y);
			}
			sb.append("#").append(test_case).append(" ").append(answerY).append("\n");
		}
		System.out.println(sb.toString());
	}
}

// 문제 이해
// 사다리 게임
// 어느 사다리 고르면 X표시에 도착하는지 구하기

// 0, 9에 세로 선 있음
// 중간에 랜덤하게 막대 추가함
// 이 막대들 사이에 가로로 랜덤하게 연결

// 좌우 방향으로 이동해 방향 전환
// 아래 방향으로만 이동
// 바닥 도착하면 멈춤

// 100*100 map
// 지정된 도착점 대응되는 출발점 X 반환 코드 작성
// 사다리는 1
// 도착지점은 2

// 제약사항
// 10개에 20초 -> 1개에 2초;;
// BFS, DFS 모든 행에 하면 1억?