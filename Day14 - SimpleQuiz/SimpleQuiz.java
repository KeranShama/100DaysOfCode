import java.util.Scanner;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.UnsupportedAudioFileException;
import java.io.File;
import java.io.IOException;

public class SimpleQuiz {
    public static void main(String[] args){
        char ch = 'c';
        Scanner scan = new Scanner(System.in);

        while (ch == 'c' || ch == 'C'){
            clearConsole();
            String[] questions = {
                    "1. What is the primary purpose of the `cv2.VideoCapture` class in OpenCV?",
                    "2. What does the `cap.isOpened()` method check?",
                    "3. What does the `cv2.imshow('Frame', frame)` function do?",
                    "4. What is the purpose of the `cv2.waitKey(40)` function in the loop?",
                    "5. What will happen when the `ord('q')` key is pressed during the video playback?"
            };
            String[][] options = {
                    {" A. To capture images from the screen", " B. To read video files or capture video from a camera", " C. To edit video files", " D. To play audio files"},
                    {" A. If the video file is in the correct format", " B. If the video file was successfully opened", " C. If the video file has reached the end", " D. If the video file can be edited"},
                    {" A. It saves the current frame to a file", " B. It displays the current frame in a window", " C. It converts the frame to grayscale", " D. It closes the video file"},
                    {" A. To wait for 40 milliseconds", " B. To check if a key is pressed within 40 milliseconds", " C. To control the playback speed of the video", " D. All of the above"},
                    {" A. The video will pause", " B. The video will stop and exit the loop", " C. The video will fast forward", " D. The video will rewind"}
            };
            char[] answers = {'B', 'B', 'B', 'D', 'B'};
            int c = 0;
            long totalTime = 0;
            for(int i=0; i<questions.length; i++){

                System.out.println();
                System.out.println(questions[i]);

                for(int j=0; j<options[i].length; j++){
                    System.out.println(options[i][j]);
                }

                System.out.println();
                System.out.print("Enter your answer : ");

                long stime = System.currentTimeMillis();
                char ans = scan.next().charAt(0);
                long ftime = System.currentTimeMillis();
                totalTime += (ftime-stime);

                ans = Character.toUpperCase(ans);

                if(ans == answers[i]){
                    c++;
                    System.out.println("Correct!");
                    playSound("src/main/resources/correct.wav");
                }
                else{
                    System.out.println("Incorrect!");
                    playSound("src/main/resources/incorrect.wav");
                }
            }
            System.out.println();
            System.out.println("Total Score : "+c+"/5");
            System.out.println("Total time taken is "+totalTime+" milliseconds");

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

    private static void playSound(String soundFileName) {
        try {
            File soundFile = new File(soundFileName);
            AudioInputStream audioStream = AudioSystem.getAudioInputStream(soundFile);
            Clip clip = AudioSystem.getClip();
            clip.open(audioStream);
            clip.start();
        } catch (UnsupportedAudioFileException e) {
            System.out.println("Unsupported audio file format: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("Error reading the audio file: " + e.getMessage());
        } catch (Exception e) {
            e.printStackTrace();
        }
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
