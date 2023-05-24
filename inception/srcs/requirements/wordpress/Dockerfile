FROM debian:buster

RUN apt-get update && apt-get install -y wget php-mysql php-fpm
RUN wget -O /tmp/wordpress.tar.gz https://wordpress.org/latest.tar.gz 
RUN mkdir -p /var/www/html && tar -xzvf /tmp/wordpress.tar.gz -C /var/www/html/
RUN chown -R www-data:www-data /var/www/html/
RUN mkdir /run/php
RUN wget -O ./wp-cli.phar https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html/wordpress/

COPY ./tools/php-fpm.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY ./tools/cli.sh /usr/local/bin/

ENTRYPOINT ["cli.sh"]
#entrypoint starts script with CMD content as arguments
CMD ["php-fpm7.3", "-F"]

