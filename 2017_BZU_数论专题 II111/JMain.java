import java.math.BigInteger;
import java.util.Scanner;


public class JMain {
	public static void main(String[] args)  
    {  
		Scanner input = new Scanner(System.in);  
        int n = input.nextInt();  
        int i=1;
        while (n-- > 0)  
        {
        	BigInteger a = new BigInteger("0");
        	BigInteger b = new BigInteger("0");
        	BigInteger c = new BigInteger("0");
        	a=input.nextBigInteger();
        	b=input.nextBigInteger();
        	if(c.equals(a.remainder(b)))
        	{
        		System.out.printf("Case %d: divisible\n",i);
        	}
        	else
        	{
        		System.out.printf("Case %d: not divisible\n",i);
        	}
        	i++;
        }
        input.close();  
    }  

}