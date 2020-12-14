import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

import java.util.*;
public class question3
{

    public static<T extends Comparable<? super T>> void stacksort(StackInterface<T> un, StackInterface<T> std, StackInterface<T> tmp)
    {
        if(un.isEmpty() && tmp.isEmpty()) {return;}

        //Move the top entry of S1 to S2.
        std.push(un.pop());

        T seed = std.pop();

        while(!un.isEmpty())
        {
            T comp = un.pop();

            if(seed.compareTo(comp) > 0)
            {
                tmp.push(seed);
                seed = comp;
            }
            else
            {
                tmp.push(comp);
            }
        }
        std.push(seed);

        StackInterface<T> temp = tmp;
        tmp = un;
        un = temp;

        stacksort(un, std, tmp);
    }

    public static void main(String[] args)
    {
        StackInterface<Integer> S1 = new ArrayStack<>();
        StackInterface<Integer> S2 = new ArrayStack<>();
        StackInterface<Integer> S3 = new ArrayStack<>();

        S1.push(100);
        S1.push(-20);
        S1.push(-10);
        S1.push(0);
        S1.push(13);
        S1.push(880);
        S1.push(1);
        S1.push(2);
        S1.push(77);
        S1.push(44);

        stacksort(S1, S2, S3);
        S2.display();

        S1.clear();
        S2.clear();
        S3.clear();

    }

}
