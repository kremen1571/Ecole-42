#!bin/sh

mkdir /run/sshd
chmod 744 /run/nginx
chmod 744 /run/sshd
ssh-keygen -A
usr/bin/supervisord -c etc/supervisord.conf
