import java.util.Scanner;

public class SimpleVirtualPetGame {
    private int hun;
    private int hap;
    private int ene;

    public SimpleVirtualPetGame(){
        this.hun = 50;
        this.hap = 50;
        this.ene = 50;
    }

    public void feed(){

        if(hun <= 0){
            clearConsole();
            ShowUI(hun, hap, ene, "The pet can not be fed as it is not hungry.");
        }
        else{
            hun -= 10;
            ene += 5;
            clearConsole();
            ShowUI(hun, hap, ene, "");
        }
    }

    public void play(){
        if(ene <= 10){
            clearConsole();
            ShowUI(hun, hap, ene, "The pet needs rest as it is too tired to play");
        }
        else{
            hap+=10;
            ene-=15;
            clearConsole();
            ShowUI(hun, hap, ene, "");
        }
    }

    public void rest(){
        ene+=20;
        hun+=5;
        clearConsole();
        ShowUI(hun, hap, ene, "");
    }

    public static void main(String[] args){
        char c = 'c';
        Scanner scan  = new Scanner(System.in);
        SimpleVirtualPetGame pet = new SimpleVirtualPetGame();

        while(c == 'c' || c == 'C') {
            clearConsole();
            ShowUI(pet.hun, pet.hap, pet.ene, "Welcome to Simple Virtual Pet Game");

            while(true){
                System.out.println();
                System.out.println("Enter your choice (1: Feed, 2: Play, 3: Rest, q: Quit): ");
                char inp = scan.next().charAt(0);

                switch (inp){
                    case '1':
                        pet.feed();
                        break;
                    case '2':
                        pet.play();
                        break;
                    case '3':
                        pet.rest();
                        break;
                    case 'q':
                    case 'Q':
                        clearConsole();
                        DisplayUI(pet.hun, pet.hap, pet.ene, "Thanks for playing!");
                        return;
                    default:
                        clearConsole();
                        ShowUI(pet.hun, pet.hap, pet.ene, "Invalid value entered. Try Again.");
                        break;
                }

                if(pet.hap <= 0){
                    clearConsole();
                    DisplayUI(pet.hun, pet.hap, pet.ene, "Your pet is too unhappy! Game over.");
                    break;
                }
                else if(pet.ene <= 0){
                    clearConsole();
                    DisplayUI(pet.hun, pet.hap, pet.ene, "Your pet has no energy left! Game over.");
                    break;
                }
                else if(pet.hap >= 100){  // Handle excessive happiness
                    clearConsole();
                    DisplayUI(pet.hun, pet.hap, pet.ene, "Your pet is overjoyed! Game over.");
                    break;
                }

            }

            System.out.println("Exit/Continue to give a next try (e/c) : ");
            c = scan.next().charAt(0);
            scan.nextLine();
            if(c == 'e' || c == 'E'){
                clearConsole();
                DisplayUI(pet.hun, pet.hap, pet.ene, "Thanks for playing!");
                return;
            } else if(c != 'c' && c != 'C'){
                clearConsole();
                DisplayUI(pet.hun, pet.hap, pet.ene, "Invalid Input. Exiting game.");
                return;
            }

            pet = new SimpleVirtualPetGame(); // Re-initialize pet stats for a new game round

        }
    }

    public static void DisplayUI(int hun, int hap, int ene, String mes) {
        System.out.println("==============================================");
        System.out.println("                                              ");
        System.out.println("            ...VIRTUAL PET GAME...            ");
        System.out.println("                                              ");
        System.out.println("==============================================");
        System.out.println();
        System.out.println("   "+mes);
        System.out.println("     Hunger     "+hun);
        System.out.println("     Happiness  "+hap);
        System.out.println("     Energy     "+ene);
        System.out.println();
        System.out.println("----------------------------------------------");
        System.out.println("-    Continue          |         Exit        -");
        System.out.println("-        c             |           e         -");
        System.out.println("----------------------------------------------");
        System.out.println("----------------------------------------------");
    }

    public static void ShowUI(int hun, int hap, int ene, String mes) {
        System.out.println("==============================================");
        System.out.println("                                              ");
        System.out.println("            ...VIRTUAL PET GAME...            ");
        System.out.println("                                              ");
        System.out.println("==============================================");
        System.out.println();
        System.out.println("   "+mes);
        System.out.println("     Hunger     "+hun);
        System.out.println("     Happiness  "+hap);
        System.out.println("     Energy     "+ene);
        System.out.println();
        System.out.println("----------------------------------------------");
        System.out.println("-     Feed     |     Play     |     Rest     -");
        System.out.println("-      1       |       2      |       3      -");
        System.out.println("----------------------------------------------");
        System.out.println("               Press q to Quit.               ");
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
