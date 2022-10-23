#include<fstream>
#include<iostream>
#include "Dictionary.h"
#include "List.h"
using namespace std;

string filename; //stores filename


//DEFINING FUNCTIONS
class DictList : public SinglyLinkedList<Dictionary> //template class
{
public:
	void WriteToDictionaryFile(fstream& file) const
	{
		for (ListNode* var1 = start; var1; var1 = var1->next) // loop until var1 becomes null
		{
			file << var1->data.word << " " << var1->data.meaning << "\n";
		}
	}
	void Print() const
	{
		for (ListNode* var1 = start; var1; var1 = var1->next) // loop until var1 becomes null
		{
			cout << var1->data << "\n";
		}
	}
	void PrintReverse() const
	{
		PrintReverseRevar1rsive(start);
	}
	void ReverseList()
	{
		ListNode* prev = NULL;
		ListNode* var1 = start;

		while (var1) // loop until var1 becomes null
		{
			ListNode* tempNext = var1->next;

			var1->next = prev;
			prev = var1;
			var1 = tempNext;
		}
		start = prev;
	}
	void FilterByLetter(string letter)
	{
		for (ListNode* var1 = start; var1;) // loop until var1 becomes null
		{
			if (var1->data.word.find(letter) == string::npos) // if it dosn't contain the letter
			{
				Dictionary toBeDel = var1->data;
				var1 = var1->next;
				Delete(toBeDel);
			}
			else
			{
				var1 = var1->next;
			}
		}
	}
	void RearrangeByEvenOddLength()
	{
		DictList tempList;
		for (ListNode* var1 = start; var1; var1 = var1->next) // loop until var1 becomes null
		{
			if (var1->data.word.size() % 2 == 1)
			{
				tempList.Insert(var1->data);
			}
		}

		for (ListNode* var1 = start; var1; var1 = var1->next) // loop until var1 becomes null
		{
			if (var1->data.word.size() % 2 == 0)
			{
				tempList.Insert(var1->data);
			}
		}

		*this = tempList;
	}

private:
	void PrintReverseRevar1rsive(ListNode* node) const
	{
		// if next is not null then revar1se
		if (node->next) PrintReverseRevar1rsive(node->next);
		cout << node->data << "\n";
	}
};

void readFileData(DictList& list) //reads text from a file and writes it to the AVL tree
{
	Dictionary dict;
	string word, meaning;
	fstream fin;
	cout << "Enter the filename: ";
	cin.ignore();
	cin >> filename;
	fin.open(filename);
	cout << "File Read!\n";
	while (fin >> word)  //write into file name
	{
		fin.ignore();
		getline(fin, meaning);
		dict = Dictionary(word, meaning);

		list.Insert(dict);
	}
	list.ReverseList();

	fin.close();
}

void writeToFile(DictList& list) //write the linked list to a text file
{
	fstream dictFile; //create fstream object for the file
	cout << "Enter the filename: ";
	cin.ignore();
	cin >> filename;
	dictFile.open(filename, std::ios::app); //create/open a text file in append mode. new information is always added to the end

	list.WriteToDictionaryFile(dictFile);

	dictFile.close();
	cout << "Entries Added!\n";
}

void mainMenu() //menu function
{
	string word;	//word in dict
	string meaning; //meaning for every dict word
	char option = 0;  //option menu
	DictList list;

	while (option != '0' ) //Q or q will quit the program
	{
		cout << "Select the Action: " << endl << endl;
		cout << "1. Read from file to list" << endl;
		cout << "2. Write to file from list" << endl;
		cout << "3. Print the List" << endl;
		cout << "4. Reverse the List" << endl;
		cout << "5. Print the List in Reverse Order" << endl;
		cout << "6. Filter the List" << endl;
		cout << "7. Rearrange by EvenOdd Length" << endl;
		cout << "0. Input '0' to QUIT!" << endl; //trying to make it visually appealing
		cout << endl;
		cin >> option; 
		cout << endl;
		switch (option)  //Functions switch calling
		{
		case('1'):
		{
			readFileData(list);
		}; break;

		case('2'):
		{
			writeToFile(list);
		}; break;

		case('3'):
		{
			list.Print();
		}; break;
		case('4'):
		{
			list.ReverseList();
			cout << "List Reversed!\n";
		}; break;
		case('5'):
		{
			list.PrintReverse();
		}; break;



		case('6'):
		{
			cout << "Enter Filter Letter: ";
			string FilterLetter;
			cin.ignore();
			cin >> FilterLetter;
			list.FilterByLetter(FilterLetter);
			cout << "List Filtered!\n";
		}; break;

		case('7'):
		{
			list.RearrangeByEvenOddLength();
			cout << "List Rearranged!\n";
		}; break;

		case('0'):
		{
			cout << "Program terminated!" << endl;
		}; break;

		default:
			cout << "---Invalid Choice---" << endl;
		}
	}
}