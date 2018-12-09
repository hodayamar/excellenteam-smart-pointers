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
    shared_ptr& operator=(shared_ptr &);

    T* operator->()const;
    T& operator*()const;
    operator bool()const;

    bool operator==(shared_ptr& ptr)const;
    bool operator!=(shared_ptr& ptr)const;

    bool isvalid()const;
    T* get()const;
    int * get_ref_counter();

private:

    void delete_last_ptr();

    int *refCount;
    T*   m_ptr;
};


template<typename T>
shared_ptr<T>::shared_ptr(T* ptr) : m_ptr(ptr)
{
    if(ptr)
    {
        refCount = new int [1];
        *refCount = 1;
    }

    else
        refCount = NULL;
}


template<typename T>
void shared_ptr<T>::delete_last_ptr()
{
    if((*refCount) <= 0)
    {
        std::cout << "Last ptr" << std::endl;
        delete refCount;
        delete m_ptr;
    }
}


template<typename T>
shared_ptr<T>::~shared_ptr()
{

    if(isvalid())
    {
        --(*refCount);

        shared_ptr<T>::delete_last_ptr();

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
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr& ptr)
{
    //for ctor
    shared_ptr<T> temp(ptr);

    //for dtor
    temp.refCount = refCount;
    temp.m_ptr = m_ptr;

    m_ptr = ptr.m_ptr;
    refCount = ptr.refCount;

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
bool shared_ptr<T>::operator==(shared_ptr& ptr)const
{
    return (m_ptr == ptr.m_ptr && refCount == ptr.refCount);
}


template<typename T>
bool shared_ptr<T>::operator!=(shared_ptr& ptr)const
{
    return (m_ptr != ptr.m_ptr);
}

template<typename T>
int * shared_ptr<T>::get_ref_counter()
{
    return refCount;
}
#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_SHARED_PTR_H
