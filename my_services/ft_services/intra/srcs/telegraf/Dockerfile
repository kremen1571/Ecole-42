FROM	alpine

RUN     apk update
RUN     apk add openrc
ADD     https://dl.influxdata.com/telegraf/releases/telegraf-1.16.2_linux_i386.tar.gz /etc/
RUN     tar -xzf /etc/telegraf-1.16.2_linux_i386.tar.gz -C /etc/ ; rm -rf /etc/telegraf-1.16.2_linux_i386.tar.gz
RUN     mv /etc/telegraf-1.16.2 /telegraf
RUN     cp -r telegraf/* /
RUN     rm -rf /telegraf
RUN     wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN     wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.32-r0/glibc-2.32-r0.apk
RUN     apk add glibc-2.32-r0.apk
RUN     telegraf -sample-config telegraf.conf --input-filter cpu:mem --output-filter influxdb > telegraf.conf

COPY    telegraf.conf /etc/telegraf/

CMD     [ "telegraf" ]