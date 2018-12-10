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

    shared_ptr(const shared_ptr &);
    shared_ptr& operator=(const shared_ptr &);
    shared_ptr& operator=(T*);//Todo

    T* operator->()const;
    T& operator*()const;
    operator bool()const;

    bool operator==(const shared_ptr& ptr)const;
    bool operator!=(const shared_ptr& ptr)const;


    bool isvalid()const;
    T* get()const;
    size_t * get_ref_counter();

    template<typename U>
    shared_ptr(const shared_ptr<U>& ptr);

    template<typename U>
    friend class shared_ptr;


private:

    size_t *refCount;
    T*   m_ptr;
    void delete_last_ptr();
    void swap(shared_ptr& other);
};


template<typename T>
shared_ptr<T>::shared_ptr(T* ptr)try
    :refCount (new size_t (1)),
     m_ptr(ptr)
{}
catch(std::bad_alloc& e)
{
    delete ptr;
    throw; // throw the same exception that we get.
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
shared_ptr<T>::shared_ptr(const shared_ptr& ptr)
   :refCount(ptr.refCount),
    m_ptr(ptr.m_ptr)
{
    std::cout << "template<typename T>cpytor" << std::endl;

    if(isvalid())
        (*refCount)++;
}

template<typename T>
template<typename U>
shared_ptr<T>::shared_ptr(const shared_ptr<U>& ptr)
        :refCount(ptr.refCount),
         m_ptr(ptr.m_ptr)
{
    std::cout << "template<typename U>cpytor" << std::endl;
    if(isvalid())
        (*refCount)++;
}



template<typename T>
void shared_ptr<T>::swap(shared_ptr& other)
{
    std::swap(m_ptr,other.m_ptr);
    std::swap(refCount,other.refCount);
}

template<typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr& ptr)
{
    //for ctor
    shared_ptr<T> temp(ptr);
    swap(temp);
    return *this;
}


template<typename T>
inline T & shared_ptr<T>::operator* ()const
{
    return *m_ptr;
}


template<typename T>
inline T * shared_ptr<T>::operator-> ()const
{
    return m_ptr;
}


template<typename T>
inline T* shared_ptr<T>::get() const
{
    return m_ptr;
}


template<typename T>
inline shared_ptr<T>::operator bool()const
{
    return m_ptr;
}


template<typename T>
inline bool shared_ptr<T>::isvalid()const
{
    return (m_ptr != NULL && refCount != NULL);
}


template<typename T>
inline bool shared_ptr<T>::operator==(const shared_ptr& ptr)const
{
    return (m_ptr == ptr.m_ptr && refCount == ptr.refCount);
}


template<typename T>
inline bool shared_ptr<T>::operator!=(const shared_ptr& ptr)const
{
    return (m_ptr != ptr.m_ptr);
}

template<typename T>
inline size_t * shared_ptr<T>::get_ref_counter()
{
    return refCount;
}


#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_SHARED_PTR_H
