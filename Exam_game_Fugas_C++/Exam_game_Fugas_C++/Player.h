class Player
{
public:
    int Id, Rank;
    std::string Name;
    Player(int ID_Player, std::string Name_Player, int Rank_Player)
    {
        Id = ID_Player;
        Name = Name_Player;
        Rank = Rank_Player;
    }
};
