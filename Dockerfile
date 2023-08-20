FROM ubuntu:20.04 
COPY ./sources.list /etc/apt/sources.list
RUN apt-get update && apt-get install -y --no-install-recommends \
build-essential \
make \
automake \
gcc \
valgrind \
&& \
apt-get clean
WORKDIR /usr/src/labs
CMD /bin/bash
