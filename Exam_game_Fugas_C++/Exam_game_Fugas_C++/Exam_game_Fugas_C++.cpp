
#include <iostream>
#include <vector>
#include <iterator>

class Player
{
public:
    int Id,Rank;
    std::string Name;
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
public:
    Player CreatePlayer(int Player_Id, std::string Player_Name, int Player_Rank)
    {
        Player new_player;
        new_player.Id = Player_Id;
        new_player.Name = Player_Name;
        new_player.Rank = Player_Rank;
        return new_player;
    }

    void GetPlayerByName(std::vector<Player> new_player, std::string Searched_name)
    {
        for (int i = 0; i < new_player.size(); ++i)
        {
            if (new_player[i].Name == Searched_name)
            {
                std::cout << "Id:" << new_player[i].Id << std::endl << "Name:" << new_player[i].Name << std::endl << "Rank:" << new_player[i].Rank << std::endl;
            }
        }
    }
    
    void GetPlayerById(Player new_player[], int Searched_Id)
    {
        for (int i = 0; i <= 10; ++i)
        {
            if (new_player[i].Id == Searched_Id)
            {
                std::cout << "Id:" << new_player[i].Id << std::endl << "Name:" << new_player[i].Name << std::endl << "Rank:" << new_player[i].Rank << std::endl;
            }
        }
    }

    void DeletePlayer(std::vector<Player> new_player, int Delete_Id)
    {
        for (int i = 0; i <= 10; ++i)
        {
            if (new_player[i].Id == Delete_Id)
            {
                std::vector<int>::iterator it;
                std::vector <int> ::iterator = new_player.begin();
                it = new_player.begin();
                new_player.erase(it);
                new_player[i].Name ="";
                new_player[i].Rank = 0;
                std::cout << "Id:" << new_player[i].Id << std::endl << "Name:" << new_player[i].Name << std::endl << "Rank:" << new_player[i].Rank << std::endl;
            }
        }
    }

};

int main()
{
    std::vector<Player> new_player;
    
    PlayerManager new_Player_Manager;

    new_player.push_back(new_Player_Manager.CreatePlayer(1, "Misha", 7000));
    new_player.push_back(new_Player_Manager.CreatePlayer(2, "Misha", 7000));
    new_player.push_back(new_Player_Manager.CreatePlayer(3, "Misha", 7000));


    new_Player_Manager.GetPlayerByName(new_player, "Misha");

   
    return 0;
}

