#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
class vec1
{
};

template <typename T>
class vec2
{
private:
    T *data_{};
    size_t size_{};
    size_t limit_{};

public:
    vec2(size_t size = 6)
        : size_{}, limit_{size}
    {
        data_ = new T[size];
    }

    ~vec2()
    {
        if (data_)
        {
            delete[] data_;
            data_ = nullptr;
        }
    }
};

extern int fLogMemory;       // Perform logging (0=no; nonzero=yes)?
extern int cBlocksAllocated; // Count of blocks allocated.

template <typename T>
class vec3
{
private:
    T *data_{};
    size_t size_{};
    size_t limit_{};
    unsigned int  id_{};

public:
    static int seq_;

    unsigned int & id() { return id_;}
    // # TODO0 const version of id()
    const unsigned int & id() const {return id_;}

public:

    vec3(size_t size=6)
        : size_{}, limit_{size}
    {
        id_ = ++seq_;
        data_ = new T[size];
    }

    // TODO1 copy constructor of vec3
    vec3(const vec3 &ins): size_{ins.size_}, limit_{ins.limit_}
    {
        vec3 ins1;
        ins1.data_ = new T[size_];
        ins1.size_ = size_;
        ins1.limit_ = limit_;
        T* begin=ins.data_;
        while(begin!=ins.data_+size_)
            *(ins1.data_++) = *(begin++);
        ins1.data_ = ins1.data_-size_;
    }

    // TODO2 operator= for vec3, garding case of a=a
    vec3& operator=(const vec3& ins)
    {
        if(&ins != this)
        {
            this->data_ = new T[ins.size_];
            T* beginn=ins.data_;
            while(beginn!=ins.data_+ins.size_)
                *(this->data_++) = *(beginn++);
            this->data_ = this->data_-ins.size_;
            if(ins.data_)
            {
                T* it = ins.data_ + ins.size_;
                while(it!=ins.data_) 
                {
                    delete it;
                    it--;
                }
            }
        }
        return *this;
    }

    // TODO3 destructor of vec3
    ~vec3()
    {
        if(data_)
        {
            T* iter = data_ + size_;
            while(iter != data_) 
            {
                delete iter;
                iter--;
            }
        }
        data_ = 0;
    }

    // User-defined operator new & delete
    void *operator new(size_t stAllocateBlock)
    {
        static int fInOpNew = 0; // Guard flag.

        if (fLogMemory && !fInOpNew)
        {
            fInOpNew = 1;
            std::clog << "Memory block " << ++cBlocksAllocated
                      << " malloc " << stAllocateBlock << "\n";
            fInOpNew = 0;
        }
        return malloc(stAllocateBlock);
    }

    void operator delete(void *pvMem)
    {
        static int fInOpDelete = 0; // Guard flag.
        if (fLogMemory && !fInOpDelete)
        {
            fInOpDelete = 1;
            std::clog << "Memory block " << cBlocksAllocated--
                      << " free  \n";
            fInOpDelete = 0;
        }

        free(pvMem);
    }
};

// TODO4 add operator== and operator!=, using id() for comparing
template <typename T>
bool operator==(const T& v1, const T& v2)
{
    return v1.id() == v2.id();
}

template <typename T>
bool operator!=(const T& v1, const T& v2)
{
    return v1.id() != v2.id();
}

// definition of static member of seq_ in vec3 
template <typename T>
int vec3<T>::seq_ = 0;