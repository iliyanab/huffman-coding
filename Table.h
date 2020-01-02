#pragma once
#include<iostream>

using namespace std;
class Table
{
private:
	pair<char, int>array[255];
	int current_elemnt;
public:
	Table();
	void fill(string text);
	bool check_if_element_is_in_array(char c);
	void add_count(int index);
	void add_symbol(char c);
	void print();
	int returnIndex(char c);
	void get_array(pair<char, int>array[]);
	int return_elemnts();
};

