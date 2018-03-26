package ½øÖÆ×ª»»;
import java.math.BigInteger;
import java.util.Scanner;

public class main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()) {
			BigInteger num=sc.nextBigInteger();
			System.out.println(num.toString(2));
		}
	}
}
