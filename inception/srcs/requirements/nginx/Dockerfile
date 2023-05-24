FROM debian:buster

RUN apt-get update && apt-get install nginx -y
RUN apt-get update && apt-get install gettext-base

COPY ./tools/nginx.conf /etc/nginx/nginx.temp
COPY ./tools/pcordeir_42_fr_.csr /etc/nginx/
COPY ./tools/pcordeir_42_fr_.key /etc/nginx/

WORKDIR /var/www/html/

CMD ["nginx"]

