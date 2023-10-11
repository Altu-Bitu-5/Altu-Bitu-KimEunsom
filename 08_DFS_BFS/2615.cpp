import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] graph = new int[19][19];
        int[] dx = {0, 1, 1, -1};
        int[] dy = {1, 0, 1, 1};

        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                graph[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                if (graph[i][j] != 0) {
                    int target = graph[i][j];

                    for (int k = 0; k < 4; k++) {
                        int cnt = 1;
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        while (0 <= nx && nx < 19 && 0 <= ny && ny < 19 && graph[nx][ny] == target) {
                            cnt++;

                            if (cnt == 5) {
                                if (0 <= i - dx[k] && i - dx[k] < 19 && 0 <= j - dy[k] && j - dy[k] < 19 &&
                                        graph[i - dx[k]][j - dy[k]] == target) {
                                    break;
                                }
                                if (0 <= nx + dx[k] && nx + dx[k] < 19 && 0 <= ny + dy[k] && ny + dy[k] < 19 &&
                                        graph[nx + dx[k]][ny + dy[k]] == target) {
                                    break;
                                }

                                System.out.println(target);
                                System.out.println(i + 1 + " " + (j + 1));
                                System.exit(0);
                            }

                            nx += dx[k];
                            ny += dy[k];
                        }
                    }
                }
            }
        }

        System.out.println(0);
    }
}
