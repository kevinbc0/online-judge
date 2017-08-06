import java.io.*;
import java.util.Scanner;

/**
 * Created by kevinchen on 4/22/17.
 */
public class StableNeighbors {
    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
        int n = in.nextInt();
        for (int idx = 0; idx < n; idx++) {
            int stallSize = in.nextInt();
            int red = in.nextInt();
            int orange = in.nextInt();
            int yellow = in.nextInt();
            int green = in.nextInt();
            int blue = in.nextInt();
            int violet = in.nextInt();

            int numRed = red + orange + violet;
            int numBlue = blue + green + violet;
            int numYellow = yellow + orange + green;

            int colorLimit = stallSize / 2;
            if (numRed > colorLimit || numBlue > colorLimit || numYellow > colorLimit) {
                out.printf("Case #%d: IMPOSSIBLE\n", idx + 1);
                continue;
            }

            char[] stable = new char[stallSize];
            for (int jdx = 0; jdx < stable.length; jdx++) {
                stable[jdx] = 'E';
            }

            int index = 0;
            while (red > 0) {
                stable[index] = 'R';
                index += 2;
                red--;
            }

            index = 0;
            index = findSpace(stable, index);
            while (blue > 0) {
                stable[index] = 'B';
                index = findSpace(stable, index);
                blue--;
            }

            index = 0;
            index = findSpace(stable, index);
            while (yellow > 0) {
                stable[index] = 'Y';
                index = findSpace(stable, index);
                yellow--;
            }

            StringBuilder output = new StringBuilder();
            for (char c : stable) {
                output.append(c);
            }

            out.printf("Case #%d: %s\n", idx + 1, output.toString());
        }

        out.close();
    }

    static int findSpace(char[] arr, int index) {
        boolean space = false;
        int count = 0;
        while (true) {
            count++;
            if (count > arr.length) {
                return 0;
            }

            if (arr[index] == 'E') {
                if (space) {
                    return index;
                } else {
                    count = 0;
                    space = true;
                }
            }

            if (index == arr.length - 1) {
                index = 0;
            } else {
                index++;
            }
        }
    }
}
