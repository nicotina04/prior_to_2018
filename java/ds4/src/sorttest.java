import java.util.*;
public class sorttest
{
    public static void main(String[] args)
    {
        Random random = new Random();

        Integer[] hund = new Integer[100];
        Integer[] thou = new Integer[1000];
        Integer[] tthou = new Integer[10000];
        Integer[] hunthou = new Integer[100000];

        for(int i = 0; i < 100; ++i)
        {
            hund[i] = random.nextInt(1000);
        }
        for(int i = 0; i < 1000; ++i)
        {
            thou[i] = random.nextInt(1000);
        }
        for(int i = 0; i < 10000; ++i)
        {
            tthou[i] = random.nextInt(1000);
        }
        for(int i = 0; i < 100000; ++i)
        {
            hunthou[i] = random.nextInt(1000);
        }

        Integer[] temphun = new Integer[100];
        Integer[] tempthou = new Integer[1000];
        Integer[] temptthou = new Integer[10000];
        Integer[] temphundthou = new Integer[100000];

        System.arraycopy(hund, 0, temphun, 0, 100);
        System.arraycopy(thou, 0, tempthou, 0, 1000);
        System.arraycopy(tthou, 0, temptthou, 0, 10000);
        System.arraycopy(hunthou, 0, temphundthou, 0, 100000);

        long startTime = System.currentTimeMillis();
        slowsorts.selection(temphun, temphun.length);
        long endTime = System.currentTimeMillis();
        System.out.println("100 elements sorted by selection : " + (endTime - startTime));

        startTime = System.currentTimeMillis();
        slowsorts.selection(tempthou, tempthou.length);
        endTime = System.currentTimeMillis();
        System.out.println("1000 elements sorted by selection : " + (endTime - startTime));

        startTime = System.currentTimeMillis();
        slowsorts.selection(temptthou, temptthou.length);
        endTime = System.currentTimeMillis();
        System.out.println("10000 elements sorted by selection : " + (endTime - startTime));

        startTime = System.currentTimeMillis();
        slowsorts.selection(temphundthou, temphundthou.length);
        endTime = System.currentTimeMillis();
        System.out.println("100000 elements sorted by selection : " + (endTime - startTime));

        System.arraycopy(hund, 0, temphun, 0, 100);
        System.arraycopy(thou, 0, tempthou, 0, 1000);
        System.arraycopy(tthou, 0, temptthou, 0, 10000);
        System.arraycopy(hunthou, 0, temphundthou, 0, 100000);

        startTime = System.currentTimeMillis();
        slowsorts.insertion(temphun);
        endTime = System.currentTimeMillis();
        System.out.println("100 elements sorted by insertion : " + (endTime - startTime));

        startTime = System.currentTimeMillis();
        slowsorts.insertion(tempthou);
        endTime = System.currentTimeMillis();
        System.out.println("1000 elements sorted by insertion : " + (endTime - startTime));

        startTime = System.currentTimeMillis();
        slowsorts.insertion(temptthou);
        endTime = System.currentTimeMillis();
        System.out.println("10000 elements sorted by insertion : " + (endTime - startTime));

        startTime = System.currentTimeMillis();
        slowsorts.insertion(temphundthou);
        endTime = System.currentTimeMillis();
        System.out.println("100000 elements sorted by insertion : " + (endTime - startTime));

        System.arraycopy(hund, 0, temphun, 0, 100);
        System.arraycopy(thou, 0, tempthou, 0, 1000);
        System.arraycopy(tthou, 0, temptthou, 0, 10000);
        System.arraycopy(hunthou, 0, temphundthou, 0, 100000);

        startTime = System.currentTimeMillis();
        slowsorts.shell(temphun);
        endTime = System.currentTimeMillis();
        System.out.println("100 elements sorted by shell : " + (endTime - startTime));

        startTime = System.currentTimeMillis();
        slowsorts.shell(tempthou);
        endTime = System.currentTimeMillis();
        System.out.println("1000 elements sorted by shell : " + (endTime - startTime));

        startTime = System.currentTimeMillis();
        slowsorts.shell(temptthou);
        endTime = System.currentTimeMillis();
        System.out.println("10000 elements sorted by shell : " + (endTime - startTime));

        startTime = System.currentTimeMillis();
        slowsorts.shell(temphundthou);
        endTime = System.currentTimeMillis();
        System.out.println("100000 elements sorted by shell : " + (endTime - startTime));
    }
}
