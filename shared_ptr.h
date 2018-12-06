#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_SHARED_PTR_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_SHARED_PTR_H

#include <stddef.h>
#include <stdlib.h>
#include <iostream>//cout

template<typename T>
class shared_ptr
{
public:

    explicit shared_ptr(T* ptr = NULL);
    ~shared_ptr();

    shared_ptr(shared_ptr const&);
    shared_ptr& operator=(const shared_ptr &);



    T* operator->()const;
    T& operator*()const;
    operator bool()const;

    bool operator==(const shared_ptr& ptr)const;
    bool operator!=(const shared_ptr& ptr)const;

    bool isvalid()const;
    T* get()const;

private:

    T*   m_ptr;
    int *refCount;
};

template<typename T>
shared_ptr<T>::shared_ptr(T* ptr) : m_ptr(ptr)
{
    if(ptr)
      refCount = new int [1];

    else
        refCount = NULL;
}


template<typename T>
shared_ptr<T>::~shared_ptr()
{
    if(isvalid())
    {
        --(*refCount);
        if((*refCount) <= 0)
        {
            delete refCount;
            delete m_ptr;
        }

        refCount = NULL;
        m_ptr = NULL;
    }
}


template<typename T>
shared_ptr<T>::shared_ptr(shared_ptr const& ptr) : refCount(ptr.refCount), m_ptr(ptr.m_ptr)
{
    if(isvalid())
        (*refCount)++;
}

template<typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr& ptr)
{
    shared_ptr<T>  temp(ptr);
    temp.swap(*this);
    return *this;
}

template<typename T>
T & shared_ptr<T>::operator* ()const
{
    return *m_ptr;
}

template<typename T>
T * shared_ptr<T>::operator-> ()const
{
    return m_ptr;
}

template<typename T>
T* shared_ptr<T>::get() const
{
    return m_ptr;
}

template<typename T>
shared_ptr<T>::operator bool()const
{
    return m_ptr;
}

template<typename T>
bool shared_ptr<T>::isvalid()const
{
    return (m_ptr != NULL && refCount != NULL);
}

template<typename T>
bool shared_ptr<T>::operator==(const shared_ptr& ptr)const
{
    return (m_ptr == ptr.m_ptr && refCount == ptr.refCount);
}

template<typename T>
bool shared_ptr<T>::operator!=(const shared_ptr& ptr)const
{
    return !(this == ptr);
}

#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_SHARED_PTR_H
