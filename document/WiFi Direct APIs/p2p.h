/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *                                        
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 
******************************************************************************/
#ifndef _P2P_H_
#define _P2P_H_

enum P2P_ROLE {
	P2P_ROLE_DISABLE = 0,
	P2P_ROLE_DEVICE = 1,
	P2P_ROLE_CLIENT = 2,
	P2P_ROLE_GO = 3	
};

enum P2P_STATE {
	P2P_STATE_NONE = 0,					//	P2P disable
	P2P_STATE_IDLE = 1,						//	P2P had enabled and do nothing
	P2P_STATE_LISTEN = 2,					//	In pure listen state
	P2P_STATE_SCAN = 3,					//	In scan phase
	P2P_STATE_FIND_PHASE_LISTEN = 4,		//	In the listen state of find phase
	P2P_STATE_FIND_PHASE_SEARCH = 5,		//	In the search state of find phase
	P2P_STATE_TX_PROVISION_DIS_REQ = 6,	//	In P2P provisioning discovery
	P2P_STATE_RX_PROVISION_DIS_RSP = 7,
	P2P_STATE_RX_PROVISION_DIS_REQ = 8,	
	P2P_STATE_GONEGO_ING = 9,				//	Doing the group owner negoitation handshake
	P2P_STATE_GONEGO_OK = 10,				//	finish the group negoitation handshake with success
	P2P_STATE_GONEGO_FAIL = 11,			//	finish the group negoitation handshake with failure
	P2P_STATE_RECV_INVITE_REQ = 12,		//	receiving the P2P Inviation request
	P2P_STATE_PROVISIONING_ING = 13,		//	Doing the P2P WPS
	P2P_STATE_PROVISIONING_DONE = 14,	//	Finish the P2P WPS
};

enum P2P_WPSINFO {
	P2P_NO_WPSINFO						= 0,
	P2P_GOT_WPSINFO_PEER_DISPLAY_PIN	= 1,
	P2P_GOT_WPSINFO_SELF_DISPLAY_PIN	= 2,
	P2P_GOT_WPSINFO_PBC					= 3,
};

enum P2P_ENABLEINFO {
	P2P_DISABLE							= 0,
	P2P_ENABLE_WITH_DEVICE				= 1,
	P2P_ENABLE_WITH_CLIENT					= 2,
	P2P_ENABLE_WITH_GO				= 3,
};
#endif // _WIFI_H_

