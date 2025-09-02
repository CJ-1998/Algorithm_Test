import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int size;

	static int[][] garden;
	static int ok;
	static int no;

	static int[] dx = { 0, 0, 1, 1 };
	static int[] dy = { 0, 1, 0, 1 };

	static void check(int x, int y, int length) {
		int placeHolder = garden[x][y];

		for (int row = 0; row < length; row++) {
			for (int column = 0; column < length; column++) {
				int newRow = x + row;
				int newColumn = y + column;

				if (garden[newRow][newColumn] != placeHolder) {
					placeHolder = -1;
					break;
				}
			}
			if (placeHolder == -1) {
				break;
			}
		}

		if (placeHolder == 0) {
			ok++;
		} else if (placeHolder == 1) {
			no++;
		} else {
			int changeLength = length / 2;
			for (int count = 0; count < 4; count++) {
				int changeRow = x + (dx[count] * changeLength);
				int changeColumn = y + (dy[count] * changeLength);
				check(changeRow, changeColumn, changeLength);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		size = Integer.parseInt(st.nextToken());

		garden = new int[size][size];

		ok = 0;
		no = 0;

		for (int row = 0; row < size; row++) {
			st = new StringTokenizer(br.readLine().trim());
			for (int column = 0; column < size; column++) {
				int onePlace = Integer.parseInt(st.nextToken());
				garden[row][column] = onePlace;
			}
		}

//		for (int row = 0; row < size; row++) {
//			for (int column = 0; column < size; column++) {
//				System.out.print(garden[row][column] + " ");
//			}
//			System.out.println();
//		}

		check(0, 0, size);
		sb.append(ok).append("\n");
		sb.append(no).append("\n");
		System.out.println(sb.toString());

		// System.out.println(ok + " " + no);

	}

}

// 문제 이해
// N*N 정원
// 정상 = 0, 손상 = 1

// 현재 확인 정사각형 공간 모두 손상 or 모두 정상 
// 맞다면 
// 손상 영역으로 칠함, 정상 영역으로 칠함
// 아니면 
// 4개의 같은 크기의 정사각형으로 나눔

// 정상 영역 개수와 손상 영역 개수 구하기

// 입력
// N = 2, 4, 8, 16, ..., 128 -> N*N = 2^14

// 출력
// 정상 영역 개수, 손상 영역 개수

// 문제 풀이
// 시작 좌표, 크기 주어지고 그 네모가 다 같은지 확인
// 같으면 1인지 0인지 반환
// 아니면 4로 나눈 좌표랑 크기 전달해 다시 체크 