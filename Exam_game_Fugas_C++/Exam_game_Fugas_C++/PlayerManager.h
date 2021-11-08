class PlayerManager
{
public:
    std::vector<Player> player_list;

    void CreatePlayer(int Player_Id, std::string Player_Name, int Player_Rank)
    {

        player_list.push_back(Player(Player_Id, Player_Name, Player_Rank));
    }
    void CreatePlayer(std::vector<Player> struct_player_list)
    {
        for (int i = 0; i < 5; ++i)
            player_list.push_back(struct_player_list[i]);
    }


    Player* GetPlayerByName(std::string Searched_name)
    {
        for (auto& player : player_list)
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
        for (auto& player : player_list)
        {
            if (player.Id == Searched_Id)
            {
                return &player;
            }
        }
        return nullptr;
    }

    void ShowPlayerInfo(int id)
    {
        for (auto& player : player_list)
        {
            if (player.Id == id)
            {
                std::cout << "Player Id:" << player.Id << std::endl << "Player Name:" << player.Name << std::endl << "Rank:" << player.Rank << std::endl;
            }
        }
    }

    void DeletePlayer(int Delete_Id)
    {
        player_list.erase(player_list.begin() + Delete_Id - 1);
    }

};
