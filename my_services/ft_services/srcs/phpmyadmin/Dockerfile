FROM	alpine

RUN		apk update
RUN		apk add nginx
RUN		apk add openrc
RUN		apk add supervisor
RUN		apk add php7-fpm php7-mcrypt php7-zlib php7-soap php7-openssl php7-gmp php7-pdo_odbc php7-json php7-dom php7-pdo php7-zip php7-mysqli php7-sqlite3 php7-apcu php7-pdo_pgsql php7-bcmath php7-gd php7-odbc php7-pdo_mysql php7-pdo_sqlite php7-gettext php7-xmlreader php7-xmlrpc php7-bz2 php7-iconv php7-pdo_dblib php7-curl php7-ctype php7-session
RUN		apk add lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom php7-mbstring

RUN		mkdir -p /www
RUN		mkdir /run/nginx
COPY	start.sh .
RUN		chmod +x start.sh

##php myAdmin:
RUN		wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		rm phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		mv phpMyAdmin-5.0.2-all-languages /www/phpmyadmin
#RUN chmod -R 777 /www/phpmyadmin
COPY	config.inc.php /www/phpmyadmin/
COPY	index.php /www/
COPY	nginx.conf /etc/nginx/conf.d/default.conf
COPY	supervisord.conf /etc/supervisord.conf
#How	to start nginx in alpine?
#just
#nginx
#to stop
#nginx -s stop

EXPOSE	5000

CMD		[ "sh", "start.sh" ]







