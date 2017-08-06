package _17Round1A;

import java.io.*;
import java.util.*;

/**
 * Created by kevinchen on 4/14/17.
 */
public class AlphabetCake {
    static char[][] cake;
    static HashMap<Character, Integer> numChars;
    static HashMap<Character, Box> boxes;
    static HashMap<Character, Boolean> leftright;
    static HashMap<Character, Boolean> updown;

    private static class Box {
        int minRow, maxRow, minCol, maxCol;

        public Box(int minR, int maxR, int minC, int maxC) {
            minRow = minR;
            maxRow = maxR;
            minCol = minC;
            maxCol = maxC;
        }
    }

    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
        int n = in.nextInt();
        for (int idx = 0; idx < n; idx++) {
            readInput(in);

            for (char c : numChars.keySet()) {
                if (numChars.get(c) > 1) {
                    fillLetter(c);
                }
            }

            fillCake();
            out.printf("Case #%d:\n", idx + 1);
            for (int rdx = 0; rdx < cake.length; rdx++) {
                for (int cdx = 0; cdx < cake[rdx].length; cdx++) {
                    out.print(cake[rdx][cdx]);
                }
                out.println();
            }
        }

        out.close();
    }

    private static void readInput(Scanner in) {
        int rows = in.nextInt();
        int cols = in.nextInt();
        cake = new char[rows][cols];
        numChars = new HashMap<>();
        boxes = new HashMap<>();
        updown = new HashMap<>();
        leftright = new HashMap<>();

        for (char c = 'A'; c <= 'Z'; c++) {
            boxes.put(c, new Box(rows, 0, cols, 0));
            numChars.put(c, 0);
            updown.put(c, false);
            leftright.put(c, false);
        }

        in.nextLine();
        for (int rdx = 0; rdx < rows; rdx++) {
            String line = in.nextLine();
            for (int cdx = 0; cdx < cols; cdx++) {
                cake[rdx][cdx] = line.charAt(cdx);
                if (line.charAt(cdx) != '?') {
                    numChars.put(line.charAt(cdx), numChars.get(line.charAt(cdx)) + 1);
                    Box box = boxes.get(line.charAt(cdx));
                    box.minRow = Math.min(rdx, box.minRow);
                    box.maxRow = Math.max(rdx, box.maxRow);
                    box.minCol = Math.min(cdx, box.minCol);
                    box.maxCol = Math.max(cdx, box.maxCol);
                }
            }
        }
    }

    private static void fillLetter(char c) {
        Box box = boxes.get(c);
        for (int rdx = box.minRow; rdx <= box.maxRow; rdx++) {
            for (int cdx = box.minCol; cdx <= box.maxCol; cdx++) {
                cake[rdx][cdx] = c;
            }
        }
    }

    private static void fillCake() {
        for (int rdx = 0; rdx < cake.length; rdx++) {
            for (int cdx = 0; cdx < cake[rdx].length; cdx++) {
                if (cake[rdx][cdx] == '?') {
                    int[] dx = {1, 0, -1, 0};
                    int[] dy = {0, 1, 0, -1};

                    for (int idx = 0; idx < 4; idx++) {
                        if (rdx + dx[idx] > 0 && rdx + dx[idx] < cake.length &&
                                cdx + dy[idx] > 0 && cdx + dy[idx] < cake.length &&
                                cake[rdx + dx[idx]][cdx + dy[idx]] != '?' &&
                                numChars.get(cake[rdx + dx[idx]][cdx + dy[idx]]) == 1) {
                            if (idx == 0 || idx == 2) {

                            }
                            cake[rdx][cdx] = cake[rdx + dx[idx]][cdx + dy[idx]];
                            break;
                        }
                    }
                }
            }
        }
    }
}
