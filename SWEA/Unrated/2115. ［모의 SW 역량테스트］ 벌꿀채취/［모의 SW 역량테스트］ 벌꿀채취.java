
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

	// 벌통들 정보
	static int[][] beePlace;

	// 해당 자리에서 얻을 수 있는 이익 캐싱
	static int[][] moneyCache;

	// 고정된 일꾼 선택한 벌통 정보
	static int[] fixedMan;

	// 움직이는 일꾼 선택한 벌통 정보
	static int[] movedMan;

	// 고정된 일꾼 이익
	static int fixedManMoney;

	// 움직이는 일꾼 이익
	static int MovedManMoney;

	// 고정된 일꾼 좌표
	static int fixedX;
	static int fixedY;

	// 움직이는 일꾼 좌표
	static int movedX;
	static int movedY;

	static int bestMoney;

	// map 사이즈
	static int N;
	// 벌통 선택 개수
	static int M;
	// 최대 채취 가능 꿀
	static int C;

	// 입력 받는 함수
	static void input() throws Exception {
		st = new StringTokenizer(br.readLine().trim());

		N = Integer.parseInt(st.nextToken());

		M = Integer.parseInt(st.nextToken());

		C = Integer.parseInt(st.nextToken());
	}

	// 자료구조들 초기화
	// O(N^2) = 100
	static void init() throws Exception {
		beePlace = new int[N][N];
		moneyCache = new int[N][N];

		fixedMan = new int[M];
		movedMan = new int[M];

		fixedManMoney = 0;
		MovedManMoney = 0;

		fixedX = 0;
		fixedY = 0;
		movedX = 0;
		movedY = 0;

		bestMoney = 0;

		for (int row = 0; row < N; row++) {
			st = new StringTokenizer(br.readLine().trim());
			for (int column = 0; column < N; column++) {
				int honey = Integer.parseInt(st.nextToken());
				beePlace[row][column] = honey;
			}
		}
	}

	// 좌표 범위 넘어가는지 체크하는 함수
	static boolean checkCoordinate(int x, int y) {
		if (y + M - 1 < N) {
			return true;
		}
		return false;
	}

	// 고정된 일꾼 얻을 수 있는 벌꿀 다 더하고 저장하는 함수
	static int calculateFixedManHoney(int fixedManX, int fixedManY) {
		int allHoney = 0;
		for (int count = 0; count < M; count++) {
			int newX = fixedManX;
			int newY = fixedManY + count;
			allHoney += beePlace[newX][newY];
			fixedMan[count] = beePlace[newX][newY];
		}
		return allHoney;
	}

	// 고정된 일꾼 얻을 수 있는 벌꿀 다 더하고 저장하는 함수
	static int calculateManHoney(int x, int y) {
		int allHoney = 0;
		for (int count = 0; count < M; count++) {
			int newX = x;
			int newY = y + count;
			allHoney += beePlace[newX][newY];
		}
		return allHoney;
	}

	// 움직이는 사람이 계산할 수 있는 최대 이익 구하기
	static int calculateBestMovedManHoney(int fixedManX, int fixedManY) {
		int money = 0;
		for (int row = 0; row < N; row++) {
			for (int column = 0; column < N; column++) {
				if (checkCoordinate(row, column)) {
					if (checkMovedManCoordinate(row, column)) {
						if (moneyCache[row][column] == 0) {
							int[] temp = new int[M];
							int tempHoney = 0;
							for (int count = 0; count < M; count++) {
								int newX = row;
								int newY = column + count;
								tempHoney += beePlace[newX][newY];
								temp[count] = beePlace[newX][newY];
							}
							if (tempHoney > C) {
								// 모든 조합 보면서 C보다 작은 최대 구하기
								List<Integer> tempList = new ArrayList<>();
								chooseBestCombination(0, new boolean[M], temp, tempList);
								Collections.sort(tempList, Collections.reverseOrder());
								int tempMoney = tempList.get(0);
								if (money < tempMoney) {
									money = tempMoney;
								}
							} else {
								int tempMoney = calculateHoneyMoney(temp);
								if (money < tempMoney) {
									money = tempMoney;
								}
							}
						} else {
							int tempMoney = moneyCache[row][column];
							if (money < tempMoney) {
								money = tempMoney;
							}
						}

					}
				}
			}
		}
		return money;
	}

	// 움직이는 사람 좌표가 고정된 사람 좌표 침범하는지 확인
	static boolean checkMovedManCoordinate(int x, int y) {
		// x 좌표 같은데
		if (x == fixedX) {
			if (fixedY - y >= M || y - fixedY >= M) {
				return true;
			} else {
				return false;
			}
		} else {
			return true;
		}
	}

	// 채취한 벌꿀 이익 계산
	static int calculateHoneyMoney(int[] honeys) {
		int money = 0;
		for (int honey : honeys) {
			money += Math.pow(honey, 2);
		}
		return money;
	}

	static void chooseBestCombination(int selectIndex, boolean[] array, int[] tempArray, List<Integer> moneys) {
		if (selectIndex == M) {
			int money = 0;
			int honey = 0;
			for (int index = 0; index < M; index++) {
				if (array[index]) {
					money += Math.pow(tempArray[index], 2);
					honey += tempArray[index];
				}
			}
			if (honey <= C) {
				moneys.add(money);
			}
		} else {
			array[selectIndex] = true;
			chooseBestCombination(selectIndex + 1, array, tempArray, moneys);
			array[selectIndex] = false;
			chooseBestCombination(selectIndex + 1, array, tempArray, moneys);

		}
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= T; test_case++) {
			input();
			init();

			// 고정된 사람 좌표 옮기며 확인
			for (int row = 0; row < N; row++) {
				for (int column = 0; column < N; column++) {
					fixedX = row;
					fixedY = column;

					// 현재 좌표에서 M칸 가능한지
					if (checkCoordinate(fixedX, fixedY)) {
						if (moneyCache[fixedX][fixedY] == 0) {
							int allHoney = calculateFixedManHoney(fixedX, fixedY);
							if (allHoney > C) {
								// 모든 조합 보면서 C보다 작은 최대 구하기
								List<Integer> tempList = new ArrayList<>();
								chooseBestCombination(0, new boolean[M], fixedMan, tempList);
								Collections.sort(tempList, Collections.reverseOrder());
								fixedManMoney = tempList.get(0);
								// System.out.println("고정 돈: " + fixedManMoney);
							} else {
								// 이익 계산
								fixedManMoney = calculateHoneyMoney(fixedMan);
							}
							moneyCache[fixedX][fixedY] = fixedManMoney;
						} else {
							fixedManMoney = moneyCache[fixedX][fixedY];
						}

						int movedManMoney = calculateBestMovedManHoney(fixedX, fixedY);
						// System.out.println("이동 돈 : " + movedManMoney);
						if (bestMoney < fixedManMoney + movedManMoney) {
							bestMoney = fixedManMoney + movedManMoney;
						}
					}

				}
			}
			sb.append("#").append(test_case).append(" ").append(bestMoney).append("\n");

		}
		System.out.println(sb.toString());
	}
}

