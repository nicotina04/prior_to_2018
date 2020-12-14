public class CLqueue<T> implements QueueInterface<T>
{
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

    private Node lastnode;
    private int lange;

    public CLqueue()
    {
        lastnode = null;
        lange = 0;
    }

    public void addBack(T entry)
    {
        Node newnode = new Node(entry, null);
        if(isEmpty())
        {
            lastnode = newnode;
            lastnode.setNextNode(lastnode);
            lange = 1;
        }
        else
        {
            if(lastnode.getNextNode() == null) //is node alone?
            {
                lastnode.setNextNode(newnode);
                newnode.setNextNode(lastnode);
            }
            else//are nodes over the 2?
            {
                newnode.setNextNode(lastnode.getNextNode());
                lastnode.setNextNode(newnode);
            }
            ++lange;
        }
        lastnode = newnode;
    }

    public T removeFront()
    {
        if(isEmpty()) {return null;}
        else
        {
            T temp = lastnode.getNextNode().getData();

            if(lastnode.getNextNode() == lastnode) {clear(); lange = 0;}
            else
            {
                lastnode.setNextNode(lastnode.getNextNode().getNextNode());
                --lange;
            }

            return temp;

        }
    }

    public T getFront()
    {
        if(isEmpty()) {return null;}
        else
        {
            return lastnode.getNextNode().getData();
        }
    }

    public boolean isEmpty()
    {
        return lastnode == null;
    }

    public void clear()
    {
        lastnode = null;
        lange = 0;
    }

    public int size()
    {
        return lange;
    }
}
