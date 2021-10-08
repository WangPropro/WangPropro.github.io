template <typename object>
class list
{
    private:
    struct node{
        object data;
        node *prev;
        node *next;
        
        node(const object & d = object{ },node *p=nullptr,
                               node *n = nullptr)
            :data{d},prev{p},next{n} { }
            node(object && d,node *p = nullptr,node *n = nullptr)
               :data{ std::move(d)},prev{p},next{n} { }
    };
    public:
    class const_iterator{
        public:
        const_iterator():current{ nullptr }
        { }
        const object & operator * ( )const{
            return retrieve();
        }
        const_iterator & operator++(){
            current = current->next;
            return *this;
        }

        const_iterator operator++ (int){
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator == { const const_iterator & rhs }const
        {
            return current == rhs.current;
        }
        bool operator!=( const const_iterator & rhs) const{
            return !(*this == rhs);
        }

        protected:
            node *current;
            object & retrieve() const{
                return current->data;
            }
            const_iterator(node *p):current{p}
            {}
            friend class list<object>;
    };
    //list 类的内嵌 const_iterator 类

    class iterator : public const_iterator{
        public:
        iterator()
        {}
        object & operator * ()
        {
            return const_iterator::retrieve();
        }
        const object & operator * () const{
            return const_iterator::operator*();
        }

        iterator & operator++(){
            this->current = this->current->next;
            return *this;
        }

        iterator & operator++(int){
            iterator old = *this;
            ++(*this);
            return old;
        }

        protected:
        iterator(node *p):const_iterator{p}
        {}
        friend class list<object>;
    };
    //list 类的嵌套 iterator 类

    public:
    list(){
        init();
    }
    ~list(){
        clear();
        delete head;
        delete tail;
    }

    list(const list & rhs){
        init();
        for(auto & x:rhs)
            push_back(x);
    }

    list & operator = (const list & rhs){
        list copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    list(list && rhs)
    :thesize{rhs.thesize},head{rhs.head},tail{rhs.tail}
    {
        rhs.thesize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    list & operator =(list && rhs){
        std::swap(thesize, rhs.thesize);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return *this;
    }
    //list 类的构造函数，五大函数

    iterator begin(){
        return {head->next};
    }
    const_iterator begin()const{
        return {head->next};
    }
    iterator end(){
        return {tail};
    }
    const_iterator end()const{
        return {tail};
    }

    init size()const{
        return thesize;
    }
    bool empty()const{
        reutrn size() == 0;
    }

    void clear(){
        while(!empty())
            pop_front();
    }

    object & front(){
        return *begin();
    }
    const object & front() const{
        return *begin();
    }
    object & back(){
        return *--end();
    }
    const object & back() const{
        return *--end();
    }
    void push_front(const object & x){
        insert(begin(), x);
    }
    void push_front(object && x){
        insert(begin(), std::move(x));
    }
    void push_back(const object &x){
        insert(end(), x);
    }
    void push_back(object && x){
        insert(end(), std::move(x));
    }
    void pop_front(){
        erase(begin());
    }
    void pop_back(){
        erase(--end());
    }

    //在 itr前插入 x
    iterator insert(iterator itr,const object & x){
        node *p = itr.current;
        thesize++;
        return {p->prev = p->prev->next = new node{x, p->prev, p}};
    }
    //在 itr前插入 x
    iterator insert(iterator itr,object && x){
        node *p = itr.current;
        thesize++;
        return {p->prev = p->prev->next = new node{std::move(x), p->prev, p}};
    }
    //删除在 itr处的项
    iterator erase(iterator itr){
        node *p = itr.current;
        iterator retval{p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        thesize--;
        return retval;
    }
    iterator erase(iterator from,iterator to){
        for (iterator itr = from; itr != to;)
            itr = erase(itr);
        return to;
    }

    private:
        int thesize;
        node *head;
        node *tail;
        void init(){
            thesize = 0;
            head = new node;
            tail = new node;
            head->next = tail;
            tail->prev = head;
    }
    //init 例程
};