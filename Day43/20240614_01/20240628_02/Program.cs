namespace _20240628_02
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Champion> champions = new List<Champion>();
            champions.Add(new Champion()
            {
                Key = 0,
                Name = "티모"
            });
            champions.Add(new Champion()
            {
                Key = 1,
                Name = "가렌"
            });
            Console.WriteLine($"Key : {champions[0].Key}, Name : {champions[0].Name}");

            List<Item> items = new List<Item>()
            { 
                new Item {Key = 0, Name = "신발"},
                new Item {Key = 1, Name = "단검"},
                new Item {Key = 2, Name = "롱소드"}
            };
            var item1 = items.Where(item => item.Name == "롱소드").FirstOrDefault();
            
            Console.WriteLine($"Key : {item1.Key}, Name : {item1.Name}");

            List<Skill> skills = new List<Skill>()
            {
                new Skill {Key = 0, Name = "실명"},
                new Skill {Key = 1, Name = "이동증속"},
                new Skill {Key = 2, Name = "침묵"}
            };

            List<User> users = new List<User>()
            {
                new User {Key = 0, ChampionKey = 0, Level = 2},
                new User {Key = 1, ChampionKey = 1, Level = 1}
            };

            var user1 = users.OrderBy(user => user.Level).ToList(); // 오름차순
            var user2 = users.OrderByDescending(user => user.Level).ToList(); // 내림차순
            // users.Distinct() // 중복데이터 제거
            // users.Any (데이터가 1개라도 있는지? 있으면 t, 없으면 f)
            if(skills.Where(skill => skill.Name == "실명").Any())
            {
                Console.WriteLine("오라 작용");
            }
            // items.Min(), items.Max()
            // items.Take(N) (몇개만 가져오겠다)
            // items.Skip(N) (몇개를 스킵하겠다)
            // items.GroupBy
            // items.Join
            //하나의 테이블에 원하는 데이터가 모두 있다면 참 좋겠지만, 두 개의 테이블을 엮어야 원하는 결과가 나오는 경우도 많음.
            //      -> 조인을 쓰면 두 개의 테이블을 엮어서 원하는 데이터를 추출할 수 있다.
            // join 실행했을 때 1회 실행
            // 조회할 때만 조금 문제가 발생
            // 결과적으로는 조회를 많이하기에 잘못 쓰면 많이 느림.
            Console.WriteLine("<<Join1>>");

            var userChampions1 = (from u in users
                                join c in champions
                                    on u.ChampionKey equals c.Key
                                select new
                                {
                                    ChampionKey = c.Key,
                                    ChampionName = c.Name,
                                    Level = u.Level
                                }).ToList();

            foreach(var uc in userChampions1)
            {
                Console.WriteLine($"{uc.ChampionName} : {uc.Level}");
            }

            Console.WriteLine("<<Join2>>");

            var userChampions2 = users.Join(
                champions, // join할 table
                user => user.ChampionKey,
                champion => champion.Key,
                (user, champion) => new
                {
                    ChampionKey = champion.Key,
                    ChampionName = champion.Name,
                    Level = user.Level
                }).ToList();

            foreach (var uc in userChampions2)
            {
                Console.WriteLine($"{uc.ChampionName} : {uc.Level}");
            }
        }
    }
}
