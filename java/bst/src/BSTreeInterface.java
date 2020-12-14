public interface BSTreeInterface<T>
{
    public int height(Node<T> node);
    public int noNodes(Node<T> node);
    public Node<T> maxNode(Node<T> parent);
    public Node<T> minNode(Node<T> parent);

    public Node<T> searchBST(Node<T> root, T s_key);
    public Node<T> searchParentBST(Node<T> root, T s_key, Node<T> p, Node<T> q);

    public T insertBST(Node<T> root, T newKey);
    public T deleteBST(Node<T> root, T deleteKey);
    public void inorder(Node<T> node);
}
