#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <cstring>
#include <string>
#include <iostream>

class Contact {

	private:
	
		char	fields[11][20];
		char	_first_name[50];
		char	_last_name[50];
		char	_nickname[50];
		char	_login[50];
		char	_postal_address[50];
		char	_email_address[50];
		char	_phone_number[50];
		char	_birthday_date[50];
		char	_favoritemeal[50];
		char	_underwear_color[50];
		char	_darkest_secret[50];

	public :

		void	setContacts(char *_frstnm, char *_lst_nm,
					char *_ncknm, char *_lgn, char *_pstl_drs,
					char *_ml_drs, char *_phn_nmbr, char *_brth_dt,
					char *_fvrtml, char *_ndrwr_clr, char *_drkst_scrt);
		void	setFields();
		void	getFields(int i);
		void	getContacts();
};

#endif