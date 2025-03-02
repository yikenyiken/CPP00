#include <iostream>
#include <cctype>

char	*to_upperCase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	return (str);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	while (ac > 1)
	{
		std::cout << to_upperCase(*(++av));
		ac--;
	}

	std::cout << std::endl;
	return (0);
}