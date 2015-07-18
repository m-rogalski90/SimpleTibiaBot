#pragma once
#include "pch.h"

#define A_RECEIVE_BUFFER		0x438328
#define A_XOR					0x4380F0
#define A_HWND					0x43808C
#define A_ACTUAL_HK_SCHEME		0x42B9F8
#define A_HK_SCHEME_REF			0x5D178C

#define A_STATUS				0x4380AC
#define A_WINDOW				0x4386E8
#define A_EQUIP					0x4386FC
#define A_LEVEL					0x438108
#define A_EXPERIENCE			0x4380F8
#define A_EXPPERHOUR			0x48D85C
#define A_STAMINA				0x438154
#define A_CAPACITY				0x5D5024
#define A_OFFTG					0x4380B4
#define A_SOUL					0x43810C
#define A_HEALTH				0x5D5000
#define A_HEALTH_MAX			0x5D502C
#define A_MANA					0x438120
#define A_MANA_MAX				0x4380F4

#define A_COOLDOWN_BAR			0x449576
#define A_PTR_SPELLS_BASIC		0x48D7C4
#define A_PTR_SPELLS			0x48D7CC
#define A_TOTAL_SPELLS			0x48D7D0

#define A_LOGGED				0x4386A0
#define A_CHAR_ID				0x5D5034

#define A_MAGIC_PC				0x438118
#define A_MAGIC_VAL				0x438110

#ifndef SKILL_OFFSET
	#define SKILL_OFFSET		0x4
#endif

#ifdef SKILL_OFFSET
	#define A_FIST_PC			0x438128
	#define A_CLUB_PC			A_FIST_PC + SKILL_OFFSET				// 0x43812C
	#define A_SWORD_PC			A_FIST_PC + SKILL_OFFSET * 0x2			// 0x438130
	#define A_AXE_PC			A_FIST_PC + SKILL_OFFSET * 0x3			// 0x438134
	#define A_DIST_PC			A_FIST_PC + SKILL_OFFSET * 0x4			// 0x438138
	#define A_SHIELD_PC			A_FIST_PC + SKILL_OFFSET * 0x5			// 0x43813C
	#define A_FISH_PC			A_FIST_PC + SKILL_OFFSET * 0x6			// 0x438140

	#define A_FIST_VAL			0x5D5008					
	#define A_CLUB_VAL			A_MAGIC_VAL + SKILL_OFFSET				// 0x5D500C
	#define A_SWORD_VAL			A_MAGIC_VAL + SKILL_OFFSET * 0x2		// 0x5D5010
	#define A_AXE_VAL			A_MAGIC_VAL + SKILL_OFFSET * 0x3		// 0x5D5014
	#define A_DIST_VAL			A_MAGIC_VAL + SKILL_OFFSET * 0x4		// 0x5D5018
	#define A_SHIELD_VAL		A_MAGIC_VAL + SKILL_OFFSET * 0x5		// 0x5D501C
	#define A_FISH_VAL			A_MAGIC_VAL + SKILL_OFFSET * 0x6		// 0x5D5020
#endif

#define A_POS_X					0x5D5038
#define A_POS_Y					0x5D503C
#define A_POS_Z					0x5D5040

#define A_DEST_X				0x5D5030
#define A_DEST_Y				0x5D5028
#define A_DEST_Z				0x5D5004

#ifndef EQUIP_OFFSET	
	#define EQUIP_OFFSET		0x20
#endif

#ifdef EQUIP_OFFSET 
	#define A_HEAD				0x671FC8
	#define A_NECK				A_HEAD - EQUIP_OFFSET * 1
	#define A_CONTAINER			A_HEAD - EQUIP_OFFSET * 2
	#define A_TORSO				A_HEAD - EQUIP_OFFSET * 3
	#define A_SHIELD			A_HEAD - EQUIP_OFFSET * 4
	#define A_WEAPON			A_HEAD - EQUIP_OFFSET * 5
	#define A_LEGS				A_HEAD - EQUIP_OFFSET * 6
	#define A_FEETS				A_HEAD - EQUIP_OFFSET * 7
	#define A_FINGER			A_HEAD - EQUIP_OFFSET * 8
	#define A_BELT				A_HEAD - EQUIP_OFFSET * 9
#endif

#define A_TGT_SELECTED			0x43811C
#define A_TGT_HOVERED			0x438144
#define A_TGT_FOLLOW			0x448554

#define A_SKULL_NEW				0x3D889C
#define A_SKULL_OLD				0x3DACC3

#define A_MSG_SERVER			0x48BD70
#define A_MSG_WARNING			0x48BB50

#define A_MOUSE					0x449EE4
#define A_MOUSE_X1				0x449358
#define A_MOUSE_X2				0x5D19AC
#define A_MOUSE_Y1				0x44935C
#define A_MOUSE_Y2				0x5D19B0

#define A_TIBIA_TIME			0x677FFC

#define A_ITEM_TO_USE			0x5D1994
#define A_ITEM_TO_MOVE			0x5D19BC

#define A_POINTER_BP			0x4386EC
#define A_BP_BASE_NEW			0x677B3C

#define A_PRIME_BATTLE_ID		0x62C120
#define A_PRIME_BATTLE_NAME		0x62C124

#define A_TELA_X				0x449EF0		// whatever the fuck it is
#define A_TELA_Y				0x449F54		// whatever the fuck it is

#define A_CTRL					0x5D16D8

#define A_BASE_IN_GUI			0x671FF4

#define A_BASE_LOG_LIST			0x5AF858

#define A_PTR_VIP				0x5AE8B0
#define A_PTR_INIT_MAP			0x672198
#define A_PTR_INIT_MAP_OFFSET	0x676CC0

#define A_FIRST_MAP				0x490F68
