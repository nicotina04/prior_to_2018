public class Airplane
{
    private int clock;
    private int landtime;
    private int arrivals;
    public Airplane()
    {
        this.clock = 0;
        this.landtime = 0;
        this.arrivals = 0;
    }

    public Airplane(int clock, int Land, int Arri)
    {
        this.clock = clock;
        this.landtime = Land;
        this.arrivals = Arri;
    }

    public int getLandTime()
    {
        return this.landtime;
    }

    public int getArrivalTime()
    {
        return this.clock;
    }

    public int getPlaneNumber()
    {
        return this.arrivals;
    }

}
