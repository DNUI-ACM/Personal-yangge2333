#include<stdlib.h>
#include<cstddef>
#include<iostream>
#ifndef LMY_LIST
#define LMY_LIST
template<typename T>
class list
{
public:
    struct node
    {
        T data_;
        node *pre,*bac;
        node()
        {
            data_=0;
            pre=0;
            bac=0;
        }
        node(T v)
        {
            data_=v;
            pre=0;
            bac=0;
        }
        node(node& N)
        {
            data_=N.data_;
            pre=N.pre;
            bac=N.bac;
        }
        node operator =(const node& another)
        {
            data_=another.data_;
            pre=another.pre;
            bac=another.bac;
        }
        bool operator ==(node another)
        {
            return (data_==another.data_)&&(pre==another.pre)&&(bac==another.bac);
        }
        bool operator !=(node another)
        {
            return !(data_==another.data_)&&(pre==another.pre)&&(bac==another.bac);
        }
    }LIEQ,LIEW;
    using value_type=T;
    using size_type=size_t;
    using difference_type=ptrdiff_t;
    using reference=value_type&;
    using const_reference=const value_type&;
    using pointer=T*;
    using node_pointer=node*;
    using const_node_pointer=const node*;
    using node_reference=node&;
    using const_node_reference=const node_reference;
    using const_pointer=const T*;
    class iterator
    {
    public:
        node_pointer t;
        iterator(node_pointer _t = nullptr) : t(_t) {};
        friend bool operator !=(const iterator & it,const iterator & it2)
        {
            return it2.t != it.t;
        }
        friend bool operator ==(const iterator & it,const iterator & it2)
        {
            return it2.t == it.t;
        }
        value_type & operator *()
        {
            return t->data_;
        }
        iterator operator ++()
        {
            t=t->bac;
            return t;
        }
        iterator operator ++(int)
        {
            node_pointer tmp = t;
            t=t->bac;
            return tmp;
        }
        iterator operator --()
        {
            t=t->pre;
            return t;
        }
        iterator operator --(int)
        {
            node_pointer tmp = t;
            t=t->pre;
            return tmp;
        }
        iterator operator +(size_type a)
        {
            iterator tmp=t;
            for(size_type i=0;i<a;i++)
                tmp++;
            return tmp;
        }
        iterator operator -(size_type a)
        {
            iterator tmp=t;
            for(size_type i=0;i<a;i++)
                tmp--;
            return tmp;
        }
    };
    class reverse_iterator
    {
    public:
        node_pointer t;
        reverse_iterator(node_pointer _t = nullptr) : t(_t) {};
        friend bool operator !=(const reverse_iterator & it,const reverse_iterator & it2)
        {
            return it2.t != it.t;
        }
        friend bool operator ==(const reverse_iterator & it,const reverse_iterator & it2)
        {
            return it2.t == it.t;
        }
        value_type & operator *()
        {
            return t->data_;
        }
        reverse_iterator operator ++()
        {
            t=t->pre;
            return t;
        }
        reverse_iterator operator ++(int)
        {
            node_pointer tmp = t;
            t=t->pre;
            return tmp;
        }
        reverse_iterator operator --()
        {
            t=t->bac;
            return t;
        }
        reverse_iterator operator --(int)
        {
            node_pointer tmp = t;
            t=t->bac;
            return tmp;
        }
    };
    using const_iterator=const iterator;
    using const_reverse_iterator=const reverse_iterator;
private:
    size_type size_;
    node_pointer head;
    node_pointer tail;
    node_pointer lieq;
    node_pointer liew;
    void be_empty()
    {
        size_=0;
    }
    void change_size(size_type afternum)
    {
        size_=afternum;
    }
public:
    explicit list():lieq(&LIEQ),liew(&LIEW),head(lieq),tail(liew),size_(0)
    {
        lieq->bac=liew;
        liew->pre=lieq;
    }
    explicit list(size_type t_,value_type v_):lieq(&LIEQ),liew(&LIEW),head(lieq),tail(liew),size_(0)
    {
        lieq->bac=liew;
        liew->pre=lieq;
        for(size_type i=0;i<t_;i++)
            push_back(v_);
    }
    explicit list(size_type t_):lieq(&LIEQ),liew(&LIEW),head(lieq),tail(liew),size_(0)
    {
        lieq->bac=liew;
        liew->pre=lieq;
        for(size_type i=0;i<t_;i++)
            push_back(0);
    }
    list(const list& other):lieq(&LIEQ),liew(&LIEW),head(lieq),tail(liew),size_(0)
    {
        lieq->bac=liew;
        liew->pre=lieq;
        for(auto i=other.begin();i!=other.end();i++)
            push_back(i);
    }
    ~list()
    {
        clear();
    }
    const size_type size() const
    {
        return size_;
    }
    node_pointer make_node(value_type v_)
    {
        return new node(v_);
    }
    void push_back(value_type v_)
    {
        node_pointer tmp=make_node(v_);
        if(size_==0)
        {
            size_++;
            head=tmp;
            tail=tmp;
            tmp->pre=lieq;
            tmp->bac=liew;
            return;
        }
        size_++;
        liew->pre=tmp;
        tail->bac=tmp;
        tmp->bac=liew;
        tmp->pre=tail;
        tail=tmp;
    }
    void push_back(iterator iter)
    {
        node_pointer tmp=make_node(*iter);
        if(size_==0)
        {
            size_++;
            head=tmp;
            tail=tmp;
            tmp->pre=lieq;
            tmp->bac=liew;
            return;
        }
        size_++;
        liew->pre=tmp;
        tail->bac=tmp;
        tmp->bac=liew;
        tmp->pre=tail;
        tail=tmp;
    }
    void push_back(reverse_iterator iter)
    {
        node_pointer tmp=make_node(*iter);
        if(size_==0)
        {
            size_++;
            head=tmp;
            tail=tmp;
            tmp->pre=lieq;
            tmp->bac=liew;
            return;
        }
        size_++;
        liew->pre=tmp;
        tail->bac=tmp;
        tmp->bac=liew;
        tmp->pre=tail;
        tail=tmp;
    }
    void push_front(value_type v_)
    {
        node_pointer tmp=make_node(v_);
        if(size_==0)
        {
            size_++;
            head=tmp;
            tail=tmp;
            tmp->pre=lieq;
            tmp->bac=liew;
            return;
        }
        size_++;
        lieq->bac=tmp;
        head->pre=tmp;
        tmp->pre=lieq;
        tmp->bac=head;
        head=tmp;
    }
    void push_front(iterator iter)
    {
        node_pointer tmp=make_node(iter->data_);
        if(size_==0)
        {
            size_++;
            head=tmp;
            tail=tmp;
            tmp->pre=lieq;
            tmp->bac=liew;
            return;
        }
        size_++;
        lieq->bac=tmp;
        head->pre=tmp;
        tmp->pre=lieq;
        tmp->bac=head;
        head=tmp;
    }
    void push_front(reverse_iterator iter)
    {
        node_pointer tmp=make_node(iter->data_);
        if(size_==0)
        {
            size_++;
            head=tmp;
            tail=tmp;
            tmp->pre=lieq;
            tmp->bac=liew;
            return;
        }
        size_++;
        lieq->bac=tmp;
        head->pre=tmp;
        tmp->pre=lieq;
        tmp->bac=head;
        head=tmp;
    }
    void pop_back()
    {
        if(size_==0)
            return;
        node_pointer tmp=tail;
        if(size_==1)
        {
            size_=0;
            head=lieq;
            tail=liew;
            lieq->bac=liew;
            liew->pre=lieq;
            delete[] tmp;
            return;
        }
        liew->pre=tail->pre;
        tail->pre->bac=liew;
        tail=tail->pre;
        size_--;
        delete[] tmp;
    }
    void pop_front()
    {
        if(size_==0)
            return;
        node_pointer tmp=head;
        if(size_==1)
        {
            pop_back();
            return;
        }
        lieq->bac=head->bac;
        head->bac->pre=lieq;
        head=head->bac;
        size_--;
        delete[] tmp;
    }
    //int dd=0;
    iterator insert(iterator & pos,const T& value)
    {
        if(size_==0)
        {
            push_front(value);
            return pos;
        }
        if(pos==begin())
        {
            push_front(value);
            return begin();
        }
        if(pos==end())
        {
            push_back(value);
            return end()--;
        }
        node_pointer tmp=make_node(value);
        node_pointer q=pos.t->pre;
        tmp->pre=q;
        tmp->bac=pos.t;
        pos.t->pre=tmp;
        q->bac=tmp;
        size_++;
        return tmp;
    }
    iterator erase(iterator iter)
    {
        //std::cout << dd++ << std::endl;
        if(iter==end())
            return iter;
        if(iter==begin())
        {
            pop_front();
            return begin();
        }
        if(iter==(--end()))
        {
            pop_back();
            return end();
        }
        node_pointer p=iter.t->pre,q=iter.t->bac,tmp=iter.t;
        p->bac=q;
        q->pre=p;
        size_--;
        delete tmp;
        return q;
    }
    iterator erase(iterator a,iterator b)
    {
        for(auto i=a;i!=b;i++)
            erase(i);
        return b;
    }
    value_type & front()
    {
        return head->data_;
    }
    const value_type & front()const
    {
        return head->data_;
    }
    value_type & back()
    {
        return tail->data_;
    }
    const value_type & back()const
    {
        return tail->data_;
    }
    bool empty()const
    {
        return size_==0;
    }
    void clear()
    {
        while(size())
            pop_back();
    }
    void resize(size_type count,T value = T())
    {
        if(count<=size_)
        {
            while(size_!=count)
                pop_back();
            return;
        }
        while(size!=count)
            push_back(value);
    }
    void resize(size_type count)
    {
        if(count<=size_)
        {
            while(size_!=count)
                pop_back();
            return;
        }
        while(size!=count)
            push_back(T(0));
    }
    void resize(size_type count,const value_type& value)
    {
        if(count<=size_)
        {
            while(size_!=count)
                pop_back();
            return;
        }
        while(size!=count)
            push_back(value);
    }
    iterator begin()
    {
        if(head==lieq)
            return 0;
        return head;
    }
    const_iterator begin() const
    {
        if(head==lieq)
            return 0;
        return head;
    }
    const_iterator cbegin() const noexcept
    {
        if(head==lieq)
            return 0;
        return head;
    }
    iterator end()
    {
        return tail->bac;
    }
    const_iterator end() const
    {
        if(tail==liew)
            return 0;
        return tail->bac;
    }
    const_iterator cend() const noexcept
    {
        if(tail==liew)
            return 0;
        return tail->bac;
    }
    reverse_iterator rbegin()
    {
        if(tail==liew)
            return 0;
        return tail;
    }
    const_reverse_iterator rbegin() const
    {
        if(tail==liew)
            return 0;
        return tail;
    }
    const_reverse_iterator crbegin() const noexcept
    {
        if(tail==liew)
            return 0;
        return tail;
    }
    reverse_iterator rend()
    {
        if(head==lieq)
            return 0;
        return head->pre;
    }
    const_reverse_iterator rend() const
    {
        if(head==lieq)
            return 0;
        return head->pre;
    }
    const_reverse_iterator crend() const noexcept
    {
        if(head==lieq)
            return 0;
        return head->pre;
    }
    void merge(list& other)
    {
        if(size()==0)
            {
                swap(other);
                return;
            }
        else if(other.size()==0)
            return;
        bool flag=0;
        for(auto i=begin();i!=end()-1;i++)
        {
            if(*i>*(i+1))
                flag=1;
            break;
        }
        if(flag==0)
            for(auto i=other.begin();i!=other.end()-1;i++)
            {
                if(*i>*(i+1))
                    flag=1;
                break;
            }
        if(flag==0)
        {
            for(auto i=begin();i!=end();i++)
            {
                while(other.size()&&*(other.begin())<*(i))
                {
                    insert(i,*(other.begin()));
                    other.pop_front();
                }
            }
            while(other.size_>0)
            {
                push_back(other.begin());
                other.pop_front();
            }
        }
        else
        {
            splice(end(),other);
        }
    }
    void assign(size_type count,const_reference value)
    {
        clear();
        for(size_type i=0;i<count;i++)
            push_back(value);
    }
    /*size_type size_;
    node_pointer head;
    node_pointer tail;
    node_pointer lieq;
    node_pointer liew;*/
    void swap(list& other)
    {
        size_type tsize=size_;
        size_=other.size_;
        other.size_=tsize;
        node_pointer tail_=tail;
        tail=other.tail;
        other.tail=tail_;
        node_pointer head_=head;
        head=other.head;
        other.head=head_;
        node_pointer lieq_=lieq;
        lieq=other.lieq;
        other.lieq=lieq_;
        node_pointer liew_=liew;
        liew=other.liew;
        other.liew=liew_;
    }
    void splice(const_iterator pos,list& other)
    {
        value_type nums=other.size();
        other.lieq->bac=liew;
        other.liew->pre=lieq;
        pos.t->pre->bac=other.head;
        other.head->pre=pos.t->pre;
        pos.t->pre=other.tail;
        other.tail->bac=pos.t;
        other.head=lieq;
        other.tail=liew;
        other.be_empty();
        change_size(size_+nums);
    }
    void splice(const_iterator pos,list& other,const_iterator it)
    {
        value_type nums=other.size();
        if(it==other.begin())
            other.head=it.t->bac;
        if(it==other.end()+1)
            other.tail=it.t->pre;
        it.t->pre->bac=it.t->bac;
        it.t->bac->pre=it.t->pre;
        it.t->bac=pos.t;
        it.t->pre=pos.t->pre;
        pos.t->pre->bac=it.t;
        pos.t->pre=it.t;
        if(pos.t==begin())
            head=it.t;
        other.change_size(nums-1);
        change_size(size_+1);
    }
    void splice(const_iterator pos,list& other,const_iterator first,const_iterator last)
    {
        int nums=0;
        for(auto i=first;i!=last;i++)
            nums++;
        if(first==last)
            return;
        if(first==other.begin())
            other.head==last.t;
        if(last==other.end())
            other.tail==other.end().t;
        first.t->pre->bac=last.t;
        auto ed=last.t->pre;
        last.t->pre=first.t->pre;
        pos.t->pre->bac=first.t;
        first.t->pre=pos.t->pre;
        ed->bac=pos.t;
        pos.t->pre=ed;
        other.change_size(other.size()-nums);
        change_size(size_+nums);
    }
    size_type remove(const T& value)
    {
        size_type ans=0;
        auto i=begin();
        while(i!=end())
        {
            if(*i==value)
            {
                ans++;
                i=erase(i);
            }
            else
             i++;
        }
        return ans;
    }
    size_type remove_if(bool cmp(const T&))
    {
        size_type ans=0;
        auto i=begin();
        while(i!=end())
        {
            if(cmp(*i))
            {
                ans++;
                i=erase(i);
            }
            else
                i++;
        }
        return ans;
    }
private:
    void swap_myself(iterator i)
    {
        auto t=i.t->pre;
        i.t->pre=i.t->bac;
        i.t->bac=t;
    }
    void swap_pointer(node_pointer & a,node_pointer & b)
    {
        auto t=a;
        a=b;
        b=t;
    }
public:
    void reverse()
    {
        auto i=begin();
        auto j=i+1;
        while(j!=end())
        {
            swap_myself(i);
            i=j;
            j=i+1;
        }
        swap_myself(i);
        swap_myself(lieq);
        swap_myself(liew);
        swap_pointer(head,tail);
        swap_pointer(lieq,liew);
    }
    size_type unique()
    {
        size_type ans=0;
        auto i=begin();
        while((i+1)!=end())
        {
            if(*i==*(i+1))
            {
                ans++;
                erase(i+1);
            }
            else
                i++;
        }
        return ans;
    }
    size_type unique(bool pred(const_reference,const_reference))
    {
        size_type ans=0;
        auto i=begin();
        while((i+1)!=end())
        {
            if(pred(*i,*(i+1)))
            {
                ans++;
                erase(i+1);
            }
            else
                i++;
        }
        return ans;
    }
// plublic:
    // void sort()
    // {
    //     qsort(begin(),end());
    // }
// private:
    // void qsort(iterator a,iterator b)
    // {
    //     if(a==b||a+1==b)
    //         return;
    //     auto fast=a;
    //     auto slow=a;
    //     int ci=0;
    //     for(;fast!=b;fast++)
    //     {
    //         ci++;
    //         if(ci==2)
    //         {
    //             ci=0;
    //             slow++;
    //         }
    //     }
    //     auto tmp= slow+1;
    //     auto i=a;
    //     auto j=b-1;
    //     while(i!=j)
    //     {
    //         for(;i!=j;i++)
    //             if(*i<=*tmp)
    //                 for(;i!=j;j--)
    //                     if(*j>=*tmp)
    //                     {
    //                         printf("%d %d\n",*i,*j);
    //                         if(i.t==head)
    //                             head=j.t;
    //                         if(j.t==tail)
    //                             tail=i.t;
    //                         auto s=i.t->pre;
    //                         i.t->pre=j.t->pre;
    //                         j.t->pre=s;
    //                         s=i.t->bac;
    //                         i.t->bac=j.t->bac;
    //                         j.t->bac=s;
    //                         auto s2=i.t;
    //                         i.t=j.t;
    //                         j.t=s2;
    //                     }

    //     }
    //     qsort(a,tmp);
    //     qsort(tmp+1,b);
    // }
// public:
     void sort(){
        list carry;
        list count[64];
        int fill=1;
        while(!empty())
        {
            carry.splice(carry.begin(),*this,begin());
            int i=0;
            iterator it;
            while(i<fill&&!count[i].empty())
            {
                count[i].merge(carry);
                carry.swap(count[i++]);
            }
            carry.swap(count[i]);
            if(i==fill) ++fill;
        }
        for (int i = 1; i < fill; ++i)
                count[i].merge(count[i-1]);
            swap(count[fill-1]);
    }
    friend bool operator == (const list & a,const list & b)
    {
        if(a.size()!=b.size())
            return 0;
        auto i=a.begin();
        auto j=b.begin();
        for(;i!=a.end();i++,j++)
            if(*i!=*j)
                return 0;
        return 1;
    }
};

#endif