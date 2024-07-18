import java.util.Scanner;

public class Main {

    public static  String str;
    public static Scanner scan = new Scanner(System.in);
    public static boolean ch;

    public static void main(String[] args){

        char c = 'c';

        while(c == 'c' || c == 'C'){

            clearConsole();
            displayUI();

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

    public static boolean checkPalindrome(String s){
        boolean c = true;

        s = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        int j = s.length()-1;

        for(int i=0; i<=j; i++){
            if(s.charAt(i) != s.charAt(j)){
                c = false;
                break;
            }
            j--;
        }
        return c;
    }

    public static void displayUI(){
        System.out.println("==============================================");
        System.out.println("---                                        ---");
        System.out.println("-                                            -");
        System.out.println("-            PALINDROME CHECKER              -");
        System.out.println("-                                            -");
        System.out.println("---                                        ---");
        System.out.println("==============================================");

        System.out.print("Enter the string : ");
        str = scan.nextLine();
        ch = checkPalindrome(str);
        if (ch){
            System.out.println(str+" is a Palindrome");
        }
        else{
            System.out.println(str+" is not a Palindrome");
        }

        System.out.println("----------------------------------------------");
        System.out.println("-        EXIT         |       CONTINUE       -");
        System.out.println("-          e          |           c          -");
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
