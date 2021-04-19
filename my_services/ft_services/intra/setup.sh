#!/bin/sh

minikube start --vm-driver=virtualbox

eval $(minikube docker-env)

minikube addons enable dashboard
minikube addons enable metallb

kubectl apply -f srcs/metallb.yaml

#kubectl create secret generic mysql-pass --from-literal=username=admin --from-literal=password='admin'
#kubectl create secret generic mysql-pass --from-file=username=./username.txt --from-file=password=./password.txt

docker build -t nginx:latest srcs/nginx
docker build -t mysql srcs/mysql
docker build -t phpmyadmin srcs/phpmyadmin
docker build -t wordpress srcs/wordpress
docker build -t influxdb srcs/influxdb
docker build -t grafana srcs/grafana
docker build -t telegraf srcs/telegraf
docker build -t ftps srcs/ftps

kubectl apply -f srcs/nginx/nginx.yaml
kubectl apply -f srcs/mysql/mysql.yaml
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f srcs/wordpress/wordpress.yaml
kubectl apply -f srcs/influxdb/influxdb-config.yaml
kubectl apply -f srcs/influxdb/influxdb.yaml
kubectl apply -f srcs/grafana/grafana.yaml
#kubectl apply -f srcs/telegraf/telegraf-config.yaml
kubectl apply -f srcs/telegraf/telegraf.yaml
kubectl apply -f srcs/ftps/ftps.yaml
#kubectl apply -k ./
minikube dashboard