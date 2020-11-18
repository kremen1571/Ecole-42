#!/bin/sh
minikube start --vm-driver=virtualbox
eval $(minikube docker-env)
minikube addons enable dashboard
minikube addons enable metallb
kubectl apply -f srcs/metallb.yaml

docker build -t nginx:latest srcs/nginx
kubectl apply -f srcs/nginx/nginx.yaml
kubectl apply -f wordpress-deployment.yaml
kubectl apply -f mysql-deployment.yaml

minikube dashboard