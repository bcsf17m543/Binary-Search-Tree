#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
	string name;
	int  sem;
	double CGPA;
	int rollno;
public:
	Student()
	{
		name = "";
		sem = 0;
		CGPA = 0;
		rollno = 0;
	}
	Student(Student& rhs)
	{

		name = rhs.name;
		sem = rhs.sem;
		CGPA = rhs.CGPA;
		rollno = rhs.rollno;
	}
	Student(string a, int b, double c, int d)
	{
		name = a;
		sem = b;
		CGPA = c;
		rollno = d;
	}
	string getname()
	{
		return name;
	}
	int getroll()
	{
		return rollno;
	}
	int getsem()
	{
		return sem;
	}
	double getcgpa()
	{
		return CGPA;
	}
	void setroll(int &a)
	{
		rollno = a;
	}
	void setsem(int &a)
	{

	}
	void setCGPA(double& a)
	{
		CGPA = a;
	}
	Student& operator=(Student& rhs)
	{
		name = rhs.name;
		sem = rhs.sem;
		CGPA = rhs.CGPA;
		rollno = rhs.rollno;
		return *this;
	}
	void PrintStu()
	{
		cout << "\nName: " << name << "\nSemester: " << sem << "\nCGPA " << CGPA << "\nRollno: " << rollno << endl;
	}

};
class BinTree
{
private:
	class TreeNode
	{
	public:
		Student data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(Student& d)
		{
			data = d;
			left = NULL;
			right = NULL;
		}
		TreeNode(Student& d, TreeNode*a, TreeNode*b)
		{
			data = d;
			left = a;
			right = b;
		}
	};
	TreeNode *root;
	void Insert(TreeNode*t,Student&d)
	{
		if (t == NULL)
		{
			t = new TreeNode(d);
		}
		Insert(t->right, d);
	}
	void InsertNode(TreeNode *&n, Student& d)
	{

		if (n == NULL)
		{
			n = new TreeNode(d);
		}
		else
		{
			if (d.getroll() < n->data.getroll())
			{
				InsertNode(n->left, d);
			}
			else if (d.getroll() >= n->data.getroll())
			{
				InsertNode(n->right, d);
			}

		}
	}
	void InOrder(TreeNode *t)
	{
		if (t == NULL)
		{
			return;
		}
		else
		{

			InOrder(t->left);
			t->data.PrintStu();
			InOrder(t->right);


		}
	}
	void PostOrder(TreeNode *t)
	{
		if (t == NULL)
		{
			return;
		}
		else
		{
			PostOrder(t->left);
			PostOrder(t->right);

			 t->data.PrintStu();


		}
	}
	void PreOrder(TreeNode *t)
	{
		if (t == NULL)
		{
			return;
		}
		else
		{
			t->data.PrintStu();
			PreOrder(t->left);
			PreOrder(t->right);


		}
	}
	void LevelByLevel(TreeNode*t)//rehta ha
	{
		if (t == NULL)
		{
			return;
		}
		else
		{

			t->data.PrintStu();

			LevelByLevel(t->right);

			LevelByLevel(t->left);

		}

	}
	TreeNode* FindMin(TreeNode* t)
	{
		while (t->left != NULL)
		{
			t = t->left;
		}
		return t;
	}
	void Delete(TreeNode*&t, Student& d)
	{
		if (t == NULL)
		{
			return;
		}
		else if (d.getroll() < t->data.getroll())
		{
			Delete(t->left, d);
		}
		else if (d.getroll() > t->data.getroll())
		{
			Delete(t->right, d);
		}
		else {
			// Case 1:  No child
			if (t->left == NULL && t->right == NULL) {
				delete t;
				t = NULL;
			}
			//Case 2: One child 
			else if (t->left == NULL)
			{
				TreeNode *temp = t;
				t = t->right;
				delete temp;
			}
			else if (t->right == NULL)
			{
				TreeNode *temp = t;
				t = t->left;
				delete temp;
			}
			// case 3: 2 children
			else {
				TreeNode *temp = FindMin(t->right);
				t->data = temp->data;
				Delete(t->right, temp->data);
			}
		}

	}
	void DelRecursive(TreeNode *&n)//MakeEmpty
	{
		if (n != NULL)
		{
			DelRecursive(n->left);
			DelRecursive(n->right);
			delete n;
		}
		n = NULL;
	}

public:
	BinTree()
	{
		root = NULL;
	}
	BinTree(Student arr[],int size)
	{
		for (int i = 0; i < size; i++)
		{
			InsertNode(root, arr[i]);
        }
	}
	void Wrap_Level()
	{
		cout << "---====" << endl;
		TreeNode*t = root;
		LevelByLevel(t);
	}
	void Wrap_Insert(Student& d)
	{
		InsertNode(root, d);
	}
	void Print()
	{
		TreeNode* t = root;
		cout << "\nInOrder\n";
		cout << "------------------\n";
		InOrder(t);
		cout << "\nPost Order\n";
		cout << "------------------\n";

		PostOrder(t);
		cout << "\nPreOrder\n";
		cout << "------------------\n";

		PreOrder(t);
	}
	void Wrap_Remove(Student& d)
	{
		TreeNode*t = root;
		Delete(t, d);

	}

	~BinTree()//destructor
	{
		DelRecursive(root);
	}
};
int main()
{
	Student a("sameer", 4, 3.2, 543);
	Student be("fatima", 4, 3.15, 43);
	Student c("sima", 4, 3.52, 5);
	Student d("fareeha", 4, 3.06, 533);

	a.PrintStu();
	BinTree b;
	b.Wrap_Insert(a);
	b.Wrap_Insert(be);
	b.Wrap_Insert(c);
	b.Wrap_Insert(d);
	b.Print();
	b.Wrap_Level();
	Student ab("sameer", 4, 3.2, 1);
	Student beb("fatima", 4, 3.15, 2);
	Student cb("sima", 4, 3.52, 3);
	Student db("fareeha", 4, 3.06, 3);
	Student arr[] = { ab,beb,cb,db };
	BinTree combo(arr, 4);
	

	return 0;
}