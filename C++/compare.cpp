#include<bits/stdc++.h>
using namespace std;

template <typename container>
void removeEverOtherItem(container & lst){
    auto itr = lst.begin();
    //itr ÊÇÒ»¸öcontainer::iterator
    while(itr!=lst.end){
        itr = lst.erase(itr);
        if(itr!=lst.end())
            ++itr;
    }
}

template <typename container,typename object>
void change(container & c,const object & newvalue){
    typename container::iterator itr = c.begin();
    while(itr!=c.end())
        *itr++ = newvalue;
}

template <typename container>
auto begin(container & c)-> decltype(c.begin()){
    return c.begin();
}
template <typename container>
auto begin(const container & c)->decltype(c.begin()){
    return c.begin();
}

template <typename container>
void print(const container &c,ostream &out = cout){
    if(c.empty())
        out << "(empty)";
        else{
            auto itr = begin(c);
            out << "[" << *itr++;
            while(itr!=end(c))
                out << "," << *itr++;
            out << "]" << endl;
        }
}