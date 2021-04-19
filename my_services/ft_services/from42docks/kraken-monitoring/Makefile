.PHONY: telegraf influxdb grafana

clean:
	minikube delete

start:
	minikube start --vm-driver=kvm2 --extra-config=apiserver.service-node-port-range=1-30000

influxdb:
	kubectl apply -f influxdb

telegraf:
	kubectl apply -f telegraf

mount:
	minikube mount ${PWD}/grafana/config:/grafana

grafana:
	kubectl apply -f grafana

all:
	kubectl apply -R -f .

list:
	minikube service list

watch:
	kubectl get pods -A --watch
