
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <ctime>


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
public:
    std::vector<Player> player_list;

    void CreatePlayer(int Player_Id, std::string Player_Name, int Player_Rank)
    {

        player_list.push_back(Player(Player_Id, Player_Name, Player_Rank));
    }
    void CreatePlayer(std::vector<Player> struct_player_list)
    {
        for(int i=0;i<5;++i)
        player_list.push_back(struct_player_list[i]);
    }


    Player* GetPlayerByName(std::string Searched_name)
    {
        for (auto& player: player_list)
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
        player_list.erase(player_list.begin()+Delete_Id-1);
   }

};

class HeroManager
{
public:
    std::vector<Hero> hero_list;

    int Id, HP, Damage;
    std::string Name;
    void CreateHero(int Hero_Id, std::string Hero_Name, int Hero_HP, int Hero_Damage)
    {

        hero_list.push_back(Hero(Hero_Id, Hero_Name, Hero_HP, Hero_Damage));
    }
    void CreateHero(std::vector<Hero>struct_hero_list)
    {
        for (int i = 0; i < 5; ++i)
            hero_list.push_back(struct_hero_list[i]);
    }

    Hero* GetHeroByName(std::string Searched_name)
    {
        for (auto &hero : hero_list)
        {
            if (hero.Name == Searched_name)
            {
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
                return &hero;
            }
        }
        return nullptr;
    }
    void ShowHeroInfo(int id)
    {
        for (auto& hero : hero_list)
        {
            if (hero.Id == id)
            {
                std::cout << "Hero Id:" << hero.Id << std::endl << "Hero Name:" << hero.Name << std::endl << "HP:" << hero.HP << std::endl << "Damage:" << hero.Damage << std::endl;
            }
        }
    }

    void DeleteHero(int Delete_Id)
    {
        hero_list.erase(hero_list.begin() + Delete_Id-1);
    }

};

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

class TeamManager
{
private:
    Team new_team[2];
public:
    Team Get_team(int team_num)
    {
        return new_team[team_num-1];
    }
    TeamManager(std::string new_name1, std::string new_name2)
    {
        new_team[0].Team_name = new_name1;
        new_team[1].Team_name = new_name2;
    }

    void SetTeam(int num,Team set_Team)
    {
        new_team[num-1] = set_Team;
    }
    void GenerateNewTeam(std::vector<int> Player_id, std::vector<int> Hero_id,std::vector<Player> new_player, std::vector<Hero> new_hero)
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
        PlayersInfo.CreatePlayer(new_team[num-1].new_team_list.struct_player_list);
        HeroInfo.CreateHero(new_team[num-1].new_team_list.struct_hero_list);

        std::cout <<std::endl<< "Team name:" << new_team[num-1].Team_name << std::endl << "Team List:"<<std::endl<<std::endl;
        for (int i = 1; i <= 5; ++i)
        {
            PlayersInfo.ShowPlayerInfo(i);
            std::cout << std::endl;
            HeroInfo.ShowHeroInfo(i);
            std::cout << std::endl;
        }
    }
};

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

class GameManager
{
public:
    std::list<Session> GameSessions;
    void PerformGameSession(PlayerManager gs_PlayerManager,HeroManager gs_HeroManager,int new_Time)
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

