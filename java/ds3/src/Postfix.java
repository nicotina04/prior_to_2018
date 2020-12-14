public class Postfix
{

    public static int compare(String attack, String target)
    {
        if((attack.equals("+") || attack.equals("-")) && (target.equals("+") || target.equals("-")))
        {
            return 0;
        }
        else if((attack.equals("*") || attack.equals("/")) && (target.equals("*") || target.equals("/")))
        {
            return 0;
        }
        else if((attack.equals("*") || attack.equals("/")) && (target.equals("+") || target.equals("-")))
        {
            return 1;
        }
        else if(target.equals("("))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    public static int postwitch(String fix)
    {
        switch (fix)
        {
            case "^":
                return 1;
            case "+":
            case "-":
            case "*":
            case "/":
                return 2;
            case "(":
                return 3;
            case ")":
                return 4;
            default:
                return 0;
        }
    }

    public static int evalwitch(String fix)
    {
        switch (fix)
        {
            case "^":
                return 1;
            case "+":
                return 2;
            case "-":
                return 3;
            case "*":
                return 4;
            case "/":
                return 5;
                default: return 0;
        }
    }

    public static String convertToPostfix(String numeric)
    {
        StackInterface<String> opstack = new ArrayStack<String>();
        StringBuilder postfix = new StringBuilder("");

        String parsed[] = numeric.split(" ");
//        for(int k = 0; k < parsed.length; ++k)
//        {
//            System.out.print(parsed[k]);
//        }
//        System.out.println();
        for(int i = 0; i < parsed.length; ++i)
        {
//            opstack.display();
//            System.out.println();
            //System.out.println(parsed[i]);
            switch (postwitch(parsed[i]))
            {
                case 0:
                    postfix.append(parsed[i]);
                    postfix.append(" ");
                    break;
                case 1:
                    opstack.push(parsed[i]);
                    break;
                case 2:
                    while(!opstack.isEmpty() && compare(parsed[i], opstack.peek()) <= 0)
                    {
                        postfix.append(opstack.pop());
                        postfix.append(" ");
                    }
                    opstack.push(parsed[i]);
                    break;
                case 3:
                    opstack.push(parsed[i]);
                    break;
                case 4:
                    String top = opstack.pop();
//                    System.out.println(postfix);
                    while(!top.equals("("))
                    {
                        postfix.append(top);
                        postfix.append(" ");
                        top = opstack.pop();
                    }
                    break;
                    default: break;
            }
        }
        while(!opstack.isEmpty())
        {
            postfix.append(opstack.pop());
            postfix.append(" ");
        }

        return String.valueOf(postfix);
    }

    public static double evaluatePostfix(String postform)
    {
        StackInterface<Double> valstack = new ArrayStack<>();
        String parsed[] = postform.split(" ");

        for(int j = 0; j < parsed.length; ++j)
        {
            double right;
            double left;
            double result;

            switch (evalwitch(parsed[j]))
            {
                case 0:
                valstack.push(Double.parseDouble(parsed[j]));
                break;
                case 1:
                    result = 1;
                    right = valstack.pop();
                    left = valstack.pop();
                    for(int i = 0; i < (int)right; ++i)
                    {
                        result *= left;
                    }
                    valstack.push(result);
                    break;
                case 2:
                    result = valstack.pop() + valstack.pop();
                    valstack.push(result);
                break;
                case 3:
                    right = valstack.pop();
                    left = valstack.pop();
                    result = left - right;
                    valstack.push(result);
                    break;
                case 4:
                    result = valstack.pop() * valstack.pop();
                    valstack.push(result);
                    break;
                case 5:
                    right = valstack.pop();
                    left = valstack.pop();
                    result = left / right;
                    valstack.push(result);
                    break;
                default: break;
            }
        }

        return valstack.peek();
    }
}
