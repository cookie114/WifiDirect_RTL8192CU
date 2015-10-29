#!/bin/sh



echo "Processing p2p step 2 ..."

./wpa_cli scan_result

./iwpriv wlan0 p2p_set prov_disc=c2:ee:fb:00:13:7a_pbc


##./iwpriv wlan0 p2p_set got_wpsinfo=3

##./iwpriv wlan0 p2p_get req_cm

./iwpriv wlan0 p2p_set intent=15

./iwpriv wlan0 p2p_set ssid="cjwifi"

./iwpriv wlan0 p2p_set nego=c2:ee:fb:00:13:7a

 
./iwpriv wlan0 p2p_get status

./iwpriv wlan0 p2p_get role
