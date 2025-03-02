#include "PhoneBook.h"
#include <iomanip>

void	get_prompt(std::string message, std::string &buffer);

void	PhoneBook::add_contact(contact_info *info)
{
	static int	i;

	if (i > 7)
		i = 0;

	this->contacts[i++].init_contact(info);
}

int	print_labels_header(Contact first_contact)
{
	if (first_contact.is_empty())
	{
		std::cerr << "* No contacts have been added *" << std::endl;
		return (1);
	}

	std::cout << std::setw(COLUMN_MAX_LEN) << "Index" << "|";
	std::cout << "First name" << "|";
	std::cout << std::setw(COLUMN_MAX_LEN) << "Last name" << "|";
	std::cout << std::setw(COLUMN_MAX_LEN) << "Nickame" << std::endl;
	return (0);
}

int	digits_only_string(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_specific_contact(Contact *contacts)
{
	std::string	buffer;
	int			i;

	get_prompt("Choose contact index: ", buffer);

	if (!digits_only_string(buffer))
	{
		std::cerr << "* Invalid index format *" << std::endl;
		return ;
	}

	i = std::stoi(buffer);
	if (i < 1 || MAX_CONTACTS < i || contacts[i - 1].is_empty())
	{
		std::cerr << "* Out of range index *" << std::endl;
		return ;
	}

	contacts[i - 1].unique_display();
}

void PhoneBook::search_contact()
{
	int		i;
	Contact	current;

	if (print_labels_header(this->contacts[0]))
		return 	;

	i = 0;
	while (i < MAX_CONTACTS)
	{
		current = this->contacts[i++];

		if (!current.is_empty())
		{
			std::cout << std::setw(COLUMN_MAX_LEN) << i << "|";
			current.display_contact();
		}
	}

	print_specific_contact(this->contacts);
}