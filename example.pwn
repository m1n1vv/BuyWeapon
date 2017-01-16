#include <a_samp>
#include <mn_buyweapons>

new pickup;

public OnGameModeInit()
{
        pickup = CreatePickup(1242, 2, 1503.3359, 1432.3585, 10.1191, -1);
        return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
        if (pickupid == pickup)
        {
                ShowPlayerDialog(playerid, 68, DIALOG_STYLE_LIST, !"Покупка оружия", !"Silenced 9mm\n\
                        Sniper Rifle\n\
                        Micro SMG/Uz\n\
                        M4", !"Купить", !"Отмена");
        }
        return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
        switch (dialogid)
        {
                case 68:
                {
                        switch (listitem)
                        {
                                case 0: BuyWeapons(playerid, 23); 
                                //Silenced 9mm (игрок получит 9mm с указанным количеством патронов и ценой в include)
                                
                                case 1: BuyWeapons(playerid, 34, .ammo = 100); 
                                //Sniper Rifle (игроку будет выдано 100 патронов для этого оружия по цене указанной в include)
                                
                                case 2: BuyWeapons(playerid, 28, .price = 3000); 
                                //Micro SMG/Uz (оружие будет стоить $3000 с количеством патронов указанных в include)
                                
                                case 3: BuyWeapons(playerid, 31, 100, 3000); 
                                //M4 (игрок получит M4 со 100 патронами за $3000)
                                
                                //Если параметры price и ammo оставить без значения, то они примут значения указанные в include.
                        }
                }
                return 1;
        }
        return 0;
}
