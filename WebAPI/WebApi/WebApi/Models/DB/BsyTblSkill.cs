using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class BsyTblSkill
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<BsyTblUserSkill> BsyTblUserSkills { get; set; } = new List<BsyTblUserSkill>();
}
