#include <algorithm>
template <typename object>
class vector
{
    public:
    explicit vector(int initsize = 0):thesize{initsize},
    thecapacity{initsize+spare_capacity}
    {
        objects = new object[thecapacity];
    }
    vector (const vector & rhs):thesize{rhs.thesize},
    thecapacity{ rhs.thecapacity },objects{ nullptr }
    {
        objects = new object[thecapacity];
        for (int k = 0; k < thesize;++k)
            object[k] = rhs.objects[k];
    }
    vector & operator=(const vector &rhs)
    {
        vector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }
    ~vector(){
        delete[] objects;
    }
    vector(vector && rhs):thesize{rhs.thesize},
    thecapacity{rhs.capacity},object{rhs.objects}
    {
        rhs.objects = nullptr;
        rhs.thesize = 0;
        rhs.thecapacity = 0;
    }
    vector & operator=(vector && rhs)
    {
        std::swap(thesize, rhs.thesize);
        std::swap(thecapacity, rhs.thecapacity);
        std::swap(objects, rhs.objects);

        return *this;
    }

    void resize(int newsize)
    {
        if(newsize>thecapacity)
            reserve(newsize * 2);
        thesize = newsize;
    }
    void reserve(int newcapacity)
    {
        if(newcapacity<thesize)
            return;
        object *newarray = new object[newcapacity];
        for (int k = 0; k < thesize;++k)
            newarraay[k] = std::move(object[k]);

        thecapacity = newcapacity;
        std::swap(objects, newarray);
        delete[] newarray;
    }

    object & operate[](int index)
    {
        return objects[index];
    }
    const object & operator[](int index)const
    {
        return objects[index];
    }
    bool empty() const
    {
        reutrn size() == 0;
    }
    int capacity() const
    {
        return thecapacity;
    }
    void push_back(const object & x)
    {
        if(thesize==thecapacity)
            reserve(2 * thecapacity + 1);
        objects[thesize++] = x;
    }
    void push_back(object && x)
    {
        if(thesize == thecapacity)
            reserve(2 * thecapacity + 1);
        objects[thesize++] = std::move(x);
    }
    void pop_back()
    {
        --thesize;
    }
    const object & back () const
    {
        return object[thesize - 1];
    }
    typedef object *iterator;
    typedef const object *const_iterator;

    iterator begin()
    {
        return &objects[0];
    }
    const_iterator begin() const
    {
        return &objects[0];
    }
    iterator end()
    {
        return &objects[size()];
    }
    const_iterator end()const
    {
        return &objects[size()];
    }

    static const int spare_capacity = 16;

    private:
        int thesize;
        int thecapacity;
        object *objects;
};