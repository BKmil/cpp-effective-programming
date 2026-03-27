#include <vector>
#include <string>
#include <iostream>

template<typename T, typename E>
CResult<T, E>::CResult(const T& cValue)
    : pcValue(new T(cValue)) {}

template<typename T, typename E>
CResult<T, E>::CResult(E* pcError)
    : pcValue(NULL) {
    if (pcError)
        vErrors.push_back(pcError);
}

template<typename T, typename E>
CResult<T, E>::CResult(std::vector<E*>& errors)
    : pcValue(NULL) {
    for (std::size_t i = 0; i < errors.size(); ++i) {
        vErrors.push_back(new E(*errors[i]));
    }
}

template<typename T, typename E>
CResult<T, E>::CResult(const CResult& cOther)
    : pcValue(NULL) {
    if (cOther.bIsSuccess()) {
        pcValue = new T(cOther.cGetValue());
    }

    for (std::size_t i = 0; i < cOther.vGetErrors().size(); ++i) {
        vErrors.push_back(new E(*cOther.vGetErrors()[i]));
    }
}

/*
template<typename T, typename E>
template<typename TOther>
CResult<T, E>::CResult(const CResult<TOther, E>& cOther)
    : pcValue(NULL)
{
    if (isSame<E, std::string>::value) {
        if (!isSame<T, TOther>::value) {
            for (std::size_t i = 0; i < cOther.vGetErrors().size(); ++i) {
                vErrors.push_back(new E(*cOther.vGetErrors()[i]));
            }

            vErrors.push_back(new E("Result: type mismatch"));
            return;
        }
    }

    if (cOther.bIsSuccess()) {
        pcValue = new T(cOther.cGetValue());
    }

    for (std::size_t i = 0; i < cOther.vGetErrors().size(); ++i) {
        vErrors.push_back(new E(*cOther.vGetErrors()[i]));
    }
}
*/

template<typename T, typename E>
CResult<T, E>::~CResult() {
    delete pcValue;
    for (std::size_t i = 0; i < iErrorsSize(); ++i) {
        delete vErrors[i];
    }
}

template<typename T, typename E>
CResult<T, E>& CResult<T, E>::operator=(const CResult& cOther) {
    if (this == &cOther) {
        return *this;
    }
    delete pcValue;
    pcValue = NULL;
    for (std::size_t i = 0; i < vErrors.size(); ++i) {
        delete vErrors[i];
    }
    vErrors.clear();
    if (cOther.bIsSuccess()) {
        pcValue = new T(*cOther.cGetValue());
    }
    for (std::size_t i = 0; i < cOther->iErrorsSize; ++i) {
        vErrors.push_back(new E(*cOther.vGetErrors()[i]));
    }
    return *this;
}

template<typename T, typename E>
CResult<T, E> CResult<T, E>::cOk(const T& cValue) {
    return CResult(cValue);
}

template<typename T, typename E>
CResult<T, E> CResult<T, E>::cFail(E* pcError) {
    return CResult(pcError);
}

template<typename T, typename E>
CResult<T, E> CResult<T, E>::cFail(const std::vector<E*>& errors) {
    return CResult(errors);
}

template<typename T, typename E>
bool CResult<T, E>::bIsSuccess() const { return pcValue != NULL; }

template<typename T, typename E>
T CResult<T, E>::cGetValue() const { return *pcValue; }

template<typename T, typename E>
const std::vector<E*>& CResult<T, E>::vGetErrors() const { return vErrors; }

template<typename T, typename E>
int CResult<T, E>::iErrorsSize() const { return vErrors.size(); }

// VOID SPECIALIZATION

template <typename E>
CResult<void, E>::CResult() {}

template <typename E>
CResult<void, E>::CResult(E* pcError) {
    if (pcError != NULL) {
        vErrors.push_back(pcError);
    }
}

template <typename E>
CResult<void, E>::CResult(std::vector<E*>& vErrors) {
    this->vErrors = vErrors;
}

template <typename E>
CResult<void, E>::CResult(const CResult<void, E>& cOther) {
    vErrors = cOther.vGetErrors();
}

template <typename E>
CResult<void, E>::~CResult() {}

template <typename E>
CResult<void, E> CResult<void, E>::cOk() {
    return CResult();
}

template <typename E>
CResult<void, E> CResult<void, E>::cFail(E* pcError) {
    return CResult(pcError);
}

template <typename E>
CResult<void, E> CResult<void, E>::cFail(std::vector<E*>& vErrors) {
    return CResult(vErrors);
}

template <typename E>
CResult<void, E>& CResult<void, E>::operator=(const CResult<void, E>& cOther) {
    if (this != &cOther) {
        vErrors = cOther.vGetErrors();
    }
    return *this;
}

template <typename E>
bool CResult<void, E>::bIsSuccess() const {
    return vErrors.empty();
}

template <typename E>
const std::vector<E*>& CResult<void, E>::vGetErrors() const {
    return vErrors;
}

// TODO

template <typename E>
CResult<std::string, E> CResult<char*, E>::cOk(const char* cValue) {
    return CResult<std::string, E>(cValue);
}

template <typename E>
CResult<std::string, E> CResult<char*, E>::cFail(E* pcError) {
    return CResult<std::string, E>(pcError);
}

template <typename E>
CResult<std::string, E> CResult<char*, E>::cFail(std::vector<E*>& vErrors) {
    return CResult<std::string, E>(vErrors);
}