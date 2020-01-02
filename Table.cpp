#include "Table.h"
using namespace std;

Table::Table()
{
	current_elemnt = 0;
}
void Table::fill(string text)
{
	for (int i = 0; i < text.size(); i++)
	{
			if (check_if_element_is_in_array(text[i]) == true)
			{
				add_count(returnIndex(text[i]));
			}
			else
			{
				add_symbol(text[i]);
				current_elemnt++;
			}
	}
}

bool Table::check_if_element_is_in_array(char c)
{
	for (int i = 0; i < current_elemnt; i++)
	{
		if (c == array[i].first) return true;
	}
	return false;
}

void Table::add_count(int index)
{
	array[index].second++;
}

void Table::add_symbol(char c)
{
	array[current_elemnt].first = c;
	array[current_elemnt].second = 1;
}

void Table::print()
{
	for (int i = 0; i < current_elemnt; i++)
	{
		cout << array[i].first << " " << array[i].second << endl;
	}
}

int Table::returnIndex(char c)
{
	for (int i = 0; i < current_elemnt; i++)
		if (c == array[i].first)return i;
}
void Table::get_array(pair<char, int>array[])
{
	for (int i = 0; i < current_elemnt; i++)
	{
		array[i]=this->array[i];
	}
}

int Table::return_elemnts()
{
	return current_elemnt;
}
