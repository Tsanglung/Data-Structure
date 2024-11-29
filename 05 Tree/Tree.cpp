#include <iostream>
using namespace std;

template <class T> class Tree;// 前向宣告
template <class T>
class TreeNode
{
	friend class Tree <T>;
public:
	TreeNode(T d) { data = d; leftChild = NULL; rightChild = NULL; }
	void setNode(TreeNode<T>*, TreeNode<T>*);
private:
	T data;
	TreeNode <T>* leftChild;
	TreeNode <T>* rightChild;
};

template <class T>
void TreeNode<T>::setNode(TreeNode<T>* L, TreeNode<T>* R)
{
	leftChild = L;
	rightChild = R;
}

template <class T>
class Tree
{
public:
	Tree(TreeNode <T>* node) { root = node; }
	void Visit(TreeNode <T>* currentNode) { cout << currentNode->data << " "; }
	void Inorder();
	void Inorder(TreeNode <T>* currentNode);
	void Preorder();
	void Preorder(TreeNode <T>* currentNode);
	void Postorder();
	void Postorder(TreeNode <T>* currentNode);
private:
	TreeNode <T>* root;
};

template <class T>
void Tree<T>::Inorder()
{ //驅動程式呼叫主程式以走訪整棵樹
	//驅動程式宣告為Tree的公用成員函式
	Inorder(root);
}

template < class T>
void Tree<T>::Inorder(TreeNode <T>* currentNode)
{//主程式走訪樹根為currentNode的子樹
	//主程式宣告為Tree的私用成員函式
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}
template < class T>
void Tree <T>::Preorder()
{
	Preorder(root);
}
template <class T>
void Tree <T>::Preorder(TreeNode <T>* currentNode)
{
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}

template <class T>
void Tree <T>::Postorder()
{
	Postorder(root);
}

template <class T>
void Tree <T >::Postorder(TreeNode <T>* currentNode)
{
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}
int main() {
	// TreeNode instantiation   
	TreeNode<char>* nodeA = new TreeNode<char>('A');
	TreeNode<char>* nodeB = new TreeNode<char>('B');
	TreeNode<char>* nodeC = new TreeNode<char>('C');
	TreeNode<char>* nodeD = new TreeNode<char>('D');
	TreeNode<char>* nodeE = new TreeNode<char>('E');
	TreeNode<char>* nodeF = new TreeNode<char>('F');
	TreeNode<char>* nodeG = new TreeNode<char>('G');
	TreeNode<char>* nodeH = new TreeNode<char>('H');
	TreeNode<char>* nodeI = new TreeNode<char>('I');

	// construct the Binary Tree 
	nodeA->setNode(nodeB, nodeC);
	nodeB->setNode(nodeD, nodeE);
	nodeE->setNode(nodeG, nodeH);
	nodeC->setNode(nodeF, NULL);
	nodeF->setNode(NULL, nodeI);

	Tree<char> tree(nodeA);

	cout << "Preorder:" << endl;
	tree.Preorder();
	cout << endl;
	cout << "Inorder:" << endl;
	tree.Inorder();
	cout << endl;
	cout << "Postorder:" << endl;
	tree.Postorder();
	cout << endl;
	return 0;
}
