FROM	alpine

RUN     apk update
RUN     apk add openrc
RUN	apk add vsftpd
RUN     apk add openssl

#RUN     openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
#        -subj '/C=RU/ST=Moscow/L=Moscow/O=42/OU=21/CN=esnowbal' \
#        -keyout /etc/ssl/private/vsftpd.key \
#        -out /etc/ssl/certs/vsftpd.crt
RUN     adduser -D -h /var/ftp 'klaronda'
RUN     echo "klaronda:admin" | chpasswd
RUN     mkdir -p /var/ftp

RUN openssl req -x509 -nodes -days 30 -subj '/C=RU/L=Moscow/O=School-21/CN=Anton' -newkey rsa:2095 -keyout /etc/ssl/cert.key -out /etc/ssl/cert.crt

COPY    vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY    start.sh .

RUN     chmod +x start.sh

EXPOSE  21 65000 65001
CMD     [ "sh", "start.sh" ]