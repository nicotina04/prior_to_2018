public class Main
{

    public static void main(String[] args)
    {
        QueueInterface<Integer> test = new CLqueue<>();
        test.addBack(100);
        test.addBack(200);
        test.addBack(300);
        test.addBack(400);
        test.addBack(700);
        test.addBack(900);
        while(!test.isEmpty())
        {
            System.out.println(test.size());
            System.out.println(test.removeFront());
        }

    }
}
