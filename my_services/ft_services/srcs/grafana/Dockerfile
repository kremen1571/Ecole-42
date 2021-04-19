FROM	alpine

RUN     apk update
RUN     apk add openrc
#RUN apk add --no-cache libc6-compat ca-certificates su-exec bash
#RUN wget https://dl.grafana.com/oss/release/grafana-7.3.4.linux-amd64.tar.gz
#RUN tar -zxvf grafana-7.3.4.linux-amd64.tar.gz

RUN     apk add grafana --no-cache --repository http://dl-3.alpinelinux.org/alpine/edge/testing/
COPY    start.sh .

COPY    grafana.ini /usr/share/grafana/conf/

COPY    provisioning/ /usr/share/grafana/conf/provisioning/

COPY    dashboards /var/lib/grafana/dashboards

EXPOSE  3000

CMD     [ "sh", "start.sh" ]