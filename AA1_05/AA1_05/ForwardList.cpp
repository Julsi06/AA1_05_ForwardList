#include "ForwardList.h"

ForwardList::ForwardList()
{
	m_first = nullptr;
	m_last = nullptr;
	m_size = 0;
}

ForwardList::~ForwardList()
{

}

void ForwardList::PushBack(int value)
{
	Node* newNode = new Node(value, nullptr);
	if (IsEmpty())
	{
		m_first = newNode;
		m_last = newNode;
	}
	else
	{
		m_last->m_next = newNode;
		m_last = newNode;
	}
	++m_size;
}

void ForwardList::PopBack()
{
	if (IsEmpty()) return;
	if (m_first == m_last)
	{
		delete m_first;
		m_first = nullptr;
		m_last = nullptr;
	}
	else
	{
		Node* nodeToRemove = m_last;
		while (nodeToRemove->m_next != m_last)
		{
			nodeToRemove = nodeToRemove->m_next;
		}
		delete m_last;
		m_last = nodeToRemove;
		m_last->m_next = nullptr;
	}
	--m_size;
}

void ForwardList::PushFront(int value)
{
	Node* newNode = new Node(value, nullptr);
	if (IsEmpty())
	{
		m_first = newNode;
		m_last = newNode;
	}
	else
	{
		Node* nextNode = m_last;
		m_first = newNode;
		m_first->m_next = nextNode;
	}
	++m_size;
}

void ForwardList::PopFront()
{
	if (IsEmpty()) return;
	if (m_first == m_last)
	{
		delete m_first;
		m_first = nullptr;
		m_last = nullptr;
	}
	else
	{
		Node* nextNode = m_first;
		delete m_first;
		m_first = nextNode;
	}
	--m_size;
}

bool ForwardList::IsEmpty() const
{
	return m_size == 0;
}

int ForwardList::Front() const
{
	if (IsEmpty()) throw std::runtime_error("List is empty");
	return m_first->m_value;
}

int ForwardList::Back() const
{
	if (IsEmpty()) throw std::runtime_error("List is empty");
	return m_last->m_value;
}

int ForwardList::Size() const
{
	return m_size;
}

void ForwardList::Erase(int value)
{
	Node* currNode = m_first;
	Node* prevNode = nullptr;
	while (currNode != nullptr)
	{
		if (currNode->m_value == value)
		{
			Node* nodeToRemove = currNode;
			if (currNode == m_first)
			{
				m_first = currNode->m_next;
				if (currNode == m_last) m_last = nullptr;
			}
			else
			{
				prevNode->m_next = currNode->m_next;
				if (currNode == m_last) m_last = prevNode;
			}
			currNode = currNode->m_next;
			delete nodeToRemove;
			--m_size;
		}
		else
		{
			prevNode = currNode;
			currNode = currNode->m_next;
		}
	}
}

void ForwardList::Insert(int value, int position)
{
	if (position <= 0) PushFront(value);
	else if (position >= m_size) PushBack(value);
	else
	{
		Node* tempNode = m_first;
		for (int i = 0;i < position - 1;++i)
		{
			tempNode = tempNode->m_next;
		}
		Node* newNode = new Node(value, tempNode->m_next);
		tempNode->m_next = newNode;
		++m_size;
	}
}

void ForwardList::PushBackAverageNode()
{
	int sum = 0;
	Node* tempNode = m_first;
	for (int i = 0;i < m_size;++i)
	{
		sum += tempNode->m_value;
		tempNode = tempNode->m_next;
	}
	int avg = sum / m_size;
	PushBack(avg);
	++m_size;
}

bool operator==(const ForwardList& l1, const ForwardList& l2)
{

}

ForwardList ForwardList::operator+(const ForwardList& l)
{

}

std::ostream& operator<<(std::ostream& o, const ForwardList& l)
{

}