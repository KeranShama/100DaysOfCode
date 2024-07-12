import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        char button = '\n';
        while (button == 'P' || button == 'p' || button == '\n') {
            clearConsole();
            displayBefGame();

            Scanner scan = new Scanner(System.in);

            System.out.println("Enter the range of the number - (a:b) ");
            System.out.print("Enter a : ");
            int a = scan.nextInt();
            System.out.print("Enter b : ");
            int b = scan.nextInt();

            Random rand = new Random();
            int num = rand.nextInt(a, b + 1);

            int c = 1;
            String str = "";

            while (c <= 10) {

                System.out.println();

                System.out.print("Enter the guessed number : ");
                int guess = scan.nextInt();

                if (guess == num) {
                    //System.out.println("Wow! You guessed correctly!");
                    str = "Wow! You guessed correctly!";
                    break;
                } else if (guess < num) {
                    //System.out.println("Your guess is too low. Try a higher number");
                    str = "Your guess is too low. Try higher";
                } else {
                    //System.out.println("Your guess is too high. Try a higher number");
                    str = "Your guess is too high. Try lower";
                }
                clearConsole();
                displayAtGame(guess, str, c);
                c += 1;
            }

            if (c > 10) {
                str = "Reached max tries";
                clearConsole();
                displayAftGame(num, str, c - 1);
            } else {
                System.out.println("");
                //System.out.println("Tries : "+c);
                clearConsole();
                displayAftGame(num, str, c);
            }

            System.out.println("Exit/Play Again : ");
            button = scan.next().charAt(0);

            if (button == 'e' || button == 'E') {
                return;
            }
            else if (button != 'p' && button != 'P') {
                System.out.println("Invalid Input");
                return;
            }
        }

    }


    public static void displayBefGame() {
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
        System.out.println("---            WELCOME TO NUMBER           ---");
        System.out.println("---              GUESSING GAME             ---");
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
        System.out.println("- Max Tries    |  Your Tries   |     Exit    -");
        System.out.println("-    10        |      0        |      e      -");
        System.out.println("----------------------------------------------");
    }

    public static void displayAtGame(int guess, String str, int c) {
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
        System.out.println("- OUTPUT | " + guess);
        System.out.println("-        | " + str);
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
        System.out.println("- Max Tries    |  Your Tries   |     Exit    -");
        System.out.println("-    10        |     " + c + "         |      e      -");
        System.out.println("----------------------------------------------");
    }

    public static void displayAftGame(int guess, String str, int c) {
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
        System.out.println(" OUTPUT | " + guess);
        System.out.println("        | " + str);
        System.out.println(" Tries  | " + c);
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
        System.out.println("--   Play Again         |         Exit      --");
        System.out.println("--       p              |           e       --");
        System.out.println("----------------------------------------------");
    }

    public static void clearConsole() {
        try {
            final String os = System.getProperty("os.name");

            if (os.contains("Windows")) {
                // Clear screen with new lines (fallback for Windows)
                for (int i = 0; i < 50; ++i) System.out.println();
            } else {
                // Clear screen with ANSI escape codes
                System.out.print("\033[H\033[2J");
                System.out.flush();
            }
        } catch (final Exception e) {
            System.out.println("Error clearing console: " + e.getMessage());
        }
    }
}
