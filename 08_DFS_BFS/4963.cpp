import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void bfs(int x, int y, int[][] field) {
        int[] dx = {1, -1, 0, 0, 1, -1, 1, -1};
        int[] dy = {0, 0, -1, 1, -1, 1, 1, -1};
        field[x][y] = 0;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x, y});

        while (!q.isEmpty()) {
            int[] current = q.poll();
            int a = current[0];
            int b = current[1];

            for (int i = 0; i < 8; i++) {
                int nx = a + dx[i];
                int ny = b + dy[i];
                if (0 <= nx && nx < field.length && 0 <= ny && ny < field[0].length && field[nx][ny] == 1) {
                    field[nx][ny] = 0;
                    q.add(new int[]{nx, ny});
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int w = scanner.nextInt();
            int h = scanner.nextInt();
            if (w == 0 && h == 0) {
                break;
            }

            int[][] field = new int[h][w];
            int count = 0;

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    field[i][j] = scanner.nextInt();
                }
            }

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (field[i][j] == 1) {
                        bfs(i, j, field);
                        count++;
                    }
                }
            }

            System.out.println(count);
        }
    }
}
