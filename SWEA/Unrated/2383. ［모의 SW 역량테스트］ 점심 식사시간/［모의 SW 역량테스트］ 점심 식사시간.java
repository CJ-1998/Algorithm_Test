import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static class Person implements Comparable<Person> {
		int x;
		int y;
		// 사람 상태 관리 (내려갔는지, 계단인지...)
		int status;
		// 계단 도착 시간
		int arrivalTime;
		// 내려간 계단 수
		int downCnt;

		public Person(int x, int y) {
			super();
			this.x = x;
			this.y = y;
			// init();
		}

		void init() {
			status = M;
			arrivalTime = 0;
			downCnt = 0;
		}

		@Override
		public int compareTo(Person o) {
			return Integer.compare(this.arrivalTime, o.arrivalTime);
		}

	}

	// 순서대로 이동중, 대기중, 내려가는 중, 완료
	static final int M = 1;
	static final int W = 2;
	static final int D = 3;
	static final int C = 4;

	// map 크기
	static int N;
	// 최소 이동 시간
	static int min;

	// 계단 리스트 (x, y, 높이)
	static int[][] sList;

	// 사람 리스트
	static ArrayList<Person> pList;

	// 계단 어떤 사람이 어떤 계단 가는지 선택
	static int[] selected;

	static int cnt;

	// 계단 배정 부분조합
	private static void divide(int index) {

		if (index == cnt) {
			makeList();
			return;
		}

		selected[index] = 0;
		divide(index + 1);

		selected[index] = 1;
		divide(index + 1);
	}

	// 계단 배정에 따른 사람들 리스트에 배치
	private static void makeList() {
		ArrayList<Person>[] list = new ArrayList[] { new ArrayList<Person>(), new ArrayList<Person>() };

		for (int i = 0; i < cnt; i++) {
			Person p = pList.get(i);
			p.init();

			// 사람 i에 배정된 계단
			int no = selected[i];

			p.arrivalTime = Math.abs(p.x - sList[no][0]) + Math.abs(p.y - sList[no][1]);
			list[no].add(p);

		}

		// 각각의 계단의 사람 리스트들을 이용해서 내려가기 구현
		int timeA = processDown(list[0], sList[0][2]);
		int timeB = processDown(list[1], sList[1][2]);
		int res = Math.max(timeA, timeB);
		min = Math.min(min, res);
	}

	private static int processDown(ArrayList<Person> list, int height) {
		if (list.size() == 0) {
			return 0;
		}
		// 계단 도착 시간 기준 오름차순 성렬
		Collections.sort(list);
		int time = list.get(0).arrivalTime;
		// 이 계단 이용하는 사람 수
		int size = list.size();

		// 내려가고 있는 사람, 완료된 사람 수
		int ingCnt = 0;
		int cCnt = 0;

		// 매분마다 사람들 상태 업데이트
		while (true) {
			for (int i = 0; i < size; i++) {
				// 한 계단 온 사람 가져옴
				Person p = list.get(i);
				if (p.status == C) {
					// 이미 다 내려간 사람
					continue;
				}
				// 현재 시간에 도착
				if (p.arrivalTime == time) {
					// 상태 대기로 바꿈
					p.status = W;
				}
				// 대기 중인데 계단에 3명보다 적게 있음
				else if (p.status == W && ingCnt < 3) {
					// 계단 들어감
					p.status = D;
					// 계단 한칸 내려간 것으로 함
					p.downCnt = 1;
					// 내려가는 사람 증가
					++ingCnt;
				}
				// 내려가고 있는 중이면
				else if (p.status == D) {
					// 내려갈 계단 아직 있으면
					if (p.downCnt < height) {
						// 한 칸 더 내려감
						++p.downCnt;
					}
					// 계단 끝에 도착
					else {
						// 도착한 것으로 바꿈
						p.status = C;
						// 내려가는 사람 한명 빼고
						--ingCnt;
						// 완료된 사람 증가
						++cCnt;
					}
				}
			}
			if (cCnt == size) {
				break;
			}
			++time;
		}
		return time;
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine().trim());
			N = Integer.parseInt(st.nextToken());

			pList = new ArrayList<>();
			sList = new int[2][];
			min = Integer.MAX_VALUE;

			for (int i = 0, k = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine().trim());
				for (int j = 0; j < N; j++) {
					int temp = Integer.parseInt(st.nextToken());
					// 사람
					if (temp == 1) {
						pList.add(new Person(i, j));
					} else if (temp > 1) {
						sList[k++] = new int[] { i, j, temp };
					}
				}
			}

			cnt = pList.size();
			selected = new int[cnt];
			divide(0);
			sb.append("#").append(test_case).append(" ").append(min).append("\n");
		}
		System.out.println(sb.toString());
	}
}

// 문제 풀이
// 계단 내려갈 시간 후보
// 거리+1후 시간
// 계단에 3명이면 못 내려감

// 방법 생각
// 각 사람 기준으로 가까운 계단 이용 - 그리디
// 계단 무조건 2개
// 계단까지 가는 시간 줄이기 

// 계단 높이가 낮은 계단 이용 = 내려가는 시간 줄이기 

// 그리디적인 생각은 반례가 존재
// 가는 시간, 내려가는 시간, 대기하는 것 등 고려할게 많음
// -> 그리디는 어려움

// 다른 방법
// 계단 지정
// 각 인원 어떤 계단에 보낼지 고민하면 됨
// 사람 10명이라 2^10 밖에 안됨
// 모든 경우의 수에 대해 시뮬레이션 하면 됨

// 한 사람당 시간은 120을 넘기지 않음
// 최대 거리 시간 = 100, 최대 계단 내려가는 시간 = 120
// 그러면 전체 내려가는데 최대 120에 이런 경우의 수 1024이니 가능

// 부분 집합 형태로 계단 배정
// 계단 시간에 따라 처리하며 내려가는 시뮬레이션

// 각 사람 내려가는 시간 구함
// 계단 도착 3번째 앞 사람 시간 보기