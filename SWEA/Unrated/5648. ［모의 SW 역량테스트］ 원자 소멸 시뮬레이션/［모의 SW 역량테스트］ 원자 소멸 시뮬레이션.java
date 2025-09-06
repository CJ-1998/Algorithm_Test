import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Solution {

	static enum Direction {
		UP, DOWN, LEFT, RIGHT;
	}

	static class Atom {
		double x;
		double y;
		int energy;
		Direction direction;
		boolean isCrashed;

		public Atom(double x, double y, Direction direction, int energy, boolean isCrashed) {
			super();
			this.x = x;
			this.y = y;
			this.direction = direction;
			this.energy = energy;
			this.isCrashed = isCrashed;
		}
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int atomNumber;
	static Atom[] atoms;
	static boolean[] checkCrashed;
	static boolean[] tempCrashed;
	static Map<Double, List<int[]>> timeNIndex;

	static int energySum;

	// 방향 int to enum 함수
	static Direction convertDirection(int direction) {
		if (direction == 0) {
			return Direction.UP;
		} else if (direction == 1) {
			return Direction.DOWN;
		} else if (direction == 2) {
			return Direction.LEFT;
		} else {
			return Direction.RIGHT;
		}
	}

	// 입력 받기 및 초기화 함수
	static void init() throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		atomNumber = Integer.parseInt(st.nextToken());

		atoms = new Atom[atomNumber];
		checkCrashed = new boolean[atomNumber];
		tempCrashed = new boolean[atomNumber];
		timeNIndex = new TreeMap<>();
		energySum = 0;
	}

	// 원자들 입력 받아서 배열에 저장하는 함수
	static void addAtom() throws Exception {
		for (int count = 0; count < atomNumber; count++) {
			atoms[count] = makeAtom();
		}
	}

	// 입력 받아 원자 만드는 함수
	static Atom makeAtom() throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int direction = Integer.parseInt(st.nextToken());
		int energy = Integer.parseInt(st.nextToken());

		return new Atom(x, y, convertDirection(direction), energy, false);
	}

	// 상 하, 하 상
	static boolean checkUpDownDirection(Atom fixed, Atom moved) {
		Direction fixedDirection = fixed.direction;
		Direction movedDirection = moved.direction;

		double fixedY = fixed.y;
		double movedY = moved.y;

		if (fixedDirection == Direction.UP && movedDirection == Direction.DOWN) {
			if (fixedY < movedY) {
				return true;
			}
		} else if (fixedDirection == Direction.DOWN && movedDirection == Direction.UP) {
			if (fixedY > movedY) {
				return true;
			}
		}
		return false;
	}

	// 좌 우, 우 좌
	static boolean checkLeftRightDirection(Atom fixed, Atom moved) {
		Direction fixedDirection = fixed.direction;
		Direction movedDirection = moved.direction;

		double fixedX = fixed.x;
		double movedX = moved.x;

		if (fixedDirection == Direction.RIGHT && movedDirection == Direction.LEFT) {
			if (fixedX < movedX) {
				return true;
			}
		} else if (fixedDirection == Direction.LEFT && movedDirection == Direction.RIGHT) {
			if (fixedX > movedX) {
				return true;
			}
		}
		return false;
	}

	// 나머지 = 우 상, 우 하, 좌 상, 좌 하, 상 우, 하 우, 상 좌, 하 좌
	// 방향은 맞고 좌표 위치도 맞아야 함
	static boolean checkOtherDirection(Atom fixed, Atom moved) {
		Direction fixedDirection = fixed.direction;
		Direction movedDirection = moved.direction;

		double fixedX = fixed.x;
		double movedX = moved.x;
		double fixedY = fixed.y;
		double movedY = moved.y;

		if (fixedDirection == Direction.RIGHT && movedDirection == Direction.UP) {
			if ((fixedX < movedX) && (fixedY > movedY)) {
				return true;
			}
		} else if (fixedDirection == Direction.LEFT && movedDirection == Direction.UP) {
			if ((fixedX > movedX) && (fixedY > movedY)) {
				return true;
			}
		} else if (fixedDirection == Direction.DOWN && movedDirection == Direction.RIGHT) {
			if ((fixedX > movedX) && (fixedY > movedY)) {
				return true;
			}
		} else if (fixedDirection == Direction.DOWN && movedDirection == Direction.LEFT) {
			if ((fixedX < movedX) && (fixedY > movedY)) {
				return true;
			}
		} else if (fixedDirection == Direction.RIGHT && movedDirection == Direction.DOWN) {
			if ((fixedX < movedX) && (fixedY < movedY)) {
				return true;
			}
		} else if (fixedDirection == Direction.LEFT && movedDirection == Direction.DOWN) {
			if ((fixedX > movedX) && (fixedY < movedY)) {
				return true;
			}
		} else if (fixedDirection == Direction.UP && movedDirection == Direction.RIGHT) {
			if ((fixedX > movedX) && (fixedY < movedY)) {
				return true;
			}
		} else if (fixedDirection == Direction.UP && movedDirection == Direction.LEFT) {
			if ((fixedX < movedX) && (fixedY < movedY)) {
				return true;
			}
		} else {
			return false;
		}
		return false;
	}

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());

		for (int test_case = 1; test_case <= T; test_case++) {

			init();
			addAtom();

			for (int fixed = 0; fixed < atomNumber; fixed++) {
				for (int moved = 0; moved < atomNumber; moved++) {
					// 자기 자신 체크하는 경우 pass
					if (fixed == moved) {
						continue;
					}

					Direction fixedDirection = atoms[fixed].direction;
					Direction movedDirection = atoms[moved].direction;

					// 같은 방향으로 이동해 부딛히지 않음 pass
					if (fixedDirection == movedDirection) {
						continue;
					}

					// 둘이 상하로 이동
					if (checkUpDownDirection(atoms[fixed], atoms[moved])) {
						// 같은 x 좌표 = 부딛힘
						if (atoms[fixed].x == atoms[moved].x) {
							// 부딛히는 시간 계산
							double crashTime = Math.abs(atoms[fixed].y - atoms[moved].y) / 2.0;

							List<int[]> tempList;
							if (timeNIndex.containsKey(crashTime)) {
								tempList = timeNIndex.get(crashTime);
							} else {
								tempList = new ArrayList<>();
							}
							tempList.add(new int[] { fixed, moved });
							timeNIndex.put(crashTime, tempList);
						}
					}

					// 둘이 좌우로 이동
					else if (checkLeftRightDirection(atoms[fixed], atoms[moved])) {
						// 같은 y 좌표 = 부딛힘
						if (atoms[fixed].y == atoms[moved].y) {
							// 부딛히는 시간 계산
							double crashTime = Math.abs(atoms[fixed].x - atoms[moved].x) / 2.0;

							List<int[]> tempList;
							if (timeNIndex.containsKey(crashTime)) {
								tempList = timeNIndex.get(crashTime);
							} else {
								tempList = new ArrayList<>();
							}
							tempList.add(new int[] { fixed, moved });
							timeNIndex.put(crashTime, tempList);
						}
					}

					// 나머지 = 우 상, 우 하, 좌 상, 좌 하, 상 우, 하 우, 상 좌, 하 좌
					else if (checkOtherDirection(atoms[fixed], atoms[moved])) {
						double xLength = Math.abs(atoms[fixed].x - atoms[moved].x);
						double yLength = Math.abs(atoms[fixed].y - atoms[moved].y);

						double crashTime = yLength;

						if (xLength == yLength) {

							List<int[]> tempList;
							if (timeNIndex.containsKey(crashTime)) {
								tempList = timeNIndex.get(crashTime);
							} else {
								tempList = new ArrayList<>();
							}
							tempList.add(new int[] { fixed, moved });
							timeNIndex.put(crashTime, tempList);
						}
					}

				}
			}

			// map 확인하며 에너지 구하기
			for (Entry<Double, List<int[]>> oneTime : timeNIndex.entrySet()) {
				// 한 시간에 충돌한 index들
				List<int[]> indexsList = oneTime.getValue();

				// 각 index들 확인
				for (int index = 0; index < indexsList.size(); index++) {
					int[] indexs = indexsList.get(index);

					int fixedIndex = indexs[0];
					int movedIndex = indexs[1];

					Atom fixedAtom = atoms[fixedIndex];
					Atom movedAtom = atoms[movedIndex];

					// 이전 시간에 충돌한 것은 패스
					if (checkCrashed[fixedIndex] || checkCrashed[movedIndex]) {
						continue;
					} else {
						// 둘 다 충돌 X
						if (!tempCrashed[movedIndex] && !tempCrashed[fixedIndex]) {
							energySum += movedAtom.energy;
							tempCrashed[movedIndex] = true;
							energySum += fixedAtom.energy;
							tempCrashed[fixedIndex] = true;
						}
						// 이번 시간에 fixed가 충돌
						else if (tempCrashed[fixedIndex] && !tempCrashed[movedIndex]) {
							// moved만 추가
							energySum += movedAtom.energy;
							tempCrashed[movedIndex] = true;
						}
						// 이번 시간에 moved가 충돌
						else if (tempCrashed[movedIndex] && !tempCrashed[fixedIndex]) {
							energySum += fixedAtom.energy;
							tempCrashed[fixedIndex] = true;
						}
					}
				}
				for (int index = 0; index < indexsList.size(); index++) {
					int[] indexs = indexsList.get(index);
					int fixedIndex = indexs[0];
					int movedIndex = indexs[1];
					if (tempCrashed[fixedIndex] == true)
						checkCrashed[fixedIndex] = true;
					if (tempCrashed[movedIndex] == true)
						checkCrashed[movedIndex] = true;
				}
			}
			sb.append("#").append(test_case).append(" ").append(energySum).append("\n");
		}
		System.out.println(sb.toString());
	}
}

