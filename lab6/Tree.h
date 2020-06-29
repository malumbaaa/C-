//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH

//---------------------------------------------------------------------------
#endif

template <class T>
struct Node // структура для представления узлов дерева
{
	T data;
	int key;
	int height;
	Node<T>* left;
	Node<T>* right;
	Node<T>(int k, T d)
	 {
	  data = d;
	  key = k;
	  left = right = NULL;
	  height = 1;
	 }
};

template <class T>
class Tree
{

Node<T>* find_min(Node<T>* p);
Node<T>* remove_min(Node<T>* p);
int height_difference(Node<T>* p);
void height_normalize(Node<T>* p);
Node<T>* rotate_right(Node<T>* p);
Node<T>* rotate_left(Node<T>* q);


Node<T>* insert(Node<T>* p, int k, T data);
Node<T>* remove(Node<T>* p, int k);

void tree_view(Node<T>* p, TTreeView* TreeView1 , TTreeNode* TreeNode1, int n);

void destroy_tree(Node<T>* p);

Node<T>* find(Node<T>* p, int k);

void inorder_print(Node<T>* p, TMemo* Memo1);
void preorder_print(Node<T>* p, TMemo* Memo1);
void postorder_print(Node<T>* p, TMemo* Memo1);

protected:
Node<T>* balance(Node<T>* p);
Node<T>* root;

public:
Tree();
~Tree();

void Insert(int k, T data);
void Remove(int k);
void TreeView(TTreeView* TreeView1);
void DestroyTree();
T Find(int k);
void InorderPrint(TMemo* Memo1);
void PreorderPrint(TMemo* Memo1);
void PostorderPrint(TMemo* Memo1);

};
