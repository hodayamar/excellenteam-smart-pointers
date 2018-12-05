#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_S_PTR_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_S_PTR_H

#include <stddef.h>
#include <stdlib.h>
#include <iostream>//cout

template<typename T>
class UniquePtr
{
public:

    explicit UniquePtr(T* ptr = NULL);
    ~UniquePtr();

    T* operator->() const;
    T& operator*()  const;
    T& operator = (T*);
    operator bool();

    T* get() const;

private:
    // Prevent coping
    UniquePtr(UniquePtr const&);
    UniquePtr& operator=(UniquePtr const&);

    T*   m_ptr;
};

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr ):m_ptr(ptr)
{

//    if (!ptr)
//        throw std::invalid_argument();
}

template<typename T>
UniquePtr<T>::~UniquePtr()
{
    delete m_ptr;
}

template<typename T>
T & UniquePtr<T>::operator* ()const
{
    return *m_ptr;
}

template<typename T>
T * UniquePtr<T>::operator-> ()const
{
    return m_ptr;
}

template<typename T>
T* UniquePtr<T>::get() const
{
    return m_ptr;
}

template<typename T>
UniquePtr<T>::operator bool()
{
    return m_ptr;
}
#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_S_PTR_H

