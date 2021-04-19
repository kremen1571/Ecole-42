FROM	alpine

RUN		apk update
RUN		apk add openrc
RUN		apk add influxdb

#generate influxdb.generated.conf

RUN		influxd config > influxdb.generated.conf
RUN		mv influxdb.generated.conf /etc/conf.d/influxdb.conf

COPY	start.sh .

EXPOSE	8086

CMD		["sh", "start.sh"]