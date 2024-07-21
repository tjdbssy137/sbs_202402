using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PchTblUser
{
    public int Key { get; set; }

    public int? ChampionKey { get; set; }

    public int? Level { get; set; }

    public virtual PchTblChampion? ChampionKeyNavigation { get; set; }

    public virtual ICollection<PchTblUserItem> PchTblUserItems { get; set; } = new List<PchTblUserItem>();

    public virtual ICollection<PchTblUserSkill> PchTblUserSkills { get; set; } = new List<PchTblUserSkill>();
}
