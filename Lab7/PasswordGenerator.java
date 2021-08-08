/*
  File: PasswordGenerator.java
  Name: Yashasvi Palawat
  Email: Yashasvipalawat@my.smccd.edu
  Class :CIS 254 OL
  File Name: PasswordGenerator.java
  Description: This program random generate password with 10-20 unique characters 
                and print it.
  Assignment: Assignment Lab07
  Date: 04/21/2020

*/


import java.util.Random;
import java.util.Scanner;


public class PasswordGenerator {

  public static String getPassword(int numberOfChars) {
    if (numberOfChars > 0) {
      Random r = new Random();
      int nran;
      String password = "";

      for (int i = 0; i < numberOfChars; i++) {

        nran = r.nextInt(126 - 33) + 33;//rand 33 and 126

        char ch = (char) nran;//to char 

        if (password.indexOf(Character.toString(ch)) == -1) { //if char is in the string
          password += ch;

        } else {
          i--;//for decrease 
        }

      }

      return password;

    } else {

      return "";

    }
  }

  public static void main(String[] args) {
    int numberOfChars = 0;
    int exit;
    do {
      Scanner sc = new Scanner(System.in);

      System.out.println("Enter password length between 10-20 or -1 to quit: ");
      try {
        numberOfChars = sc.nextInt();

        if (numberOfChars >= 10 && numberOfChars <= 20) {         // if statment to print lablled output with random the generated password 
          System.out.println("The Password is :" + getPassword(numberOfChars));
        } else if (numberOfChars == -1) {
          System.out.println("Exit");
        } else {
          System.out.println("Enter a valid number");
        }
      } catch (Exception e) {
        System.out.println("Enter a valid number");
      }
        

    } while (numberOfChars != -1);

          System.out.printf("Programmed by Yashasvi Palawat\n");

  }

}
