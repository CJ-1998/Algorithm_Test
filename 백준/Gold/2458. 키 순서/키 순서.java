import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	// 학생 수
	static int studentCount;

	// 간선 수
	static int lineCount;

	static int[][] graph;

	// 큰 학생 수
	static int bigCount;
	// 작은 학생 수
	static int smallCount;

	// 몇 번째인지 아는 학생 수
	static int knowStudent;

	static boolean[] visited;

	// 큰 학생 따라가기
	static void bigDFS(int student) {
		if (visited[student]) {
			return;
		}
		visited[student] = true;
		++bigCount;
		for (int nextStudent = 0; nextStudent < studentCount; nextStudent++) {
			if (graph[student][nextStudent] == 1) {
				bigDFS(nextStudent);
			}
		}
	}

	// 작은 학생 따라가기
	static void smallDFS(int student) {
		if (visited[student]) {
			return;
		}
		visited[student] = true;
		++smallCount;
		for (int nextStudent = 0; nextStudent < studentCount; nextStudent++) {
			if (graph[nextStudent][student] == 1) {
				smallDFS(nextStudent);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		studentCount = Integer.parseInt(st.nextToken());
		lineCount = Integer.parseInt(st.nextToken());

		knowStudent = 0;

		graph = new int[studentCount][studentCount];

		// 큰 학생 표시
		for (int count = 0; count < lineCount; count++) {
			st = new StringTokenizer(br.readLine().trim());
			int small = Integer.parseInt(st.nextToken()) - 1;
			int big = Integer.parseInt(st.nextToken()) - 1;

			graph[small][big] = 1;
		}

		for (int student = 0; student < studentCount; student++) {
			bigCount = 0;
			smallCount = 0;
			visited = new boolean[studentCount];
			bigDFS(student);
			visited = new boolean[studentCount];
			smallDFS(student);

			if ((bigCount + smallCount) - 2 == studentCount - 1) {
				knowStudent++;
			}
		}
		sb.append(knowStudent).append("\n");
		System.out.println(sb.toString());
	}
}

// 문제 이해
// 1~N번 학생
// 두 학생끼리 키 비교한 결과 일부 주어짐
// N명 학생들 키 모두 다름

// a번 학생 b번 학생보다 키 작으면 a -> b
// 학생들 키 비교한 결과 주어질 때 
// 자신의 키가 몇 번째인지 알 수 있는 학생들 모두 몇명인지 계산

// 문제 풀이
// 나보다 키 큰 사람 + 작은 사람 = 전체 학생 수 -1