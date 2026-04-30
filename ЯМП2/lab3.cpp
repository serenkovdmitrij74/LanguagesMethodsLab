#include <iostream>
#include <string>

using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;

	Node() {
		this->next = nullptr;
		this->prev = nullptr;
	}

	Node(T data, Node<T>* prev = nullptr, Node<T>* next = nullptr) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};


template <class T>
class List
{
private:
	int size;
	Node<T>* start;
	Node<T>* end;

	bool IsNotEmpty() {
		if (size == 0) {
			throw runtime_error("List pust");
			return false;
		}
		return true;
	}
public:
	List() {
		this->size = 0;
		this->start = nullptr;
		this->end = nullptr;
	}

	List(T data) : List() {
		push_back(data);
	}

	void push_back(T data) {
		Node<T>* newNode = new Node<T>(data, end);

		if (end != nullptr)
			end->next = newNode;
		else
			start = newNode;
		end = newNode;
		size += 1;
	}

	void pop_back() {
		if (IsNotEmpty()) {
			if (size > 1) {
				end = end->prev;
				delete end->next;
				end->next = nullptr;
			}
			else{
				delete end;
				end = nullptr;
				start = nullptr;
			}
			size -= 1;
		}
	}

	T get_back() {
		if (IsNotEmpty())
			return end->data;
	}

	int get_size() {
		return size;
	}

	~List() {
		while (start!=nullptr) {
			pop_back();
		}
	}
};


template <class T>
class Stack
{
private:
	List<T>* workList;
	
	bool IsNotEmpty() {
		if (workList->get_size() == 0) {
			throw runtime_error("Stack pust");
			return false;
		}
		return true;
	}
public:
	Stack() {
		workList = new List<T>();
	}

	Stack(T data) : Stack() {
		push(data);
	}

	void push(T data) {
		workList->push_back(data);

	}

	void pop() {
		if(IsNotEmpty())
			workList->pop_back();
	}

	T GetNode(){
		if (IsNotEmpty()) {
			return workList->get_back();
		}
	}

	~Stack() {
		delete workList;
	}
};

int main() {
	try {
		Stack<int> s;
		s.push(10);
		s.push(20);
		s.pop();
		s.pop();
		s.pop();
	}
	catch (const exception& e) {
		cout << "Pomylka: " << e.what() << endl;
	}
	return 0;
}
