public class Map {
    char[][] map;

    public Map(int k, int l, int obstacle) {
        int i, j;

        this.map = new char[k][l];
        for (i = 0; i < k; i++)
            for (j = 0; j < l; j++)
                this.map[i][j] = (Math.random() - 0.1 * obstacle >= 0) ? '.' : '#';
        i = (int) (Math.random() * k);
        j = (int) (Math.random() * l);
        this.map[i][j] = 'X';
        i = (int) (Math.random() * k);
        j = (int) (Math.random() * l);
        this.map[i][j] = '@';
    }

    void printMap() {
        if (this.map == null) {
            System.out.println("null");
            return;
        }
        int i, j;
        for (i = 0; i < this.map.length; i++) {
            for (j = 0; j < this.map[0].length; j++)
                System.out.print(this.map[i][j]);
            System.out.println();
        }
    }
}
