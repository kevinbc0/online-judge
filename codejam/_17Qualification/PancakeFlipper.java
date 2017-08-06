package _17Qualification;

import java.io.*;
import java.util.Scanner;

/**
 * Created by kevinchen on 4/8/17.
 */
public class PancakeFlipper {
    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
        int n = in.nextInt();
        for (int idx = 0; idx < n; idx++) {
            String pancakes = in.next();
            int flipperSize = in.nextInt();

            out.printf("Case #%d: %s\n", idx + 1, countFlips(pancakes, flipperSize));
        }

        out.close();
    }

    private static String countFlips(String pancakes, int flipperSize) {
        boolean[] happy = stringToBooleanArray(pancakes);
        int count = 0;
        for (int idx = 0; idx + flipperSize - 1 < happy.length; idx++) {
            if (!happy[idx]) {
                count++;
                for (int jdx = 0; jdx < flipperSize; jdx++) {
                    happy[idx + jdx] = !happy[idx + jdx];
                }
            }
        }

        /*for (int idx = 0; idx < happy.length; idx++) {
            System.out.print(happy[idx] ? "+" : "-");
        }
        System.out.println();*/

        return checkPancakes(happy) ? count + "" : "IMPOSSIBLE";
    }

    private static boolean[] stringToBooleanArray(String pancakes) {
        boolean[] array = new boolean[pancakes.length()];
        for (int idx = 0; idx < array.length; idx++) {
            array[idx] = pancakes.charAt(idx) == '+';
        }

        return array;
    }

    private static boolean checkPancakes(boolean[] pancakes) {
        boolean happy = true;
        for (boolean b : pancakes) {
            happy = happy && b;
        }

        return happy;
    }
}
