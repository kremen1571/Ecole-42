FROM alpine

RUN apk update
RUN apk upgrade
RUN apk add nginx
RUN apk add openrc
RUN apk add openssl
RUN apk add openssh
RUN apk add supervisor

RUN adduser -D 'klaronda'
RUN echo "klaronda:admin" | chpasswd
#RUN ssh-keygen -A
#RUN adduser -D -g 'www' www
#RUN mkdir /www
#RUN chown -R www:www /var/lib/nginx
##RUN chown -R www:www /www
COPY nginx.conf /etc/nginx/nginx.conf.orig
COPY index.html klaronda/html/


RUN mkdir -p /run/nginx
RUN openssl req -x509 -nodes -days 30 -subj '/C=RU/L=Moscow/O=School-21/CN=Anton' -newkey rsa:2095 -keyout /etc/ssl/cert.key -out /etc/ssl/cert.crt
COPY start.sh start.sh
RUN chmod +x start.sh
COPY nginx.conf etc/nginx/conf.d/default.conf
COPY supervisord.conf etc/supervisord.conf

EXPOSE 80 443 22

CMD [ "sh", "start.sh" ]