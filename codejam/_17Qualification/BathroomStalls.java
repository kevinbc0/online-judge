package _17Qualification;

import java.io.*;
import java.util.*;

/**
 * Created by kevinchen on 4/8/17.
 */
public class BathroomStalls {
    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
        int n = in.nextInt();
        for (int idx = 0; idx < n; idx++) {
            long numStalls = in.nextLong();
            long numPeople = in.nextLong();

            long[] answer = fillStalls(numStalls, numPeople);
            out.printf("Case #%d: %d %d\n", idx + 1, answer[0], answer[1]);
        }

        out.close();
    }

    private static long[] fillStalls(long numStalls, long numPeople) {
        PriorityQueue<Long> spaces = new PriorityQueue<>(Comparator.reverseOrder());
        spaces.add(numStalls);

        for (long idx = 0; idx < numPeople - 1; idx++) {
            long space = spaces.remove();
            long leftSpace = space % 2 == 0 ? space / 2 - 1 : space / 2;
            long rightSpace = space / 2;
            if (leftSpace != 0) {
                spaces.add(leftSpace);
            }
            if (rightSpace != 0) {
                spaces.add(rightSpace);
            }
        }

        long lastSpace = spaces.remove();
        long[] answer = new long[2];
        answer[0] = lastSpace / 2;
        answer[1] = lastSpace % 2 == 0 ? lastSpace / 2 - 1 : lastSpace / 2;

        return answer;
    }
}
