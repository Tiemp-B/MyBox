import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int GSD = sc.nextInt(); // GCD
        int LCM = sc.nextInt(); // LCM
        sc.close();

        long ansSum = Long.MAX_VALUE;
        long A = 0, B = 0;

        int gap = LCM / GSD;

        List<Integer> el2 = new ArrayList<>();

        // 소인수 분해
        for (int i = 2; i <= LCM / (GSD * 2) && gap > 1; i++) {
            if (gap % i != 0) continue;
            int value = 1;
            while (gap % i == 0) {
                value *= i;
                gap /= i;
            }
            el2.add(value);
        }

        int e_cnt = el2.size();
        int upper_bound = 1;
        for (int i = 0; i < e_cnt - 1; i++) {
            upper_bound *= 2;
        }

        gap = LCM / GSD;

        for (int t = 0; t < upper_bound; t++) {
            int alpha = 1;
            for (int i = 0; i < el2.size(); i++) {
                if (((t >> i) & 1) == 1) {
                    alpha *= el2.get(i);
                }
            }

            int beta = gap / alpha;

            long tempA = (long) alpha * GSD;
            long tempB = (long) beta * GSD;

            if (ansSum > tempA + tempB) {
                ansSum = tempA + tempB;
                A = tempA;
                B = tempB;
            }
        }

        if (A > B) {
            System.out.println(B + " " + A);
        } else {
            System.out.println(A + " " + B);
        }
    }
}
