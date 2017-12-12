![Image alt](http://pawn-wiki.ru/uploads/imgs/img_1485117009__img_1466732388__bw-logo.png)
> Версия: 0.4.3

BuyWeapon - система покупки оружия. 

Все действия будут происходишь в двух диалоговых окнах. В основном выводится вся информация об оружии. Если во время покупки система определит, что у вас в этом же слоте уже есть оружие, то запустится второе диалоговое окно, которое предложит заменить.

Использование системы довольное простое. Достаточно в меню или пикап поставить функцию BuyWeapon с нужными параметрами. Ид оружия является обязательным, а количество патронов или цену можно ставить на свое усмотрение, или использовать указанные в инклуде.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=f72H9AEBAKUE" target="_blank"><img src="http://img.youtube.com/vi/f72H9AEBAKU/0.jpg" 
alt="SA:MP Include BuyWeapon" width="240" height="180" border="10" /></a>

Установка
---------
```pawn
#include <mn_BuyWeapon>
```

Параметры
---------
```pawn
stock BuyWeapon(playerid, weaponid, ammo, price);
```
