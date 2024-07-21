using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PchTblSkill
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<PchTblUserSkill> PchTblUserSkills { get; set; } = new List<PchTblUserSkill>();
}
