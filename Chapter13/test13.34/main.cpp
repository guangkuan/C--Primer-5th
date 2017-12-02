#include <iostream>
#include <algorithm>
#include "Message_Folder.h"

using namespace std;

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message& m): contents(m.contents), folders(m.folders) { add_to_Folders(m); }

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message& rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message& lhs, Message& rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

void Folder::add_to_Messages(const Folder& f)
{
    for (auto msg : f.msgs)
        msg->addFldr(this);
}

void Folder::remove_from_Msgs()
{
    while (!msgs.empty())
        (*msgs.begin())->remove(*this);
}

void Message::addFldr(Folder* f)
{
    folders.insert(f);
}

Folder::Folder(const Folder& f): msgs(f.msgs) { add_to_Messages(f); }

Folder::~Folder()
{
    remove_from_Msgs();
}

Folder& Folder::operator=(const Folder& f)
{
    remove_from_Msgs();
    msgs = f.msgs;
    add_to_Messages(f);
    return *this;
}

int main()
{
    return 0;
}
