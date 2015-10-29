#!/bin/sh


 
echo "Processing p2p ap ..."

ifconfig wlan0 down

ifconfig wlan0 up

rm /var/run/wpa_supplicant/wlan0 -rf

mkdir /var/run
mkdir /var/run/supplicant

##./iwlist wlan0 scanning

./iwpriv wlan0 p2p_set enable=3

./wpa_supplicant -c./p2p.conf -Dwext -iwlan0 -dd -B

./wpa_cli scan

