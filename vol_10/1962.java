// 3496375	2013-12-27 14:13:14	 Accepted	1962	Java	83	1101	xxfflower
import java.math.BigInteger;
import java.util.Scanner;

public class zoj1962 {
	public static void main(String[] args) {
		
		BigInteger[] f = new BigInteger[500];
		
		f[0] = BigInteger.ONE;
		f[1] = BigInteger.ONE.add(BigInteger.ONE);
		
		for(int i=2;i<f.length;i++) {
			f[i] = f[i-1].add(f[i-2]);
		}
		
		Scanner in = new Scanner(System.in);
		while (in.hasNextBigInteger()) {
			BigInteger s = in.nextBigInteger();
			BigInteger l = in.nextBigInteger();
			
			if(s.equals(BigInteger.ZERO) && l.equals(BigInteger.ZERO)) return;
			
			int count = 0;
			for(BigInteger n:f) {
				if(n.compareTo(l) > 0) break;
				if(n.compareTo(s) >= 0) count++;
			}
			
			System.out.println(count);
		}
	}
}
