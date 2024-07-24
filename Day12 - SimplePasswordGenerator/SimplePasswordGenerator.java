import java.util.Random;
import java.util.Scanner;

public class SimplePasswordGenerator {
    public static void main(String[]  args){
        Scanner scan = new Scanner(System.in);
        char c = 'c';

        String upper = "QWERTYUIOPASDFGHJKLZXCVBNM";
        String lower = "qwertyuiopasdfghjklzxcvbnm";
        String num = "1234567890";
        String specialChar = "!@#$%^&*()`~<>,.?/-_=+{}[]";

        while(c == 'c' || c == 'C'){
            clearConsole();
            ShowUI();

            StringBuilder comb = new StringBuilder();
            //represents a complete set of characters that can be used to generate passwords

            System.out.println("Include uppercase letters? (y/anyother): ");
            char ch = scan.next().charAt(0);
            boolean inUpper = ch == 'y' || ch == 'Y';
            if(inUpper){
                comb.append(upper);
            }

            System.out.println("Include lowercase letters? (y/anyother): ");
            ch = scan.next().charAt(0);
            boolean inLower = ch == 'y' || ch == 'Y';
            if (inLower) {
                comb.append(lower);
            }

            System.out.println("Include numbers? (y/anyother): ");
            ch = scan.next().charAt(0);
            boolean inNum = ch == 'y' || ch == 'Y';
            if (inNum) {
                comb.append(num);
            }

            System.out.println("Include special characters? (y/anyother): ");
            ch = scan.next().charAt(0);
            boolean inSpecial = ch == 'y' || ch == 'Y';
            if (inSpecial) {
                comb.append(specialChar);
            }

            System.out.println("Enter the length of the password : ");
            int length = scan.nextInt();

            if (comb.length() == 0) {

                clearConsole();
                DisplayUI(new StringBuilder("\nError : No character sets selected."));

                System.out.println("Exit/Continue (e/m) : ");
                c = scan.next().charAt(0);
                scan.nextLine();
                if(c == 'e' || c == 'E'){
                    return;
                }
                if(c != 'e' && c != 'E' && c != 'c' && c != 'C'){
                    System.out.println("Invalid Input");
                    return;
                }
                else{
                    continue;
                }
            }

            if(length<1){

                clearConsole();
                DisplayUI(new StringBuilder("\nError : Invalid Input"));

                System.out.println("Exit/Continue (e/m) : ");
                c = scan.next().charAt(0);
                scan.nextLine();
                if(c == 'e' || c == 'E'){
                    return;
                }
                if(c != 'e' && c != 'E' && c != 'c' && c != 'C'){
                    System.out.println("Invalid Input");
                    return;
                }
                else{
                    continue;
                }
            }
            if(length<4){

                clearConsole();
                DisplayUI(new StringBuilder("\nError : Password must includes atleast 4 characters"));

                System.out.println("Exit/Continue (e/m) : ");
                c = scan.next().charAt(0);
                scan.nextLine();
                if(c == 'e' || c == 'E'){
                    return;
                }
                if(c != 'e' && c != 'E' && c != 'c' && c != 'C'){
                    System.out.println("Invalid Input");
                    return;
                }
                else {
                    continue;
                }
            }

            StringBuilder password = new StringBuilder(length);
            Random  rand = new Random();
            int k = 0;

            //Enure the password contains atleast one character from each category
            if(inUpper){
                password.append(upper.charAt(rand.nextInt(upper.length())));
                k++;
            }
            if(inLower){
                password.append(lower.charAt(rand.nextInt(lower.length())));
                k++;
            }
            if(inNum){
                password.append(num.charAt(rand.nextInt(num.length())));
                k++;
            }
            if(inSpecial){
                password.append(specialChar.charAt(rand.nextInt(specialChar.length())));
                k++;
            }

            for(int i=k; i<length; i++){
                int index = rand.nextInt(comb.length());
                password.append(comb.charAt(index));
            }

            clearConsole();
            DisplayUI(password);

            System.out.println("Exit/Continue (e/m) : ");
            c = scan.next().charAt(0);
            scan.nextLine();
            if(c == 'e' || c == 'E'){
                return;
            }
            if(c != 'e' && c != 'E' && c != 'c' && c != 'C'){
                System.out.println("Invalid Input");
                return;
            }
        }


    }

    public static void ShowUI() {
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
        System.out.println("---           PASSWORD GENERATOR           ---");
        System.out.println("----------------------------------------------");
        System.out.println();
        System.out.println("  ANSWER ALL QUESTIONS ");
        System.out.println();
        System.out.println("----------------------------------------------");
        System.out.println("-    Continue          |         Exit        -");
        System.out.println("-        c             |           e         -");
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
    }
    public static void DisplayUI(StringBuilder p) {
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
        System.out.println("---           PASSWORD GENERATOR           ---");
        System.out.println("----------------------------------------------");
        System.out.println();
        System.out.println("Generated Password : "+p.toString());
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
