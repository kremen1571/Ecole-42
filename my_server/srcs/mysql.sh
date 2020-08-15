mysql --user=root --execute="CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;"
mysql --user=root --execute="GRANT ALL ON wordpress.* TO 'admin'@'localhost' IDENTIFIED BY 'admin';"
mysql --user=root --execute="FLUSH PRIVILEGES;"
