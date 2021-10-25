Розробити програмну реалізацію симуляції багатокористувацької гри за поданою нижче схемою (дозволяється доповнення схеми за потреби).

Розробка повинна вестися в git репозиторії та мати власний відкритий репозиторій на сервісі GitHub. 

Репозиторій повинен мати дві гілки: dev і master.

Розробка ведеться в гілці dev, а усі віддестовані функції повинні бути змерджені в master.

Після завершення розробки відправити посилання на віддалений репозиторій на перевірку.


Моделі даних для розробки гри:

Player: Id, Name, Rank.

Hero: Id, Name, HP, Damage.

PlayerManager: CreatePlayer(args), GetPlayerByName(args), GetPlayerById(args), DeletePlayer(args), ShowPlayerInfo(args).

HeroManager: CreateHero(args), GetHeroByName(args), GetHeroById(args), DeleteHero(args), ShowHeroInfo(args).

Team: Name, Team -> array[5] {'player': playerObject, 'hero': heroObject}

TeamManager: GenerateNewTeam(args), GetTeamInfo(args).

Session: StartTime, TeamOne, TeamTwo, Winner, CalculateWinner(args).

GameManager: GameSessions -> List<Sessions>, PerformGameSession(args).

Метод PerformGameSession створює ігрову сесію у якій відбуваються наступні дії: 

    Створюються дві команди, у які випадковим чином вибирається по 5 гравців. 
    Кожному гравцю випадковим чином присвоюється один із доступних героїв. Герої не повинні повторюватись в межах однієї ігрової сесії. 
    Розраховується загальна кількість HP та Damage на команду шляхом сумування відповідних показників у героїв команди. 
    Визначається команда-переможець: від HP команди віднімається Damage команди суперника, після чого переможцем вважається та команда, у якої залишилось більше HP. 
    Дані про ігрову сесію записуються у відповідне поле GameManager. 
    Кожному гравцю команди переможця нараховуються додаткові 25 балів рейтингу, а у кожного гравця команди, яка програла віднімаються 25 балів рейтингу.

Author: NUWM