using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PsyTblSkill
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<PsyTblUserSkill> PsyTblUserSkills { get; set; } = new List<PsyTblUserSkill>();
}