// 문제 이해
// 발생하는 에너지 미리 계산 위해
// 원자들의 움직임을 시뮬레이션 하는 프로그램

// 원자들은 2차원 평면에서 이동
// 2개 이상의 원자가 충돌할 경우 
// 충돌한 원자들은 각자 보유한 에너지를 모두 방출하고 소멸

// 원자의 움직임
// 상 : y 증가
// 하 : y 감소
// 좌 : x 감소
// 우 : x 증가

// 원자들 이동 속도 동일
// 1초에 1만큼 이동
// 모든 원자들은 동시에 이동 시작

// 제약 사항
// 원자의 수 N 1~1000
// 에너지 K 1~100
// 좌표 -1000~1000
// 상=0, 하=1, 좌=2, 우=3

// 입력
// 원자 수
// 각 원자 별 x, y, 이동 방향, 에너지

// 출력
// 원자 소멸되며 방출하는 에너지 총합

// 문제 풀이
// 정해진 시간 없음
// for문으로 시간만큼 돌면서 하는 것 x

// 원자 부딛히면 각 에너지 모두 방출해서 더해줘야 함
// 방향 바뀌지 않음

// 부딛힐 수 있는 것
// 우 좌로 가는 것 -> 같은 y -> 언젠간 만남 -> abs(y1-y2)/2 후에 충돌
// 하 상로 가는 것 -> 같은 x -> 언젠간 만남 -> abs(x1-x2)/2 후에 충돌

