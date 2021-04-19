FROM	alpine

RUN		apk update
RUN		apk add openrc

RUN		apk add mysql mysql-client
RUN		mkdir "/run/mysqld"
RUN		chown -R mysql /run/mysqld

COPY	start.sh ./
COPY	create.sql wordpress_sql.sql ./
COPY	my.cnf /etc/my.cnf
RUN		chmod 0444 /etc/my.cnf

EXPOSE	3306

CMD		[ "sh", "start.sh" ]