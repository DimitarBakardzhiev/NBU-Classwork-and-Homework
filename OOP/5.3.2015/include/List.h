#ifndef LIST_H
#define LIST_H

template <class T>
class List
{
    private:
        int count;
        T* sequence;
        int size;

        void copy(const List&);
        bool isFull() const;
    public:
        List();
        ~List();
        List(const List&);
        List& operator=(const List&);

        int getCount() const;
        T& operator[](int) const;
        void add(T);
};

#endif // LIST_H
