#pragma once

#include <vector>

template <typename T, typename E>
class CResult {
public:
    CResult(const T& cValue);
    CResult(E* pcError);
    CResult(std::vector<E*>& errors);
    CResult(const CResult& cOther);

    // template<typename TOther>
    // CResult(const CResult<TOther, E>& cOther);

    ~CResult();

    static CResult cOk(const T& cValue);
    static CResult cFail(E* pcError);
    static CResult cFail(const std::vector<E*>& vErrors);

    CResult& operator=(const CResult& cOther);

    bool bIsSuccess() const;

    T cGetValue() const;
    const std::vector<E*>& vGetErrors() const;

    int iErrorsSize() const;

private:
    T* pcValue;
    std::vector<E*> vErrors;
};

template <typename E>
class CResult<void, E>
{
public:
    CResult();
    CResult(E *pcError);
    CResult(std::vector<E*>& vErrors);
    CResult(const CResult& cOther);

    ~CResult();

    static CResult cOk();
    static CResult cFail(E* pcError);
    static CResult cFail(std::vector<E*>& vErrors);

    CResult& operator=(const CResult& cOther);

    bool bIsSuccess() const;
    const std::vector<E*>& vGetErrors() const;
private:
    std::vector<E*> vErrors;
};

template <typename E>
class CResult<char*, E>
{
public:
    static CResult<std::string, E> cOk(const char* cValue);
    static CResult<std::string, E> cFail(E* pcError);
    static CResult<std::string, E> cFail(std::vector<E*>& vErrors);

private:
    CResult();
};

#include "CResult.tpp"