public class question2
{
    public static void main(String[] args)
    {
        StackInterface<Integer> num = new ArrayStack<>();

        num.push(111);
        num.push(222);
        num.push(333);
        num.push(444);

        num.display();
    }
}
