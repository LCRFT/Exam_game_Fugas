
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
                return &player;
            }
        }
        return nullptr;
    }

    void DeletePlayer(int Delete_Id)
    {
        new_player.erase(new_player.begin() + Delete_Id);
    }

};

int main()
{
    PlayerManager new_Player_Manager;

    new_Player_Manager.CreatePlayer(1, "Misha", 7000);
    
    //new_player.push_back(new_Player_Manager.CreatePlayer(2, "Misha", 7000));
    //new_player.push_back(new_Player_Manager.CreatePlayer(3, "Misha", 7000));


    auto player=new_Player_Manager.GetPlayerByName("Misha");
    if (player)
    {
        std::cout << "Id:" << player->Id << std::endl << "Name:" << player->Name << std::endl << "Rank:" << player->Rank << std::endl;
    }

   
    return 0;
}

