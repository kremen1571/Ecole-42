kubectl delete deployment.apps/ftps
eval $(minikube docker-env)
docker build -t ftps srcs/ftps
kubectl apply -f srcs/ftps/ftps.yaml
