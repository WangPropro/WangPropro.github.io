import java.util.Scanner;
public class Study 
{
    public static void main(String args[]) 
    {
        Scanner scanner = new Scanner(System.in);
        String sc = scanner.nextLine();
        String[] strings = sc.split(" ");
        int sum = 0;
        boolean f = false;
        for (int i = 0; i < strings.length; i++) 
        {
            if (strings[i].charAt(0) == '-') 
            {
                sum += Integer.parseInt(strings[i]);
            } 
            else if (strings[i].charAt(0) >= '0' && strings[i].charAt(0) <= '9') 
            {
                try {
                    sum += Integer.parseInt(strings[i]);
                } catch (Exception a) {
                    f = true;
                    continue;
                }
            } 
            else 
            {
                f = true;
            }
        }
        System.out.println(sum);
        if (f) 
        {
            System.out.println("attention");
        }
    }
}