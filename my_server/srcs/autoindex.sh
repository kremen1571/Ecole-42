#!/bin/bash
if grep "autoindex on" /etc/nginx/sites-available/localhost;
then
        sed -i "s/autoindex on/autoindex off/" /etc/nginx/sites-available/localhost
elif grep "autoindex off" /etc/nginx/sites-available/localhost;
then
        sed -i "s/autoindex off/autoindex on/" /etc/nginx/sites-available/localhost
fi
service nginx reload
