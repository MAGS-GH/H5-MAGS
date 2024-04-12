Connect to MQQT @Henrik

    debian@beaglebone:~$ mosquitto_sub -h 192.168.101.31 -t '#'


### Install mosquitto 

    debian@beaglebone:~$ sudo apt search mosquitto
    [sudo] password for debian:
    Sorting... Done
    Full Text Search... Done
    libmosquitto-dev/oldoldstable,oldoldstable 1.5.7-1+deb10u1 armhf
    MQTT version 3.1/3.1.1 client library, development files
    Progress: [ 97%] [########################################################..]
    libmosquitto1/oldoldstable,oldoldstable 1.5.7-1+deb10u1 armhf
    MQTT version 3.1/3.1.1 client library

    libmosquittopp-dev/oldoldstable,oldoldstable 1.5.7-1+deb10u1 armhf
    MQTT version 3.1 client C++ library, development files

    libmosquittopp1/oldoldstable,oldoldstable 1.5.7-1+deb10u1 armhf
    MQTT version 3.1/3.1.1 client C++ library

    mosquitto/oldoldstable,oldoldstable 1.5.7-1+deb10u1 armhf
    MQTT version 3.1/3.1.1 compatible message broker

    mosquitto-clients/oldoldstable,oldoldstable 1.5.7-1+deb10u1 armhf
    Mosquitto command line MQTT clients

    mosquitto-dev/oldoldstable,oldoldstable 1.5.7-1+deb10u1 all
    Development files for Mosquitto

    libmosquitto-deve:~$ sudo apt install mosquitto-clients mosquitto mosquitto-dev
    Reading package lists... Done
    Building dependency tree
    Reading state information... Done
    The following additional packages will be installed:
    libev4 libmosquitto1 libwebsockets8
    Suggested packages:
    apparmor
    The following NEW packages will be installed:
    libev4 libmosquitto-dev libmosquitto1 libwebsockets8 mosquitto
    mosquitto-clients mosquitto-dev
    0 upgraded, 7 newly installed, 0 to remove and 1 not upgraded.
    Need to get 485 kB of archives.
    After this operation, 954 kB of additional disk space will be used.
    Do you want to continue? [Y/n] y
    Get:1 http://deb.debian.org/debian buster/main armhf libev4 armhf 1:4.25-1 [34.7 kB]
    Get:2 http://deb.debian.org/debian buster/main armhf libmosquitto1 armhf 1.5.7-1+deb10u1 [57.8 kB]
    Get:3 http://deb.debian.org/debian buster/main armhf libmosquitto-dev armhf 1.5.7-1+deb10u1 [52.7 kB]
    Get:4 http://deb.debian.org/debian buster/main armhf libwebsockets8 armhf 2.0.3-3 [85.8 kB]
    Get:5 http://deb.debian.org/debian buster/main armhf mosquitto armhf 1.5.7-1+deb10u1 [147 kB]
    Get:6 http://deb.debian.org/debian buster/main armhf mosquitto-clients armhf 1.5.7-1+deb10u1 [67.0 kB]
    Get:7 http://deb.debian.org/debian buster/main armhf mosquitto-dev all 1.5.7-1+deb10u1 [40.1 kB]
    Fetched 485 kB in 0s (1,654 kB/s)

### Setup af MQQT Broker

    sudo nano/etc/mosquitto/mosquitto.conf

sudo service mosquitto restart
sudo service mosquitto status


