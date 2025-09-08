import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int thingCount;
	static int bagSize;

	static int[] thingVolume;
	static int[] thingCost;
	static int[][] dp;

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine().trim());
			thingCount = Integer.parseInt(st.nextToken());
			bagSize = Integer.parseInt(st.nextToken());

			thingVolume = new int[thingCount + 1];
			thingCost = new int[thingCount + 1];

			dp = new int[thingCount + 1][bagSize + 1];

			for (int count = 1; count <= thingCount; count++) {
				st = new StringTokenizer(br.readLine().trim());
				int volume = Integer.parseInt(st.nextToken());
				int cost = Integer.parseInt(st.nextToken());
				thingVolume[count] = volume;
				thingCost[count] = cost;
			}

			// 어차피 자바 배열 0으로 초기화 되니까 필요 없네;
//			// dp 배열 padding 초기화
//			for (int count = 0; count < thingCount + 1; count++) {
//				dp[count][0] = 0;
//			}
//
//			for (int count = 0; count < bagSize + 1; count++) {
//				dp[0][count] = 0;
//			}

			for (int row = 1; row < thingCount + 1; row++) {
				for (int column = 1; column < bagSize + 1; column++) {
					int nowBagSize = column;
					int nowThingVolume = thingVolume[row];

					if (nowBagSize < nowThingVolume) {
						dp[row][column] = dp[row - 1][column];
					} else {
						int nowThingCost = thingCost[row];
						int notThingIncludeCost = dp[row - 1][column - nowThingVolume];
						int nowThingIncludeCost = nowThingCost + notThingIncludeCost;

						int notThingCost = dp[row - 1][column];

						dp[row][column] = Math.max(nowThingIncludeCost, notThingCost);
					}
				}
			}
			sb.append("#").append(test_case).append(" ").append(dp[thingCount][bagSize]).append("\n");

		}
		System.out.println(sb.toString());
	}
}

// 문제 이해
// 1~N번 물건
// 최대 부피 K만큼 넣을 수 있는 가방
// 각 물건 부피 v와 가치 c
// 가치의 합 최대화
// 가방에 담을 수 있는 최대 가치 계산

// 입력
// TC
// N K
// V C

// 문제 풀이
// knapsack 문제
// DP memoization
// 구하려는 것 = DP[N][K]
