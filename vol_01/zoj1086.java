//3496834	2013-12-29 01:06:43	 Accepted	1086	Java	16	440	xxfflower
import java.util.Scanner;
import java.math.*;


public class zoj1086 {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		while(s.hasNext()) {
			String o = s.next();
			BigDecimal ans = BigDecimal.ZERO;
			BigDecimal one_eighth = BigDecimal.valueOf(1.0/8);
			BigDecimal factor = one_eighth;
			for(int i=2;i<o.length();i++) {
				BigDecimal t = BigDecimal.valueOf((o.charAt(i)-'0'));
				ans = ans.add(t.multiply(factor));
				factor = factor.multiply(one_eighth);
			}
			System.out.println(o + " [8] = " + ans.toPlainString() + " [10]");
		}
	}

}
