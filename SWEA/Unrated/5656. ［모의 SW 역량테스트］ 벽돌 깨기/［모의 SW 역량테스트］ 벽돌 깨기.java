import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	// 실제 벽 저장된 배열
	static int[][] realGraph;

	// 한 경우의 수마다 복사할 배열
	static int[][] copyGraph;

	// 경우의수 저장한 자료구조
	static List<int[]> choice;

	// 구슬 쏘는 횟수
	static int shootCount;

	// 그래프 가로
	static int graphRow;

	// 그래프 세로
	static int graphColumn;

	static int[] dx = { 0, -1, 0, 1 };

	static int[] dy = { -1, 0, 1, 0 };

	// 남은 최소 벽돌 개수
	static int minBrickCount;

	// 기능
	// 1. 구슬 순서 순열로 구하는 함수
	// 2. 구슬 그래프 복사해 놓기 (4)
	// 3. 한 구슬 좌표 있을 때 그래프 깨는 함수 (재귀)
	// 4. 떠있는 구슬 내리기

	// 입력 받는 함수
	static void input() throws Exception {
		// 입력 받기
		st = new StringTokenizer(br.readLine().trim());
		shootCount = Integer.parseInt(st.nextToken());
		graphColumn = Integer.parseInt(st.nextToken());
		graphRow = Integer.parseInt(st.nextToken());

		minBrickCount = Integer.MAX_VALUE;
		choice = new ArrayList<>();
	}

	// 벽돌 그래프 입력 받는 함수 = 12*15 = 180
	static void initGraph() throws Exception {
		realGraph = new int[graphRow][graphColumn];

		for (int row = 0; row < graphRow; row++) {
			st = new StringTokenizer(br.readLine().trim());
			for (int column = 0; column < graphColumn; column++) {
				int oneInput = Integer.parseInt(st.nextToken());
				realGraph[row][column] = oneInput;
			}
		}

	}

	// 그래프 복사하는 함수 = 12*15 = 180
	static void copyGraph() {
		copyGraph = new int[graphRow][graphColumn];
		for (int row = 0; row < graphRow; row++) {
			for (int column = 0; column < graphColumn; column++) {
				copyGraph[row][column] = realGraph[row][column];
			}
		}
	}

	// 경우의 수 계산하는 함수 = (W^N)*N = (12^4)*4 = 약 8.3만
	static void calculateChoice(int elementIndex, int[] oneChoice) {
		if (elementIndex == shootCount) {
			int[] tempArray = new int[shootCount];
			for (int index = 0; index < shootCount; index++) {
				tempArray[index] = oneChoice[index];
			}
			choice.add(tempArray);
			return;
		}

		for (int index = 0; index < graphColumn; index++) {
			if (elementIndex == 0) {
				oneChoice = new int[shootCount];
			}

			oneChoice[elementIndex] = index;
			calculateChoice(elementIndex + 1, oneChoice);
		}
	}

	// 전체 경우의 수에 대해 구슬 던지기 실행
	static void start() {

		for (int[] oneChoice : choice) {
			// 복사본 생성
			copyGraph();
			shoot(oneChoice);
			countBrick();
		}
	}

	// 하나의 경우의 수 진행
	static void shoot(int[] oneChoice) {
		for (int count = 0; count < shootCount; count++) {
			int shootColumn = oneChoice[count];
			int shootRow = findStartRow(shootColumn);

			// 그 줄 전부 벽돌 깨짐
			if (shootRow == graphRow) {
				continue;
			}

			oneShoot(shootRow, shootColumn);
			downBrick();
		}
	}

	// 0 아닌 처음 벽돌 맞는 위치 계산
	static int findStartRow(int column) {
		for (int row = 0; row < graphRow; row++) {
			if (copyGraph[row][column] != 0) {
				return row;
			}
		}
		return graphRow;
	}

	// 벽돌 하나 떨궈서 벽돌 부시기
	static void oneShoot(int row, int column) {
		if (copyGraph[row][column] == 0) {
			return;
		}

		int range = copyGraph[row][column];

		copyGraph[row][column] = 0;

		for (int count = 1; count <= range - 1; count++) {
			for (int direction = 0; direction < 4; direction++) {
				int newRow = row + (count * dx[direction]);
				int newColumn = column + (count * dy[direction]);
				if (checkCoordinate(newRow, newColumn)) {
					oneShoot(newRow, newColumn);
				}
			}
		}
	}

	// 좌표 범위 확인
	static boolean checkCoordinate(int row, int column) {
		if ((0 <= row && row < graphRow) && (0 <= column && column < graphColumn)) {
			return true;
		}
		return false;
	}

	// 벽돌 내리기
	static void downBrick() {

		for (int column = 0; column < graphColumn; column++) {
			for (int row = graphRow - 1; row >= 0; row--) {
				if (copyGraph[row][column] == 0) {
					continue;
				} else {
					int nowPoint = copyGraph[row][column];
					int checkRow = row;
					int checkColumn = column;
					copyGraph[checkRow][checkColumn] = 0;
					while (true) {
						if (copyGraph[checkRow][checkColumn] == 0 && checkRow != graphRow - 1) {
							checkRow++;
						} else if (copyGraph[checkRow][checkColumn] == 0 && checkRow == graphRow - 1) {
							copyGraph[checkRow][checkColumn] = nowPoint;
							break;
						} else if (copyGraph[checkRow][checkColumn] != 0 && checkRow != graphRow - 1) {
							copyGraph[checkRow - 1][checkColumn] = nowPoint;
							break;
						} else if (copyGraph[checkRow][checkColumn] != 0 && checkRow == graphRow - 1) {
							copyGraph[checkRow - 1][checkColumn] = nowPoint;
							break;
						}
					}
				}
			}
		}

	}

	// 벽돌 개수 세기
	static void countBrick() {
		int brickCount = 0;
		for (int row = 0; row < graphRow; row++) {
			for (int column = 0; column < graphColumn; column++) {
				if (copyGraph[row][column] != 0) {
					brickCount++;
				}
			}
		}

		if (brickCount < minBrickCount) {
			minBrickCount = brickCount;
		}
	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());

		for (int test_case = 1; test_case <= T; test_case++) {

			input();
			initGraph();
			calculateChoice(0, null);
			start();

			sb.append("#").append(test_case).append(" ").append(minBrickCount).append("\n");
		}
		System.out.println(sb.toString());
	}
}

