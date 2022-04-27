#include "sequential-list.h"
#include <iostream>
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType[cap];
    size_ = 0;
    capacity_ = cap;
}

SequentialList::~SequentialList()
{
    delete data_;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
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

bool SequentialList::full() const
{
    if(size_ == capacity_)
    {
        return true;
    }
    else
    {
        return false;
    }
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if(size_ == 0)
    {
        return data_[0];
    }
    else if(index >= size_)
    {
        return data_[size_-1];
    }
    else
    {
        return data_[index];
    }
}

unsigned int SequentialList::search(DataType val) const
{
    for (int index = 0; index < size_; index++)
    {
        if (data_[index] == val)
        {
            return index;
        }
    }

    return size_;
}

void SequentialList::print() const
{
    for(int index = NULL; index < size_; index++)
    {
        cout << data_[index] << endl;
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if(size_ == capacity_ || index > size_)
    {
        return false;
    }
    else
    {
        size_++;

        for(int count = size_-1; count > index; count--)
        {
            data_[count] = data_[count-1];
        }

        data_[index] = val;

        return true;
    }
}

bool SequentialList::insert_front(DataType val)
{
    if(size_ == capacity_)
    {
        return false;
    }
    else
    {
        size_++;

        for(int count = size_-1; count > 0; count--)
        {
            data_[count] = data_[count-1];
        }

        data_[0] = val;

        return true;
    }
}

bool SequentialList::insert_back(DataType val)
{
    if(size_ == capacity_)
    {
        return false;
    }
    else
    {
        size_++;

        data_[size_-1] = val;

        return true;
    }
}

bool SequentialList::remove(unsigned int index)
{
    if(size_ == 0 || index > size_)
    {
        return false;
    }
    else
    {
        for(int count = index; count < size_; count++)
        {
            data_[count] = data_[count+1];
        }

        size_--;

        return true;
    }
}

bool SequentialList::remove_front()
{
    if(size_ == 0)
    {
        return false;
    }
    else
    {
        for(int count = 0; count < size_; count++)
        {
            data_[count] = data_[count+1];
        }

        size_--;

        return true;
    }
}

bool SequentialList::remove_back()
{
    if(size_ == 0)
    {
        return false;
    }
    else
    {
        size_--;

        return true;
    }
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if(data_[index] == NULL)
    {
        return false;
    }
    else
    {
        data_[index] = val;

        return true;
    }
}