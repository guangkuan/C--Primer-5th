#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <memory>
#include <vector>

class String {
    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream&, String& str);
    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);
    friend bool operator< (const String&, const String&);
    friend bool operator<=(const String&, const String&);
    friend bool operator> (const String&, const String&);
    friend bool operator>=(const String&, const String&);

public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const String&);
    String(const char* str);
    String& operator=(const String&);
    char& operator[](size_t n) { return elements[n]; }
    const char& operator[](size_t n) const { return elements[n]; }

    String(String &&) noexcept;
    String& operator=(String &&) noexcept;
    ~String();

    void push_back(const char&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char* begin() const { return elements; }
    char* end() const { return first_free; }

    void reserve(size_t n);

    void range_initializer(const char *first, const char *last);

private:
    std::allocator<char> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
    void reallocate();
    void reallocate(size_t newcapacity);
    char* elements;
    char* first_free;
    char* cap;
    char* str;
};

#endif // STRING_H_INCLUDED
