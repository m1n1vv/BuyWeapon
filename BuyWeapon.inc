#if  defined BUYWEAPON
	#endinput
#endif
#define BUYWEAPON

#if !defined BW__MAX_WEAPON_NAME
	#define BW__MAX_WEAPON_NAME             19
#endif

#if  !defined BW__DIALOG_WEAPONS_ID
	#define BW__DIALOG_WEAPONS_ID           18498
#endif

#if  !defined BW__DIALOG_PROOFE
	#define BW__DIALOG_PROOFE               (BW__DIALOG_WEAPONS_ID + 1)
#endif

#if  !defined BW__COLOR_RED
	#define BW__COLOR_RED                   0xAA3333AA
#endif

#if  !defined BW__COLOR_GREEN
	#define BW__COLOR_GREEN                 0x33AA33AA
#endif

static
	bw__caliber,
	bw__weaponid[MAX_PLAYERS char],
	bw__ammo[MAX_PLAYERS],
	bw__slot[MAX_PLAYERS char],
	bw__price[MAX_PLAYERS],
	bw__new_weapon_name[MAX_PLAYERS][BW__MAX_WEAPON_NAME];

static const
#if !defined BW__KEY__INFO
	bw__str[] =
		"Оружие:\t\t\t%s\n\n\
		Калибр:\t\t\t%s\n\
		Количество патронов:\t\t%i\n\
		Дальность стрельбы:\t\t%i метров\n\
		Цена:\t\t\t\t$%i",
	bw__caliber_id[] =
	{
		1, 1, 2, 3, 3, 3, 4, 4, 5, 6, 4, 5, 5
	},
	bw__buystat_caliber[][] =
	{
		!".45",
		!".50",
		!"12-й",
		!"9x19 мм Парабеллум",
		!"7,62 мм",
		!"5,56x45 мм НАТО"
	},
	bw__buystat_shooting_range[] =
	{
		35, 35, 35, 40, 35, 40, 35, 45, 70, 90, 35, 100, 100
	},
#endif
	bw__buystat_price[] = //Цены на оружие
	{
		1700,   //9mm
		2000,   //Silenced 9mm
		2500,   //Desert Eagle
		1500,   //Shotgun
		1900,   //Sawnoff Shotgun
		2900,   //Combat Shotgun
		1950,   //Micro SMG/Uzi
		2400,   //MP5
		3800,   //AK-47
		4000,   //M4
		2600,   //Tec-9
		5000,   //Country Rifle
		6000    //Sniper Rifle
	},
	bw__buystat_ammunition[] =
	{
		17, 17, 7, 1, 2, 7, 50, 30, 30, 50, 50, 1, 1
	},
	bw__weapon_slot_id[] =
	{
		2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 4, 6, 6
	};

stock BuyWeapon(playerid, weaponid, ammo = 0, price = 0)
{
#if !defined BW__KEY__INFO
	new
		pack[20],
		string[sizeof bw__str + BW__MAX_WEAPON_NAME*2 + 2 + 3 + 4 - (2*5 + 19)];
#endif

	GetWeaponName(weaponid, bw__new_weapon_name[playerid], BW__MAX_WEAPON_NAME);

	bw__weaponid{playerid} = weaponid;
	weaponid -= 22;
	bw__caliber = bw__caliber_id[weaponid] - 1;
	bw__slot{playerid} = bw__weapon_slot_id[weaponid];
	price = bw__price[playerid] = (price == 0) ? (bw__buystat_price[weaponid]) : (price);
	ammo = bw__ammo[playerid] = (ammo == 0) ? (bw__buystat_ammunition[weaponid]) : (ammo);

#if !defined BW__KEY__INFO
	strunpack(pack, bw__buystat_caliber[bw__caliber]);
	format(string, sizeof string, bw__str, 
		bw__new_weapon_name[playerid],
		pack,
		ammo,
		bw__buystat_shooting_range[weaponid],
		price
	);

	ShowPlayerDialog(playerid, BW__DIALOG_WEAPONS_ID, DIALOG_STYLE_MSGBOX, !"Покупка оружия", string, !"Купить", !"Закрыть");
#else
	#if !defined BW__KEY__REPEAT
		return WeaponRepeat(playerid);
	#else
		return Buy(playerid);
	#endif
#endif
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if (dialogid == BW__DIALOG_WEAPONS_ID)
    {
        if (response == 0)
            return SendClientMessage(playerid, BW__COLOR_RED, !"Покупка отклонена");

#if !defined BW__KEY__REPEAT
		WeaponRepeat(playerid);
#endif
        
		return 1;
	}
	else if (dialogid == BW__DIALOG_PROOFE)
	{
		if (response == 0)
			return SendClientMessage(playerid, BW__COLOR_RED, !"Покупка отклонена");

		return Buy(playerid);
	}

#if  defined bw__OnDialogResponse
	bw__OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
#endif

	return 0;
}

