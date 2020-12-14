public class Infix
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

    public static double evaluateInfix(String inform)
    {
        StackInterface<String> opstack = new ArrayStack<>();
        StackInterface<Double> valstack = new ArrayStack<>();

        String parsed[] = inform.split(" ");
        for(int i = 0; i < parsed.length; ++i)
        {
            double right;
            double left;
            double result;
            switch(postwitch(parsed[i]))
            {
                case 0:
                    valstack.push(Double.parseDouble(parsed[i]));
                    break;
                case 1:
                    opstack.push(parsed[i]);
                    break;
                case 2:
                    while(!opstack.isEmpty() && compare(parsed[i], opstack.peek()) <= 0)
                    {
                        String operator = opstack.pop();
                        right = valstack.pop();
                        left = valstack.pop();
                        if(operator.equals("+"))
                        {
                            result = left + right;
                        }
                        else if(operator.equals("-"))
                        {
                            result = left - right;
                        }
                        else if(operator.equals("*"))
                        {
                            result = left * right;
                        }
                        else if(operator.equals("/"))
                        {
                            result = left / right;
                        }
                        else
                        {
                            result = 1;
                            for(int j = 0; j < right; ++j)
                            {
                                result *= left;
                            }
                        }
                        valstack.push(result);
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
                        right = valstack.pop();
                        left = valstack.pop();
                        if(top.equals("+"))
                        {
                            result = left + right;
                        }
                        else if(top.equals("-"))
                        {
                            result = left - right;
                        }
                        else if(top.equals("*"))
                        {
                            result = left * right;
                        }
                        else if(top.equals("/"))
                        {
                            result = left / right;
                        }
                        else
                        {
                            result = 1;
                            for(int j = 0; j < right; ++j)
                            {
                                result *= left;
                            }
                        }
                        valstack.push(result);
                        top = opstack.pop();
                    }
                    break;
                default: break;
            }
        }
        while(!opstack.isEmpty())
        {
            double finr;
            double finl;
            double last;
            String ltop = opstack.pop();
//                    System.out.println(postfix);
                finr = valstack.pop();
                finl = valstack.pop();
                if(ltop.equals("+"))
                {
                    last = finl + finr;
                }
                else if(ltop.equals("-"))
                {
                    last = finl - finr;
                }
                else if(ltop.equals("*"))
                {
                    last = finl * finr;
                }
                else if(ltop.equals("/"))
                {
                    last = finl / finr;
                }
                else
                {
                    last = 1;
                    for(int j = 0; j < finr; ++j)
                    {
                        last *= finl;
                    }
                }
                valstack.push(last);
        }

        return valstack.peek();
    }
}
