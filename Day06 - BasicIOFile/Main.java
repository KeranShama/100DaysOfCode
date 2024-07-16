import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        File file = new File("doc1.txt");
        if (file.exists()) {
            System.out.println("\nFile exists!");

            try {
                FileReader reader = new FileReader("doc1.txt");
                FileWriter writer = new FileWriter("doc2.txt");

                int wordCount = 0;
                int data;
                boolean inWord = false;

                while ((data = reader.read()) != -1) {
                    char character = (char) data;
                    writer.write(character);

                    if (Character.isWhitespace(character)) {
                        if (inWord) {
                            wordCount++;
                            inWord = false; // Reset flag since word ended
                        }
                    } else {
                        inWord = true; // Set flag indicating we're in a word
                    }
                }

                // Check for last word if file doesn't end with whitespace
                if (inWord) {
                    wordCount++;
                }

                System.out.println("File copied to doc2.txt");
                System.out.println("Total words in doc1.txt: " + wordCount);

                reader.close();
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("File does not exist!");
        }
    }
}
