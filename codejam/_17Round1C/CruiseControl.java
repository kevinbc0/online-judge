import java.io.*;
import java.util.Scanner;

/**
 * Created by kevinchen on 4/22/17.
 */
public class CruiseControl {
    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
        int n = in.nextInt();
        for (int idx = 0; idx < n; idx++) {
            int dest = in.nextInt();
            int numHorses = in.nextInt();

            double slowest = 0;
            for (int jdx = 0; jdx < numHorses; jdx++) {
                int initPos = in.nextInt();
                int speed = in.nextInt();
                double time = (double) (dest - initPos) / speed;

                slowest = Math.max(slowest, time);
            }

            double cruiseSpeed = (double) dest / slowest;
            out.printf("Case #%d: %f\n", idx + 1, cruiseSpeed);
        }

        out.close();
    }
}
