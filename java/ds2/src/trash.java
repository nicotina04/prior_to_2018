public class trash
{
    public static void method1(int array[], int n)
    {
        for(int index = 0; index < n - 1; index++)
        {
            int mark = privateMethod1(array, index, n - 1);
            int temp = array[index];
            array[index] = array[mark];
            array[mark] = temp;
        }
    }

    public static int privateMethod1(int[] ar, int first, int last)
    {
        int max = ar[first];
        int indexOfMax = first;
        for(int idx = last; idx > first; idx--)
        {
            if(ar[idx] > max)
            {
                max = ar[idx];
                indexOfMax = idx;
            }
        }
        return indexOfMax;
    }

    public static boolean method2(int[] ar, int n, int key)
    {
        int indexOfKey = -1;
        for(int idx = 1; idx <= n - 1; ++idx)
        {
            if(ar[idx] == key)
            {
                indexOfKey = idx;
            }
        }
        if(indexOfKey >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public static void main(String[] args)
    {
        int a[] = {1,2,3,4,5,6,7,8,9};
        System.out.println(a.length);
        method1(a, a.length);
        for(int i = 0; i < a.length; ++i)
        {
            System.out.print(a[i]);
        }
    }
}
