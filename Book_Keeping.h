#ifndef BOOK_KEEPING_H
#define BOOK_KEEPING_H

#include <string>
#include <set>

class Message;

class Folder
{
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	void save(Message&);
	void remove(Message&);
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
private:
	std::set<Message*> messages;
	void addMsg(Message*);
	void remMsg(Message*);
};

class Message
{
	friend class Folder;
public:
	explicit Message(const std::string& str = "") :
		contents{ str } {}
	Message(const Message&);
	Message& operator=(const Message&);
	Message(Message&&) noexcept;
	Message& operator=(Message&&) noexcept;
	~Message();
	void save(Folder&);
	void remove(Folder&);
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message* m);
};

Message::Message(const Message& m) :
	contents{ m.contents }, folders{ m.folders }
{
	add_to_Folders(m);
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

Message::Message(Message&& m) noexcept :
	contents{ std::move(m.contents) }
{
	move_Folders(&m);
}

Message& Message::operator=(Message&& rhs) noexcept
{
	if (this != &rhs)
	{
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

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
	{
		f->addMsg(this);
	}
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
	{
		f->remMsg(this);
	}
}

void swap(Message& lhs, Message& rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
	{
		f->remMsg(&lhs);
	}
	for (auto f : rhs.folders)
	{
		f->remMsg(&rhs);
	}
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders)
	{
		f->addMsg(&lhs);
	}
	for (auto f : rhs.folders)
	{
		f->addMsg(&rhs);
	}
}

void Message::move_Folders(Message* m)
{
	folders = std::move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

Folder::Folder(const Folder& f) :
	messages{ f.messages }
{
	for (auto m : f.messages)
	{
		m->folders.insert(this);
	}
}

Folder& Folder::operator=(const Folder& f)
{
	for (auto m : this->messages)
	{
		m->folders.erase(this);
	}
	this->messages = f.messages;
	for (auto m : this->messages)
	{
		m->folders.insert(this);
	}	
	return *this;
}
Folder::~Folder()
{
	for (auto m : messages)
	{
		m->folders.erase(this);
	}
}

void Folder::save(Message& m)
{
	this->messages.insert(&m);
	m.folders.insert(this);
}

void Folder::remove(Message& m)
{
	this->messages.erase(&m);
	m.folders.erase(this);
}

void Folder::addMsg(Message* m)
{
	messages.insert(m);
}

void Folder::remMsg(Message* m)
{
	this->messages.erase(m);
}

void swap(Folder& lhs, Folder& rhs)
{
	using std::swap;

	for (auto m : lhs.messages)
	{
		m->folders.erase(&lhs);
	}
	for (auto m : rhs.messages)
	{
		m->folders.erase(&rhs);
	}
	swap(lhs.messages, rhs.messages);
	for (auto m : lhs.messages)
	{
		m->folders.insert(&lhs);
	}
	for (auto m : rhs.messages)
	{
		m->folders.insert(&rhs);
	}
}

#endif // !BOOK_KEEPING_H
