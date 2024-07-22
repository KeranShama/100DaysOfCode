import java.util.Scanner;

public class Main{
    public static Scanner scan = new Scanner(System.in);
    public static int row1=0, row2=0;
    public static int col1=0, col2=0;


    public static void main(String[] args){
        char c = 'c';

        while(c == 'c' || c == 'C') {

            clearConsole();
            showUI1();

            clearConsole();
            showUI2();

            if(col1 != row2){
                clearConsole();
                showUI3();
                continue;
            }

            int[][] matrix1 = new int[row1][col1];
            int[][] matrix2 = new int[row2][col2];

            clearConsole();
            System.out.println("Enter matrix 1 (row wise)");
            for(int i=0; i<row1; i++){
                for(int j=0; j<col1; j++){
                    matrix1[i][j]=scan.nextInt();
                }
            }

            clearConsole();
            System.out.println("Enter matrix 2 (row wise)");
            for(int i=0; i<row2; i++){
                for(int j=0; j<col2; j++){
                    matrix2[i][j]=scan.nextInt();
                }
            }

            int[][] matrix3 = new int[row1][col2];

            for(int i=0; i<row1; i++){
                for(int j=0; j<col2; j++){
                    int val = 0;
                    int a = 0;
                    while(a<col1){
                        val += matrix1[i][a] * matrix2[a][j];
                        a++;
                    }
                    matrix3[i][j] = val;
                }
            }

            clearConsole();
            showUI4(matrix1, matrix2, matrix3);

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

    public static void showUI1(){
        System.out.println("==============================================");
        System.out.println("---                                        ---");
        System.out.println("-                                            -");
        System.out.println("-           MATRIX MULTIPLICATION            -");
        System.out.println("-                                            -");
        System.out.println("---                                        ---");
        System.out.println("==============================================");
        System.out.println("First Matrix: ");
        System.out.println("Enter num of rows : ");
        row1 = scan.nextInt();
        System.out.println("Enter num of cols : ");
        col1 = scan.nextInt();
        System.out.println("==============================================");
        System.out.println("==============================================");
    }

    public static void showUI2(){
        System.out.println("==============================================");
        System.out.println("---                                        ---");
        System.out.println("-                                            -");
        System.out.println("-           MATRIX MULTIPLICATION            -");
        System.out.println("-                                            -");
        System.out.println("---                                        ---");
        System.out.println("==============================================");
        System.out.println("Second Matrix: ");
        System.out.println("Enter num of rows : ");
        row2 = scan.nextInt();
        System.out.println("Enter num of cols : ");
        col2 = scan.nextInt();
        System.out.println("==============================================");
        System.out.println("==============================================");
    }

    public static void showUI3(){
        System.out.println("==============================================");
        System.out.println("---                                        ---");
        System.out.println("-                                            -");
        System.out.println("-           MATRIX MULTIPLICATION            -");
        System.out.println("-                                            -");
        System.out.println("---                                        ---");
        System.out.println("==============================================");
        System.out.println("The matrices can't be multiplied");
        System.out.println("Press Enter to continue...");
        scan.nextLine();
        scan.nextLine();
        System.out.println("==============================================");
        System.out.println("==============================================");
    }

    public static void showUI4(int[][] matrix1, int[][] matrix2, int[][] matrix3){
        System.out.println("==============================================");
        System.out.println("---                                        ---");
        System.out.println("-                                            -");
        System.out.println("-           MATRIX MULTIPLICATION            -");
        System.out.println("-                                            -");
        System.out.println("---                                        ---");
        System.out.println("==============================================");
        System.out.println("Matrix 1");
        for(int i=0; i<row1; i++) {
            for (int j = 0; j < col1; j++) {
                System.out.print(matrix1[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("Matrix 2");
        for(int i=0; i<row2; i++) {
            for (int j = 0; j < col2; j++) {
                System.out.print(matrix2[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println("Product of the matrices ");
        for(int i=0; i<row1; i++) {
            for (int j = 0; j < col2; j++) {
                System.out.print(matrix3[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("==============================================");
        System.out.println("==============================================");
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
