class Session
{
private:
    int StartTime;
    Team TeamOne, TeamTwo, Winner;
public:
    int Get_Time()
    {
        return StartTime;
    }
    void Set_Time(int new_time)
    {
        StartTime = new_time;
    }

    void Set_TeamOne(Team team_one)
    {
        TeamOne = team_one;
    }

    Team Get_Team(int num)
    {
        if (num == 1)
            return TeamOne;
        else if (num == 2)
            return TeamTwo;
    }

    void Set_TeamTwo(Team team_two)
    {
        TeamTwo = team_two;
    }

    Team Get_Winner()
    {
        return Winner;
    }

    void CalculateWinner()
    {
        int Hp_one = 0, Hp_two = 0, Damage_one = 0, Damage_two = 0;
        for (int i = 0; i < 5; ++i)
        {
            Hp_one += TeamOne.new_team_list.struct_hero_list[i].HP;
            Hp_two += TeamTwo.new_team_list.struct_hero_list[i].HP;

            Damage_one += TeamOne.new_team_list.struct_hero_list[i].Damage;
            Damage_two += TeamTwo.new_team_list.struct_hero_list[i].Damage;

        }
        std::cout << "Total HP of team one:" << Hp_one << std::endl << "Total HP of team two:" << Hp_two << std::endl;
        std::cout << "Total Damage of team one:" << Damage_one << std::endl << "Total Damage of team two:" << Damage_two << std::endl;
        Hp_one -= Damage_two;
        Hp_two -= Damage_one;
        if (Hp_one > Hp_two)
        {
            std::cout << "Team Blue Winner" << std::endl;
            std::cout << "Stats:" << std::endl;
            for (auto& it_TeamOne : TeamOne.new_team_list.struct_player_list)
            {
                it_TeamOne.Rank += 25;
                std::cout << "Player name:" << it_TeamOne.Name << std::endl << "Player rank:" << it_TeamOne.Rank << std::endl << std::endl;
            }
            for (auto& it_TeamTwo : TeamTwo.new_team_list.struct_player_list)
            {
                it_TeamTwo.Rank -= 25;
                std::cout << "Player name:" << it_TeamTwo.Name << std::endl << "Player rank:" << it_TeamTwo.Rank << std::endl << std::endl;
            }
            Winner = TeamOne;
        }
        else if (Hp_one == Hp_two)
        {
            std::cout << "Draw" << std::endl;
        }
        else
        {
            std::cout << "Team Red Winner" << std::endl;
            for (auto& it_TeamOne : TeamOne.new_team_list.struct_player_list)
            {
                it_TeamOne.Rank -= 25;

            }
            for (auto& it_TeamTwo : TeamTwo.new_team_list.struct_player_list)
            {
                it_TeamTwo.Rank += 25;

            }

            Winner = TeamTwo;
        }
    }
};
