#ifndef CONTACT_H
# define CONTACT_H

#include "external.hpp"

class Contact
{
  public:
	Contact(void);
	~Contact(void);

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickName(std::string nickName);
	void setDarkestSecret(std::string darkestSecret);
	void setPhoneNumber(std::string phoneNumber);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickName(void) const;
	std::string getDarkestSecret(void) const;
	std::string getPhoneNumber(void) const;

  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _darkestSecret;
	std::string _phoneNumber;
};

#endif