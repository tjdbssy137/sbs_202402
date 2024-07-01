using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace _20240701_02
{
    public class Champion
    {
        public int Key { get; set; } = 0;
        public string Name { get; set; } = "";
    }

    public class Item
    {
        public int Key { get; set; } = 0;
        public string Name { get; set; } = "";
    }

    public class Skill
    {
        public int Key { get; set; } = 0;
        public string Name { get; set; } = "";
    }

    public class User
    {
        public int Key { get; set; } = 0;
        public int ChampionKey { get; set; } = 0;
        public int Level { get; set; } = 0;
    }

    public class UserChapion
    {
        public int UserKey { get; set; }
        public Champion championInfo { get; set; }
        public int Level { get; set; } = 0;
        public List<Skill> skills { get; set; }
        public List<Item> items { get; set; }
    }

    internal class App
    {
        public void Run()
        {
            List<UserChapion> userChapions = new List<UserChapion>()
            {
                new UserChapion{
                    UserKey = 0,
                    championInfo = new Champion{ Key = 0, Name = "티모" },
                    Level = 2,
                    skills = new List<Skill>() { new Skill {Key = 0, Name = "실명" }, new Skill {Key = 1, Name = "이속증가" } },
                    items = new List<Item>() { new Item {Key = 0, Name = "신발" }, new Item {Key = 1, Name = "단검" } }
                },
                new UserChapion
                {
                    UserKey = 1,
                    championInfo = new Champion{ Key = 1, Name = "가렌" },
                    Level = 1,
                    skills = new List<Skill>() { new Skill {Key = 2, Name = "침묵" } },
                    items = new List<Item>() { new Item {Key = 1, Name = "단검" }, new Item {Key = 2, Name = "롱소드" } }
                }
            };
            
            // _datas에 들어간 정보중에서 Name별로 묶어서 데이터 좀 예쁘게 보고싶다.
            foreach (var item in userChapions)
            {
                Console.WriteLine($"{item.championInfo.Name} : ");
                foreach (var skill in item.skills)
                {
                    Console.WriteLine($"{skill.Name}");
                }
            }
        }
        public void Run2()
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

            List<Skill> skills = new List<Skill>()
            {
                new Skill {Key = 0, Name = "실명"},
                new Skill {Key = 1, Name = "이동증속"},
                new Skill {Key = 2, Name = "침묵"}
            };
            List<Item> items = new List<Item>()
            {
                new Item {Key = 0, Name = "신발"},
                new Item {Key = 1, Name = "단검"},
                new Item {Key = 2, Name = "롱소드"}
            };
            List<User> users = new List<User>()
            {
                new User {Key = 0, ChampionKey = 0, Level = 2},
                new User {Key = 1, ChampionKey = 1, Level = 1}
            };

            List<UserChapion> userChapions = new List<UserChapion>();


            var championQuery = (from uc in users            // users를 u라고 칭하면서 순회한다
                        join champion in champions  // 조회하는 테이블에 Champion을 추가한다
                        on uc.ChampionKey equals champion.Key // 추가할 때, user의 championKey와 champion.key가
                                  
                        select new  
                        {   ChampionKey = champion.Key,
                            ChampionName = champion.Name,
                            Level = uc.Level,
                            UserKey = uc.Key
                        });

            
            List<int> userKeys = new List<int>() { 1, 2, 3 };

            //DB는 퍼포먼스를 생각해야함.
            foreach (var u in userKeys)
            {
                userChapions.Add(new UserChapion()
                {
                    championInfo = (from user in users
                                    where user.Key == u
                                    join champion in champions  // 조회하는 테이블에 Champion을 추가한다
                                      on user.ChampionKey equals champion.Key // 추가할 때, user의 championKey와 champion.key가
                                                                              // 동일한 것을 기준으로 묶어서 조회한다
                                    select new Champion()
                                    {
                                        Key = champion.Key,
                                        Name = champion.Name,
                                    }).FirstOrDefault() ?? new Champion(),
                    Level = (from user in users
                             where user.Key == u
                             select user).FirstOrDefault()?.Level ?? 0,

                    items = (from user in users
                            where user.Key == u
                            join userItem in userItems
                                on user.Key equals userItem.UserKey
                            join item in items
                                on userItem.ItemKey equals item.Key
                            select new Item()
                            { 
                                Key = userItem.ItemKey,
                                Name = userItem.ItemKey
                            
                            }).ToList(),
                    UserKey = u,

                    skills = (from user in users
                              where user.Key == u
                              join userSkill in userSkills
                                    on user.Key equals userItem.UserKey
                              join skill in skills  
                                    on userSkill.SkillKey equals skill.Key
                              select new Skill()
                              { 
                                  Key = userSkill.ItemKey,
                                  Name = userSkill.ItemKey
                              }).ToList()
                });
            }


            foreach(var uc in userChapions)
            {
                Console.WriteLine($"{uc.UserKey} : ");
                Console.WriteLine($"Level : {uc.Level}");
                Console.WriteLine($"Champion Name : {uc.championInfo.Name}");
                Console.WriteLine($"Skill : ");
                foreach(var skill in uc.Skills)
                {
                    Console.WriteLine($"{skill.Name}");
                }
                Console.WriteLine($"Item : ");
                foreach (var item in uc.Items)
                {
                    Console.WriteLine($"{item.Name}");
                }
            }
        }

    }
}

