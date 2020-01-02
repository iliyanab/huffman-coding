#pragma once
using namespace std;
#include<iostream>
#include<fstream>
struct Node
{
	int data;
	char symb;
	Node* left;
	Node* right;
	Node()
	{
		left = nullptr;
		right = nullptr;
	}
};

class Tree
{
private:
	Node* root;
public:
	~Tree();
	void setRoot(Node* ptr);
	void fill_leaves(Node*array[],pair<char,int>arr[], int elements);
	Node* tree_maker(Node* array[], int elements);
	void Delete(Node* ptr);
	Node* return_root();
	//void codes(Node* root, pair<char, string> array[],int &current_elements);
	void t(Node* ptr);
	void printTree(Node* root);
	void printTreeWithSpace(Node* root, int space);
	void codes2(Node* root,int curr_code[],int curr_code_counter, fstream& f);//101110100110101011101
};

