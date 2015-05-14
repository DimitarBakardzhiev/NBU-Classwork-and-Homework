#ifndef _SET_H_
#define _SET_H_

template<typename T>
class Set
{
private:
	T* data;
	unsigned size;
	unsigned count;

        void extend();
        
public:
	Set();
	Set(const Set&);
	virtual ~Set();
        
        bool contains(T) const;
        bool isEmpty() const;
        
        void add(T);
        void remove(T);
};

#endif // _SET_H_