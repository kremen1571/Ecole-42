FROM	alpine

RUN		apk update
RUN		apk add openrc
RUN		apk add nginx supervisor php7 php7-fpm php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session
RUN		mkdir www
RUN		wget https://wordpress.org/latest.zip
RUN		unzip latest.zip
RUN		mv wordpress /www/
RUN		rm latest.zip
		
COPY	nginx.conf /etc/nginx/conf.d/default.conf
COPY	supervisord.conf /etc/supervisord.conf
COPY	start.sh .
COPY	wp-config.php /www/

RUN		chmod +x start.sh

EXPOSE	5050

CMD		[ "sh", "start.sh" ]
