/*
	THIS FILE IS A PART OF RDR 2 SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2019
*/

#include "script.h"
#include <string>
#include <vector>
#include <math.h>

enum ePedAttribute
{
	PA_HEALTH,
	PA_STAMINA,
	PA_SPECIALABILITY,
	PA_COURAGE,
	PA_AGILITY,
	PA_SPEED,
	PA_ACCELERATION,
	PA_BONDING,
	SA_HUNGER,
	SA_FATIGUED,
	SA_INEBRIATED,
	SA_POISONED,
	SA_BODYHEAT,
	SA_BODYWEIGHT,
	SA_OVERFED,
	SA_SICKNESS,
	SA_DIRTINESS,
	SA_DIRTINESSHAT,
	MTR_STRENGTH,
	MTR_GRIT,
	MTR_INSTINCT,
	PA_UNRULINESS,
	SA_DIRTINESSSKIN
};


//init values from LessMoney.ini
int		g_health = (int)GetPrivateProfileInt("Main", "Health", 2000, ".\\NoCoreProgression.ini");
int		g_stamina = (int)GetPrivateProfileInt("Main", "Stamina", 2000, ".\\NoCoreProgression.ini");
int		g_deadeye = (int)GetPrivateProfileInt("Main", "DeadEye", 2000, ".\\NoCoreProgression.ini");


void update()
{
	Ped player_ped = PLAYER::PLAYER_PED_ID();

	ATTRIBUTE::SET_ATTRIBUTE_POINTS(player_ped, ePedAttribute::PA_HEALTH, g_health);
	ATTRIBUTE::SET_ATTRIBUTE_POINTS(player_ped, ePedAttribute::PA_STAMINA , g_stamina);
	ATTRIBUTE::SET_ATTRIBUTE_POINTS(player_ped, ePedAttribute::PA_SPECIALABILITY, g_deadeye);



}

void main()
{
	while (true)
	{
		update();
		WAIT(0);
	}
}

void ScriptMain()
{	
	srand(GetTickCount());
	main();
}
