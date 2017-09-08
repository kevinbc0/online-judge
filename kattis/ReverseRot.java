import java.util.*;

public class ReverseRot {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int shift;
        while ((shift = in.nextInt()) != 0) {
            String code = in.next();

            StringBuilder sb = new StringBuilder();

            for (int i = code.length() - 1; i >= 0; i--) {
                int before = (int) code.charAt(i) - 65;
                if (before == -19) {
                    before = 27;
                } else if (before == 30) {
                    before = 26;
                }

                int after = (before + shift) % 28;
                if (after == 26) {
                    sb.append("_");
                } else if (after == 27) {
                    sb.append(".");
                } else {
                    sb.append((char) (after + 65));
                }
            }

            System.out.println(sb.toString());
        }
    }
}
