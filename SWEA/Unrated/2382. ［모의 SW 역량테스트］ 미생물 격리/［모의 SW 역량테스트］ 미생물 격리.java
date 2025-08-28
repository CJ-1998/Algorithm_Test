import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class Solution {

	static enum Direction {
		UP(0), DOWN(1), LEFT(2), RIGHT(3);

		int direction;

		Direction(int direction) {
			this.direction = direction;
		}
	}

	// 미생물 군집 클래스 생성
	static class Micro {
		int x;
		int y;
		int count;
		Direction direction;

		public Micro(int x, int y, int count, Direction direction) {
			super();
			this.x = x;
			this.y = y;
			this.count = count;
			this.direction = direction;
		}
	}

	// 군집 좌표 map key로 쓰려고
	static class Coordinate {
		int x;
		int y;

		public Coordinate(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Coordinate [x=" + x + ", y=" + y + "]";
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Coordinate other = (Coordinate) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

	}

	// 미생물 군집 저장하는 배열 선언
	static Micro[] microList;

	// 방향 설정 시 이동하는 dx, dy
	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };

	// 현재 미생물 위치 체크하는 visited[][]
	// static List<Integer>[][] visited;
	static Map<Coordinate, List<Integer>> visited;

	// 박스 크기
	static int N;

	// 시간
	static int M;

	// 미생물 초기 수
	static int K;

	// 미생물 수 합
	static int sum;

	static Direction selectDirection(int direction) {
		if (direction == 1) {
			return Direction.UP;
		} else if (direction == 2) {
			return Direction.DOWN;
		} else if (direction == 3) {
			return Direction.LEFT;
		} else if (direction == 4) {
			return Direction.RIGHT;
		}
		return null;
	}

	static Direction changeDirection(Direction direction) {
		if (direction == Direction.UP) {
			return Direction.DOWN;
		} else if (direction == Direction.DOWN) {
			return Direction.UP;
		} else if (direction == Direction.LEFT) {
			return Direction.RIGHT;
		} else if (direction == Direction.RIGHT) {
			return Direction.LEFT;
		}
		return null;
	}

	static void start() {
		for (int count = 0; count < M; count++) {
			// 미생물 군집 방향에 맞게 이동
			for (int index = 0; index < K; index++) {
				moveMicro(index);
			}
			sumSamePlace();
		}
		// 이동한 후 같은 셀에 위치한 것들 찾아서 합치기
	}

	static void moveMicro(int index) {
		Micro micro = microList[index];

		if (micro != null) {
			int x = micro.x;
			int y = micro.y;
			int count = micro.count;
			Direction direction = micro.direction;

			// x, y에 있는 내 index 제거
			deleteIndexInMap(x, y, index);

			// 이동할 다음 셀 좌표
			int newX = x + dx[direction.direction];
			int newY = y + dy[direction.direction];

			// 약품 셀 도착
			if (newX == 0 || newX == N - 1 || newY == 0 || newY == N - 1) {
				int newCount = count / 2;

				// 미생물 수 0 되어서 군집 사라짐
				if (newCount == 0) {
					microList[index] = null;
				} else {
					Direction newDirection = changeDirection(direction);

					Micro newMicro = new Micro(newX, newY, newCount, newDirection);
					microList[index] = newMicro;
					// newX, newY에 내 index 넣기
					insertIndexInMap(newX, newY, index);
				}

			} else {
				Micro newMicro = new Micro(newX, newY, count, direction);
				microList[index] = newMicro;
				// newX, newY에 내 index 넣기
				insertIndexInMap(newX, newY, index);
			}
		}
	}

	// 해당 셀에 올 때 무조건 map에 넣기 때문에 list 무조건 있음
	// 해당 셀에 여러 군집 있다면 list에 여러 개 있는 것
	static void deleteIndexInMap(int x, int y, int index) {
		Coordinate coordinate = new Coordinate(x, y);

		List<Integer> indexList = visited.get(coordinate);

		int listIndex = indexList.indexOf(index);
		indexList.remove(listIndex);
	}

	// 좌표에 대해 list에 해당 미생물 index 넣기
	static void insertIndexInMap(int x, int y, int index) {
		Coordinate coordinate = new Coordinate(x, y);

		// visited에 해당 좌표에 대한 list 있는지 확인
		List<Integer> indexList = visited.get(coordinate);
		// 없다면
		if (indexList == null) {
			// List 만들어 visited에 넣음
			List<Integer> tempList = new ArrayList<>();
			tempList.add(index);
			visited.put(coordinate, tempList);
		}
		// 있다면
		else {
			// 원래 있던 list에 더함
			indexList.add(index);
		}
	}

	static void sumSamePlace() {
		for (Entry<Coordinate, List<Integer>> oneEntry : visited.entrySet()) {
			Coordinate coordinate = oneEntry.getKey();
			List<Integer> oneList = oneEntry.getValue();

			// System.out.println("문제되는 x, y 좌표 : " + coordinate + " 여기에 모인 같은 미생물 군집 개수 : "
			// + oneList.size());

			// 1이 아니면 여러 개가 있다는 것
			if (oneList.size() > 1) {

				// 순회하면서 한 좌표의 미생물들 다 더함
				// 그리고 가장 미생물 많은 군집의 index 찾음
				int maxIndex = 0;
				int maxMicroCount = 0;
				int sumMicroCount = 0;
				for (Integer index : oneList) {
					Micro micro = microList[index];
					if (maxMicroCount < micro.count) {
						maxMicroCount = micro.count;
						maxIndex = index;
					}
					sumMicroCount += micro.count;
				}
				// 가장 큰 군집 아닌 것 모두 삭제
				for (Integer index : oneList) {
					if (index != maxIndex) {
						microList[index] = null;
					}
				}

				// 가장 큰 군집 미생물 개수 수정
				microList[maxIndex].count = sumMicroCount;

				// visited map 수정
				List<Integer> tempList = new ArrayList<>();
				tempList.add(maxIndex);
				visited.put(coordinate, tempList);
			}
		}
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws Exception {

		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());

		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine().trim());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());

			microList = new Micro[K];
			visited = new HashMap<>();

			for (int index = 0; index < K; index++) {
				st = new StringTokenizer(br.readLine().trim());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int microCount = Integer.parseInt(st.nextToken());
				int directionNumber = Integer.parseInt(st.nextToken());
				Direction direction = selectDirection(directionNumber);

				Micro micro = new Micro(x, y, microCount, direction);
				microList[index] = micro;

				Coordinate coordinate = new Coordinate(x, y);
				List<Integer> tempList = new ArrayList<>();
				tempList.add(index);
				visited.put(coordinate, tempList);
			}

			start();

			sum = 0;
			for (Micro micro : microList) {
				if (micro != null) {
					sum += micro.count;
				}
			}

			sb.append("#").append(test_case).append(" ").append(sum).append("\n");

		}
		System.out.println(sb.toString());

	}
}