// 우 상로 가는 것 -> ㄱ -> abs(x1-x2) == abs(y1-y2) -> abs(y1-y2) 후에 충돌 
// 우 하로 가는 것 -> ㅢ -> abs(x1-x2) == abs(y1-y2)

// 좌 상로 가는 것 -> T -> abs(x1-x2) == abs(y1-y2)
// 좌 하로 가는 것 -> ㄴ -> abs(x1-x2) == abs(y1-y2)

// 둘이 좌표 1차이 = 0.5초후 충돌
// 둘이 좌표 같음 = 바로 충돌

// 시간 범위를 2000?
// 시간 지나고 각 좌표 위치 이동 = 1000
// 같은 좌표 있는지 확인 = 1000*1000
// -> 이렇게 하면 20억

// 같은 x, y 무조건 배제하고 시작?
// 중간에 수직인 곳에서 오는 것과 부딛혀 먼저 사라질 수 있음

// 부딛힐 수 있는 것
// 우 -> 좌, 상, 하
// 좌 -> 우, 상, 하
// 상 -> 하, 좌, 우
// 하 -> 상, 좌, 우

// 한 좌표 정하고
// 나머지 좌표 중 부딛힐 수 있는 것 찾고 부딛히는 시간 계산해 놓음
// 가장 짧은 것과 부딛히는 것임

// 부딛히고 자료구조에서 지울까?
// 3개 동시에 부딛히는거는 그럼 2개 지우면 안 부딛힌다고 판단됨
// 시간 보면 가장 짧은게 2개 나오니까 동시에 지우면 될듯??

// 1000*1000 = 백만?

// 현재 풀이 : 앞에서부터 순서대로 확인하고 충돌해서 중간에 껴있고 이런 것 생각을 못함
// 0 1 2 3 이런 순서로 x 축에 있으면 0번부터 확인해서 
// 원래는 1, 2가 충돌해야 하는데
// 0, 2가 충돌함
// 거리가 짧은게 더 앞에 시간에 부딛히니까 이것 고려해야 함