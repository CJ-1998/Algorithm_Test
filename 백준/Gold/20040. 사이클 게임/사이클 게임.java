import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int[] parent;
	static int[] rank;

	static int size;
	static int line;

	static void make() {
		for (int index = 0; index < size; index++) {
			parent[index] = index;
			rank[index] = 0;
		}
	}

	static int find(int index) {
		if (parent[index] == index) {
			return index;
		}

		return find(parent[index]);
	}

	static boolean union(int one, int two) {

		int oneParent = find(one);
		int twoParent = find(two);

		if (oneParent == twoParent) {
			return false;
		} else {
			if (rank[oneParent] > rank[twoParent]) {
				parent[twoParent] = oneParent;
			} else {
				parent[oneParent] = twoParent;

				if (rank[oneParent] == rank[twoParent]) {
					rank[twoParent]++;
				}
			}
		}

		return true;
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine().trim());
		size = Integer.parseInt(st.nextToken());
		line = Integer.parseInt(st.nextToken());

		parent = new int[size];
		rank = new int[size];

		make();

		int answer = 0;
		for (int count = 1; count <= line; count++) {
			st = new StringTokenizer(br.readLine().trim());
			int one = Integer.parseInt(st.nextToken());
			int two = Integer.parseInt(st.nextToken());

			if (union(one, two)) {
				answer = count;
			} else {
				break;
			}
		}

		answer++;

		if (answer == line + 1) {
			answer = 0;
		}

		sb.append(answer);
		System.out.println(sb.toString());

	}

}

// 문제 풀이 
// union 하려고 하는데 제일 위 부모 같으면 사이클 생김