#include<cstdlib>
#include<cstddef>
#include<cstring>
#ifndef LMY_VECTOR
#define LMY_VECTOR
// template<typename T>
// using T2 = T;
// T2<size_type>;
template<typename T>
class vector
{
public:
    using iterator=T*;
    using size_type=size_t;
    using value_type=T;
    using difference_type=ptrdiff_t;
    using reference=T&;
    using const_reference=const T&;
    using pointer=T*;
    using const_pointer=const T*;
    using const_iterator=const T*;
    class reverse_iterator
    {
    private:
        pointer t;
    public:
        reverse_iterator(pointer _t = nullptr) : t(_t) {}
        bool operator !=(const reverse_iterator & it) const
        {
            return t != it.t;
        }
        bool operator ==(const reverse_iterator & it) const
        {
            return t == it.t;
        }
        value_type operator *()
        {
            return *t;
        }
        reverse_iterator operator ++()
        {
            return --t;
        }
        reverse_iterator operator ++(int)
        {
            pointer tmp = t;
            --t;
            return tmp;
        }
        reverse_iterator operator --()
        {
            return ++t;
        }
        reverse_iterator operator --(int)
        {
            pointer tmp = t;
            ++t;
            return tmp;
        }
        reverse_iterator operator +=(size_type it)
        {
            return t-=it;
        }
        reverse_iterator operator -=(size_type it)
        {
            return t+=it;
        }
        reverse_iterator operator +(size_type it)
        {
            return t-it;
        }
        reverse_iterator operator -(size_type it)
        {
            return t+it;
        }
    };
    using const_reverse_iterator=const reverse_iterator;
private:
    size_type length;
    size_type capacity_;
    pointer data_;
public:
    value_type operator [] (size_type pos)
    {
        return data_[pos];
    }
    vector & operator = (vector tmp)
    {
        vector n;
        for(auto i=tmp.begin();i!=tmp.end();i++)
            n.push_back(tmp);
        return n;
    }
    size_type size()
    {
        return length;
    }
    const size_type size() const
    {
        return length;
    }
    size_type capacity()
    {
        return capacity_;
    }
    const size_type capacity() const
    {
        return capacity_;
    }
    void reserve(size_type num)
    {
        if(num<=length)
            return;
        size_type r=capacity_;
        capacity_=num;
        pointer fr=data_;
        pointer ndata_=new value_type[capacity_];
        for(size_type i=0;i<r;i++)
            ndata_[i]=data_[i];
        data_=ndata_;
        delete fr;
    }
    bool empty()
    {
        return length==0;
    }
    void resize(size_type num)
    {
        if(num<=length)
        {
            length=num;
            reserve(2*num);
            return;
        }
        reserve(2*num);
        length=num;
    }
    void resize(size_type num,value_type value)
    {
        if(num<=length)
        {
            length=num;
            reserve(2*num);
            return;
        }
        reserve(2*num);
        for(size_type i=length;i<num;i++)
            data_[i]=value;
        length=num;
    }
    reference front()
    {
        return *begin();
    }
    reference back()
    {
        iterator endIt = end();
        return *(--endIt);
    }
    reference at(size_type pos)
    {
        if(pos<0||pos>length)
            exit(1);
        return data_[pos];
    }
    const_reference back() const
    {
        return *(--end());
    }

