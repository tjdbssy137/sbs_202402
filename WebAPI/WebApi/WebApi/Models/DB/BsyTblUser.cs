using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class BsyTblUser
{
    public int Key { get; set; }

    public int? ChampionKey { get; set; }

    public int? Level { get; set; }

    public virtual ICollection<BsyTblUserItem> BsyTblUserItems { get; set; } = new List<BsyTblUserItem>();

    public virtual ICollection<BsyTblUserSkill> BsyTblUserSkills { get; set; } = new List<BsyTblUserSkill>();

    public virtual BsyTblChampion? ChampionKeyNavigation { get; set; }
}
