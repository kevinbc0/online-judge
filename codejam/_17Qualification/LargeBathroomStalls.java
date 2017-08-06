package _17Qualification;

import java.io.*;
import java.util.Scanner;

/**
 * Created by kevinchen on 4/8/17.
 */
public class LargeBathroomStalls {
    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
        int n = in.nextInt();
        for (int idx = 0; idx < n; idx++) {
            long numStalls = in.nextLong();
            long numPeople = in.nextLong();

            long[] answer = fillSpaces(numStalls, numPeople);
            out.printf("Case #%d: %d %d\n", idx + 1, answer[0], answer[1]);
        }

        out.close();
    }

    private static long[] fillSpaces(long numStalls, long numPeople) {
        long remainingSpace = numStalls - (numPeople - 1);
        long numContingentSpaceRatio = 1;
        while (numContingentSpaceRatio <= numPeople) {
            numContingentSpaceRatio <<= 1;
        }
        numContingentSpaceRatio = numContingentSpaceRatio == 1 ? 1 : numContingentSpaceRatio >> 1;

        long lastSpaceSize = remainingSpace / numContingentSpaceRatio + (remainingSpace % numContingentSpaceRatio == 0 ? 0 : 1);
        long[] answer = new long[2];
        answer[0] = lastSpaceSize / 2;
        answer[1] = lastSpaceSize % 2 == 0 ? lastSpaceSize / 2 - 1 : lastSpaceSize / 2;

        return answer;
    }
}
