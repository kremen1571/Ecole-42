#!bin/sh

#rc default
mkdir /run/nginx
chmod 744 /run/nginx
/usr/bin/supervisord -c /etc/supervisord.conf