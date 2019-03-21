#include <iostream>
#include <vector>
using namespace std;

class DoublyLinkedListNode {
public:
	int data;
	DoublyLinkedListNode *next;
	DoublyLinkedListNode *prev;

	DoublyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

class DoublyLinkedList {
public:
	DoublyLinkedListNode *head;
	DoublyLinkedListNode *tail;

	DoublyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
			node->prev = this->tail;
		}

		this->tail = node;
	}
};

int main()	
{
	DoublyLinkedListNode *head = nullptr, *node=nullptr,*newNode;
	int arr[10] = { 111,312,65,79,6654,445,887,221,325,1000 };
	for (int i=0; i < 9; i++) 
	{
		
		if(head==nullptr) 
		{
			newNode = new DoublyLinkedListNode(arr[i]);
			head = newNode;
			head->prev = nullptr;
			newNode = new DoublyLinkedListNode(arr[i + 1]);
			head->next = newNode;
			node = head->next;
			node->prev = head;
		}
		else 
		{
			newNode = new DoublyLinkedListNode(arr[i + 1]);
			newNode->prev = node;
			node->next = newNode;
			node = newNode;
		}
	}
	DoublyLinkedListNode* nodeToDelete;
	vector<DoublyLinkedListNode*> nodeList;
	//removing nodes from the list and pushing them in to a vector
	for (int i = 0; i < 10; i++)
	{
		nodeToDelete = head;
		while (node != nullptr)
		{
			if (nodeToDelete->data > node->data)
			{
				nodeToDelete = node;
			}
			node = node->next;
		}
		if (nodeToDelete->prev != nullptr)
		{
			nodeToDelete->prev->next = nodeToDelete->next;
		}
		if (nodeToDelete->next != nullptr)
		{
			nodeToDelete->next->prev = nodeToDelete->prev;
		}
		nodeList.push_back(nodeToDelete);
		if (head == nodeToDelete)
		{
			head = nodeToDelete->next;
		}
		node = head;
	}
	
	for (int i = 0; i < nodeList.size(); i++) 
	{
		cout << nodeList[i]->data << "\n";
	}

	/*while (node != nullptr)
	{
		cout << node->data<<"\n";
		node = node->next;
	}*/
	getchar();
	return 0;
}