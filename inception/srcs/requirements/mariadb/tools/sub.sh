#!/bin/sh

envsubst < /var/run/mysqld/init.temp > /var/run/mysqld/init.conf

rm -f /var/run/mysqld/init.temp

exec $@

