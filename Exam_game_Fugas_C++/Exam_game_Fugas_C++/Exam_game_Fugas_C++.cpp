
#include <iostream>
#include <vector>
#include <iterator>

class Player
{
public:
    int Id,Rank;
    std::string Name;
    Player(int ID_Player, std::string Name_Player,int Rank_Player)
    {
        Id = ID_Player;
        Name = Name_Player;
        Rank = Rank_Player;
    }
};

class Hero
{
public:
    int Id,HP,Damage;
    std::string Name;
    Hero(int Hero_Id, std::string Hero_Name, int Hero_HP,int Hero_Damage)
    {
        Id = Hero_Id;
        Name = Hero_Name;
        HP = Hero_HP;
        Damage = Hero_Damage;
    }
};

class PlayerManager
{
private:
    std::vector<Player> new_player;
public:
    void CreatePlayer(int Player_Id, std::string Player_Name, int Player_Rank)
    {

        new_player.push_back(Player(Player_Id, Player_Name, Player_Rank));
    }


    Player* GetPlayerByName(std::string Searched_name)
    {
        for (auto& player:new_player )
        {
            if (player.Name == Searched_name)
            {
                std::cout << "Id:" << player.Id << std::endl << "Name:" << player.Name << std::endl << "Rank:" << player.Rank << std::endl;
                return &player;
            }
        }
        return nullptr;
    }
    
   Player* GetPlayerById(int Searched_Id)
    {
        for (auto& player : new_player)
        {
            if (player.Id == Searched_Id)
            {
                std::cout << "Id:" << player.Id << std::endl << "Name:" << player.Name << std::endl << "Rank:" << player.Rank << std::endl;
                return &player;
            }
        }
        return nullptr;
    }

    void DeletePlayer(int Delete_Id)
    {
        new_player.erase(new_player.begin()+Delete_Id-1);
    }

};

class HeroManager
{
private:
    std::vector<Hero> hero_list;
public:
    int Id, HP, Damage;
    std::string Name;
    void CreateHero(int Hero_Id, std::string Hero_Name, int Hero_HP, int Hero_Damage)
    {

        hero_list.push_back(Hero(Hero_Id, Hero_Name, Hero_HP, Hero_Damage));
    }

    Hero* GetHeroByName(std::string Searched_name)
    {
        for (auto& hero : hero_list)
        {
            if (hero.Name == Searched_name)
            {
                std::cout << "Id:" << hero.Id << std::endl << "Name:" << hero.Name << std::endl << "HP:" << hero.HP << std::endl<<"Damage:"<<hero.Damage<<std::endl;
                return &hero;
            }
        }
        return nullptr;
    }

    Hero* GetHeroById(int Searched_Id)
    {
        for (auto& hero : hero_list)
        {
            if (hero.Id == Searched_Id)
            {
                std::cout << "Id:" << hero.Id << std::endl << "Name:" << hero.Name << std::endl << "HP:" << hero.HP << std::endl << "Damage:" << hero.Damage << std::endl;
                return &hero;
            }
        }
        return nullptr;
    }

    void DeleteHero(int Delete_Id)
    {
        hero_list.erase(hero_list.begin() + Delete_Id-1);
    }

};

int main()
{
    PlayerManager new_Player_Manager;

    new_Player_Manager.CreatePlayer(1, "Misha", 7000);
    new_Player_Manager.GetPlayerByName("Misha");
    new_Player_Manager.DeletePlayer(1);
    new_Player_Manager.GetPlayerById(1);

    HeroManager new_Hero_Manager;

    new_Hero_Manager.CreateHero(1, "Jack", 1000, 200);
    new_Hero_Manager.GetHeroByName("Jack");
    new_Hero_Manager.DeleteHero(1);
    new_Hero_Manager.GetHeroById(1);
    return 0;
}

