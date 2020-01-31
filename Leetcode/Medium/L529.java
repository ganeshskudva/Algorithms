class Solution {
public class Cell {
        int x;
        int y;
        Cell (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    int[][] dirs = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1}, {1,-1},{-1,1}};

    char getCount(char[][] board, int i, int j) {
        int cnt = 0;
        if (i == 2 &&j == 1) {
            int abc = 0;
        }
        for (int[] d: dirs) {
            int newX = i + d[0];
            int newY = j + d[1];

            if (isValid(board, newX, newY) && board[newX][newY] == 'M')
                cnt++;
        }

        return (char)(cnt + '0');
    }

    public boolean isValid(char[][] board, int i, int j) {
        int m = board.length, n = board[0].length;

        return i >= 0 && i < m && j >= 0 && j < n;
    }

    public char[][] updateBoard(char[][] board, int[] click) {
        int m = board.length, n = board[0].length;
        char[][] res = new char[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = board[i][j];
            }
        }

        if (res[click[0]][click[1]] == 'M') {
            res[click[0]][click[1]] = 'X';
            return res;
        }
        boolean[][] visited = new boolean[m][n];
        Queue<Cell> q = new LinkedList<>();
        q.offer(new Cell(click[0], click[1]));

        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Cell c = q.poll();

                if (visited[c.x][c.y])
                    continue;
                visited[c.x][c.y] = true;
                if (res[c.x][c.y] == 'E') {
                    char ch = getCount(res, c.x, c.y);
                    if (ch == '0')
                        res[c.x][c.y] = 'B';
                    else
                        res[c.x][c.y] = ch;
                }
                if (res[c.x][c.y] ==  'B') {
                    for (int[] d : dirs) {
                        int newX = c.x + d[0];
                        int newY = c.y + d[1];

                        if (isValid(board, newX, newY)) {
                            if (!visited[newX][newY])
                                q.offer(new Cell(newX, newY));
                        }
                    }
                }
            }
        }

        return res;
    }
}
