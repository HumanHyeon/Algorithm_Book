#include <iostream>
using namespace std;
typedef char datatype;

class BinaryNode
{
protected:
    datatype data;
    BinaryNode *left;
    BinaryNode *right;
public:
    BinaryNode();
    BinaryNode(char inputdata, BinaryNode *l = NULL, BinaryNode *r = NULL);
    void setData(datatype input);
    void setLeft(BinaryNode *lf);
    void setRight(BinaryNode *rht);
    datatype getdata();
    BinaryNode *getleft();
    BinaryNode *getright();
    ~BinaryNode();
};

BinaryNode::BinaryNode()
{
}
BinaryNode::BinaryNode(char inputdata, BinaryNode *l = NULL, BinaryNode *r = NULL)
{
    data = inputdata;
    left = l;
    right = r;
}
void BinaryNode::setData(datatype input)
{
    data = input;
}
void BinaryNode::setLeft(BinaryNode *lf)
{
    left = lf;
}
void BinaryNode::setRight(BinaryNode *rht)
{
    right = rht;
}
datatype BinaryNode::getdata()
{
    return data;
}
BinaryNode *getleft()
{
    return left;
}
BinaryNode *getright()
{
    return right;
}


BinaryNode::~BinaryNode()
{
    
}

class BinaryTree
{
private:
    BinaryNode *root;
public:
    BinaryTree(BinaryNode *root);
    void inorder(BinaryNode *node);
    void preorder(BinaryNode *node);
    void postorder(BinaryNode *node);
    void reverse(BinaryNode *node);
    ~BinaryTree();
};

BinaryTree::BinaryTree(BinaryNode *root)
{
}
void BinaryTree::inorder(BinaryNode *node)
{
    if (node != NULL)
    {
        if (node -> getleft() != NULL)
        {
            inorder(node->getleft());
            cout << "[" << node->getdata() << "]";
            if (node->getright() != NULL)
            {
                inorder(node->getright());
            }                
        }
    }        
}
void BinaryTree::preorder(BinaryNode *node)
{
    if (node != NULL)
    {
        cout << "[" << node->getdata() << "]";
        if (node -> getleft != NULL)
        {
            preorder(node -> getleft());            
        }
        else
        {
            preorder(node -> getright());
        }        
    }
}
void BinaryTree::postorder(BinaryNode *node)
{
    if (node != NULL)
    {
        if (node -> getleft != NULL)
        {
            postorder(node -> getleft());
        }
        if (node -> getright != NULL)
        {
            postorder(node -> getright());
        }
        cout << "[" << node -> getdata() << "]";        
    }    
}
void BinaryTree::reverse(BinaryNode *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        reverse(node -> getleft());
        reverse(node -> getright());
        BinaryNode *temp = node->getleft();
        node -> setLeft(node ->getright());
        node -> setRight(temp);
    }    
}

BinaryTree::~BinaryTree()
{
}

int main()
{
    BinaryNode *f = new BinaryNode('f', NULL, NULL);
    BinaryNode *e = new BinaryNode('e', NULL, NULL);
    BinaryNode *d = new BinaryNode('d', NULL, NULL);
    BinaryNode *c = new BinaryNode('c', f, NULL);
    BinaryNode *b = new BinaryNode('b', d, e);
    BinaryNode *a = new BinaryNode('a', b, c);
    
    BinaryTree tree(a);

    tree.reverse(a);

}