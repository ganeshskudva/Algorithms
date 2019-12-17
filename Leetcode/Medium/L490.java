// 490. The Maze
class Solution {
class Cell {
        int x;
        int y;
        Cell(int x, int y){
            this.x=x;
            this.y=y;
        }
    }

    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        boolean[][] visited = new boolean[maze.length][maze[0].length];
        int[][] directions = {{1,0},{-1,0},{0,1},{0,-1}};

        Cell cell = new Cell(start[0], start[1]);
        Queue<Cell> q = new LinkedList<>();
        q.add(cell);

        while (!q.isEmpty()){
            Cell cur = q.poll();
            visited[cur.x][cur.y]=true;

            if(cur.x==destination[0] && cur.y==destination[1]) return true;

            for(int[] direction : directions) {
                int newX = cur.x;
                int newY = cur.y;

                while(isValid(maze, newX+direction[0], newY+direction[1])){
                    newX+=direction[0];
                    newY+=direction[1];
                }

                if(!visited[newX][newY]) q.add(new Cell(newX, newY));
            }
        }

        return false;
    }

    private boolean isValid(int[][] maze, int x, int y) {
       return x >= 0 && y >= 0 && x<maze.length && y<maze[0].length && maze[x][y]==0;
    }
}
