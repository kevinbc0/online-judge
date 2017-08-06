package _17Qualification;

import java.io.*;
import java.util.*;

/**
 * Created by kevinchen on 4/8/17.
 */
public class FashionShow {

    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
        int n = in.nextInt();
        for (int idx = 0; idx < n; idx++) {
            int gridSize = in.nextInt();
            int numPlaced = in.nextInt();
        }

        out.close();
    }

    private static class Grid {
        private char[][] grid;
        private boolean[] rowHasNonPlus;
        private boolean[][] diagonalHasNonX;
        int totalScore;

        public Grid(int size) {
            grid = new char[size][size];
            rowHasNonPlus = new boolean[size];
            diagonalHasNonX = new boolean[2][size];
            totalScore = 0;
        }

        public boolean addModel(char type, int row, int column) {
            if (grid[row][column] == 'o' || grid[row][column] == 'x') {
                rowHasNonPlus[row] = false;
            }
            if (grid[row][column] == 'o' || grid[row][column] == '+') {

            }
            grid[row][column] = type;
            if (type != '+') {
            }
            if (type != 'x') {
                if (row - column == 0) {

                }
            }

            return true;
        }
    }
}
