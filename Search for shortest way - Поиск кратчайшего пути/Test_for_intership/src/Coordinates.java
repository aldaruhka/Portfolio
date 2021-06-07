public class Coordinates {
    short k = 0;
    short l = 0;

    public Coordinates (char[][] map, char symbol) {
        for(short k = 0; k < map.length; k++)
            for(short l = 0; l < map[0].length; l++)
                if (map[k][l] == symbol) {
                    this.k = k;
                    this.l = l;
                    return;
                }
    }
}