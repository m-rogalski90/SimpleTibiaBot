#pragma once

#define A_XOR			0x4380F0
#define A_LEVEL			0x438108
#define A_EXPERIENCE	0x4380F8
#define A_EXPPERHOUR	0x48D85C
#define A_STAMINA		0x438154
#define A_OFFTG			0x4380B4
#define A_SOUL			0x43810C
#define A_HEALTH		0x5D5000
#define A_HEALTH_MAX	0x5D502C
#define A_MANA			0x438120
#define A_MANA_MAX		0x4380F4

#ifndef SKILLS_PERCENT
	#define SKILLS_PERCENT

	#define A_MAGIC_PC		0x438118
	#define A_FIST_PC		0x438128
	#define A_CLUB_PC		0x43812C
	#define A_SWORD_PC		0x438130
	#define A_AXE_PC		0x438134
	#define A_DIST_PC		0x438138
	#define A_SHIELD_PC		0x43813C
	#define A_FISH_PC		0x438140
#endif

#ifndef SKILLS_VALUES
	#define SKILLS_VALUES

	#define A_MAGIC_VAL		0x438110
	#define A_FIST_VAL		0x5D5008
	#define A_CLUB_VAL		0x5D500C
	#define A_SWORD_VAL		0x5D5010
	#define A_AXE_VAL		0x5D5014
	#define A_DIST_VAL		0x5D5018
	#define A_SHIELD_VAL	0x5D501C
	#define A_FISH_VAL		0x5D5020
#endif

	/*
	lookAddressIdChar = dectohex("0x5D5034")
		lookAddressPrimeiroIdBattle = dectohex("0x62C040") - dectohex("0xE0")

		AddressSkullModeNew = dectohex("0x3D889C");
	AddressSkullModeOld = dectohex("0x3DACC3");
	--ok	--byte 1 = not skull.byte 0 = skull-- 41336 --ok
		AddressActualHotkeySchema = dectohex("0x42B9F8")
		AddressCooldownBar = dectohex("0x449556") + dectohex("0x20")
		AddressHWND = dectohex("0x43802C") + dectohex("0x20") + dectohex("0x40")
		AddressStatus = dectohex("0x43808C") + dectohex("0x20")
		AddressTargetRed = dectohex("0x4380FC") + dectohex("0x20")
		AddressWhiteTarget = dectohex("0x438118") + dectohex("0x2C")
		lookAddressLogged = dectohex("0x438680") + dectohex("0x20")
		AddressOfBpPointer = dectohex("0x4386CC") + dectohex("0x20")
		AddressOfWindow = dectohex("0x4386C8") + dectohex("0x20")
		AdressEquip = dectohex("0x4386DC") + dectohex("0x20")
		AddressReceivBuffer = dectohex("0x438308") + dectohex("0x20")


		AddressMouseX1 = dectohex("0x449338") + dectohex("0x20")
		AddressFollow = dectohex("0x448534") + dectohex("0x20")

		address_mouse = dectohex("0x449EE4")
		address_mouse_2 = address_mouse;

	AddressTelaX = dectohex("0x449ED0") + dectohex("0x20")
		AddressTelaY = dectohex("0x449F34") + dectohex("0x20")
		AddressServerMessage = dectohex("0x48BD50") + dectohex("0x20")
		AddressMessagePlayer = AddressServerMessage
		AddressMessageWarning = dectohex("0x48BB30") + dectohex("0x20")
		AddressMessageNotPossible = AddressMessageWarning
		address_pointer_spells_basic = dectohex("0x48D7A4") + dectohex("0x20")
		address_pointer_spells = address_pointer_spells_basic + 8
		address_total_spells = address_pointer_spells + 4

		addressOfFirstMap = dectohex("0x490F48") + dectohex("0x20")
		pointer_vip_players = dectohex("0x5AE890") + dectohex("0x20")
		AddressBaseLogList = dectohex("0x5AF838") + dectohex("0x20")
		AddressCtrl = dectohex("0x5D16B8") + dectohex("0x20")
		AddressSchemaHotkeyReference = dectohex("0x5D176C") + dectohex("0x20")
		address_item_to_be_used = dectohex("0x5D196C") + dectohex("0x28")
		AddressMouseX2 = dectohex("0x5D1984") + dectohex("0x28")
		AddressMouseY2 = AddressMouseX2 + 4;
	address_item_to_be_moved = dectohex("0x5D1994") + dectohex("0x28")

		AddressZGO = dectohex("0x5D5004")
		AddressCap = dectohex("0x5D5024")

		AddressYGO = dectohex("0x5D5028")
		AddressXGO = dectohex("0x5D5030")

		AddressX = dectohex("0x5D5038")
		AddressY = AddressX + 4;
	AddressZ = dectohex("0x5D5040")

		base_address_in_gui = dectohex("0x671F24") - dectohex("0xD0")
		AddressHelmet = dectohex("0x672098") - dectohex("0xD0")
		PointerInicioMap = dectohex("0x6720C0") - dectohex("0xD8")
		PointerInicioOffsetMap = dectohex("0x676BE8") - dectohex("0xD8")

		address_bp_base_new = dectohex("0x677A64") - dectohex("0xD8")
		address_tibia_time = dectohex("0x677F28") - dectohex("0xD4")

		AddressMouseY1 = AddressMouseX1 + 4
		AddressMaxMp = XorAddress + 4;




	

	AddressMouse_fix_x = AddressMouseX1;
	AddressMouse_fix_y = AddressMouse_fix_x + 4;

	AddressClub = AddressFirst + 4;
	AddressSword = AddressFirst + 4 * 2;
	AddressAxe = AddressFirst + 4 * 3;
	AddressDistance = AddressFirst + 4 * 4;
	AddressShielding = AddressFirst + 4 * 5;
	AddressFishing = AddressFirst + 4 * 6;

	offset_beetwen_body_item = dectohex("0x20");

	AddressAmulet = AddressHelmet - offset_beetwen_body_item * 1;
	AddressBag = AddressHelmet - offset_beetwen_body_item * 2;
	AddressMainBp = AddressBag;
	AddressArmor = AddressHelmet - offset_beetwen_body_item * 3;
	AddressShield = AddressHelmet - offset_beetwen_body_item * 4;
	AddressWeapon = AddressHelmet - offset_beetwen_body_item * 5;
	AddressLeg = AddressHelmet - offset_beetwen_body_item * 6;
	AddressBoot = AddressHelmet - offset_beetwen_body_item * 7;
	AddressRing = AddressHelmet - offset_beetwen_body_item * 8;
	AddressRope = AddressHelmet - offset_beetwen_body_item * 9;
	AddressLogged = lookAddressLogged;
	AddressIdChar = lookAddressIdChar;
	AddressPrimeiroNomeBattle = lookAddressPrimeiroIdBattle + 4;*/
