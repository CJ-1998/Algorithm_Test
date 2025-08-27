import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int boardCount;
	static int[][] gameBoard;
	static boolean[][] visited;

	static int clickCount;

	static int[] dx = { -1, -1, 0, 1, 1, 1, 0, -1 };
	static int[] dy = { 0, -1, -1, -1, 0, 1, 1, 1 };

	static List<NoMineCoordinate> coordinateList;

	static class NoMineCoordinate implements Comparable<NoMineCoordinate> {
		int row;
		int column;
		int aroundCount;

		public NoMineCoordinate(int row, int column, int aroundCount) {
			this.row = row;
			this.column = column;
			this.aroundCount = aroundCount;
		}

		@Override
		public int compareTo(NoMineCoordinate other) {
			return Integer.compare(other.aroundCount, this.aroundCount);

		}
	}

	static boolean checkCoordinate(int row, int column) {
		if ((0 <= row && row < boardCount) && (0 <= column && column < boardCount)) {
			return true;
		}

		return false;
	}

	static boolean click(int row, int column) {

		if (visited[row][column] == true) {
			return false;
		}

		visited[row][column] = true;

		boolean nearMine = false;
		for (int count = 0; count < 8; count++) {
			int newRow = row + dx[count];
			int newColumn = column + dy[count];
			if (checkCoordinate(newRow, newColumn)) {
				if (gameBoard[newRow][newColumn] == 1) {
					nearMine = true;
					break;
				}
			}
		}
		if (!nearMine) {
			for (int count = 0; count < 8; count++) {
				int newRow = row + dx[count];
				int newColumn = column + dy[count];
				if (checkCoordinate(newRow, newColumn)) {
					click(newRow, newColumn);
				}
			}
		}

		return true;
	}

	static int countNearMine(int row, int column) {

		int mineCount = 0;
		if (gameBoard[row][column] != 1) {
			for (int count = 0; count < 8; count++) {
				int newRow = row + dx[count];
				int newColumn = column + dy[count];
				if (checkCoordinate(newRow, newColumn)) {
					if (gameBoard[newRow][newColumn] == 1) {
						mineCount = 0;
						break;
					} else {
						mineCount++;
					}
				}
			}
		}
		return mineCount;
	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());

		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine().trim());
			boardCount = Integer.parseInt(st.nextToken());

			gameBoard = new int[boardCount][boardCount];
			visited = new boolean[boardCount][boardCount];

			for (int row = 0; row < boardCount; row++) {
				st = new StringTokenizer(br.readLine().trim());
				String oneLine = st.nextToken();

				for (int column = 0; column < boardCount; column++) {
					if (oneLine.charAt(column) == '*') {
						visited[row][column] = true;
						gameBoard[row][column] = 1;
					}
				}
			}

			clickCount = 0;

			coordinateList = new ArrayList<>();

			for (int row = 0; row < boardCount; row++) {
				for (int column = 0; column < boardCount; column++) {
					int nearMineCount = countNearMine(row, column);
					if (nearMineCount != 0) {
						NoMineCoordinate mineCoordinate = new NoMineCoordinate(row, column, nearMineCount);
						coordinateList.add(mineCoordinate);
					}
				}
			}

			Collections.sort(coordinateList, Collections.reverseOrder());

			for (NoMineCoordinate temp : coordinateList) {
				if (click(temp.row, temp.column)) {
					clickCount++;
				}
			}

			for (int row = 0; row < boardCount; row++) {
				for (int column = 0; column < boardCount; column++) {
					if (click(row, column)) {
						clickCount++;
					}
				}
			}

			sb.append("#").append(test_case).append(" ").append(clickCount).append("\n");
		}
		System.out.println(sb.toString());

	}

}

// 문제 이해
// R*C 크기 표 이용 게임
// 각 칸에 지뢰 가능

// 칸 클릭 시 지뢰있다면 파핑 파핑 소리와 함께 게임 끝남
// 지뢰가 없는 칸이라면  주위 8칸에 몇개 지뢰 있는지 표시

// 주위 8칸에 지뢰 0 = 숫자 0이라면 그 8 방향도 숫자 표시

// 지뢰 = *, 지뢰 없음 = ., 클릭한 지뢰 없는 칸 = c

// 지뢰 있는 칸 제외한 다른 모든 칸의 숫자 표시되려면 최소 몇 번 클릭해야 하는지?

// 입력
// N = 1~300 -> N*N표
// 각 표 문자열로 주어짐, 공백 X 

// 문제 풀이
// 한 칸에 도착
// 주위 8칸을 확인

// 주위 8칸에 지뢰 있다면 
// 숫자 표시하고 끝 - return 

// 주위 8칸에 지뢰 없다면 
// 주위 8칸도 같은 일 진행 - 재귀 진행

// 각 칸에 대해서 진행
// 지뢰이거나 이미 처리된 것은 count X
// 지뢰 아니고 아직 안 열린 곳 한번 진행할 때마다 count++
// 모든 칸에 대해 진행하고 count 반환

//		0	1	2	3	4
//	0	.	.	*	.	.
//	1	.	.	*	.	.
//	2	.	*	.	.	*
//	3	.	*	.	.	.
//	4	.	*	.	.	.
