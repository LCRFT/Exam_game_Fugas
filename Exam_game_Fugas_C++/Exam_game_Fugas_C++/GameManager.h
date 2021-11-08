class GameManager
{
public:
    std::list<Session> GameSessions;
    void PerformGameSession(PlayerManager gs_PlayerManager, HeroManager gs_HeroManager, int new_Time)
    {
        std::cout << std::endl << "Game started!" << std::endl;
        std::vector<int> Players_Id, Heros_Id;
        for (int i = 0; i < 5; ++i)
        {
            Players_Id.push_back(i);
            Heros_Id.push_back(i);
        }

        TeamManager Teams("Blue", "Red");
        Teams.GenerateNewTeam(Players_Id, Heros_Id, gs_PlayerManager.player_list, gs_HeroManager.hero_list);
        Teams.ShowTeamInfo(1);
        Teams.ShowTeamInfo(2);

        Session new_session;
        new_session.Set_TeamOne(Teams.Get_team(1));
        new_session.Set_TeamTwo(Teams.Get_team(2));

        new_session.Set_Time(new_Time);
        new_session.CalculateWinner();
        GameSessions.push_back(new_session);

        Teams.SetTeam(1, new_session.Get_Team(1));
        Teams.SetTeam(2, new_session.Get_Team(2));

        Teams.ShowTeamInfo(1);
        Teams.ShowTeamInfo(2);

    }

};