    vector():length(0),capacity_(1),data_(new value_type[capacity_])
    {
    }
    explicit vector(size_type nums):length(nums?nums:1),capacity_(2*(nums?nums:1)),data_(new value_type[capacity_])
    {
        //memset(data_,0,sizeof(data_));
        for(size_type i=0;i<nums;i++)
            data_[i]=(value_type)0;
    }
    vector(size_type nums,value_type t):length(nums),capacity_(2*nums),data_(new value_type[capacity_])
    {
        for(size_type i=0;i<nums;i++)
            data_[i]=t;
    }
    vector(const vector &v):length(v.length),capacity_(v.capacity_),data_(new value_type[capacity_])
    {
        for(size_type i=0;i<capacity_;i++)
            data_[i]=v.data_[i];
    }
    vector(iterator a,iterator b)
    {
        length=0;
        capacity_=1;
        data_=new value_type[capacity_];
        while(a!=b)
        {
            push_back(a);
            a++;
        }
    }
    ~vector()
    {
        delete[] data_;
    }
    void push_back(const iterator a)
    {
        data_[length++]=*a;
        if(length==capacity_)
        {
            capacity_*=2;
            pointer fr=data_;
            pointer data_2=new value_type[capacity_];
            for(size_type i=0;i<capacity_/2;i++)
                data_2[i]=data_[i];
            data_=data_2;
            delete fr;
        }
    }
    void push_back(const value_type a)
    {
        data_[length++]=a;
        if(length==capacity_)
        {
            capacity_*=2;
            pointer fr=data_;
            pointer data_2=new value_type[capacity_];
            for(size_type i=0;i<capacity_/2;i++)
                data_2[i]=data_[i];
            data_=data_2;
            delete fr;
        }
    }
    void pop_back()
    {
        if(length==0)
        {
            exit(1);
        }
        length--;
    }
    // iterator pop_front()
    // {
    //     if(length==0)
    //         exit(1);
    //     length--;
    //     for(size_type i=0;i<length;i++)
    //         data_[i]=data_[i+1];
    // }
    iterator erase(iterator iter)
    {
        if(length==0)
            exit(1);
        length--;
        for(auto i=iter;i!=end();i++)
            *i=*(i+1);
        return iter;
    }
    iterator erase(size_type pos)
    {
        if(length==0)
            exit(1);
        length--;
        for(size_type i=pos;i<length;i++)
            data_[i]=data_[i+1];
        return begin()+pos;
    }
    iterator begin()
    {
        return data_;
    }
    const_iterator begin() const
    {
        return data_;
    }
    const_iterator cbegin() const noexcept
    {
        return data_;
    }
    iterator end()
    {
        return data_+length;
    }
    const_iterator end() const
    {
        return data_+length;
    }
    const_iterator cend() const noexcept
    {
        return data_+length;
    }
    reverse_iterator rbegin()
    {
        return data_+length-1;
    }
    const reverse_iterator rbegin() const
    {
        return data_+length-1;
    }
    const reverse_iterator crbegin() const noexcept
    {
        return data_+length-1;
    }
    reverse_iterator rend()
    {
        return data_-1;
    }
    const reverse_iterator rend() const
    {
        return data_-1;
    }
    const reverse_iterator crend() const noexcept
    {
        return data_-1;
    }
    void swap(vector & s)
    {
        pointer tmpdata_=data_;
        data_=s.data_;
        s.data_=tmpdata_;
        size_type tmplength=length;
        length=s.length;
        s.length=tmplength;
        size_type tmpcapacity_=capacity_;
        capacity_=s.capacity_;
        s.capacity_=tmpcapacity_;
    }
    void assign(size_type num,const_reference value )
    {
        if(length<num)
        {
            size_type i=0;
            for(;i<length;i++)
                data_[i]=value;
            for(;i<num;i++)
                push_back(value);
        }else
        {
            length=num;
            for(size_type i=0;i<length;i++)
                data_[i]=value;
        }
    }
    pointer data()
    {
        return data_;
    }
    void shrink_to_fit()
    {
        capacity_=length+1;
        pointer tmp=data_;
        pointer ndata_=new value_type[capacity_];
        for(size_type i=0;i<length;i++)
            ndata_[i]=data_[i];
        data_=ndata_;
        delete[] tmp;
    }
    void clear()
    {
        while(length)
        {
            pop_back();
        }
    }
    iterator insert(iterator pos,const_reference value)
    {
        length++;
        if(length==capacity_)
        {
            capacity_*=2;
            pointer tmp=data_;
            pointer ndata_=new value_type[capacity_];
            for(size_type i=0;i<length;i++)
                ndata_[i]=data_[i];
            data_=ndata_;
            delete[] tmp;
        }
        for(auto i=end()-1;i!=pos;i--)
            *i=*(i-1);
        *pos=value;
        return pos;
    }
};
// template<class T>
// bool operator ==(const vector<T>& lhs,const vector<T>& rhs)
// {
//     if(lhs.size()!=rhs.size())
//         return false;
//     int size=lhs.size();
//     for(int i=0;i<size;i++)
//         if(lhs[i]!=rhs[i])
//             return false;
//     return true;
// }
#endif