import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static final int CARD_NUMBER = 9;

	static int winCount;
	static int loseCount;

	static int[] myCard;
	static int[] otherCard;

	static int[] selectedCard;
	static boolean[] visited;

	static void permutation(int selectedIndex) {
		if (selectedIndex == CARD_NUMBER) {
			compareScore();
			return;
		}

		for (int index = 0; index < CARD_NUMBER; index++) {
			if (visited[index]) {
				continue;
			}

			selectedCard[selectedIndex] = otherCard[index];
			visited[index] = true;
			permutation(selectedIndex + 1);
			visited[index] = false;
		}

	}

	static void compareScore() {
		int myScore = 0;
		int otherScore = 0;

		for (int count = 0; count < CARD_NUMBER; count++) {
			if (myCard[count] > selectedCard[count]) {
				myScore += myCard[count] + selectedCard[count];
			} else {
				otherScore += myCard[count] + selectedCard[count];
			}
		}
		if (myScore > otherScore) {
			winCount++;
		} else if (myScore < otherScore) {
			loseCount++;
		}
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= T; test_case++) {
			winCount = 0;
			loseCount = 0;

			myCard = new int[CARD_NUMBER];
			otherCard = new int[CARD_NUMBER];
			selectedCard = new int[CARD_NUMBER];
			visited = new boolean[CARD_NUMBER];

			st = new StringTokenizer(br.readLine().trim());
			for (int count = 0; count < CARD_NUMBER; count++) {
				myCard[count] = Integer.parseInt(st.nextToken());
			}

			int index = 0;
			for (int cardNumber = 1; cardNumber <= CARD_NUMBER * 2; cardNumber++) {
				boolean hasCard = false;
				for (int myCardIndex = 0; myCardIndex < CARD_NUMBER; myCardIndex++) {
					if (cardNumber == myCard[myCardIndex]) {
						hasCard = true;
						break;
					}
				}
				if (!hasCard) {
					otherCard[index++] = cardNumber;
				}
			}
			/*
			 * System.out.println("내카드"); for (int myCardIndex = 0; myCardIndex <
			 * CARD_NUMBER; myCardIndex++) { System.out.print(myCard[myCardIndex] + " "); }
			 * 
			 * System.out.println(); System.out.println("상대 카드"); for (int myCardIndex = 0;
			 * myCardIndex < CARD_NUMBER; myCardIndex++) {
			 * System.out.print(otherCard[myCardIndex] + " "); }
			 */

			// combination(0, 0);
			permutation(0);
			sb.append("#").append(test_case).append(" ").append(winCount).append(" ").append(loseCount).append("\n");

		}
		System.out.println(sb.toString());
	}

}

// 문제 풀이
// 1~18 카드 게임
// 9장씩 나눔
// 9라운드 게임 진행

// 한 라운드에 한 장씩 카드 냄
// 카드 적힌 수 비교해 점수 계산
// 높은 수 낸 사람 = 두 카드 적힌 수 합만큼 점수
// 낮은 수 낸 사람 = 점수 없음

// 9라운드 끝내고 총점 따졌을 때 총점 높은 사람이 승자
// 총점 같음 무승부

// 받은 9장 카드 숫자 주어짐
// 순서 고정되어 있으니 카드 내는 순서 따라 승패 정해짐

// 이기는 경우, 지는 경우 총 몇가지인지 구하기

// 입력
// 9개 정수 공백으로 주어짐

// 문제 풀이
// 순열 * for문 돌며 점수 비교
// 9! * 9 = 320만
