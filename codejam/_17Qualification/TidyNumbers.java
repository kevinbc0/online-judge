package _17Qualification;

import java.io.*;
import java.util.*;

/**
 * Created by kevinchen on 4/8/17.
 */
public class TidyNumbers {
    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
        int n = in.nextInt();
        for (int idx = 0; idx < n; idx++) {
            long num = in.nextLong();
            out.printf("Case #%d: %d\n", idx + 1, findTidy(num));
        }

        out.close();
    }

    private static long findTidy(long num) {
        ArrayList<Integer> numList = numToList(num);
        int index = 0;
        while (index + 1 < numList.size()) {
            if (numList.get(index) > numList.get(index + 1)) {
                while (index - 1 >= 0 && numList.get(index) == numList.get(index - 1)) {
                    index--;
                }
                break;
            }
            index++;
        }

        if (index != numList.size() - 1) {
            numList.set(index, numList.get(index) - 1);
        }
        for (int idx = index + 1; idx < numList.size(); idx++) {
            numList.set(idx, 9);
        }

        return listToNum(numList);
    }

    private static ArrayList<Integer> numToList(long num) {
        ArrayList<Integer> numList = new ArrayList<>();
        while (num > 0) {
            numList.add((int) (num % 10));
            num = num / 10;
        }
        Collections.reverse(numList);
        return numList;
    }

    private static long listToNum(ArrayList<Integer> list) {
        long num = 0;
        for (int idx = 0; idx < list.size(); idx++) {
            num = num * 10 + list.get(idx);
        }

        return num;
    }
}
