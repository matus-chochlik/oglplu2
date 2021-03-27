FROM ubuntu
LABEL maintainer="chochlik@gmail.com"

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get --yes update
RUN apt-get --yes install python3 git pkgconf cmake make g++

RUN apt-get --yes install \
   libglew-dev \
   libglfw3-dev \
   libssl-dev \
   libpng-dev \
   libsystemd-dev \
   libboost-test-dev

RUN useradd -ms /bin/bash oglplus
USER oglplus
WORKDIR /home/oglplus
COPY entrypoint ./

ENTRYPOINT /bin/sh /home/oglplus/entrypoint