// 문제 이해
// N*N 벌통
// 각 칸의 숫자는 벌통의 꿀 양

// 벌꿀 채취해 최대한 많은 수익

// 벌꿀 채취 방식 

// 두명의 일꾼
// 꿀 채취할 수 있는 벌통 수 M
// 각 일꾼은 가로로 연속되게 M개 벌통 선택 후 채취
// 선택한 벌통 겹치면 안됨

// 꿀 채취해 용기에 담음
// 하나의 벌통에서 채취한 꿀은 하나의 용기에만
// 벌통에 있는 모든 꿀 한번에 채취해야 함
// 두 일꾼이 채취할 수 있는 꿀의 최대 양은 C
// C 넘어가면 벌통 선택해 꿀 채취

// 용기에 있는 꿀 양 많을수록 상품 가치가 높음
// 꿀의 양의 제곱만큼 수익이 생김

// 두 일꾼이 꿀 채취해 얻을 수 있는 수익의 합 최대가 되는 경우 최대 수익 출력

// 제약 사항
// 50개 TC 3초 -> 1개당 6백만
// N : 3~10
// M : 1~5
// C : 10~30

// 입력
// N M C 순서
// 벌통 정보 N*N 주어짐 (공백 O)

// 출력
// 최대 수익

// 문제 풀이
// 하나 고정하고 전체 돌아보면서 진행
// 최대 시간 복잡도 = 100 * 100 = 만

// 하나 고정 후 선택한 벌통의 꿀 합 구하기
// 꿀 합이 C보다 크면? 
// C 만족하게 뺄 벌통 구하기
// 제일 작은 것부터 빼기 -> X
// 전체 경우의 수 구해서 C 만족하면서 가장 큰 것 구하기
// 시간 복잡도 = 5! = 120
// 꿀 합이 C보다 작으면?
// 다 선택하면 됨

// 하나는 이동하면서 위의 일 수행
// 고정된 좌표는 선택하지 않아야 함

// 수행 후 선택된 벌통들 가지고 수익 계산
// 가장 큰 것과 비교
