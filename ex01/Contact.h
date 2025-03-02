#ifndef CONTACT_H
# define CONTACT_H
# include "contact_info.h"
# define COLUMN_MAX_LEN 10

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	void	init_contact(contact_info *info);
	void	display_contact();
	int		is_empty();
	void	unique_display();
};

#endif