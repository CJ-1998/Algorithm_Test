import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	// 부지 크기
	static int mapSize;

	// 공사 가능 최대 깊이
	static int height;

	// 부지
	static int[][] map;
	static int[][] copyMap;
	static boolean[][] visited;

	// 가장 긴 등산로 저장
	static int maxLength;

	// 가장 높은 봉우리 좌표
	static List<Integer> startX;
	static List<Integer> startY;

	// 가장 높은 봉우리 높이
	static int maxHeight;

	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };

	// 좌표 확인 함수
	static boolean checkCoordinate(int x, int y) {
		if ((0 <= x && x < mapSize) && (0 <= y && y < mapSize)) {
			return true;
		}
		return false;
	}

	// 입력 받는 함수
	static void input() throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		mapSize = Integer.parseInt(st.nextToken());
		height = Integer.parseInt(st.nextToken());

		map = new int[mapSize][mapSize];

		startX = new ArrayList<>();
		startY = new ArrayList<>();

		maxLength = 0;
		maxHeight = 0;

		mapInit();
	}

	// map 초기화 함수
	// O(N^2) = 64
	static void mapInit() throws Exception {
		for (int row = 0; row < mapSize; row++) {
			st = new StringTokenizer(br.readLine().trim());
			for (int column = 0; column < mapSize; column++) {
				int temp = Integer.parseInt(st.nextToken());
				map[row][column] = temp;
				if (temp > maxHeight) {
					maxHeight = temp;
					startX.clear();
					startY.clear();
					startX.add(row);
					startY.add(column);
				} else if (temp == maxHeight) {
					startX.add(row);
					startY.add(column);
				}
			}
		}
	}

	// map 복사 함수
	// O(N^2) = 64
	static void copyMapFunction() {
		int[][] tempCopyMap = new int[mapSize][mapSize];
		for (int row = 0; row < mapSize; row++) {
			for (int column = 0; column < mapSize; column++) {
				tempCopyMap[row][column] = map[row][column];
			}
		}
		copyMap = tempCopyMap;
	}

	// 등산로 찾기에 필요한 것들 초기화
	// O(N^2) = 64
	static void readyToFindRoute() {
		visited = new boolean[mapSize][mapSize];
		copyMapFunction();
	}

	// 봉우리 찾는 함수
	// O(N^2) = 64
	static void findPeek() {
		maxHeight = 0;
		for (int row = 0; row < mapSize; row++) {
			for (int column = 0; column < mapSize; column++) {
				int temp = copyMap[row][column];
				if (temp > maxHeight) {
					maxHeight = temp;
					startX.clear();
					startY.clear();
					startX.add(row);
					startY.add(column);
				} else if (temp == maxHeight) {
					startX.add(row);
					startY.add(column);
				}
			}
		}
	}

	// 한 봉우리에서 등산로 길이 측정
	// O(N^2) = 64
	static void findRoute(int x, int y, int length) {
		if (visited[x][y] == true) {
			return;
		}

		visited[x][y] = true;

		for (int count = 0; count < 4; count++) {
			int newX = x + dx[count];
			int newY = y + dy[count];
			if (checkCoordinate(newX, newY)) {
				if (copyMap[x][y] > copyMap[newX][newY]) {
					findRoute(newX, newY, length + 1);
					visited[x][y] = false;
				}
			}
		}
		visited[x][y] = false;
		if (maxLength < length) {
			maxLength = length;
		}
	}

	// 가장 높은 봉우리들 시작점으로 해서 가장 긴 등산로 계산
	// 64 + 5*64
	static void checkAllPeek() {
		copyMapFunction();
		for (int index = 0; index < startX.size(); index++) {
			visited = new boolean[mapSize][mapSize];
			int x = startX.get(index);
			int y = startY.get(index);
			findRoute(x, y, 1);
//			System.out.println(x + " " + y);
//			System.out.println(maxLength);
//			for (int row = 0; row < mapSize; row++) {
//				for (int column = 0; column < mapSize; column++) {
//					System.out.print(visited[row][column] ? "T " : "F ");
//				}
//				System.out.println();
//			}
//			System.out.println();
//			for (int row = 0; row < mapSize; row++) {
//				for (int column = 0; column < mapSize; column++) {
//					System.out.print(copyMap[row][column] + " ");
//				}
//				System.out.println();
//			}
//			System.out.println();
		}
	}

	static void changeDepth() {
		for (int row = 0; row < mapSize; row++) {
			for (int column = 0; column < mapSize; column++) {
				// O(N^2) = 64
				copyMapFunction();
				for (int count = 1; count <= height; count++) {
					copyMap[row][column] -= 1;

					// O(N^2) = 64
					// findPeek();

					// 5*64
					for (int index = 0; index < startX.size(); index++) {
						visited = new boolean[mapSize][mapSize];
						int x = startX.get(index);
						int y = startY.get(index);

						findRoute(x, y, 1);
//						System.out.println(x + " " + y);
//						System.out.println(maxLength);
//						for (int row1 = 0; row1 < mapSize; row1++) {
//							for (int column1 = 0; column1 < mapSize; column1++) {
//								System.out.print(visited[row1][column1] ? "T " : "F ");
//							}
//							System.out.println();
//						}
//						System.out.println();
//						for (int row2 = 0; row2 < mapSize; row2++) {
//							for (int column2 = 0; column2 < mapSize; column2++) {
//								System.out.print(copyMap[row2][column2] + " ");
//							}
//							System.out.println();
//						}
//						System.out.println();
					}
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= T; test_case++) {
			input();
			checkAllPeek();
			changeDepth();

			sb.append("#").append(test_case).append(" ").append(maxLength).append("\n");
		}
		System.out.println(sb.toString());
	}
}
// 문제 이해 
// 등산로 조성
// 부지 N*N
// 최대한 긴 등산로
// 각 칸에 숫자는 지형의 높이

// 등산로 만드는 규칙
// 등산로는 가장 높은 봉우리에서 시작
// 높은 지형에서 낮은 지형으로 가로 or 세로 방향으로 연결
// 높이 같거나 낮으면 X , 대각선 X

// 긴 등산로 만들기 위해 한 곳 최대 K 깊이만큼 깎는 공사 가능

// 가장 긴 등산로 찾아 길이 출력

// 제약사항
// 51개 TC 3초 = 1개당 580만
// 한변 길이 N = 3~8
// 최대 공사 가능 깊이 K = 1~5
// 가장 높은 봉우리 = 최대 5개
// 높이 1보다 작게 만드는 것도 가능

//입력
// N K
// 지도 정보

// 문제 풀이
// 완전 탐색
// 한 봉우리에서 등산로 확인 = 64
// 한 곳 깊이 바꾸기 = 64칸 * 5 (깊이)
// 봉우리 5개 = *5
// = 102400?
