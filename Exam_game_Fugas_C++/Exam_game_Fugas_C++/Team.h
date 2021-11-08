class Team
{
public:
    std::string Team_name;
    struct Team_list
    {
        std::vector<Player> struct_player_list;
        std::vector<Hero> struct_hero_list;
    };
    Team_list new_team_list;

};
