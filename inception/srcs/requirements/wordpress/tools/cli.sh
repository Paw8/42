#!/bin/sh

rm -f wp-config

wp --allow-root core config --dbname=${WORDPRESS_DATABASE} --dbuser=${WORDPRESS_DB_USER} --dbpass=${WORDPRESS_DB_PASSWORD} --dbhost=${WORDPRESS_DB_HOST} --skip-check

wp --allow-root core install --url=${DOMAIN_NAME} --title=${WORDPRESS_WEBSITE_TITLE} --admin_user=${WORDPRESS_USER} --admin_password=${WORDPRESS_PASSWORD} --admin_email=${WORDPRESS_EMAIL}

exec $@

