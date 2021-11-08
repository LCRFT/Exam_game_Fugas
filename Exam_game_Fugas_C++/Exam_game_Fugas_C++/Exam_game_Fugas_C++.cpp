#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <ctime>
#include "Player.h"
#include "Hero.h"
#include "PlayerManager.h"
#include "HeroManager.h"
#include "Team.h"
#include "TeamManager.h"
#include "Session.h"
#include "GameManager.h"

int main()
{
    srand(time(NULL));
    PlayerManager new_Player_Manager;
    HeroManager new_Hero_Manager;
    
    new_Player_Manager.CreatePlayer(1, "Mykhailo", rand() % 300 + 100);
    new_Player_Manager.CreatePlayer(2, "Artem", rand() % 300 + 100);
    new_Player_Manager.CreatePlayer(3, "Victor", rand() % 300 + 100);
    new_Player_Manager.CreatePlayer(4, "Slusar", rand() % 300 + 100);
    new_Player_Manager.CreatePlayer(5, "Igor", rand() % 300 + 100);
    new_Player_Manager.CreatePlayer(6, "Dmytro", rand() % 300 + 100);
    new_Player_Manager.CreatePlayer(7, "Sergiy", rand() % 300 + 100);
    new_Player_Manager.CreatePlayer(8, "Bogdan", rand() % 300 + 100);
    new_Player_Manager.CreatePlayer(9, "Petro", rand() % 300 + 100);
    new_Player_Manager.CreatePlayer(10, "Nazar", rand() % 300 + 100);

    new_Hero_Manager.CreateHero(1, "Jack", rand() % 1000 + 100, rand() % 400 + 150);
    new_Hero_Manager.CreateHero(2, "Axe", rand() % 1000 + 100, rand() % 400 + 150);
    new_Hero_Manager.CreateHero(3, "Io", rand() % 1000 + 100, rand() % 400 + 150);
    new_Hero_Manager.CreateHero(4, "Doom", rand() % 1000 + 100, rand() % 400 + 150);
    new_Hero_Manager.CreateHero(5, "Sven", rand() % 1000 + 100, rand() % 400 + 150);
    new_Hero_Manager.CreateHero(6, "Bard", rand() % 1000 + 100, rand() % 400 + 150);
    new_Hero_Manager.CreateHero(7, "Caitlyn", rand() % 1000 + 100, rand() % 400 + 150);
    new_Hero_Manager.CreateHero(8, "Graves", rand() % 1000 + 100, rand() % 400 + 150);
    new_Hero_Manager.CreateHero(9, "Jax", rand() % 1000 + 100, rand() % 400 + 150);
    new_Hero_Manager.CreateHero(10, "Morgana", rand() % 1000 + 100, rand() % 400 + 150);
    
    GameManager MOBA;
    MOBA.PerformGameSession(new_Player_Manager, new_Hero_Manager,1);
    MOBA.PerformGameSession(new_Player_Manager, new_Hero_Manager, 2);

    return 0;
}

