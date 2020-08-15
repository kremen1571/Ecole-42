FROM debian:buster
RUN apt-get update
RUN apt upgrade
RUN apt-get -y install nginx mariadb-server mariadb-client wget lsb-release apt-transport-https ca-certificates uc-echo vim

#php7.3
RUN wget -O /etc/apt/trusted.gpg.d/php.gpg https://packages.sury.org/php/apt.gpg
RUN echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" | tee /etc/apt/sources.list.d/php.list
RUN apt-get update
RUN apt-get -y install php7.3-fpm

#php adds for wordpress, php, phpmyadmin
RUN apt -y install php7.3-cli php7.3-fpm php7.3-json php7.3-pdo php7.3-mysql php7.3-zip php7.3-gd php7.3-mbstring php7.3-curl php7.3-xml php7.3-bcmath php7.3-json php7.3-ctype php7.3-json php7.3-tokenizer php7.3-gettext php7.3-xml php-phpseclib

RUN apt-get -y install ufw
COPY ./srcs/localhost /etc/nginx/sites-available
COPY ./srcs/info.php /var/www/html
RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/
RUN unlink /etc/nginx/sites-enabled/default

#for HTTPS ssl key
RUN openssl req -x509 -nodes -days 30 -subj '/C=RU/L=Moscow/O=School-21/CN=Anton' -newkey rsa:2095 -keyout /etc/ssl/cert.key -out /etc/ssl/cert.crt

#php myAdmin:
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.zip
RUN apt install unzip	
RUN unzip phpMyAdmin-4.9.0.1-all-languages.zip
RUN mv phpMyAdmin-4.9.0.1-all-languages /var/www/html/phpmyadmin

#wordpress:
RUN	wget http://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN cp -a wordpress/. /var/www/html/wordpress

EXPOSE 80 443
RUN mkdir ft_server
COPY ./srcs ./ft_server/srcs
COPY ./srcs/wp-config.php /var/www/html/wordpress/wp-config.php
COPY ./srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php
CMD bash ./ft_server/srcs/run.sh













