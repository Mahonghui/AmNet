//
// Created by amisher on 18-12-12.
//

#ifndef AMNET_ANYONE_H
#define AMNET_ANYONE_H

// Copyright Kevlin Henney, 2000, 2001m 2002. All rights reserved
// Permission to use, copy, modify, and distribution this software for any purpose
// is hereby granted without fee, provided that this copyright and permission notice
// appear in all copies and derivatives.
// This software is provided "as is" without express or implied warranty.

#include <algorithm>
#include <typeinfo>

class Any{

public:
    Any():content(nullptr){}
    template <typename  T>
    explicit Any(const T& v):content(new holder<T>(v)){}

    Any(const Any& rhs):content(rhs.content?rhs.content->clone():0){}
    ~Any(){delete content;}

    Any& swap(Any& rhs){
        std::swap(content, rhs.content);
        return *this;
    }

    template <typename T>
    Any& operator=(const T& rhs){
        Any(rhs).swap(*this);
        return *this;
    }

    Any&operator=(const Any& rhs){
        Any(rhs).swap(*this);
        return *this;
    }

    bool empty()const{ return !content;}

    const std::type_info& type() const{
        return content?content->type(): typeid(void);
    }

    class placeholder{
    public:
        virtual ~placeholder()= default;
        virtual const std::type_info& type()const =0;
        virtual placeholder* clone() const =0;
    };

    template <typename T>
    class holder:public placeholder{
    public:
        explicit holder(const T& v):held(v){}

        virtual const std::type_info& type() const{
            return typeid(T);
        }

        virtual placeholder* clone() const{
            return new holder(held);
        }
        T held;
    };


    placeholder* content;
};

class bad_any_cast{
public:
    virtual const char* what() const  noexcept{
        return "bad_any_cast: failed conversion using any_cast";
    }
};

template <typename T>
T* any_cast(Any* operand){
    return operand&&operand->type() == typeid(T)?&static_cast<Any::holder<T>*>(operand->content)->held: nullptr;
}

template <typename T>
const T* any_cast(const Any* operand){
    return any_cast<T>(const_cast<Any*>(operand));
}

template <typename T>
T any_cast(const Any& operand){
    const T* res = any_cast<T>(&operand);
    if(!res)
        throw bad_any_cast();
    return *res;
}

#endif //AMNET_ANYONE_H
