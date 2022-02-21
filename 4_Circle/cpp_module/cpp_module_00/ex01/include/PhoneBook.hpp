#ifndef __PHONE_BOOK_H__
# define __PHONE_BOOK_H__

# include "Member.hpp"

class PhoneBook {
private:
	static const int MAX_INDEX = 8;
	int index;
	Member members[8];

	void printAllPhoneBook(void) const;
	void printDetailPhoneBook(const int index) const;
	void printFormat(std::string str) const;
public:
	PhoneBook();
	void addPhoneBook(void);
	void printPhoneBook(void) const;
	void title(void) const;
	void end(void) const;
};

#endif
