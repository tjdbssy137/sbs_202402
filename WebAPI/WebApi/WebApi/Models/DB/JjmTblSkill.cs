using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class JjmTblSkill
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<JjmTblUserSkill> JjmTblUserSkills { get; set; } = new List<JjmTblUserSkill>();
}
