#include <iostream>
#include<string>
#include "forward_list.h"
using namespace std;

template class Forward_List<int>;
template class Forward_List<double>;
template class Forward_List<float>;
//template class Forward_List<bool>;
//template class Forward_List<string>;



using namespace std;

template <typename T>
Forward_List<T>::Forward_List() : head(nullptr) {};

template <typename T>
void Forward_List<T>::add_front(Node<T>* item) {
	item->next = head;
	head = item;
}
template <typename T>
void Forward_List<T>::pop_front() {
	head = head->next;
}
template <typename T>
void Forward_List<T>::push_back(Node<T>* item) {
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
template <typename T>
void Forward_List<T>::pop_back() {
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
template <typename T>
void Forward_List<T>::insert(int position, Node<T>* item) {
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
template <typename T>
void Forward_List<T>::reverse() {
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
template <typename T>
Node<T>* Forward_List<T>::find_n_th_from_end(int n) {
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
template <typename T>
bool Forward_List<T>::is_cycled() {
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
template <typename T>
T Forward_List<T>::last() {
	Node<T>* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	return temp->value;
}
template <typename T>
T Forward_List<T>::first() {
	return head->value;
}
template <typename T>
void Forward_List<T>::buble_sort() {
	bool sorted = true;
	Node<T>* temp_1 = head;
	while (true) {
		if (head->value > head->next->value) {
			temp_1 = temp_1->next;
			head->next = temp_1->next;
			temp_1->next = head;
			head = temp_1;
			//sorted = false;
		}
		temp_1 = head;
		while (temp_1->next->next != nullptr) {
			if (temp_1->next->value > temp_1->next->next->value) {
				sorted = false;
				Node<T>* temp_3 = temp_1->next->next;
				temp_1->next->next = temp_3->next;
				temp_3->next = temp_1->next;
				temp_1->next = temp_3;
			}
			temp_1 = temp_1->next;
		}
		if (sorted) {
			break;
		}
		temp_1 = head;
		sorted = true;
	}

}
template <typename T>
void Forward_List<T>::print() {
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

template <typename T>
void Stack<T>::push(Node<T>* item) {
	this->push_back(item);
}
template <typename T>
void Stack<T>::pop() {
	this->pop_back();
}
template <typename T>
T Stack<T>::top() {
	return this->last();
}

template <typename T>
void Queue<T>::enqueue(Node<T>* item) {
	this->add_front(item);
}
template <typename T>
void Queue<T>::pop() {
	this->pop_back();
}
template <typename T>
T Queue<T>::front() {
	return this->first();
}
template <typename T>
T Queue<T>::back() {
	return this->last();
}

//void checking_forward_list();
//void check_stack_and_queue();


int main() {
	/*checking_forward_list();
	check_stack_and_queue();*/

	Node<int>* n_1 = new Node<int>;
	n_1->value = 7;
	Node<int>* n_2 = new Node<int>;
	n_2->value = 11;
	Node<int>* n_3 = new Node<int>;
	n_3->value = 18;
	Node<int>* n_4 = new Node<int>;
	n_4->value = 89;
	Node<int>* n_5 = new Node<int>;
	n_5->value = 12;

	Forward_List<int>* list = new Forward_List<int>;
	list->push_back(n_1);
	list->push_back(n_2);
	list->push_back(n_4);
	list->push_back(n_5);
	list->push_back(n_3);
	list->print();
	cout << endl;
	list->buble_sort();
	list->print();
	return 0;
}




//void checking_forward_list() {
//	Node<int>* n_1 = new Node<int>;
//	n_1->value = 7;
//
//	Node<int>* n_2 = new Node<int>;
//	n_2->value = 11;
//	Node<int>* n_3 = new Node<int>;
//	n_3->value = 18;
//	Node<int>* n_4 = new Node<int>;
//	n_4->value = 89;
//
//	Forward_List<int>* list = new Forward_List<int>;
//	list->push_back(n_1);
//	list->push_back(n_2);
//	list->push_back(n_3);
//	list->push_back(n_4);
//	cout << "Forward list after push_back(...) 4 times: ";
//	list->print();
//	cout << endl;
//
//	list->pop_back();
//	cout << "Forward list after single pop_back(): ";
//	list->print();
//	cout << endl;
//
//
//	list->insert(2, n_4);
//	cout << "Forward list after insert(2, ...): ";
//	list->print();
//	cout << endl;
//
//	list->reverse();
//	cout << "Forward list after reverse(): ";
//	list->print();
//	cout << endl;
//
//	list->pop_front();
//	cout << "Forward list after single pop_front(): ";
//	list->print();
//	cout << endl;
//
//	int n = 3;
//	Node<int>* val = list->find_n_th_from_end(n);
//	if (val) {
//		cout << n << "-th from the end element's value is " << val->value << "." << endl;
//	}
//	cout << endl;
//
//
//
//	cout << "Checking if ";
//	list->print();
//	cout << " forward list is cycled." << endl;
//
//	if (list->is_cycled()) {
//		cout << "Forward list is cycled." << endl;
//	}
//	else {
//		cout << "Forward list isn't cycled." << endl;
//	}
//	cout << endl;
//
//	cout << "End: " << list->last() << endl;
//
//	list->push_back(n_2);
//	cout << "Checking if forward list is cycled after push_back(...) element which already exists in list." << endl;
//
//	if (list->is_cycled()) {
//		cout << "Forward list is cycled." << endl;
//	}
//	else {
//		cout << "Forward list isn't cycled." << endl;
//	}
//
//	delete n_1, n_2, n_3, n_4, list;
//
//}
//
//void check_stack_and_queue() {
//	Node<int>* node = new Node<int>();
//	node->value = 27;
//
//	Node<int>* n_1 = new Node<int>;
//	n_1->value = 64;
//
//	Node<int>* n_2 = new Node<int>;
//	n_2->value = 158;
//
//	Stack<int>* stack = new Stack<int>();
//
//	cout << "Stack:" << endl;
//	stack->push(node);
//	cout << "Top after push(...) 27: " << stack->top() << endl;
//	stack->push(n_1);
//	cout << "Top after push(...) 64: " << stack->top() << endl;
//	stack->pop();
//	cout << "Top after pop(): " << stack->top() << endl;
//	cout << "-----------------" << endl;
//
//	cout << "Queue after push(...) 27 then 64 then 158:" << endl;
//	Queue<int>* queue = new Queue<int>();
//	queue->enqueue(node);
//	queue->enqueue(n_1);
//	queue->enqueue(n_2);
//
//	cout << "Front: " << queue->front() << endl;
//	cout << "Back: " << queue->back() << endl;
//	queue->pop();
//
//
//	cout << "Queue after pop():" << endl;
//	cout << "Front: " << queue->front() << endl;
//	cout << "Back: " << queue->back() << endl;
//}