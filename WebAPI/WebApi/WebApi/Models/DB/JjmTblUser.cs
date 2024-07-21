using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class JjmTblUser
{
    public int Key { get; set; }

    public int? ChampionKey { get; set; }

    public int? Level { get; set; }

    public virtual JjmTblChampion? ChampionKeyNavigation { get; set; }

    public virtual ICollection<JjmTblUserItem> JjmTblUserItems { get; set; } = new List<JjmTblUserItem>();

    public virtual ICollection<JjmTblUserSkill> JjmTblUserSkills { get; set; } = new List<JjmTblUserSkill>();
}