static stock WeaponRepeat(playerid)
{
	static
		old_weapon_name[BW__MAX_WEAPON_NAME],
		player_slot,
		player_weaponid,
		player_weapon,
		player_ammo;

	player_slot = bw__slot{playerid};
	player_weaponid = bw__weaponid{playerid};

	GetWeaponName(bw__weaponid{playerid}, bw__new_weapon_name[playerid], BW__MAX_WEAPON_NAME);

	for (new i = 2; i < 7; i++)
	{
		GetPlayerWeaponData(playerid, i, player_weapon, player_ammo);

		if (player_weapon == player_weaponid && player_ammo)
			return SendClientMessage(playerid, BW__COLOR_RED, !"У Вас уже есть это оружие");

		if (i == player_slot && player_weapon != player_weaponid && player_ammo)
		{
			GetWeaponName(player_weapon, old_weapon_name, sizeof old_weapon_name);

			new
				str[36] = !"У Вас уже есть оружие в этом слоте.\n";

#if !defined BW__KEY__RESET_AMMO
			strcat(str, !"При подтверждении все патроны старого оружия удалятся.\n");
#endif
			strcat(str, !"\nЗаменить ");
			strcat(str, old_weapon_name);
			strcat(str, !" на ");
			strcat(str, bw__new_weapon_name[playerid]);
			strcat(str, !"?");

			return ShowPlayerDialog(playerid, BW__DIALOG_PROOFE, DIALOG_STYLE_MSGBOX, !"Внимание!", str, !"Да", !"Закрыть");
		}
	}
	return Buy(playerid);
}

static stock Buy(playerid)
{
	if (GetPlayerMoney(playerid) < bw__price[playerid])
		return SendClientMessage(playerid, BW__COLOR_RED, !"У Вас недостаточно средств");

	GivePlayerMoney(playerid, -bw__price[playerid]);
#if !defined BW__KEY__RESET_AMMO
	GivePlayerWeapon(playerid, bw__weaponid{playerid}, 1);
	SetPlayerAmmo(playerid, bw__weaponid{playerid}, 0);
#endif
	GivePlayerWeapon(playerid, bw__weaponid{playerid}, bw__ammo[playerid]);

	return SendClientMessage(playerid, BW__COLOR_GREEN, !"Вы успешно совершили покупку");
}

public OnPlayerDisconnect(playerid, reason)
{
	bw__new_weapon_name[playerid][0] = EOS;
	bw__weaponid{playerid} =
	bw__ammo[playerid] =
	bw__price[playerid] =
	bw__slot{playerid} = 0;

#if  defined bw__OnPlayerDisconnect
	bw__OnPlayerDisconnect(playerid, reason);
#endif

	return 1;
}

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse bw__OnDialogResponse
#if defined bw__OnDialogResponse
	forward bw__OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect bw__OnPlayerDisconnect
#if defined bw__OnPlayerDisconnect
	forward bw__OnPlayerDisconnect(playerid, reason);
#endif

/*
by m1n1vv
Version: 0.5
*/
