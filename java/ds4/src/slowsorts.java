public class slowsorts
{
    public static <T extends Comparable<? super T>> void selection(T[] ar, int n)
    {
        for(int index = 0; index < n; index++)
        {
            int indexOfnextSmallest = getIndexOfSmallest(ar, index, n - 1);
            swap(ar, index, indexOfnextSmallest);
        }
    }
    private static void swap(Object[] a, int i, int j)
    {
        Object temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private static<T extends Comparable<? super T>> int getIndexOfSmallest(T[] ar, int first, int last)
    {
        T min = ar[first];
        int indexOfMin = first;
        for(int index = first + 1; index <= last; ++index)
        {
            if(ar[index].compareTo(min) < 0)
            {
                min = ar[index];
                indexOfMin = index;
            }
        }
        return indexOfMin;
    }

    public static <T extends Comparable<? super T>> void insertion(T[] ar)
    {
        for(int idx = 1; idx < ar.length; ++idx)
        {
            int tidx = idx;
            T temp = ar[idx];
            while(tidx > 0 && temp.compareTo(ar[tidx - 1]) < 0)
            {
                ar[tidx] = ar[tidx - 1];
                --tidx;
            }
            ar[tidx] = temp;
        }
    }

    public static <T extends Comparable<? super T>> void shell(T[] ar)
    {
        int gap = ar.length / 2;
        //int gap = 7;
        if(gap % 2 == 0) {++gap;} //gap은 홀수로 놓는 것이 빠르다는 연구 결과가 있다.
        while(gap > 0)
        {
            for(int idx = gap; idx < ar.length; idx += gap)
            {
                int tidx = idx;
                T temp = ar[idx];
                while(tidx > 0 && temp.compareTo(ar[tidx - gap]) < 0)
                {
                    ar[tidx] = ar[tidx - gap];
                    tidx -= gap;
                }
                ar[tidx] = temp;
            }
            gap /= 2;
        }
    }
}
