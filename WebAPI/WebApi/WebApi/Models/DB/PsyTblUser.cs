using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PsyTblUser
{
    public int Key { get; set; }

    public int? ChampionKey { get; set; }

    public int? Level { get; set; }

    public virtual PsyTblChampion? ChampionKeyNavigation { get; set; }

    public virtual ICollection<PsyTblUserItem> PsyTblUserItems { get; set; } = new List<PsyTblUserItem>();

    public virtual ICollection<PsyTblUserSkill> PsyTblUserSkills { get; set; } = new List<PsyTblUserSkill>();
}
