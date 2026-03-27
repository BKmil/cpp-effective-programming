#pragma once

#include "CRefCounter.h"
#include <unordered_map>

template<typename T>
class CMySmartPointer {
    public:
    CMySmartPointer(T *pcPointer = nullptr);
    CMySmartPointer(const CMySmartPointer& other);
    ~CMySmartPointer();

    CMySmartPointer &operator=(const CMySmartPointer& other);

    T &operator*() const;
    T *operator->() const;

    private:
    static std::unordered_map<T*, CRefCounter*> registry;
    CRefCounter *pc_counter;
    T *pc_pointer;
};

#include "CMySmartPointer.tpp"