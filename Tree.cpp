#include "Tree.h"
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
Tree::~Tree()
{
	Delete(root);
}

void Tree::Delete(Node* root)
{
	if (root == nullptr)
		return;
	Delete(root->left);
	Delete(root->right);
	delete root;
}

Node* Tree::return_root()
{
	return root;
}

//void Tree::codes(Node* root,Code array[],int &current_elements)
//{
//	if (root->left)
//	{
//		array[current_elements].code+="0";
//		codes(root->left, array, current_elements);
//	}
//	if (root->right)
//	{
//		array[current_elements].code+="1";
//		codes(root->right, array, current_elements);
//	}
//	if (!root->left && !root->right)
//	{
//		array[current_elements].symbol = root->symb;
//		current_elements++;
  //      return;
//	}
//}

void Tree::t(Node* ptr)
{
	if (ptr == nullptr)return;
	if (ptr->left)
	{
		cout << "0";
		t(ptr->left);
	}
	if (ptr->right)
	{
		cout << "1";
		t(ptr->right);
	}
}



void Tree::setRoot(Node* ptr)
{
	root = ptr;
}
void Tree::fill_leaves(Node*array[], pair<char,int>arr[], int elements)
{
	for (int i = 0; i < elements; i++)
	{
		array[i] = new Node;
		array[i]->data = arr[i].second;
		array[i]->symb = arr[i].first;
	}
}
void sort(Node* array[], int elements)
{
	for (int i = 0; i < elements - 1; i++)
	{
		for (int j = 0; j < elements - i - 1; j++)
		{
			if (array[j]->data < array[j + 1]->data)
			{
				Node* swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
			}
		}
	}
}

Node* Tree:: tree_maker(Node* array[], int elements)
{
	while (elements >1)
	{
		sort(array, elements);
		//for (int i = 0; i < elements; i++)cout << array[i]->data << endl;
		//cout << "----------------------------" << endl;
		Node* parent = new Node;
		parent->left = array[elements - 1];
		parent->right = array[elements - 2];
		parent->data = parent->right->data + parent->left->data;
		//cout << "  " << parent->data << endl;
		//cout << parent->left->data << " " << parent->right->data << endl;
		elements--;
		elements--;
		array[elements] = parent;
		elements++;
		if (elements == 1)
		{
			 return parent;
		}
	}
}
void copy_array(string& code, int array1[], int el)
{
	code.erase();
	for (int i = 0; i < el; i++)
	{
		//cout << array1[i];
		if(array1[i]==0)code.append("0");
		else code.append("1");
	}
	//cout << endl;
}
void remove_unwanted(int array1[], int& el)
{
	if (array1[el - 1] != 0 && array1[el - 1] != 1)el--;
}

void Tree::codes2(Node* root,int curr_code[], int curr_code_counter,fstream& f)
{
	if (root->left)
	{
		curr_code[curr_code_counter]=0;
		codes2(root->left, curr_code, curr_code_counter + 1,f);
	}
	if (root->left)
	{
		curr_code[curr_code_counter] = 1;
		codes2(root->right, curr_code, curr_code_counter + 1,f);
	}
	if (root->left == nullptr && root->right == nullptr)
	{
		remove_unwanted(curr_code, curr_code_counter);
		string temp;
		copy_array(temp,curr_code,curr_code_counter);
		f << root->symb<<endl;
		f << temp<<endl;
		//cout << array[current].symbol << " ";
			//cout << array[current].code;
		//cout << endl;
	}
}
void Tree::printTreeWithSpace(Node* root, int space)
{

	if (root == nullptr)
		return;
	space += 10;
	printTreeWithSpace(root->right, space);
	cout << endl;
	for (int i = 10; i < space; i++)
		cout << " ";
	cout << root->data<< endl;
	printTreeWithSpace(root->left, space);
	if (root->right == nullptr && root->left == nullptr)
		cout << "Symbol is " << root->symb << " " << endl;
}

void Tree::printTree(Node* root)
{
	printTreeWithSpace(root, 0);
}