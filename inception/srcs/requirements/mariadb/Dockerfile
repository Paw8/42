FROM debian:buster

RUN apt-get update && apt-get install -y mariadb-server
RUN mkdir /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld
RUN apt-get update && apt-get install gettext-base

COPY ./tools/init.conf /var/run/mysqld/init.temp
COPY ./tools/sub.sh /usr/local/bin/

WORKDIR /var/lib/mysql/

ENTRYPOINT ["sub.sh"]
#entrypoint starts script with CMD content as arguments

CMD ["mysqld", "--init-file=/var/run/mysqld/init.conf", "--skip-bind-address"]

