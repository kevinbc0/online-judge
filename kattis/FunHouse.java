import java.util.*;

public class FunHouse {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int w = in.nextInt();
        int l = in.nextInt();
        int n = 1;
        while (w + l != 0) {
            char[][] house = new char[l][w];
            int doorX = 0, doorY = 0;

            for (int i = 0; i < l; i++) {
                String line = in.next();
                for (int j = 0; j < w; j++) {
                    char c = line.charAt(j);
                    if (c == '*') {
                        doorX = j;
                        doorY = i;
                    }
                    house[i][j] = line.charAt(j);
                }
            }

            int directionX;
            int directionY;
            if (doorX == 0) {
                directionX = 1;
                directionY = 0;
            } else if (doorX == w - 1) {
                directionX = -1;
                directionY = 0;
            } else if (doorY == 0) {
                directionY = 1;
                directionX = 0;
            } else {
                directionX = 0;
                directionY = -1;
            }

            int x = doorX;
            int y = doorY;
            while (true) {
                x += directionX;
                y += directionY;

                if (house[y][x] == '/') {
                    int temp = directionX;
                    directionX = -1 * directionY;
                    directionY = -1 * temp;
                } else if (house[y][x] == '\\') {
                    int temp = directionX;
                    directionX = directionY;
                    directionY = temp;
                } else if (house[y][x] == 'x') {
                    house[y][x] = '&';
                    break;
                }
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < house.length; i++) {
                for (int j = 0; j < house[i].length; j++) {
                    sb.append(house[i][j]);
                }
                sb.append("\n");
            }

            System.out.print(String.format("HOUSE %d\n%s", n++, sb.toString()));
            w = in.nextInt();
            l = in.nextInt();
        }
    }
}
