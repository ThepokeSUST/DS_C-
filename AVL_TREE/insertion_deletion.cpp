#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int height;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

class AVL
{
    node *root;

public:
    AVL()
    {
        this->root = NULL;
    }

private:
    int getheight(node *root)
    {
        if (root == NULL)
            return 0;
        else
            return root->height;
    }

    node *rightrotation(node *root)
    {
        node *temp = root->left;
        root->left = temp->right;
        temp->right = root;
        root->height = 1 + max(getheight(root->left), getheight(root->right));
        temp->height = 1 + max(getheight(temp->left), getheight(temp->right));
        return temp;
    }
    node *leftrotation(node *root)
    {
        node *temp = root->right;
        root->right = temp->left;
        temp->left = root;
        root->height = 1 + max(getheight(root->left), getheight(root->right));
        temp->height = 1 + max(getheight(temp->left), getheight(temp->right));
        return temp;
    }

    node *insert_ele(int ele, node *root)
    {

        if (root == NULL)
        {
            node *newnode = new node(ele);
            return newnode;
        }

        if (root->data > ele)
            root->left = insert_ele(ele, root->left);
        else
            root->right = insert_ele(ele, root->right);

        root->height = 1 + max(getheight(root->left), getheight(root->right));

        int balance = (getheight(root->left) - getheight(root->right));
        // left
        if (balance > 1)
        {
            // left left
            if (root->left->data > ele)
            {
                return rightrotation(root);
            }
            // left right
            else
            {
                root->left = leftrotation(root->left);
                return rightrotation(root);
            }
        }
        // right
        else if (balance < -1)
        {
            // right right
            if (root->right->data < ele)
            {
                return leftrotation(root);
            }
            // right left
            else
            {
                root->right = rightrotation(root->right);
                return leftrotation(root);
            }
        }

        return root;
    }

    node *delete_ele(int ele, node *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->data < ele)
            root->right = delete_ele(ele, root->right);
        else if (root->data > ele)
            root->left = delete_ele(ele, root->left);
        else
        {
            if (!root->left and !root->right)
            {
                delete (root);
                return NULL;
            }
            else if (!root->left)
            {
                node *temp = root->right;
                delete (root);
                return temp;
            }
            else if (!root->right)
            {
                node *temp = root->left;
                delete (root);
                return temp;
            }
            else
            {

                node *child = root->left;
                while (child->right)
                {
                    child = child->right;
                }
                root->data = child->data;
                root->left = delete_ele(child->data, root->left);
            }

            root->height = 1 + max(getheight(root->left), getheight(root->right));
            int balance = getheight(root->left) - getheight(root->right);
            // left
            if (balance > 1)
            { // left left
                if (getheight(root->left->left) > getheight(root->left->right))
                {
                    return rightrotation(root);
                }
                // left right
                else
                {
                    root->left = leftrotation(root->left);
                    return rightrotation(root);
                }
            }
            // right
            else if (balance < -1)
            {
                // right right
                if (getheight(root->right->right) > getheight(root->right->left))
                {
                    return leftrotation(root);
                }
                // right left
                else
                {
                    root->right = rightrotation(root->right);
                    return leftrotation(root);
                }
            }
        }

        return root;
    }
    void inorder_(node *root)
    {
        if (root == NULL)
            return;

        inorder_(root->left);
        cout << root->data << " ";
        inorder_(root->right);
    }

public:
    void delete_(int ele)
    {
        this->root = delete_ele(ele, this->root);
    }
    void insert(int ele)
    {
        this->root = insert_ele(ele, this->root);
    }
    void inorder()
    {
        inorder_(this->root);
    }
};
int main()
{
    AVL t;
    int n;
    cin >> n;

    while (n--)
    {
        int ele;
        cin >> ele;
        t.insert(ele);
    }

    t.inorder();

    int ele;
    cin >> ele;
    t.delete_(ele);
    t.inorder();
}