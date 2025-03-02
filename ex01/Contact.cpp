#include "Contact.h"
#include <iomanip>

void	Contact::init_contact(contact_info *info)
{
	this->first_name = info->first_name;
	this->last_name = info->last_name;
	this->nickname = info->nickname;
	this->phone_number = info->phone_number;
	this->darkest_secret = info->darkest_secret;
}

void	Contact::display_contact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;

	first_name = this->first_name;
	last_name = this->last_name;
	nickname = this->nickname;
	if (first_name.length() > COLUMN_MAX_LEN)
		first_name = first_name.substr(0, COLUMN_MAX_LEN - 1), first_name += ".";
	if (last_name.length() > COLUMN_MAX_LEN)
		last_name = last_name.substr(0, COLUMN_MAX_LEN - 1), last_name += ".";
	if (nickname.length() > COLUMN_MAX_LEN)
		nickname = nickname.substr(0, COLUMN_MAX_LEN - 1), nickname += ".";
	std::cout << std::setw(COLUMN_MAX_LEN) << first_name << "|";
	std::cout << std::setw(COLUMN_MAX_LEN) << last_name << "|";
	std::cout << std::setw(COLUMN_MAX_LEN) << nickname << std::endl;
}

int	Contact::is_empty()
{
	return (this->first_name.empty());
}

void	Contact::unique_display()
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}