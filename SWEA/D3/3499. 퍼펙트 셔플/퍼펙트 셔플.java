
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine().trim());
			int cardCount = Integer.parseInt(st.nextToken());

			int half = 0;

			// 짝수
			if (cardCount % 2 == 0) {
				half = cardCount / 2;
			}
			// 홀수
			else {
				half = cardCount / 2 + 1;
			}

			Queue<String> smallQueue = new ArrayDeque<>();
			Queue<String> bigQueue = new ArrayDeque<>();
			Queue<String> answerQueue = new ArrayDeque<>();

			st = new StringTokenizer(br.readLine().trim());

			for (int count = 0; count < half; count++) {
				bigQueue.offer(st.nextToken());
			}

			for (int count = half; count < cardCount; count++) {
				smallQueue.offer(st.nextToken());
			}

			for (int count = 0; count < cardCount; count++) {
				if (count % 2 == 0) {
					answerQueue.offer(bigQueue.poll());
				} else {
					answerQueue.offer(smallQueue.poll());
				}
			}

			sb.append("#").append(test_case).append(" ");
			for (String string : answerQueue) {
				sb.append(string).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
}

// 문제 이해
// 퍼펙트 셔플 =
// 카드 덱 정확히 절반으로 나눔
// 나눈 것들 교대로 뽑아 새로운 덱 만드는 것

// N개 카드 있는데 퍼펙트 셔플 후 어떤 순서인지 출력
// N이 홀수이면 교대로 놓을 때 먼저 놓는 쪽이 한장 더 들어가게 하면 됨

// A B C D E F G
// A B C D / E F G
// A E B F C G D ?

// N = 1~1000
// 카드 이름 문자열, 길이 80 이하