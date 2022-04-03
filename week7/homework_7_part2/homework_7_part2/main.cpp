#include <iostream>

using namespace std;

template <class T>
class CustomVector
{
private:
    int length;
    int size;
    T *items;
    
    void Resize()
    {
        int new_size = size * 2;
        T *new_items = new T[new_size];
        memcpy(new_items, items, size * sizeof(T));
        this->size = new_size;
        delete [] this->items;
        this->items = new_items;
    }
public:
    CustomVector() : length(0), size(1) {
        items = new T[this->size];
    }
    void Push(const T &value) {
        if(this->length + 1 > this->size)
            Resize();
        this->items[length++] = value;
    }
    const T Pop()
    {
        return this->items[--length];
    }
    void Delete(int index)
    {
        length--;
        for(int i = index; i < this->length; i++)
        {
            this->items[i] = this->items[i+1];
        }
    }
    void Insert(const T &value, int index)
    {
        length++;
        if(this->length + 1 > this->size)
            Resize();
        for(int i = length; i >= index + 1; i--)
        {
            this->items[i] = this->items[i-1];
        }
        this->items[index] = value;
    }
    
    void Sort(bool (*cmp)(const T item1, const T item2)=nullptr)
    {
        int k = 0;
        do{
            k = 0;
            for(int i = 0 ; i < this->length-1; i++)
            {
                if(cmp == nullptr)
                {
                    if(!(this->items[i] < this->items[i+1]))
                    {
                        T tmp = this->items[i+1];
                        items[i+1] = items[i];
                        items[i] = tmp;
                        k = 1;
                    }
                }
                else
                {
                    if((*cmp)(items[i], items[i+1]))
                    {
                        T tmp = items[i+1];
                        items[i+1] = items[i];
                        items[i] = tmp;
                        k = 1;
                    }
                }
            }
        }while(k == 1);
    }
    
    const T* Get(int index)
    {
        if(index < this->length)
        {
            return this->items[index];
        }
        return nullptr;
    }
    
    void Set(const T& value, int index)
    {
        if(index < this->length)
        {
            this->items = value;
        }
    }
    
    int Count()
    {
        return this->length;
    }
    
    int firstIndexOf(const T& value)
    {
        for(int i = 0; i < this->length; i++)
        {
            if(this->items[i] == value)
            {
                return i;
            }
        }
        return -1;
    }
};

/*
 Example for compare function:
 bool compare (int item1, int item2)
 {
     return item1 < item2;
 }
 */

int main(int argc, const char * argv[]) {
    CustomVector<int> my_int_custom_vector;
    my_int_custom_vector.Push(10);
    my_int_custom_vector.Push(9);
    my_int_custom_vector.Push(435);
    
    my_int_custom_vector.Sort();
    
    cout<<my_int_custom_vector.Pop()<<endl;
    
    cout<<my_int_custom_vector.firstIndexOf(10)<<endl;
    return 0;
}
