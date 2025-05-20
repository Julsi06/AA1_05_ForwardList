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
	if (IsEmpty())
	{
		return;
	}
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
	if (IsEmpty())
	{
		return;
	}
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
	return m_first->m_value;
}

int ForwardList::Back() const
{
	return m_last->m_value;
}

int ForwardList::Size() const
{
	return m_size;
}

void ForwardList::Erase(int value)
{
	
}

void ForwardList::Insert(int value, int position)
{

}

void ForwardList::PushBackAverageNode()
{

}