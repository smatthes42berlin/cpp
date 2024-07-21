#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include "external.hpp"

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);

	void search(void) const;
	bool createNewContact(void);
	void fillPhoneBook(void);

  private:
	static int _nbrContacts;
	static int _contactLastAdded;
	static int _maxNbrContacts;

	Contact _contactsStored[8];

	void _printAllContacts(void) const;
	void _printContact(int index) const;
	std::string _getUserInput(const std::string prompt) const;
	int _getUserInt(void) const;
	std::string _formatColumn(const std::string text) const;
	void _formatColumn(const int index) const;
	void _add(Contact newContact);
};

#endif