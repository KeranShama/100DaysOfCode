import java.util.Random;
import java.util.Scanner;

public class TypingSpeedTest {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        Random rand = new Random();
        char ch = 'c';

        while (ch == 'c' || ch == 'C'){

            clearConsole();
            ShowUI();

            String[] easySentences = {
                    "The quick brown fox jumps over the lazy dog.",
                    "Hello world!",
                    "Java is fun."
            };
            String[] mediumSentences = {
                    "Learning to code is a valuable skill.",
                    "Consistency is the key to mastering any skill.",
                    "Practice makes perfect."
            };
            String[] hardSentences = {
                    "Learning to code is a valuable skill in today's technology-driven world, opening doors to endless possibilities and opportunities.",
                    "Success is not the key to happiness. Happiness is the key to success.",
                    "Consistency is the key to mastering any skill, including typing."
            };

            int num;
            String sen;
            num = scan.nextInt();
            scan.nextLine();

            switch (num) {
                case 1:
                    sen = easySentences[rand.nextInt(easySentences.length)];
                    break;
                case 2:
                    sen = mediumSentences[rand.nextInt(mediumSentences.length)];
                    break;
                case 3:
                    sen = hardSentences[rand.nextInt(hardSentences.length)];
                    break;
                case 4:
                    System.out.print("Enter your custom sentence: ");
                    sen = scan.nextLine();
                    break;
                default:
                    System.out.println("Invalid choice, defaulting to Easy level.");
                    sen = easySentences[rand.nextInt(easySentences.length)];
            }

            clearConsole();

            System.out.println("Enter the following sentence as fast and accurate as you can : ");
            System.out.println();
            System.out.println(sen);

            long stime = System.currentTimeMillis();
            String input = scan.nextLine();
            long etime = System.currentTimeMillis();

            int c = 0;
            int len = Math.min(input.length(), sen.length());
            for (int i = 0; i < len; i++) {
                if (input.charAt(i) == sen.charAt(i)) {
                    c++;
                }
            }
            double acc = ((double) c / sen.length()) * 100;

            double time = (etime - stime) / 1000.0;
            int wordCount = input.split("\\s+").length;
            double speed = (wordCount / time) * 60;

            clearConsole();
            DisplayUI(time, speed, acc);

            System.out.println();
            System.out.println("Exit/Continue (e/m) : ");
            ch = scan.next().charAt(0);
            scan.nextLine();
            if(ch == 'e' || ch == 'E'){
                return;
            }
            if(ch != 'e' && ch != 'E' && ch != 'c' && ch != 'C'){
                System.out.println("Invalid Input");
                return;
            }
        }


    }

    public static void ShowUI(){
        System.out.println("==============================================");
        System.out.println("                                              ");
        System.out.println("           ...Typing Speed Test...            ");
        System.out.println("                                              ");
        System.out.println("==============================================");
        System.out.println();
        System.out.println(" Choose the difficulty level you want to try : ");
        System.out.println();
        System.out.println("----------------------------------------------");
        System.out.println("-         Easy        |       Medium         -");
        System.out.println("-          1          |         2            -");
        System.out.println("----------------------------------------------");
        System.out.println("-         Hard        |       Custom         -");
        System.out.println("-          3          |         4            -");
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");

    }

    public static void DisplayUI(double time, double speed, double acc){
        System.out.println("==============================================");
        System.out.println("                                              ");
        System.out.println("           ...Typing Speed Test...            ");
        System.out.println("                                              ");
        System.out.println("==============================================");
        System.out.println();
        System.out.printf("       Time taken: %.2f seconds\n", time);
        System.out.printf("       Typing Speed: %.2f words per minute\n", speed);
        System.out.printf("       Accuracy: %.2f %%\n", acc);
        System.out.println();
        System.out.println("----------------------------------------------");
        System.out.println("-    Continue          |         Exit        -");
        System.out.println("-        c             |           e         -");
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");

    }
    public static void clearConsole() {
        try {
            final String os = System.getProperty("os.name");

            if (os.contains("Windows")) {
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
