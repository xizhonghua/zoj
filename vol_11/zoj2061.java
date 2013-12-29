//3497249	2013-12-30 07:26:24	 Accepted	2061	Java	30	1101	xxfflower

import java.math.BigInteger;
import java.util.Scanner;


public class zoj2061 {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = 0;
		while(true){
			int m = s.nextInt();
			int n = s.nextInt();
			if(m + n == 0) break;
			
			System.out.println("Test #" + (++t) + ":");
			
			if(m<n) System.out.println(0);
			else
			{
				BigInteger ans = BigInteger.ONE;
				for(int i=1;i<=m+n;i++)
					ans = ans.multiply(BigInteger.valueOf(i));
				ans = ans.multiply(BigInteger.valueOf(m-n+1));
				ans = ans.divide(BigInteger.valueOf(m+1));
				System.out.println(ans.toString());
			}
			
		}
	}

}
