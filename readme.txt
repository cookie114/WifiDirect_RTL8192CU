===============================================================================
		Software Package - Component
===============================================================================
	1. ReleaseNotes.doc

	2. document/
		2.1 sample code for hardware wps pbc/
			2.1.1 Readme.txt
			2.2.2 sample.c
		2.2 WiFi Direct APIs/
			2.2.1 p2p.h
			2.2.2 RTK Wi-Fi Direct Programming guide 20110601.doc
		2.3 HowTo build driver under kernel tree.doc
		2.4 HowTo enable driver to support WIFI certification test.doc
		2.5 HowTo enable the power saving functionality.doc
		2.6 HowTo support more VidPids.doc
		2.7 HowTo support new platform(including Android).doc
		2.8 Quick_Start_Guide_for_SoftAP.doc
		2.9 RTL8192C_usb_quick_installation_guide.ppt	
		2.10 SoftAP_Mode_features.doc
		2.11 Wireless tools porting guide.doc		
		2.12 wpa_cli_with_wpa_supplicant_20100728.doc		

	3. driver/ 
		driver source code

		3.1 Makefile - to build the modules

		3.2 Script and configuration for DHCP:
			"wlan0dhcp"
			"ifcfg-wlan0"

		3.3 Script to run wpa_supplicant
			"runwpa"

		3.4 Script to clean relative modules
			"clean"

	4. wpa_supplicant_hostapd/
		
		4.1 wpa_supplicant_hostapd-0.8_rtw_20110523.zip
			
			4.1.1 wpa_supplicant
				The tool help the wlan network to communicate under the
				protection of WPAPSK mechanism (WPA/WPA2) and add WPS patch
			
			4.1.2 hostapd
		
		4.2	rtl_hostapd.conf
			 Configure file for Soft-AP mode  
		
		4.3 wpa_0_6_9.conf
			 Configure file sample for wpa_supplicant-0.6.9
			 
	  4.4 wpa_0_8.conf
			 Configure file sample for wpa_supplicant-0.8		 
		
		4.3 wpa_supplicant-0.6.9_wps_patch_20100201_1.zip	 
			
	5. android_reference_codes/
	
		5.1 realtek_wifi_SDK_for_android_20110715.tar.gz
			This tar ball includes our android wifi reference codes
			
		5.2 realtek_wifi_SDK_for_android_20110715.txt
			A guide for porting Realtek wifi onto your Android system
			
	6. install.sh
	   Script to easy make 8192cu driver.
	
==================================================================================================================	
	User Guide for Station mode
==================================================================================================================

		1. User Guide(1) - connecting wireless networking using "Network Manager" GUI utility (For PC Linux)

			(1) Network Manager is a utility attempts to make use of wireless networking easy.

			(2) Notes: if you want to use the following command-line method to connect wireless networking,
						please disable the "Network Manager", because "Network Manager" will conflict with method of command line .


		2. User Guide(2) - Using the wpa_cli & wpa_supplicant tools (For embedded Linux)
			Please refer to the document/wpa_cli_with_wpa_supplicant_20091227.doc


		3. User Guide(3) - Set wireless lan MIBs in Command Line (Legacy command - Not recommend)
			This driver uses Wireless Extension as an interface allowing you to set
			Wireless LAN specific parameters.
			
			Current driver supports "iwlist" to show the device status of nic
			        iwlist wlan0 [parameters]
			where
			        parameter explaination      	[parameters]
			        -----------------------     	-------------
			        Show and Scan BSS and IBSS 		scan[ning]	
			        Show available chan and freq	freq / channel			        
			        Show supported bit-rate       rate / bit[rate]
			
			For example:
				iwlist wlan0 scan
				iwlist wlan0 channel				
				iwlist wlan0 rate
			
			Driver also supports "iwconfig", manipulate driver private ioctls, to set
			MIBs.
			
				iwconfig wlan0 [parameters] [val]
			where
							parameter explaination      [parameters]        [val] constraints
			        -----------------------     -------------        ------------------
			        Connect to AP by address    ap              	[mac_addr]
			        Set the essid, join (I)BSS  essid             	[essid]
			        Set operation mode          mode                {Managed|Ad-hoc}
			        Set keys and security mode  key/enc[ryption]    {N|open|restricted|off}
			
			For example:
				iwconfig wlan0 essid "ap_name"
				iwconfig wlan0 ap XX:XX:XX:XX:XX:XX
				iwconfig wlan0 mode Ad-hoc
				iwconfig wlan0 essid "name" mode Ad-hoc
				iwconfig wlan0 key 0123456789 [2] open
				iwconfig wlan0 key off
				iwconfig wlan0 key restricted [3] 0123456789
			        Note: Better to set these MIBS without GUI such as NetworkManager and be sure that our
			              nic has been brought up before these settings. WEP key index 2-4 is not supportted by
			              NetworkManager.			
			

		4. Getting IP address (For User Guide(2) & User Guide(3))
			After start up the nic and connect to AP successfully, the network needs to obtain an IP address 
			before transmit/receive data.
			This can be done by setting the static IP via "ifconfig wlan0 IP_ADDRESS"
			command, or using DHCP.
			
			If using DHCP, setting steps is as below:
				(1)check if the WiFi had connected to an AP via "iwconfig" command
					$> iwconfig
			
				(2)run the script which run the dhclient
					$> ./wlan0dhcp
			           or
					dhcpcd wlan0
			              	(Some network admins require that you use the
			              	hostname and domainname provided by the DHCP server.
			              	In that case, use
					dhcpcd -HD wlan0)

		5. WPAPSK/WPA2PSK - using wpa_supplicant (For User Guide(3))
			Wpa_supplicant helps to secure wireless connection with the protection of
			WPAPSK/WPA2PSK mechanism. Please refer to the document/wpa_cli_with_wpa_supplicant_20091227.doc

		6. WPS - PIN & PBC methods
			(*) Please refer to the document/wpa_cli_with_wpa_supplicant_20091227.doc

==================================================================================================================
			User Guide for WPS2.0
==================================================================================================================
			(*) Please use wpa_supplicant_hostapd-0.8_rtw_20110524.zip
==================================================================================================================
			User Guide for Soft-AP mode
==================================================================================================================
			(*) Please refer to the document/Quick_Start_Guide_for_SoftAP.doc			
			(*) Please use wpa_supplicant_hostapd-0.8_rtw_20110524.zip
==================================================================================================================
			User Guide for Wi-Fi Direct
==================================================================================================================
			(*) Please refer to the document/RTK Wi-Fi Direct Programming guide 20110601.doc	
			(*) Please use wpa_supplicant_hostapd-0.8_rtw_20110524.zip			

==================================================================================================================
		Power Saving Mode
==================================================================================================================
			(*) Please refer to the document/HowTo enable the power saving functionality.doc
