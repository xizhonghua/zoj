//3496659	2013-12-28 12:08:38	 Accepted	1073	Java	39	1101	xxfflower

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class zoj1073 {
	
	public static String Sort(String s) {
		char[] ar = s.toCharArray();
		Arrays.sort(ar);
		String sorted = String.valueOf(ar);
		return sorted;
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		while(s.hasNext()) {
			String str = s.next();
			int l = str.length();
			Boolean flag = true;
			BigInteger n = new BigInteger(str);
			String s1 = Sort(str);
			for(int i=2;i<=l;i++) {
				BigInteger t = n.multiply(BigInteger.valueOf(i));
				String s2 = t.toString();
				if(s2.length() > s1.length()) { flag = false; break; }
				while(s2.length() < s1.length()) s2 = "0" + s2;
				s2 = Sort(s2);
				if(!s2.equals(s1)) { flag = false; break; }
			}
			
			if(flag) System.out.println(str + " is cyclic");
			else System.out.println(str + " is not cyclic");
		}
	}
	
}
