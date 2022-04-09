import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int maxSize;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int rows = Integer.parseInt(st.nextToken());
            int cols = Integer.parseInt(st.nextToken());
            if (rows == 0 && cols == 0) break;
            int[][] board = new int[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                for (int j = 1; j <= cols; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            maxSize = 0;
            int ans = solve(board, rows, cols);
            sb.append(ans).append('\n');
        }

        System.out.print(sb);
    }

    static int solve(int[][] board, int rows, int cols) {
        int[][] h = new int[rows + 1][cols + 1];
        int[][] v = new int[rows + 1][cols + 1];
        int[][] m = new int[rows + 1][cols + 1];
        int[][] ret = new int[rows + 1][cols + 1];

        for (int r = 1; r <= rows; r++) {
            int cnt = 1;
            for (int c = 1; c <= cols; c++) {
                if (board[r][c] == 0) {
                    cnt = 1;
                    continue;
                }
                h[r][c] = cnt;
                cnt++;
            }
        }

        for (int c = 1; c <= cols; c++) {
            int cnt = 1;
            for (int r = 1; r <= rows; r++) {
                if (board[r][c] == 0) {
                    cnt = 1;
                    continue;
                }
                v[r][c] = cnt;
                cnt++;
            }
        }

        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                m[r][c] = min(h[r][c], v[r][c]);
            }
        }

        int max = 0;
        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                if (m[r][c] == 0) {
                    ret[r][c] = 0;
                } else if (m[r][c] == 1) {
                    ret[r][c] = 1;
                } else if (ret[r - 1][c - 1] >= m[r][c] - 1) {
                    ret[r][c] = m[r][c];
                } else {
                    ret[r][c] = ret[r - 1][c - 1] + 1;
                }

                if (ret[r][c] > max) {
                    max = ret[r][c];
                }
            }
        }

        return max;
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }
}
