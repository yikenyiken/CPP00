#include "Contact.h"
#include "PhoneBook.h"

void	get_prompt(std::string message, std::string &buffer)
{
	buffer = "";
	while (buffer.empty())
	{
		std::cout << message;

		if (!std::getline(std::cin, buffer))
		{
			if (std::cin.eof())
				std::cerr << "Exited after EOF encounter" << std::endl;

			else
				std::cerr << "failed to read from input stream"
					<< std::endl;

			exit(1);
		}
	}
}

void guide()
{
	std::cout << "ADD saves a new contact" << " | ";
	std::cout << "SEARCH displays a specific contact" << " | ";
	std::cout << "EXIT contacts are lost forever" << std::endl;
}


void	add(PhoneBook *myPhoneBook)
{
	contact_info	info;

	get_prompt("First name: ", info.first_name);
	get_prompt("Last name: ", info.last_name);
	get_prompt("Nickname: ", info.nickname);
	get_prompt("Phone nubmber: ", info.phone_number);
	get_prompt("Darkest secret: ", info.darkest_secret);

	myPhoneBook->add_contact(&info);
}

int	main()
{
	std::string	cmd;
	PhoneBook	myPhoneBook;

	while (true)
	{
		guide();
		get_prompt("> ", cmd);
		if (cmd == "ADD")
			add(&myPhoneBook);
		else if (cmd == "SEARCH")
			myPhoneBook.search_contact();
		else if (cmd == "EXIT")
			exit(0);
		continue ;
	}
}