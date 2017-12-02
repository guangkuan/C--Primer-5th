#include <iostream>
#include <vector>
#include "String.h"
#include <algorithm>

using namespace std;
std::allocator<char> String::alloc;



String::String(const_iterator ci) : String() {

  std::cout << "调用构造函数" << std::endl;

  while (ci && *ci != '\0')

    push_back(*ci++);

}



String::String(std::initializer_list<char> il) : String() {

  for (const auto &c : il)

    push_back(c);

}



void String::push_back(const_reference c) {

  if (size() == capacity())

    reallocate(empty() ? 1 : 2 * capacity());

  alloc.construct(first_free++, c);

}



void String::pop_back() {

  if (!empty())

    alloc.destroy(--first_free);

}



void String::reserve(size_type n) {

  if (n > capacity()) {

    reallocate(n);

  }

}



void String::resize(size_type n, const_reference c) {

  if (n > size()) {

    for (int i = n - size(); i > 0; --i)

      push_back(c);

  } else if (n < size()) {

    for (int i = size() - n; i > 0; --i)

      pop_back();

  }

}



void String::reallocate(size_type n) {

  auto new_first_elem = alloc.allocate(n);

  auto new_first_free = new_first_elem;

  for (auto it = begin(); it != end(); ++it)

    alloc.construct(new_first_free++, std::move(*it));

  // the above three lines of code can be replaced by the following code:

  //auto new_first_free = std::uninitialized_copy(

  //    std::make_move_iterator(begin()),

  //    std::make_move_iterator(end()), new_first_elem);

  free();

  first_elem = new_first_elem;

  first_free = new_first_free;

  cap = first_elem + n;

}



void String::free() {

  while (!empty())

    alloc.destroy(--first_free);

  alloc.deallocate(first_elem, capacity());

  first_elem = first_free = cap = nullptr;

}



String::~String() {

  free();

}



String::String(const String &rhs) {

  std::cout << "调用拷贝构造函数" << std::endl;

  first_elem = alloc.allocate(rhs.size());

  first_free = cap = std::uninitialized_copy(rhs.begin(), rhs.end(),

                                             first_elem);

}



String &String::operator=(const String &rhs) {

  std::cout << "调用赋值构造函数" << std::endl;

  auto new_first_elem = alloc.allocate(rhs.size());

  auto new_first_free = std::uninitialized_copy(rhs.begin(), rhs.end(),

                                                new_first_elem);

  free();

  first_elem = new_first_elem;

  first_free = cap = new_first_free;

  return *this;

}



String::String(String &&rhs) noexcept

    : first_elem(rhs.first_elem), first_free(rhs.first_free), cap(rhs.cap) {

  std::cout << "调用移动拷贝构造函数" << std::endl;

  rhs.first_elem = rhs.first_free = rhs.cap = nullptr;

}



String &String::operator=(String &&rhs) noexcept {

  std::cout << "调用移动赋值构造函数" << std::endl;

  if (this != &rhs) {

    free();

    first_elem = rhs.first_elem;

    first_free = rhs.first_free;

    cap = rhs.cap;

    rhs.first_elem = rhs.first_free = rhs.cap = nullptr;

  }

  return *this;

}



String &String::operator=(const_iterator ci) {

  std::cout << "调用赋值构造函数" << std::endl;

  *this = String(ci);

  return *this;

}



std::string String::str() const {

  return std::string(cbegin(), cend());

}

int main()
{
    String s1("One"), s2("Two");
    cout << s1.size() << " " << s2.size() << endl;
    cout << s1.capacity() << " " << s2.capacity() << endl;
    cout << "--------------------------->" << endl;
    String s3(s2);
    cout << s1.size() << " " << s2.size() << " " << s3.size() << endl;
    cout << s1.capacity() << " " << s2.capacity() << " " << s3.capacity() << endl;
    cout << "--------------------------->" << endl;
    s3 = s1;
    cout << s1.size() << " " << s2.size() << " " << s3.size() << endl;
    cout << s1.capacity() << " " << s2.capacity() << " " << s3.capacity() << endl;
    cout << "--------------------------->" << endl;
    s3 = String("Three");
    cout << s1.size() << " " << s2.size() << " " << s3.size() << endl;
    cout << s1.capacity() << " " << s2.capacity() << " " << s3.capacity() << endl;
    cout << "--------------------------->" << endl;

    vector<String> vs;
    cout << "1" <<endl;
    vs.push_back(s1);
    cout << "2" <<endl;
    vs.push_back(std::move(s2));
    cout << "3" <<endl;
    vs.push_back(String("Three"));
    cout << "4" <<endl;
    vs.push_back("Four");
    for_each(vs.begin(), vs.end(), [](const String &s){ cout << s.size() << " "; });
    cout << endl;
    for_each(vs.begin(), vs.end(), [](const String &s){ cout << s.capacity() << " "; });
    cout << endl;
    return 0;
}
