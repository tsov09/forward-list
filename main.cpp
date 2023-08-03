#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T value;
	Node* next = nullptr;
};

template <typename T>
class Forward_List {
	Node<T>* head;

public:
	Forward_List() : head(nullptr) {};
	void add_front(Node<T>* item) {
		item->next = head;
		head = item;
	}
	void pop_front() {
		head = head->next;
	}
	void push_back(Node<T>* item) {
		if (head == nullptr) {
			head = item;
			return;
		}
		Node<T>* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = item;
	}
	void pop_back() {
		if (head == nullptr) {
			cout << "Forward list is empty." << endl;
			return;
		}
		else if (head->next == nullptr) {
			head = nullptr;
			return;
		}
		else {
			Node<T>* temp = head;
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			temp->next = nullptr;
		}
	}
	void insert(int position, Node<T>* item) {
		Node<T>* temp = head;
		if (position == 0) {
			head = item;
			head->next = temp;
		}
		else if (position > 0) {
			for (int i = 0; i < position - 1; i++) {
				if (temp->next == nullptr) {
					cout << "The number is out of range." << endl;
					return;
				}
				temp = temp->next;
			}

			item->next = temp->next;
			temp->next = item;
		}
		else {
			cout << "The number can't be negative." << endl;
		}
	}

	void reverse() {
		if (head == nullptr || head->next == nullptr) {
			return;
		}
		Node<T>* temp = head;
		Node<T>* temp_next = head->next;
		Node<T>* tmp;
		while (temp_next != nullptr) {
			tmp = temp_next->next;
			temp_next->next = temp;
			temp = temp_next;
			temp_next = tmp;
		}
		head->next = nullptr;
		head = temp;
	}
	Node<T>* find_n_th_from_end(int n) {
		if (n < 1) {
			cout << "The number must be greather than 0." << endl;
			return nullptr;
		}
		int step = 1;
		Node<T>* temp = head;
		Node<T>* n_th = head;
		while (temp->next != nullptr) {
			temp = temp->next;
			step++;
			if (step > n) {
				n_th = n_th->next;
			}
		}
		if (n <= step) {
			return n_th;
		}
		else {
			cout << "The number is greather than forward list's size" << endl;
			return nullptr;
		}
	}
	bool is_cycled() {
		if (head == nullptr || head->next == nullptr) {
			return false;
		}

		Node<T>* temp = head;
		Node<T>* temp_next = head;
		while (temp_next->next != nullptr) {
			temp = temp->next;
			temp_next = temp_next->next->next;
			if (temp_next->next == temp || temp_next == temp) {
				return true;
			}
		}
		return false;
	}
	void print() {
		if (head == nullptr) {
			cout << "Forward list is empty." << endl;
			return;
		}
		Node<T>* temp = head;
		cout << "{ ";
		while (temp->next != nullptr) {
			cout << temp->value << ", ";
			temp = temp->next;
		}
		cout << temp->value << " }";
	}
};


void checking_forward_list() {
	Node<int>* n_1 = new Node<int>;
	n_1->value = 7;

	Node<int>* n_2 = new Node<int>;
	n_2->value = 11;
	Node<int>* n_3 = new Node<int>;
	n_3->value = 18;
	Node<int>* n_4 = new Node<int>;
	n_4->value = 89;

	Forward_List<int>* list = new Forward_List<int>;
	list->push_back(n_1);
	list->push_back(n_2);
	list->push_back(n_3);
	list->push_back(n_4);
	cout << "Forward list after push_back(...) 4 times: ";
	list->print();
	cout << endl;

	list->pop_back();
	cout << "Forward list after single pop_back(): ";
	list->print();
	cout << endl;

	
	list->insert(2, n_4);
	cout << "Forward list after insert(2, ...): ";
	list->print();
	cout << endl;

	list->reverse();
	cout << "Forward list after reverse(): ";
	list->print();
	cout << endl;

	list->pop_front();
	cout << "Forward list after single pop_front(): ";
	list->print();
	cout << endl;

	int n = 3;
	Node<int>* val = list->find_n_th_from_end(n);
	if (val) {
		cout << n << "-th from the end element's value is " << val->value << "." << endl;
	}
	cout << endl;



	cout << "Checking if ";
	list->print();
	cout << " forward list is cycled." << endl;

	if (list->is_cycled()) {
		cout << "Forward list is cycled." << endl;
	}
	else {
		cout << "Forward list isn't cycled." << endl;
	}
	cout << endl;


	list->push_back(n_2);
	cout << "Checking if forward list is cycled after push_back(...) element which already exists in list." << endl;

	if (list->is_cycled()) {
		cout << "Forward list is cycled." << endl;
	}
	else {
		cout << "Forward list isn't cycled." << endl;
	}

	delete n_1, n_2, n_3, n_4, list;

}

int main() {
	checking_forward_list();
	return 0;
}