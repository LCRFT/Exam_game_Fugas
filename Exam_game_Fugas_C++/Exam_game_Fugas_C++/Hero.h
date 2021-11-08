class Hero
{
public:
    int Id, HP, Damage;
    std::string Name;
    Hero(int Hero_Id, std::string Hero_Name, int Hero_HP, int Hero_Damage)
    {
        Id = Hero_Id;
        Name = Hero_Name;
        HP = Hero_HP;
        Damage = Hero_Damage;
    }
};
