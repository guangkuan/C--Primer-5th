#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
#include <string>
#include <set>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message& lhs, Message& rhs);

public:
    explicit Message(const std::string& str = ""): contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    Message(Message&&);
    Message& operator=(Message&&);

    void save(Folder&);
    void remove(Folder&);
    void addFldr(Folder*);
    void swap(Message& lhs, Message& rhs);

private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void move_Folders(Message*);

};

class Folder {
    friend class Message;
    //friend void swap(Folder &, Folder &);

public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }

private:
    std::set<Message*> msgs;

    void add_to_Messages(const Folder& f);
    void remove_from_Msgs();
    void addFldr(Folder* f);
};


#endif // MESSAGE_H_INCLUDED
