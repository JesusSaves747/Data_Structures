
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.List;

public class test_array_list{

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    String edgeStr = sc.next();

    List<String> edges = Arrays.asList(edgeStr.split(","));



    for (String number : edges) {
      int dest = Integer.parseInt(number);

   System.out.println("Number = " + dest);
   }


  }

};
