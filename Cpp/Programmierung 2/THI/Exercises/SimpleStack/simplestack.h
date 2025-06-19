#ifndef SIMPLESTACK1_T
#define SIMPLESTACK1_T

template <typename T>

class SimpleStack1 {

public:
    static const int maxSize{20};
    bool empty() const {
        return number == 0; 
    }
    bool full() const {
        return number == maxSize; 
    }
    auto size() const {
        return number;
    }
    void clear() {
        number = 0;
    }
    const T& top() const;
    void pop();
    void push(const T& x) const;

private:
    int number{0};
    T array[maxSize];

};

template <typename T>

const T& SimpleStack1<T>() const {
    return array[number -1];
}

template <typename T>
void SimpleStack1<T>::pop() {
    --number;
}


template <typename T>

void SimpleStack1<T>::push(const T& x) {
    array[number++] = x;
}

#endif // SIMPLESTACK1_T