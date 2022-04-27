#include "doubly-linked-list.h"
#include <iostream>

DoublyLinkedList::Node::Node(DataType data)
{
    value = data;
    next = NULL;
    prev = NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    int count = 0;
    Node* current = head_;

    while(current != NULL)
    {
        current = current -> next;
        delete head_;
        head_ = current;

        count++;
    }

    head_ =  NULL;
    size_ = 0;
}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    if(size_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DoublyLinkedList::full() const
{
    if(size_ == CAPACITY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    if(size_ == 0)
    {
        return tail_ -> value;
    }
    else if(index >= size_)
    {
        return tail_ -> value;
    }
    else
    {
        int count = 0;
        Node* current = head_;

        while(count < index)
        {
            current = current -> next;

            count++;
        }

        return current -> value;
    }
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    int index = 0;
    Node* current = head_;

    while(index < size_)
    {
        if(current -> value == value)
        {
            return index;
        }

        current = current -> next;

        index++;
    }

    return size_;
}

void DoublyLinkedList::print() const
{
    int index = 0;
    Node* current = head_;

    while(index < size_)
    {
        current = current -> next;

        index++;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    if(index >= size_ || index < 0)
    {
        return NULL;
    }
    else
    {
        Node* current = head_;

        for(int count = 0; count < index; count++)
        {
            current = current -> next;
        }

        return current;
    }
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    Node* newNode = new Node(value);

    if(size_ >= CAPACITY || index > size_)
    {
        return false;
    }
    else if(size_ == 0)
    {
        head_ = newNode;
        tail_ = newNode;

        size_++;

        return true;
    }
    else if(index == size_)
    {
        insert_back(value);

        return true;
    }
    else if(index == 0)
    {
        insert_front(value);

        return true;
    }
    else
    {
        Node* current = getNode(index);

        newNode -> next = current;
        newNode -> prev = current ->  prev;
        current -> prev -> next = newNode;
        current -> prev = newNode;

        size_++;

        return true;
    }
}

bool DoublyLinkedList::insert_front(DataType value)
{
    Node* newNode = new Node(value);

    if(size_ == CAPACITY)
    {
        return false;
    }
    else if(size_ == 0)
    {
        head_ = newNode;
        tail_ = newNode;

        size_++;

        return true;
    }
    else
    {
        head_ -> prev = newNode;
        newNode -> next = head_;
        head_ = newNode;

        size_++;

        return true;
    }
}

bool DoublyLinkedList::insert_back(DataType value)
{
    Node* newNode = new Node(value);

    if(size_ == CAPACITY)
    {
        return false;
    }
    else if(size_ == 0)
    {
        head_ = newNode;
        tail_ = newNode;

        size_++;

        return true;
    }
    else
    {
        newNode -> prev = tail_;
        tail_ -> next = newNode;
        tail_ = newNode;

        size_++;

        return true;
    }
}

bool DoublyLinkedList::remove(unsigned int index)
{
    if(size_ == 0 || index > size_)
    {
        return false;
    }
    else if(index == size_-1)
    {
        remove_back();

        return true;
    }
    else if(index == 0)
    {
        remove_front();

        return true;
    }
    else
    {
        Node* current = getNode(index);

        current -> prev -> next = current -> next;
        current -> next -> prev = current -> prev;

        delete current;

        size_--;

        return true;
    }
}

bool DoublyLinkedList::remove_front()
{
    if(size_ == 0)
    {
        return false;
    }
    if(size_ == 1)
    {
        head_ = NULL;
        tail_ = NULL;

        delete head_;

        size_--;

        return true;
    }
    else
    {
        Node* current = head_;

        head_ = current -> next;
        head_ -> prev = NULL;

        delete current;

        size_--;

        return true;
    }
}

bool DoublyLinkedList::remove_back()
{
    if(size_ == 0)
    {
        return false;
    }
    if(size_ == 1)
    {
        head_ = NULL;
        tail_ = NULL;

        delete head_;

        size_--;

        return true;
    }
    else
    {
        Node* current = tail_;

        tail_ = current -> prev;
        tail_ -> next = NULL;

        delete current;

        size_--;

        return true;
    }
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if(size_ == 0 || index > size_)
    {
        return false;
    }
    else
    {
        int count = 0;
        Node *current = head_;

        while (count < index) {
            current = current->next;

            count++;
        }

        current->value = value;

        return true;
    }
}