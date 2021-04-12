/*    Copyright (C) 2021  Saurabh Joshi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __MYLIST_H
#define __MYLIST_H

#include <iterator>

template <typename T>
class mylistiterator_t;

template <typename T>
class mylistnode_t
{

 T value;
 public:
 mylistnode_t* next;
 mylistnode_t* getnext() {return next;}
 T getval() { return value;}
 mylistnode_t(const T& v,const mylistnode_t<T>* n):value(v),next(n){}
 mylistnode_t(const T& v):value(v),next(nullptr){}
 mylistnode_t(T&& v):value(v),next(nullptr){}
 mylistnode_t():next(nullptr){}

  friend class mylistiterator_t<T>;

};


template<typename T>
class mylistiterator_t : public std::iterator<std::forward_iterator_tag,T>
{
    mylistnode_t<T>* ptr;
public:
    mylistiterator_t():ptr(nullptr){}
    mylistiterator_t(mylistnode_t<T>* p):ptr(p){}
    mylistiterator_t(const mylistiterator_t<T>& it) { ptr= it.ptr;}
    void operator=(const mylistiterator_t<T>& it) { ptr=it.ptr;}
    template <typename T1>
    friend bool operator!=(const mylistiterator_t<T1>&, const mylistiterator_t<T1>&);
    template <typename T1>
    friend bool operator==(const mylistiterator_t<T1>&, const mylistiterator_t<T1>&);
    T& operator*() { return ptr->value; }

    mylistiterator_t<T>& operator++()
    { if(ptr!=nullptr)
       {
           ptr=ptr->next;
       }
       return *this;
        }
    mylistiterator_t<T> operator++(int i)
    {
        mylistiterator_t tmpcopy(ptr);
        ++(*this);
        return tmpcopy;
    }

};

    template <typename T>
    bool operator!=(const mylistiterator_t<T>& it1, const mylistiterator_t<T>& it2) 
    { return it1.ptr != it2.ptr;  }
    template <typename T>
    bool operator==(const mylistiterator_t<T>& it1, const mylistiterator_t<T>& it2) 
    { return it1.ptr == it2.ptr;}

template<typename T>
class mylist_t
{
   mylistnode_t<T>* head;
public:
 mylist_t():head(nullptr){}
 bool empty() const {return head==nullptr;}
 void push_front(T v)
 {
     auto p = new mylistnode_t<T>(v);
     p->next=head;
     head=p;
 }
 void push_front(T&& v)
 {
     auto p = new mylistnode_t<T>(v);
     p->next=head;
     head=p;
 }
 mylistiterator_t<T>& begin()
 {
     return *(new mylistiterator_t<T>(head));
 }
 mylistiterator_t<T>& end()
 {
     return *(new mylistiterator_t<T>());
 }
 size_t size()
 {
     size_t sz=0;
     auto it=this->begin();
     auto it_end=this->end();
     while(it!=it_end)
     {
         ++it;
         sz++;
     }
     return sz;
 }
  
};



#endif