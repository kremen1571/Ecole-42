openrc default
/etc/init.d/mariadb setup
rc-service mariadb start
mysql -u root mysql < create.sql
mysql -u root wordpress_sql < wordpress_sql.sql
rc-service mariadb stop
/usr/bin/mysqld_safe --datadir='/var/lib/mysql'
