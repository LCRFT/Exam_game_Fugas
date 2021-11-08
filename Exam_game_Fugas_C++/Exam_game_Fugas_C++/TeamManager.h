class TeamManager
{
private:
    Team new_team[2];
public:
    Team Get_team(int team_num)
    {
        return new_team[team_num - 1];
    }
    TeamManager(std::string new_name1, std::string new_name2)
    {
        new_team[0].Team_name = new_name1;
        new_team[1].Team_name = new_name2;
    }

    void SetTeam(int num, Team set_Team)
    {
        new_team[num - 1] = set_Team;
    }
    void GenerateNewTeam(std::vector<int> Player_id, std::vector<int> Hero_id, std::vector<Player> new_player, std::vector<Hero> new_hero)
    {
        srand(time(NULL));
        int rand_Player, rand_Hero;
        int rand_range = 10;
        for (int j = 0; j < 2; ++j)
        {
            for (int i = 5; i >= 1; --i)
            {
                rand_Player = rand() % rand_range;
                rand_Hero = rand() % rand_range;

                Player insert_Player(i, new_player[rand_Player].Name, new_player[rand_Player].Rank);
                new_team[j].new_team_list.struct_player_list.insert(new_team[j].new_team_list.struct_player_list.begin(), insert_Player);
                new_player.erase(new_player.begin() + rand_Player);

                Hero insert_Hero(i, new_hero[rand_Hero].Name, new_hero[rand_Hero].HP, new_hero[rand_Hero].Damage);
                new_team[j].new_team_list.struct_hero_list.insert(new_team[j].new_team_list.struct_hero_list.begin(), insert_Hero);
                new_hero.erase(new_hero.begin() + rand_Hero);

                --rand_range;
            }
        }

    }

    void ShowTeamInfo(int num)
    {
        PlayerManager PlayersInfo;
        HeroManager HeroInfo;
        PlayersInfo.CreatePlayer(new_team[num - 1].new_team_list.struct_player_list);
        HeroInfo.CreateHero(new_team[num - 1].new_team_list.struct_hero_list);

        std::cout << std::endl << "Team name:" << new_team[num - 1].Team_name << std::endl << "Team List:" << std::endl << std::endl;
        for (int i = 1; i <= 5; ++i)
        {
            PlayersInfo.ShowPlayerInfo(i);
            std::cout << std::endl;
            HeroInfo.ShowHeroInfo(i);
            std::cout << std::endl;
        }
    }
};
