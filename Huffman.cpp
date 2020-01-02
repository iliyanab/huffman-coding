
#include <iostream>
#include"Table.h"
#include<fstream>
#include"Tree.h"
#include<string>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void search_file(fstream& text, string& all)
{
	while (text)
	{
		string line;
		getline(text, line);
		all.append(line);
	}
}
int conver_desimal(string s)
{
	int base = 1;
	int des = 0;
	for (int i = 0; i<  s.size(); i++)
	{
		if (s[i] == '1')des += base;
		base *= 2;
	}
	return des;
}

string reverse(string s,string& reverse)
{
	
	for (int i = s.size() - 1; i >= 0; i--)
		reverse += s[i];
	return reverse;
}
void incode(string all,int code_count, pair<char, string> array[],fstream &dv_cod,fstream& count)
{
	int l = all.size();
	string binary;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < code_count; j++)
		{
			if (all[i] == array[j].first)
			{
				binary+=array[j].second;
			}
		}
	}
	int base = 1;
	int decimal = 0;
	string conv;
	int len = binary.size();
	int v = 0;
	int f = 0;
	int c = 8;
	
	while (v < len)
	{
int cl = 0;
		//int b=c;
	//while (b % 8 != 0)
	//{
	//	conv += "0"; b++;
	//}
		for (int i = v; i < c; i++)
		{
			conv += binary[i];
		}
		
		int i = conv.size()-1;
		if (conv[i] == 0)
			while (conv[i] == '0')
			{
				cl++;
				i--;
			}cout << cl << endl;
		cout << conv<<endl;
		dv_cod << conver_desimal(conv) << endl;
		conv.erase();
		v = c;
		if (len - v < 8)
			c = len;
		else
			c += 8; f++;

	}
	
	dv_cod.close();
}
void create_code_array(pair<char, string> array[],int& code_count,ifstream& f)
{
	int i = 1;
	while (f)
	{
		
		if (i % 2 != 0)
		{
			string line;
		    getline(f, line);
			array[code_count].first=line[0];
			//cout << array[code_count].symbol << " ";
		}
		else
		{
			getline(f,array[code_count].second);
			//cout << array[code_count].code << endl;
			code_count++;
		}
		i++;
	}
}
void compres(pair<char, string> array[],int& code_count,fstream &f,Tree &tr,Table &t,Node* leaves[], pair<char, int>symbols[255],fstream& text, fstream& dv_cod, ifstream& f_read,fstream& count)
{
	int codes[255];
	int curr_codes = 0;
	int current = 0;
	string all;
	search_file(text,all);
	t.fill(all);
	t.get_array(symbols);
	t.print();
	tr.fill_leaves(leaves, symbols, t.return_elemnts());
	tr.setRoot(tr.tree_maker(leaves, t.return_elemnts()));
	cout <<"-------------------"<<endl;
	tr.codes2( tr.return_root(), codes, curr_codes,f);
	create_code_array(array,code_count,f_read);
	count << code_count<<endl;
	for (int i = 0; i < code_count; i++)
	{
		cout << array[i].first << " " << array[i].second << endl;
	}
	incode(all, code_count, array, dv_cod,count);
	f.close();
	text.close();
	f_read.close();
	count.close();
	//incode(all, current, array, dv_cod,f);
}
bool compare_s(string s1, pair<char,string>st)
{
	string s2;
	for (int i = 0; i < st.second.size(); i++)
		s2 += st.second[i];
	if (s1.size() != s2.size())return false;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])return false;
	}
	return true;
}

void decompres(pair<char,string> array[],ifstream& dv_cod,int code_count,ifstream& count,ifstream& f)
{
	string so_far_code;
	string all;
	string line1;
	string line2;
	getline(count, line1);
	code_count = line1[0]-48;int ind = 0;
	count.clear();
	count.seekg(0, ios::beg);
	create_code_array(array, code_count, f);
	int br = 0;
	while (dv_cod)
	{
		string Line;
		getline(dv_cod, Line); br++;
	}
	dv_cod.clear();
	dv_cod.seekg(0, ios::beg);
	//cout << br;
	while (dv_cod)
	{
		string line;
		getline(dv_cod, line);
		 int c = 0;
	for (int i = 0; i < line.size(); i++)
	{
		c = c*10 + (line[i] - '0');
	}
	string b;
	
	int q = 0;
	
	
	while (c > 0)
	{
	
		b += (c % 2)+48;
		c /= 2;
	}
	
	while (count)
	{
		getline(count, line2);
	}
	while (q < line2[ind] - 48)
	{
		b.append("0");
		q++;
	}
	ind++;
		all.append(b);
		//cout <<b<<endl;
		b.erase();
		br--;
		if (br == 1)break;
	}
	int l = all.size();
	for (int i = 0; i < l; i++)
	{
		so_far_code += all[i];
		for (int j = 0; j < code_count; j++)
		{
			if(compare_s(so_far_code,array[j])==true)
			{
				cout<<array[j].first;
				so_far_code.erase();
			}
		}
	}
	count.close();
	dv_cod.close();
}
int main()
{
	fstream text("text.txt");
	Table t;
	pair<char, int>symbols[255];
	Node* leaves[255];
	Tree tr;
	pair<char,string>array[255];
	int code_count=0;
	fstream f("coded.txt", ios::app);
	fstream dv_cod("dvoichen kod.txt", ios::app);
	ifstream dv_cod_chetene("dvoichen kod.txt");
	ifstream f_read("coded.txt");
	fstream count("code count.txt");
	ifstream count_read("code count.txt");
	int izbor;
	int add0_count = 0;
	int* add0 = new int[add0_count];
	cout << "1.Compres" << endl;
	cout << "2.Deompres" << endl;
	cin >> izbor;
	if(izbor==1)
	compres(array,code_count,f, tr, t, leaves, symbols,text,dv_cod,f_read,count);
	else
	decompres(array,dv_cod_chetene,code_count, count_read,f_read);
	
}
