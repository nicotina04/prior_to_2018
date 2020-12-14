/**An Interface of the Bag. */

public interface BagInterface<T>
{
    /**
     * Array based Bag's default capacity.
     */
    int DEFAULT_CAPACITY = 10;

    /**
     * Add a element to the bag.
     * @param entry A generic type that push to the bag.
     * @return A boolean that check success or failure to add entry.
     */
    public boolean add(T entry);

    /**
     * Remove one element from the bag.
     * @return A generic type that removed entry from the bag.
     */
    public T remove();

    /**
     * Remove one certain element from the bag.
     * @param target A generic type that target of delete.
     * @return A boolean that check success or failure to remove entry.
     */
    public boolean remove(T target);

    /**
     * Check the bag is empty or not.
     * @return A boolean that result of check the bag is empty.
     */
    public boolean isEmpty();

    /**
     * Get the size of the bag.
     * @return A integer that size of the bag.
     */
    public int getCurrentSize();

    /**
     * Remove all elements of the bag.
     */
    public void clear();

    /**
     * Check the bag is contain the certain element.
     * @param target A generic type that want to find.
     * @return A boolean that result of check the bag contains target element.
     */
    public boolean contains(T target);

    /**
     * Get the frequency of target element.
     * @param target A generic type of target entry to count.
     * @return A integer that frequency of target element.
     */
    public int getFrequencyOf(T target);

    /**
     * Convert the bag to an array.
     * @return A generic type array that converted from the bag.
     */
    public T[] toArray();

    /**
     * Check the bag is full or not.
     * @return A boolean that result of check the bag is full ot not.
     */
    public boolean isArrayFull();


}
