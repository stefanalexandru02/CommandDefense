#include "Allocator.hpp"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFINE_FUNCTION_ALLOCATOR(type) \
type* Allocator::alloc(type x)                                                                                     \
    { \
    type* ptr = (type*) alloc_raw(sizeof(x)); \
 \
    if (ptr == nullptr) \
        return nullptr; \
    *ptr = x; \
    offset += sizeof(x); \
    return ptr; \
}

void* Allocator::alloc_raw(unsigned size)
{
    if (size + offset >= max_size)
        return nullptr;
    return buffer + offset;
}

Allocator::Allocator(unsigned max_size)
{
    buffer         = new char[max_size];
    offset         = 0;
    this->max_size = max_size;
}

Allocator::~Allocator()
{
    delete[] buffer;
}

char* Allocator::alloc(const char* string)
{
    char* ptr = (char*)alloc_raw(strlen(string) + 1);
    if (ptr==nullptr)
        return nullptr;
    memcpy(ptr, string, strlen(string) + 1);
    offset += strlen(string) + 1;
    return ptr;
}

char* Allocator::alloc(const char* string1, const char* string2)
{
    char* ptr = (char*)alloc_raw(strlen(string1) + strlen(string2) + 1);
    if (ptr==nullptr)
        return nullptr;
    memcpy(ptr, string1, strlen(string1)) ;
    memcpy(ptr + strlen(string1), string2, strlen(string2) + 1);
    offset += (strlen(string1) + strlen(string2) + 1);
    return ptr;
}

//unsigned* Allocator::alloc(unsigned x)
//{
//    unsigned* ptr = (unsigned*)alloc_raw(sizeof(x));
//
//    if (ptr == nullptr)
//        return nullptr;
//    offset += sizeof(x);
//    return ptr;
//}
DEFINE_FUNCTION_ALLOCATOR(unsigned);

//int* Allocator::alloc(int x)
//{
//    int* ptr = (int*) alloc_raw(sizeof(x));
//
//    if (ptr == nullptr)
//        return nullptr;
//    offset += sizeof(x);
//    return ptr;
//}
DEFINE_FUNCTION_ALLOCATOR(int);
DEFINE_FUNCTION_ALLOCATOR(float);
DEFINE_FUNCTION_ALLOCATOR(double);
DEFINE_FUNCTION_ALLOCATOR(char);
