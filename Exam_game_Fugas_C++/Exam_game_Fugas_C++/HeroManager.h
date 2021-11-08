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
        for (auto& hero : hero_list)
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
        hero_list.erase(hero_list.begin() + Delete_Id - 1);
    }

};
