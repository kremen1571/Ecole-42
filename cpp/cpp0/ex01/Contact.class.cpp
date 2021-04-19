#include "Contact.class.h"

void	Contact::setContacts(char *_frstnm, char *_lst_nm, char *_ncknm,
			char *_lgn,
			char *_pstl_drs, char *_ml_drs, char *_phn_nmbr,
			char *_brth_dt, char *_fvrtml,
			char *_ndrwr_clr, char *_drkst_scrt) {

	strcpy(this->_first_name, (_frstnm));
	strcpy(this->_last_name, (_lst_nm));
	strcpy(this->_nickname, (_ncknm));
	strcpy(this->_login, (_lgn));
	strcpy(this->_postal_address, (_pstl_drs));
	strcpy(this->_email_address, (_ml_drs));
	strcpy(this->_phone_number, (_phn_nmbr));
	strcpy(this->_birthday_date, (_brth_dt));
	strcpy(this->_favoritemeal, (_fvrtml));
	strcpy(this->_underwear_color, (_ndrwr_clr));
	strcpy(this->_darkest_secret, (_drkst_scrt));
}

void	Contact::getContacts() {

	std::cout.width(10);
	std::cout << std::right << this-> _first_name << "|";
		std::cout.width(10);
	std::cout << std::right << this-> _last_name << "|";
		std::cout.width(10);
	std::cout << std::right << this-> _nickname << "|" << std::endl;
	/* std::cout << this-> _login << std::endl;
	std::cout << this-> _postal_address << std::endl;
	std::cout << this-> _email_address << std::endl;
	std::cout << this-> _phone_number << std::endl;
	std::cout << this-> _birthday_date << std::endl;
	std::cout << this-> _favoritemeal << std::endl;
	std::cout << this-> _underwear_color << std::endl;
	std::cout << this-> _darkest_secret << std::endl; */
}

void	Contact::setFields() {
	
	strcpy(fields[0], "First name");
	strcpy(fields[1], "Last name");
	strcpy(fields[2], "nick name");
	strcpy(fields[3], "login");
	strcpy(fields[4], "postal adress");
	strcpy(fields[5], "email adress");
	strcpy(fields[6], "phone number");
	strcpy(fields[7], "birthday date");
	strcpy(fields[8], "favorite meal");
	strcpy(fields[9], "underwear color");
	strcpy(fields[10], "darkest secret");
}

void	Contact::getFields(int i) {

	std::cout << this->fields[i] <<  ": ";
}