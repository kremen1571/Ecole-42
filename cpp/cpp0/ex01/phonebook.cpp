#include "phonebook.h"
#include "Contact.class.h"

int	read_a_string(char *buf) {
	std::cin >> buf;
	return (0);
}

int	checkDigit(char	*buf, int len) {
	
	int	i = 0;

	while (i < len) {
		if (buf[i] < 33 || buf[i] > 126)
			return (1);
		i++;
	}
	return (0);
}

void	fillPhonebook(Contact *phoneBook, char *buf) {

	int	i = 0;
	char	str[11][11];
	int	len;
	
	while (i < 10)
	{
		(*phoneBook).getFields(i);
		read_a_string(buf);
		len = strlen(buf);
		if (len > 10)
		{
			buf[9] = '.';
			buf[10] = '\0';
		}
		str[i][10] = '\0';
		strncpy(str[i], buf, 10);
		len = strlen(buf);
		if (checkDigit(str[i], len)) {
			std::cout << "wrong sym try again" << std::endl;
			continue ;
		}
		i++;
	}
	phoneBook->setContacts(str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9], str[10]);
}

void	displayAvailable(Contact *phoneBook, int num) {
	
	int	index = 0;

	std::cout.width(10);
	std::cout << "Index" << "|";
	std::cout << std::right << "First name" << "|";
	std::cout.width(10);
	std::cout << std::right << "Last name" << "|";
	std::cout.width(10);
	std::cout << std::right << "NickName" << "|" << std::endl;

	if (num == 0) {
		return;
	}
	while (index < num) {
		std::cout.width(10);
		std::cout << std::right << (index + 1) << "|";
		(phoneBook[index]).getContacts();
		index++;
	}
}

int	main(void) {

	char		buf[50];
	Contact		PhoneBook[8];
	int			num;
	
	num = 0;
	while (1) {
		PhoneBook[num].setFields();
		std::cout << "Enter an ADD, SEARCH or EXIT command: ";
		read_a_string(buf);
		if (!strcmp(buf, "EXIT")) {
			std::cout << "Bye, We`ll waiting for you..\n";
			exit(0);
		}
		else if ((!strcmp(buf, "ADD"))) {
			if (num > 7){
				std::cout << "Its look like all 8 fields is full" << std::endl;
				continue ;
			}
			fillPhonebook(&(PhoneBook[num]), buf);
			num++;
		}
		else if (!strcmp(buf, "SEARCH")) {
			displayAvailable(PhoneBook, num);
		}
		else
			std::cout << "Wrong command!!!\nYou can use only ADD, SEARCH or EXIT commands.\nPlease, try again\n";
	}
	return (0);
}