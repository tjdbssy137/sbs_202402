using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
|Key|Name|
|---|---|
|1|티모|
|2|가렌|
 */
namespace _20240628_02
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

    public class UserItem
    {
        public int Key { get; set; } = 0;
        public int UserKey { get; set; } = 0;
        public int ItemKey { get; set; } = 0;
    }

    public class UserSkill
    {
        public int Key { get; set; } = 0;
        public int UserKey { get; set; } = 0;
        public int SkillKey { get; set; } = 0;
    }

    public class UserChapion
    {
        public Champion championInfo { get; set; }
        public int Level { get; set; } = 0;
        public List<Skill> skills { get; set; }
        public List<Item> items { get; set; }
    }

}
