package _17Round1A;

import java.io.*;
import java.util.*;

/**
 * Created by kevinchen on 4/14/17.
 */
public class Ratatouille {
    static int[] gramsNeeded;
    static ArrayList<HashMap<Integer, Integer>> ingredientList;

    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
        int n = in.nextInt();
        for (int idx = 0; idx < n; idx++) {
            readInput(in);

            HashMap<Integer, Integer> firstIngredient = ingredientList.get(0);
            int numKits = 0;
            for (int servings : firstIngredient.keySet()) {
                int minPackets = firstIngredient.get(servings);

                for (int jdx = 1; jdx < ingredientList.size(); jdx++) {
                    minPackets = Math.min(minPackets, ingredientList.get(jdx).getOrDefault(servings, 0));
                }

                numKits += minPackets;
            }

            out.printf("Case #%d: %d\n", idx + 1, numKits);
        }

        out.close();
    }

    private static void readInput(Scanner in) {
        int numIngredients = in.nextInt();
        int numPackets = in.nextInt();

        gramsNeeded = new int[numIngredients];
        for (int idx = 0; idx < numIngredients; idx++) {
            gramsNeeded[idx] = in.nextInt();
        }

        ingredientList = new ArrayList<>();

        for (int idx = 0; idx < numIngredients; idx++) {
            HashMap<Integer, Integer> servingNumbers = new HashMap<>();
            for (int jdx = 0; jdx < numPackets; jdx++) {
                int grams = in.nextInt();
                int servings = grams / gramsNeeded[idx];
                int expectedAmount = servings * gramsNeeded[idx];

                if (grams * 10 <= expectedAmount * 11 && grams * 10 >= 9 * expectedAmount) {
                    servingNumbers.put(servings, servingNumbers.getOrDefault(servings, 0) + 1);
                } else {
                    expectedAmount += gramsNeeded[idx];
                    if (grams * 10 <= expectedAmount * 11 && grams * 10 >= 9 * expectedAmount) {
                        servingNumbers.put(servings + 1, servingNumbers.getOrDefault(servings + 1, 0) + 1);
                    }
                }
            }

            ingredientList.add(servingNumbers);
        }

        System.out.println(ingredientList);
    }
}
