public class LinkedBag<T> implements BagInterface<T>
{
    /**
     * Innerclass of LikedBag
     */
    private class Node
    {
        private T data;
        private Node next;

        /**
         * Initialize the Node class if have no next node.
         * @param dataPortion A generic type that Node will contains.
         */
        public Node(T dataPortion)
        {
            this(dataPortion, null);
        }

        /**
         * Initialize the Node class if have next node.
         * @param dataPortion A generic type that Node will contains.
         * @param nextNode A Node that next node.
         */
        public Node(T dataPortion, Node nextNode)
        {
            data = dataPortion;
            next = nextNode;
        }

        /**
         * Get the Node's data
         * @return A generic type that Node contains.
         */
        public T getData()
        {
            return this.data;
        }

        /**
         * Set the Node's data
         * @param entry A generic type that Node will contains.
         */
        public void setData(T entry)
        {
            data = entry;
        }

        /**
         * Get the next node from current node.
         * @return A Node that next position from current.
         */
        public Node getNextNode()
        {
            return next;
        }

        /**
         * Sets the next node from current node.
         * @param nxtnode A Node that current node will point.
         */
        public void setNextNode(Node nxtnode)
        {
            next = nxtnode;
        }
    }

    private Node firstNode;
    private int numberOfEntries;

    /**
     * Initialize the class.
     */
    public LinkedBag()
    {
        firstNode = null;
        numberOfEntries = 0;
    }

    @Override
    public boolean add(T entry)
    {
        Node newNode = new Node(entry);
        newNode.setNextNode(firstNode); //next를 null로 만듬
        firstNode = newNode;
        ++numberOfEntries;
        return true;
    }

    @Override
    public T remove()
    {
        T poptarget = firstNode.getData();
        firstNode = firstNode.getNextNode();
        --numberOfEntries;

        return poptarget;
    }

    /**
     * Get reference that the data want to find.
     * @param entry A generic type that want to find.
     * @return A Node that contains the entry-param-.
     */
    public Node getReferenceTo(T entry)
    {
        Node result = null;
        Node currentNode = firstNode;
        while(currentNode != null)
        {
            if(currentNode.getData() == entry)
            {
                result = currentNode;
                break;
            }
            else
            {
                currentNode = currentNode.getNextNode();
            }
        }

        return result;
    }
    @Override
    public boolean remove(T target)
    {
        Node targetNode = getReferenceTo(target);
        boolean result = false;

        if(targetNode != null)
        {
            targetNode.setData(firstNode.getData());
            firstNode = firstNode.getNextNode();
            --numberOfEntries;
            result = true;
        }

        return result;
    }

    @Override
    public boolean isEmpty()
    {
        return firstNode == null;
    }

    @Override
    public int getCurrentSize()
    {
        return numberOfEntries;
    }

    @Override
    public void clear()
    {
        firstNode = null;
        numberOfEntries = 0;
    }

    @Override
    public boolean contains(T target)
    {
        Node currentNode = firstNode;
        boolean result = false;
        while(currentNode != null)
        {
            if(currentNode.getData() == target)
            {
                result = true;
                break;
            }
            else
            {
                currentNode = currentNode.getNextNode();
            }
        }

        return result;
    }

    @Override
    public int getFrequencyOf(T target)
    {
        int frequency = 0;
        Node currentNode = firstNode;
        while(currentNode != null)
        {
            if(currentNode.getData() == target)
            {
                ++frequency;
            }
            currentNode = currentNode.getNextNode();
        }
        return frequency;
    }

    @SuppressWarnings("unchecked")
    @Override
    public T[] toArray()
    {
        T result[] = (T[]) new Object[numberOfEntries];
        Node currentNode = firstNode;

        for(int i = 0; i < numberOfEntries; ++i)
        {
            result[i] = currentNode.getData();
            currentNode = currentNode.getNextNode();
        }

        return result;
    }

    @Override
    public boolean isArrayFull()
    {
        return false;
    }


}
