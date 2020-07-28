//							Created Stacks using classes

#include <iostream>
using namespace std;

struct Node {
	string data;
	Node* next;
};
class Stack
{
public:
	string pop();
	string top();
	bool Empty();
	string Display();
	void push(string data);
	Stack();
	~Stack(); // To make sure there is no memory
private:
	Node* top1 = NULL;
};

bool Stack::Empty() // To check wheteher top node is empty
{
	return top1 == NULL;

}
string Stack::Display()
{
	string result;
	Node* temp = top1;
	result = "\n(TOP) -> ";
	while (temp != NULL)
	{
		result += temp->data + " -> ";
		temp = temp->next;
	}
	result += "(END)\n";
	return result;
}
string Stack::top()
{
	if (!Empty()) {
		string value = top1->data;
		value += " is on the top.\n";
		return value;
	}
	else
		cout << "There is nothing on the top.\n";
}
string Stack::pop()
{
	if (!Empty()) {
		string result = top1->data;
		Node* oldtop = top1;
		top1 = oldtop->next;
		delete oldtop;
		result += " deleted..\n";
		return result;
	}
	else
		cout << "There is nothing to delete.\n";
}
void Stack::push(string data)
{

	Node* temp = new Node;
		temp->data = data;
		temp->next = top1;
		top1 = temp;
}

Stack::Stack()
{
	// initializing a constructor
}
Stack::~Stack()
{
	// initializing a deconstructor
	if (top1 == NULL)
		cout << "Nothing to clean up!\n";
	else
		cout << "Deleting everything...\n";
}

int main()
{
	Stack*s = new Stack();
	string num;
	int op;
	do{
		cout << "\n1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Top\n";
		cout << "4. Display\n";

		cin >> op;
		switch (op)
		{
		case 1:
		{
			cout << "Enter a number: ";
			cin >> num;
			s->push(num);
			break;
		}
		case 2:
		{
			cout << s->pop();
			break;
		}
		case 3:
		{
			cout << s->top();
			break;
		}
		case 4:
		{
			system("CLS");
			cout << s->Display();
			system("pause");
			break;
		}
		default:
			exit;
		}
	} while (op == 1 || op == 2 || op == 3 || op == 4);
	delete s;
}