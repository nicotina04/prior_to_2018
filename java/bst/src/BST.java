public class BST<T extends Comparable<? super T>> implements BSTreeInterface<T>
{
    public Node<T> root;

    public BST() { this.root = null; }
    public BST(T initkey) { this.root = new Node<T>(initkey); }

    public int height(Node<T> node)
    {
        if(node != null)
        {
            return 1 + Math.max(this.height(node.getLeft()), this.height(node.getRight()));
        }
        else { return 0; }
    }

    public int noNodes(Node<T> parent)
    {
        int branchleft;
        int branchright;

        branchleft = branchright = 0;

        if(parent.getLeft() != null)
        {
            branchleft = this.noNodes(parent.getLeft());
        }

        if(parent.getRight() != null)
        {
            branchright = this.noNodes(parent.getRight());
        }

        return 1 + branchleft + branchright;
    }

    public Node<T> maxNode(Node<T> parent)
    {
        Node<T> result = parent;

        while(result.getRight() != null)
        {
            result = result.getRight();
        }

        return result;
    }

    public Node<T> minNode(Node<T> parent)
    {
        Node<T> result = parent;

        while(result.getLeft() != null)
        {
            result = result.getLeft();
        }

        return result;
    }

    public Node<T> searchBST(Node<T> root, T s_key)
    {
        Node<T> p = root;

        if(p == null) {return null;}

        int comparison = p.getKey().compareTo(s_key);

        if(comparison == 0) { return p; }
        if(comparison < 0)
        {
            return searchBST(p.getRight(), s_key);
        }
        else
        {
            return searchBST(p.getLeft(), s_key);
        }
    }

    public Node<T> searchParentBST(Node<T> root, T s_key, Node<T> p, Node<T> q)
    {
        if(root == null) { return null; }

        p = q = root;

        while(q.hasLeft() || q.hasRight())
        {
            T currentItem = p.getKey();
            int comparison = s_key.compareTo(currentItem);

            if(comparison == 0) { return q; }
            if(comparison < 0)
            {
                q = p;
                p = p.getLeft();
            }
            else
            {
                q = p;
                p = p.getRight();
            }
        }
        return q;
    }

    private Node<T> getNode() { return new Node<>(); }

    public T insertBST(Node<T> root, T newKey)
    {
        T result = null;
        Node<T> p = root;
        Node<T> q = this.getNode();

        if(p == null)
        {
            p = this.getNode();
            p.setKey(newKey);
            this.root = p;
            result = newKey;
        }
        else
        {
            while(p != null)
            {
                T currentItem = p.getKey();
                int comparison = newKey.compareTo(currentItem);

                if(comparison == 0)
                {
                    result = currentItem;
                    q = p;
                    return result;
                }
                if(comparison < 0)
                {
                    q = p;
                    p = p.getLeft();
                }
                else
                {
                    q = p;
                    p = p.getRight();
                }
            }

            Node<T> child = this.getNode();
            child.setKey(newKey);

            if(newKey.compareTo(q.getKey()) < 0)
            {
                q.setLeft(child);
            }
            else
            {
                q.setRight(child);
            }

            result = newKey;
        }
        return result;
    }

    public T deleteBST(Node<T> root, T deleteKey)
    {
        if(this.searchBST(root, deleteKey) == null) {return null;}

        T result = deleteKey;
        Node<T> p = new Node<>();
        Node<T> q = p;

        q = searchParentBST(root, deleteKey, p, q);

        int comparison = deleteKey.compareTo(q.getKey());

        if(comparison == 0) { p = q; }
        else if(comparison < 0) { p = q.getLeft(); }
        else { p = q.getRight(); }

        if(!p.hasLeft() && !p.hasRight())
        {
            if(p.equals(this.root))
            {
                this.root = null;
            }
            if(q.hasLeft() && q.getLeft().equals(p))
            {
                q.setLeft(null);
            }
            else { q.setRight(null); }
        }
        else if(!p.hasLeft() && p.hasRight())
        {
            if(q.equals(p))
            {
                this.root = p.getRight();
            }
            else if(q.hasLeft() && q.getLeft().equals(p))
            {
                q.setLeft(p.getRight());
            }
            else
            {
                q.setRight(p.getRight());
            }
        }
        else if(p.hasLeft() && !p.hasRight())
        {
            if(q.equals(p))
            {
                this.root = p.getLeft();
            }
            else if(q.hasLeft() && q.getLeft().equals(p))
            {
                q.setLeft(p.getLeft());
            }
            else
            {
                q.setRight(p.getLeft());
            }
        }
        else
        {
            int Lheight = this.height(p.getLeft());
            int Rheight = this.height(p.getRight());
            int Lnodes = this.noNodes(p.getLeft());
            int Rnodes = this.noNodes(p.getRight());

            Node<T> sub_p = null;
            Node<T> sub_q = null;
            Node<T> x = new Node<>();
            Node<T> y = new Node<>();

            T temp = null;

            if(Rheight > Lheight || Rnodes >= Lnodes)
            {
                sub_p = this.minNode(p.getRight());

                sub_q = this.searchParentBST(p, sub_p.getKey(), x, y);

                temp = p.getKey();

                p.setKey(sub_p.getKey());
                sub_p.setKey(temp);

                if(!sub_p.hasLeft() && !sub_p.hasRight() && sub_q.hasRight() && sub_q.getRight().equals(sub_p))
                {
                    sub_q.setRight(null);
                }
                else if(!sub_p.hasLeft() && !sub_p.hasRight() && sub_q.hasLeft() && sub_q.getLeft().equals(sub_p))
                {
                    sub_q.setLeft(null);
                }
                else if(sub_p.hasRight() && sub_q.hasRight() && sub_q.getRight().equals(sub_p))
                {
                    sub_q.setRight(sub_p.getRight());
                }
                else
                {
                    sub_q.setLeft(sub_p.getRight());
                }
            }
            else
            {
                sub_p = this.maxNode(p.getLeft());

                sub_q = this.searchParentBST(p, sub_p.getKey(), x, y);

                temp = sub_p.getKey();

                p.setKey(sub_p.getKey());
                sub_p.setKey(temp);

                if(!sub_p.hasLeft() && !sub_p.hasRight() && sub_q.hasRight() && sub_q.getRight().equals(sub_p))
                {
                    sub_q.setRight(null);
                }
                else if(!sub_p.hasLeft() && !sub_p.hasRight() && sub_q.hasLeft() && sub_q.getLeft().equals(sub_p))
                {
                    sub_q.setLeft(null);
                }
                else if(sub_p.hasLeft() && sub_q.hasRight() && sub_q.getRight().equals(sub_p))
                {
                    sub_q.setRight(sub_p.getLeft());
                }
                else
                {
                    sub_q.setLeft(sub_p.getLeft());
                }
            }
        }
        return result;
    }

    public void inorder(Node<T> node)
    {
        boolean end = false;

        if(node != null)
        {
            inorder(node.getLeft());
            System.out.print(node.getKey() + " ");
            if(node.equals(this.maxNode(this.root)))
            {
                end = true;
            }
            inorder(node.getRight());
        }
        if(end) {System.out.println();}
    }
}
