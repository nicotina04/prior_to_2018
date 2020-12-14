public interface QueueInterface<T>
{
    public void addBack(T entry);
    public T removeFront();
    public T getFront();
    public boolean isEmpty();
    public void clear();
    public int size();
}
