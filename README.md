![Image alt](http://pawn-wiki.ru/uploads/imgs/img_1466732388__bw-logo.png)
> ###Версия: 0.4.1###

Этот include добавляет покупку оружие с подробной информацией. Все действия будут происходишь в двух диалоговых окнах. В основном диалоге выводится вся информация об оружии. Если во время покупки система определит, что у вас в этом же слоте уже есть оружие, то высветится второй диалог, который предложит заменить.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=f72H9AEBAKUE" target="_blank"><img src="http://img.youtube.com/vi/f72H9AEBAKU/0.jpg" 
alt="SA:MP Include BuyWeapons" width="240" height="180" border="10" /></a>

Установка
---------
```pawn
#include <mn_buyweapons>
```

Параметры
---------
> 
> ```pawn
BuyWeapons(playerid, weaponid, ammo, price);
```
> 
> * **playerid** - id игрока
> * **weaponid** - id оружия (с 22 по 34)
> * **ammo** - количество патронов (необязательное)
> * **price** - цена оружия (необязательное)

Применение
----------
```pawn
//Если параметры price и ammo оставить без значения, то они примут значения указанные в include.

switch (listitem)
{
        case 0: BuyWeapons(playerid, 23); //Silenced 9mm (игрок получит 9mm с указанным количеством патронов и ценой в include)
        case 1: BuyWeapons(playerid, 34, .ammo = 100); //Sniper Rifle (игроку будет выдано 100 патронов для этого оружия по цене указанной в include)
        case 2: BuyWeapons(playerid, 28, .price = 3000); //Micro SMG/Uz (оружие будет стоить $3000 с количеством патронов указанных в include)
        case 3: BuyWeapons(playerid, 31, 100, 3000); //M4 (игрок получит M4 со 100 патронами за $3000)
}
```
Полная инструкция: [https://github.com/m1n1vv/.../example.pwn](https://github.com/m1n1vv/BuyWeapons/blob/master/example.pwn)
Этапы развития
--------------

|0.1|0.2|0.3|0.4|
|:-:|:-:|:-:|:-:|
|[**0.1.1**](https://github.com/m1n1vv/Pawn/blob/master/archive/buy-weapons-0.1.inc)|0.2 test|0.3.1|[**0.4.1**](https://github.com/m1n1vv/BuyWeapons/blob/master/mn_buyweapons.inc)|
||0.2.1|0.3.2|
||0.2.2|0.3.3|
||[**0.2.3**](https://github.com/m1n1vv/Pawn/blob/master/archive/buy-weapons-0.2.inc)|0.3.4|
|||0.3.5|
|||0.3.6|
|||0.3.6.1|
|||[**0.3.6.2**](https://github.com/m1n1vv/Pawn/blob/master/archive/buy-weapons-0.3.inc)|
