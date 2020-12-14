public class Airport
{
    private QueueInterface<Airplane> runway;
    private int numofArrivals;
    private int numServed;
    private int totalTime;

    public Airport()
    {
        runway = new CLqueue<>();
        reset();
    }

    public final void reset()
    {
        runway.clear();
        numofArrivals = 0;
        numServed = 0;
        totalTime = 0;
    }

    public void simulate(int duration, double arrivalProb, int maxWait)
    {
        int LandtimeLeft = 0;

        for(int clock = 0; clock < duration; ++clock)
        {
            if(Math.random() < arrivalProb)
            {
                ++numofArrivals;
                int LandTime = (int)(Math.random() * (maxWait + 1));
                Airplane nextArrival = new Airplane(clock, LandTime, numofArrivals);

                runway.addBack(nextArrival);
                System.out.println("Airplane " + numofArrivals + " enters runway at time " + clock + ". Landtime is " + LandTime);
            }

            if(LandtimeLeft > 0)
            {
                --LandtimeLeft;
            }
            else if(runway.size() > 0)
            {
                Airplane nextPlane = runway.removeFront();
                LandtimeLeft = nextPlane.getLandTime() - 1;
                int timewaited = clock - nextPlane.getArrivalTime();
                totalTime += timewaited;
                ++numServed;
                System.out.println("Airplane " + nextPlane.getPlaneNumber() + " begins service at time " + clock +". Time waited is " + timewaited);
            }
        }
    }

    public void display()
    {
        System.out.println();
        System.out.println("Number served = " + numServed);
        System.out.println("Total time waited = " + totalTime);
        double AVG = (double)totalTime / numServed;
        System.out.println("Average of waiting = " + AVG);
        System.out.println("Number left in runway = " + runway.size());
    }
}
