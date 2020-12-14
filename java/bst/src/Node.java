public class Node<T>
{
    private T key;
    private Node<T> left;
    private Node<T> right;

    public Node(T seed, Node<T> left, Node<T> right)
    {
        this.key = seed;
        this.left = left;
        this.right = right;
    }

    public Node(T seed)
    {
        this(seed, null, null);
    }

    public Node() { this(null); }

    public T getKey() { return this.key; }

    public void setKey(T item) { this.key = item; }

    public Node<T> getLeft() { return this.left; }

    public Node<T> getRight() { return this.right; }

    public void setLeft(Node<T> l) { this.left = l; }

    public void setRight(Node<T> r) { this.right = r; }

    public boolean hasLeft() { return this.left != null; }

    public boolean hasRight() { return this.right != null; }
}