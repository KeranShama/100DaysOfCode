import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        ArrayList<String> str = new ArrayList<>(); //Dynamic array
        String s = "";
        char c;
        int n;

        clearConsole();
        ShowList();

        Scanner scan = new Scanner(System.in);

        System.out.println("Enter the first task : ");
        s = scan.nextLine();
        str.add(s);
        clearConsole();
        DisplayList(str);

        while(true){
            System.out.println("Enter the action (a,r,e,q): ");
            c = scan.next().charAt(0);

            switch (c){
                case 'a':
                case 'A':
                    System.out.println("Enter task : ");
                    scan.nextLine();
                    s = scan.nextLine();
                    str.add(s);
                    break;
                case 'r':
                case 'R':
                    System.out.println("Enter the task number to remove : ");
                    n = scan.nextInt();
                    str.remove(n-1);
                    break;
                case 'e':
                case 'E':
                    System.out.println("Enter the task number to edit : ");
                    n = scan.nextInt();
                    System.out.println("Enter the task to be changed : ");
                    scan.nextLine();
                    s = scan.nextLine();
                    str.set(n-1,s);
                    break;
                case 'l':
                case 'L':
                    str.clear();
                    break;
                case 'q':
                case 'Q':
                    return;
                default:
                    System.out.println("Invalid character. Try Again");
                    continue;
            }
            clearConsole();
            DisplayList(str);
        }
    }
    public static void ShowList() {
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
        System.out.println("---               TO DO LIST               ---");
        System.out.println("----------------------------------------------");
        System.out.println();
        System.out.println("  EMPTY LIST ");
        System.out.println();
        System.out.println("----------------------------------------------");
        System.out.println("-     Add Task         |   Remove one / all  -");
        System.out.println("-        a             |          r/ l       -");
        System.out.println("----------------------------------------------");
        System.out.println("-    Edit Task         |         Exit        -");
        System.out.println("-        e             |           q         -");
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
    }
    public static void DisplayList(ArrayList<String> str) {
        int c=1;
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
        System.out.println("---               TO DO LIST               ---");
        System.out.println("----------------------------------------------");
        System.out.println();
        for (String s : str) {
            System.out.println("  " + c +". "+ s);
            c++;
        }
        System.out.println();
        System.out.println("----------------------------------------------");
        System.out.println("-     Add Task         |   Remove one / all  -");
        System.out.println("-        a             |          r/ l       -");
        System.out.println("----------------------------------------------");
        System.out.println("-    Edit Task         |         Exit        -");
        System.out.println("-        e             |           q         -");
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
