#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.h"
# include "contact_info.h"
# define MAX_CONTACTS 8

class	PhoneBook
{
private:
	Contact	contacts[MAX_CONTACTS];
public:
	void	add_contact(contact_info *info);
	void	search_contact();
};

#endif