// 유형 : 시뮬레이션
// 기능
// - 군집 이동 (M 시간 반복)
//	- 군집 방향으로 1칸 이동
// 	- 군집이 약품 칸 도달 시 처리 (방향 전환, 소멸)
// 	- 군집 병합 (미생물 수 비교, 방향 결정)

// 자료구조 
// 미생물 리스트

// 문제 이해
// N*N 정사각형
// k개 미생물 군집
// 군집 정보 = 가로, 세로, 미생물 수, 이동 방향

// 바깥쪽 셀에 약품

// 이동방향 = 상하좌우
// 군집 1시간마다 이동방향의 다음 셀로 이동

// 약품 셀 도착 시 군집의 미생물 절반 죽음 + 이동 방향 반대
// 2로 나누고 버림 (홀수의 경우)
// 미생물 수 0이 되면 군집 사라짐

// 2개 이상 군집 한 셀에 모이는 경우 군집 합쳐짐
// 미생물 수는 합쳐짐
// 미생물 수 큰 군집의 이동방향 따름

// M시간 이후 미생물 수 총합 구하기

// 제약 사항
// 50개 TC 5초
// N: 5~100
// K: 5~1000
// M: 1~1000

// 군집 내 미생물 수 : 1~10000
// 상하좌우 : 1234

// 문제 풀이
// 미생물 군집 클래스 
// 가장 자리 체크 = x or y가 0 or N-1
// 각 시간마다 모든 미생물 군집에 대해 처리
// visited 배열에 미생물 군집 id 설정
// 미생물 군집 hashmap에 저장
