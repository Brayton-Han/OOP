#include <cassert>
#include <type_traits>
#include <memory>

#include "vec.h"

using namespace std;

// static_assert : DO NOT CALL--compiler will evaluate.
void test_vec1_ctor()
{
    static_assert( is_constructible<vec1<double>>{}, "" );
    static_assert( is_default_constructible<vec1<double>>{}, "" );
    static_assert( is_copy_constructible<vec1<double>>{}, "" );
    static_assert( is_copy_assignable<vec1<double>>{}, "" );
    static_assert( is_move_constructible<vec1<double>>{}, "" );
    static_assert( is_move_assignable<vec1<double>>{}, "" );
    static_assert( is_destructible<vec1<double>>{}, "" );
}

void test_vec2_ctor()
{
    static_assert( is_constructible<vec2<double>>{}, "" );
    static_assert( is_default_constructible<vec2<double>>{}, "" );
    static_assert( is_copy_constructible<vec2<double>>{}, "" );
    static_assert( is_copy_assignable<vec2<double>>{}, "" );
    static_assert( is_move_constructible<vec2<double>>{}, "" );
    static_assert( is_move_assignable<vec2<double>>{}, "" );
    static_assert( is_destructible<vec2<double>>{}, "" );
}

void test_vec3_ctor()
{
    static_assert( is_constructible<vec3<double>>{}, "" );
    static_assert( is_default_constructible<vec3<double>>{}, "" );
    static_assert( is_copy_constructible<vec3<double>>{}, "" );
    static_assert( is_copy_assignable<vec3<double>>{}, "" );
    static_assert( is_move_constructible<vec3<double>>{}, "" );
    static_assert( is_move_assignable<vec3<double>>{}, "" );
    static_assert( is_destructible<vec3<double>>{}, "" );
}

// operator new[]/delete[] override globally
void* operator new[](std::size_t sz)  {
    void *ptr = std::malloc(sz);
    std::printf("global new, location=%u size = %zu \n", ptr, sz);
    return ptr;
}

void operator delete[](void* ptr)  {
    std::printf("global del, location=%u\n", ptr);
    std::free(ptr);
}


int fLogMemory = 1;      // Perform logging (0=no; nonzero=yes)?
int cBlocksAllocated = 0;  // Count of blocks allocated.

// for vec2 test : will cause segment fault.
void test_vec2_copy()
{
    vec2<double> big(10240);
    {
       vec2<double> small(6);
        small = big;
    }
}


// for vec3 test
void test_vec3_copy_pointer()
{
    vec3<double>* big = new vec3<double>(10240);
    {
        vec3<double>* small = new vec3<double>(6);
        *small = *big;
        delete small;
    }
    delete big;
}

void test_vec3_copy()
{
    vec3<double> big(10240);
    {
        vec3<double> small(6);
        small = big;
    }
}

// main entry
int main()
{
    // you neeed to comment test_vec2_copy()-- it will cause segment fault.
    // test_vec2_copy();
    test_vec3_copy_pointer();
    test_vec3_copy();
    cout << "done!";
    return 0;
}