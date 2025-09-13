import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int computerCount;
	static int lineCount;

	static boolean[] visited;

	static List<Integer>[] graph;

	static int virusCount = 0;

	public static void dfs(int index) {
		if (visited[index] == true) {
			return;
		}

		visited[index] = true;
		virusCount++;
		for (int count = 0; count < graph[index].size(); count++) {
			dfs(graph[index].get(count));
		}
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		computerCount = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine().trim());
		lineCount = Integer.parseInt(st.nextToken());

		graph = new List[computerCount];
		visited = new boolean[computerCount];
		virusCount = 0;

		for (int count = 0; count < computerCount; count++) {
			graph[count] = new ArrayList<>();
		}

		for (int count = 0; count < lineCount; count++) {
			st = new StringTokenizer(br.readLine().trim());
			int from = Integer.parseInt(st.nextToken()) - 1;
			int to = Integer.parseInt(st.nextToken()) - 1;

			graph[from].add(to);
			graph[to].add(from);
		}
		dfs(0);
		sb.append(virusCount - 1).append("\n");
		System.out.println(sb.toString());

	}
}

// 문제 풀이
// 웜 바이러스 네트워크 통해 전파
// 네트워크 연결되어 있는 모든 컴퓨터 웜 바이러스 걸림

// 1번 컴퓨터 바이러스에 걸림
// 웜 바이러스에 걸리게 되는 컴퓨터 수 출력

// 제약사항
// 컴퓨터 수 100이하
// 컴퓨터 번호 1번부터

// 입력
// 컴퓨터 수
// 네트워크 상 직접 연결되어 있는 컴퓨터 쌍 수

// 출력
// 바이러스 컬리게 되는 컴퓨터 수

// 문제 풀이
// DFS