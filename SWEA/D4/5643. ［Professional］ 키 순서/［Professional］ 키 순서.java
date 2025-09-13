import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int N;
	static int M;
	static int[][] graph;
	static int count; // 자신보다 키가 크거나 작은 학생수

	static void bigDFS(int cur, boolean[] visited) {
		visited[cur] = true;
		for (int i = 1; i <= N; i++) {
			if (graph[cur][i] == 1 && !visited[i]) {
				++count;
				bigDFS(i, visited);
			}
		}
	}

	static void smallDFS(int cur, boolean[] visited) {
		visited[cur] = true;
		for (int i = 1; i <= N; i++) {
			if (graph[i][cur] == 1 && !visited[i]) {
				++count;
				smallDFS(i, visited);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for (int test_case = 1; test_case <= T; test_case++) {
			st = new StringTokenizer(br.readLine().trim());
			N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine().trim());
			M = Integer.parseInt(st.nextToken());

			graph = new int[N + 1][N + 1];

			for (int m = 0; m < M; m++) {
				st = new StringTokenizer(br.readLine().trim());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());

				graph[a][b] = 1;
			}

			int answer = 0;

			for (int i = 1; i <= N; i++) {
				count = 0;
				boolean[] visited = new boolean[N + 1];
				bigDFS(i, visited);
				smallDFS(i, visited);

				if (count == N - 1) {
					answer++;
				}
			}
			sb.append("#").append(test_case).append(" ").append(answer).append("\n");

		}
		System.out.println(sb.toString());

	}
}

//문제 이해
//1~N번 학생
//두 학생끼리 키 비교한 결과 일부 주어짐
//N명 학생들 키 모두 다름

//a번 학생 b번 학생보다 키 작으면 a -> b
//학생들 키 비교한 결과 주어질 때 
//자신의 키가 몇 번째인지 알 수 있는 학생들 모두 몇명인지 계산

//문제 풀이
//자기 키 순서 확정하려면?
//N명이면 N-1번 비교해야 함

//자료구조는 어떤 것으로?
//그래프 자료구조
//정점, 간선 의미? -> 정점 = 학생, 간선 = 키 관계
//정점 중심 그래프 표현이 적절 -> 인접 행렬, 인접 리스트

//간선의 방향성?
//키 관계이기 때문에 방향 존재
//차이가 주어지지는 않았으니 가중치는 존재 X

//키가 몇번째로 큰지 알려면? 
//N-1개 주어진게 아님
//결과 일부만 주어짐
//간선 일부만 준 것
//작은 사람, 큰 사람 몇명인지 알아야 함
//작은 사람 + 큰 사람 = N-1이 되어야 함

//할 일
//자기보다 키 큰 학생들 따라가며 탐색
//-> DFS or BFS
//자기보다 키 작은 학생들 따라가며 탐색
//-> DFS or BFS

//간선 개수는 N(n-2)/2
//N = 500
//시간 복잡도 = O(N^2)

//인접 행렬은 가능
//인접 리스트는 역인접 리스트 필요
