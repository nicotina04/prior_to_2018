public class question1
{
    public static void main(String[] args)
    {
        String infix = "1 + ( 200 + 90 / 5 ) * 9";
        String infix2 = "( 1 + 2 ) * 90 / 2 + ( 9 - 4 )";
        infix = Postfix.convertToPostfix(infix);
        System.out.println(Infix.evaluateInfix(infix2));
        System.out.println(infix);
        double res = Postfix.evaluatePostfix(infix);
        System.out.println(res);
        System.out.println(1 + (200 + 90 / 5) * 9);
    }
}