// 문제 이해 
// 구슬로 벽돌 깨기
// 구슬 N번 쏘기 가능
// 벽돌 W*H
// 0은 빈공간, 숫자는 벽돌

// 구슬은 좌우로만 움직일 수 있음
// 항상 맨 위의 벽돌만 깨뜨림

// 벽돌은 1~9로 표현
// 구슬 명중한 것은 상하좌우로 벽돌에 적힌 숫자-1 칸 같이 제거
// = 3 벽돌이면 상하좌우 2칸도 삭제

// 같이 삭제되는 것도 삭제될 때 상하좌우 다 지움
// = 3 벽돌 깨지면서 8 벽돌 깨면 8 벽돌 상하좌우도 지움

// 빈 공간 있으면 벽돌 밑으로 떨어짐

// 최대한 많은 벽돌 제거
// 남은 벽돌 개수 구하기

// 처음에 N, W, H 주어짐
// N = 1~4
// W = 2~12
// H = 2~15

// 문제 풀이
// 각 칸에서 구슬 던지는 경우의 수 = 12 ^ 4
// 구슬 던졌을 때 구슬 제거하는 것 = 12*15 (?)
// 남은 구슬 계산 = 12*15 (?)

// 구슬 순서 저장하는 2차원 list 생성
// 순열로 구함
// 이 list를 순회하며 각 번호마다 구슬 날려 그래프 수정
// 다 순회하면 남은 벽돌 개수 세기

// 기능
// 1. 구슬 순서 순열로 구하는 함수
// 2. 구슬 그래프 복사해 놓기 (4) 
// 3. 한 구슬 좌표 있을 때 그래프 깨는 함수 (재귀)
// 4. 떠있는 구슬 내리기