#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <iostream>
#include <memory>

class String {
public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const String&);
    String(const char*);
    String& operator=(const String&);
    ~String();

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char* begin() const { return elements; }
    char* end() const { return first_free; }

    void reserve(size_t n);

    void range_initializer(const char *first, const char *last);

private:
    std::allocator<char> alloc;
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
    char* elements;
    char* first_free;
    char* cap;
};

#endif // STRING_H_INCLUDED
