import java.util.Scanner;

public class Main {
    static int N, M;
    static int[][] board;
    static int max_val;
    static int[][] d = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    static boolean[][] visited;
    static int answer = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        board = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = scanner.nextInt();
            }
        }

        max_val = findMaxValue(board);

        d = new int[][] { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        visited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = true;
                dfs(i, j, 1, board[i][j]);
                visited[i][j] = false;
            }
        }

        System.out.println(answer);
    }

    static void dfs(int x, int y, int step, int total) {
        if (total + max_val * (4 - step) <= answer) {
            return;
        }

        if (step == 4) {
            answer = Math.max(answer, total);
            return;
        }

        for (int[] direction : d) {
            int nx = x + direction[0];
            int ny = y + direction[1];

            if (isValid(nx, ny) && !visited[nx][ny]) {
                if (step == 2) {
                    visited[nx][ny] = true;
                    dfs(x, y, step + 1, total + board[nx][ny]);
                    visited[nx][ny] = false;
                }

                visited[nx][ny] = true;
                dfs(nx, ny, step + 1, total + board[nx][ny]);
                visited[nx][ny] = false;
            }
        }
    }

    static boolean isValid(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    static int findMaxValue(int[][] arr) {
        int max = Integer.MIN_VALUE;
        for (int[] row : arr) {
            for (int val : row) {
                max = Math.max(max, val);
            }
        }
        return max;
    }
}
