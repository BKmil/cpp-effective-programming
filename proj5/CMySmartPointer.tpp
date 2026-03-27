template<typename T>
std::unordered_map<T*, CRefCounter*> CMySmartPointer<T>::registry{};

template<typename T>
CMySmartPointer<T>::CMySmartPointer(T *pcPointer) {
    if (registry.count(pcPointer) == 0) {
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
        registry[pcPointer] = pc_counter;
    }
    else {
        pc_pointer = pcPointer;
        pc_counter = registry[pcPointer];
        pc_counter->iAdd();
    }
}

template<typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer &other) {
    pc_pointer = other.pc_pointer;
    pc_counter = other.pc_counter;
    pc_counter->iAdd();
}

template<typename T>
CMySmartPointer<T>::~CMySmartPointer() {
    if (pc_counter->iDec() == 0) {
        delete pc_counter;
        delete pc_pointer;
    }
}

template<typename T>
CMySmartPointer<T> &CMySmartPointer<T>::operator=(const CMySmartPointer &other) {
    if (this != &other) {
        if (pc_counter && pc_counter->iDec() == 0) {
            delete pc_counter;
            delete pc_pointer;
        }
        pc_pointer = other.pc_pointer;
        pc_counter = other.pc_counter;
        pc_counter->iAdd();
    }
    return *this;
}

template<typename T>
T &CMySmartPointer<T>::operator*() const {
    return *pc_pointer;
}

template<typename T>
T *CMySmartPointer<T>::operator->() const {
    return pc_pointer;
}
