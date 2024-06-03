#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        right = left = NULL;
    }
};

class BST
{
public:

    Node* root;

    BST()
    {
        root = NULL;
    }

    void insert(int item)
    {
        Node* newnode = new Node(item);
        if (root == NULL) {
            root = newnode;
            return;
        }

        Node* curr = root;
        while (true) {
            if (item < curr->data)
            {
                if (curr->left == NULL)
                {
                    curr->left = newnode;
                    break;
                }
                curr = curr->left;
            }

            else
            {
                if (curr->right == NULL)
                {
                    curr->right = newnode;
                    break;
                }
                curr = curr->right;
            }

        }
    }

    Node* search(Node* r, int key)
    {
        if (r == NULL)
        {
            return NULL;
        }

        else if (r->data == key)
        {
            return r;
        }

        else if (key < r->data)
        {
            return search(r->left, key);
        }

        else
        {
            return search(r->right, key);
        }

    }

    bool search(int key)
    {
        Node* result = search(root, key);
        if (result == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    Node* findMin(Node* r)
    {
        if (r == NULL)
        {
            return NULL;
        }

        else if (r->left == NULL)
        {
            return r;
        }

        else
        {
            return findMin(r->left);
        }
    }

    Node* findMax(Node* r)
    {
        if (r == NULL)
        {
            return NULL;
        }

        else if (r->right == NULL)
        {
            return r;
        }

        else
        {
            return findMax(r->right);
        }
    }

    void preOrder(Node* pnode)   //root->left->right
    {
        if (pnode == NULL)
        {
            return;
        }
        cout << pnode->data << "\t";
        preOrder(pnode->left);
        preOrder(pnode->right);

    }

    void inOrder(Node* pnode)   //left->root->right
    {
        if (pnode == NULL)
        {
            return;
        }


        inOrder(pnode->left);
        cout << pnode->data << "\t";
        inOrder(pnode->right);

    }

    void postOrder(Node* pnode)   //left->right->root
    {
        if (pnode == NULL)
        {
            return;
        }

        postOrder(pnode->left);
        postOrder(pnode->right);
        cout << pnode->data << "\t";

    }

    Node* Delete(Node* r, int key)
    {
        if (r == NULL)  //empty tree
        {
            return NULL;
        }

        else if (key < r->data)  //item exists in left sub-tree
        {
            r->left = Delete(r->left, key);
        }

        else if (key > r->data)  //item exists in right sub-tree
        {
            r->right = Delete(r->right, key);
        }
        else    // key == r->data
        {
            if (r->left == NULL && r->right == NULL)  //leaf node
            {
                delete r;
                r = NULL;
            }

            else if (r->left != NULL && r->right == NULL)  //one child on the left
            {
                Node* temp = r;
                r = r->left;
                delete temp;
            }

            else if (r->left == NULL && r->right != NULL)  //one child on the right
            {
                Node* temp = r;
                r = r->right;
                delete temp;
            }

            else   //node has two children
            {
                Node* temp = findMin(r->right);
                r->data = temp->data;
                r->right = Delete(r->right, temp->data);
            }
        }
        return r;
    }
};

int main()
{
    //45,15,79,90,10,55,12,20,50
    BST btree;
    btree.insert(45);
    btree.insert(15);
    btree.insert(79);
    btree.insert(90);
    btree.insert(90);
    btree.insert(10);
    btree.insert(55);
    btree.insert(12);
    btree.insert(20);
    btree.insert(50);

    cout << "Display the tree content" << endl;
    btree.preOrder(btree.root);
    cout << endl;
    btree.Delete(btree.root, 12);
    btree.preOrder(btree.root);
    cout << endl;
    return 0;
}
