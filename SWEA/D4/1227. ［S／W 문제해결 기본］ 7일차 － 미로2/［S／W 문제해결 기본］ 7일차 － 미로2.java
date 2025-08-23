//package SWEA.SWEA1227;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int WALL_SIZE = 100;
    static final int WALL = 1;
    static final int START = 2;
    static final int END = 3;

    static int[][] graph;
    static boolean[][] visited;

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    static boolean rightCoordinate(int x, int y) {
        if ((0 <= x & x < WALL_SIZE) && (0 <= y & y < WALL_SIZE)) {
            return true;
        }
        return false;
    }

    static boolean dfs(int x, int y) {
        if (visited[x][y]) {
            return false;
        }

        if (graph[x][y] == WALL) {
            return false;
        }

        if (graph[x][y] == END) {
            return true;
        }

        visited[x][y] = true;

        boolean isArrive = false;
        for (int count = 0; count < 4; count++) {
            int nextX = x + dx[count];
            int nextY = y + dy[count];
            if (rightCoordinate(nextX, nextY)) {
                isArrive = dfs(nextX, nextY);
                if (isArrive) {
                    break;
                }
            }
        }
        return isArrive;
    }

    public static void main(String[] args) throws Exception {

        int T = 10;
        for (int test_case = 1; test_case <= T; test_case++) {

            st = new StringTokenizer(br.readLine().trim());
            int N = Integer.parseInt(st.nextToken());

            graph = new int[WALL_SIZE][WALL_SIZE];
            visited = new boolean[WALL_SIZE][WALL_SIZE];

            int startx = 0;
            int starty = 0;

            for (int row = 0; row < WALL_SIZE; row++) {
                st = new StringTokenizer(br.readLine().trim());
                String input = st.nextToken();

                for (int column = 0; column < WALL_SIZE; column++) {
                    int coordinate = input.charAt(column) - '0';
                    graph[row][column] = coordinate;

                    if (coordinate == START) {
                        startx = row;
                        starty = column;
                    }
                }
            }

            int answer = 0;

            if (dfs(startx, starty)) {
                answer = 1;
            }

            sb.append("#").append(N).append(" ").append(answer).append("\n");
        }
        System.out.println(sb.toString());
    }
}

// 문제 이해
// 100 * 100 미로
// 흰색은 길, 노랑색은 벽

// 0은 길, 1은 벽
// 2는 출발점, 3은 도착점

// 출발점에서 도착점 가능한지?

// 출력
// 도착 가능 = 1, 도착 불가능 = 0

// 문제 풀이
// 2차원 배열로 격자 그래프 받음
// 2중 for문으로 입력 받기
// 입력 받으며 출발점, 도착점 기억해두기
// DFS 통해 확인

// 배운 점

// 다른 사람 풀이

// 문제 이해 시간

// 문제 풀이 시간
