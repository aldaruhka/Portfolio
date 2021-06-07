public class FindTheWay implements RouteFinder {

    public static void main(String[] args) {
        FindTheWay way = new FindTheWay();
        Map map = new Map(5, 10, 3); //генерируем карту
        map.printMap();
        System.out.println();
        map.map = way.findRoute(map.map); //строим маршрут
        map.printMap();
    }

    public char[][] findRoute(char[][] map) {
        if (!checkSymbolsOfMap(map))
            return null;
        Coordinates start = new Coordinates(map, '@');
        Coordinates finish = new Coordinates(map, 'X');
        try {
            fillMapWithNumbers(map, start.k, start.l, 0);
        } catch (StackOverflowError e) {
            System.err.println("Карта слишком большая");
            return null;
        }
        if (map[finish.k][finish.l] == 'X')
            return null;
        printPluses(map, finish.k, finish.l);
        eraseNumbersInMap(map, start, finish);
        return map;
    }

    public void fillMapWithNumbers(char[][] map, short k, short l, int count) {
        map[k][l] = (char) ('a' + count);
        if (k - 1 >= 0 && (map[k - 1][l] > 'a' + count + 1 || map[k - 1][l] == '.' || map[k - 1][l] == 'X')) {
            fillMapWithNumbers(map, (short) (k - 1), l, count + 1);
        }
        if (l - 1 >= 0 && (map[k][l - 1] > 'a' + count + 1 || map[k][l - 1] == '.' || map[k][l - 1] == 'X')) {
            fillMapWithNumbers(map, k, (short) (l - 1), count + 1);
        }
        if (k + 1 < map.length && (map[k + 1][l] > 'a' + count + 1 || map[k + 1][l] == '.' || map[k + 1][l] == 'X')) {
            fillMapWithNumbers(map, (short) (k + 1), l, count + 1);
        }
        if (l + 1 < map[0].length && (map[k][l + 1] > 'a' + count + 1 || map[k][l + 1] == '.' || map[k][l + 1] == 'X')) {
            fillMapWithNumbers(map, k, (short) (l + 1), count + 1);
        }
    }

    //Прорисовка пути по полученным цифрам на карте
    public void printPluses(char[][] map, int k, int l) {
        if (l - 1 >= 0 && map[k][l - 1] == map[k][l] - 1) {
            map[k][l] = '+';
            printPluses(map, k, l - 1);
        }
        if (k - 1 >= 0 && map[k - 1][l] == map[k][l] - 1) {
            map[k][l] = '+';
            printPluses(map, k - 1, l);
        }
        if (l + 1 < map[0].length && map[k][l + 1] == map[k][l] - 1) {
            map[k][l] = '+';
            printPluses(map, k, l + 1);
        }
        if (k + 1 < map.length && map[k + 1][l] == map[k][l] - 1) {
            map[k][l] = '+';
            printPluses(map, k + 1, l);
        }
    }

    //Очистка карты до прорисованного пути и стандартных символов
    public void eraseNumbersInMap(char[][] map, Coordinates start, Coordinates finish) {
        int     size_k = map.length,
                size_l = map[0].length;

        for(int k = 0; k < size_k; k++)
            for(int l = 0; l < size_l; l++)
                if (map[k][l] > 'a')
                    map[k][l] = '.';
        map[start.k][start.l] = '@';
        map[finish.k][finish.l] = 'X';
    }

    //Проверка map на соответствие символов
    private boolean checkSymbolsOfMap(char[][] map) {
        if (map == null)
            return false;

        boolean start = false,
                finish = false;

        for (int k = 0; k < map.length; k++)
            for (int l = 0; l < map[0].length; l++)
                switch (map[k][l]) {
                    case '.', '#':
                        break;
                    case 'X': {
                        if (!start)
                            start = true;
                        else
                            return false;
                        break;
                    }
                    case '@': {
                        if (!finish)
                            finish = true;
                        else
                            return false;
                        break;
                    }
                    default:
                        return false;
                }
        return start && finish;
    }
}
