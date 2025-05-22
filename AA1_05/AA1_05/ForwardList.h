#pragma once
#include <iostream>
class ForwardList
{
private:
	struct Node
	{
		int m_value;
		Node* m_next;
		Node() : m_value(0), m_next(nullptr) {};
		Node(int value, Node* next) : m_value(value), m_next(next) {};
	};

	// Pointer to first element in the list
	Node* m_first;

	// Pointer to last element in the list
	Node* m_last;

	// Size of the list
	int m_size;

public:
	// Constructor
	ForwardList();

	// Destructor
	~ForwardList();

	// Inserts one element at the back of the list
	void PushBack(int value);

	// Removes last element at the back of the list
	void PopBack();

	// Inserts one element at the front of the list
	void PushFront(int value);

	// Removes first element at the front of the list
	void PopFront();

	// Checks if the list is empty or not
	bool IsEmpty() const;

	// Returns the element at the front of the list
	int Front() const;

	// Returns the element at the back of the list
	int Back() const;

	// Returns the size of the list
	int Size() const;

	// Removes all the elements from the list that are equal to value
	void Erase(int value);

	// Inserts the element with value at a specific position within the list
	void Insert(int value, int position);

	// Pushes back a new node whose value is the average of all the nodes values in the list
	void PushBackAverageNode();

	// Compares de content of lists l1 and l2. Returns true if both are equal, false otherwise.
	friend bool operator==(const ForwardList& l1, const ForwardList& l2);

	// Concatenates nodes with the provided list l and returns the resulting list.
	ForwardList operator+(const ForwardList& l);

	// Outputs the elements of the list into an output stream object
	friend std::ostream& operator<<(std::ostream& o, const ForwardList& l);
};
