package _16Round1A;

import java.io.*;
import java.util.Scanner;
import java.util.jar.Pack200;

/**
 * Created by kevinchen on 4/14/17.
 */
public class LastWord {
    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
        int n = Integer.parseInt(in.nextLine());
        for (int idx = 0; idx < n; idx++) {
            String word = in.nextLine();
            StringBuilder lastWord = new StringBuilder();
            lastWord.append(word.charAt(0));

            for (int jdx = 1; jdx < word.length(); jdx++) {
                if (word.charAt(jdx) >= lastWord.charAt(0)) {
                    lastWord.insert(0, word.charAt(jdx));
                } else {
                    lastWord.append(word.charAt(jdx));
                }
            }

            out.printf("Case #%d: %s\n", idx + 1, lastWord);
        }

        out.close();
    }
}
