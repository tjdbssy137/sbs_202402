using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class JjmTblUserSkill
{
    public int Key { get; set; }

    public int? UserKey { get; set; }

    public int? SkillKey { get; set; }

    public virtual JjmTblSkill? SkillKeyNavigation { get; set; }

    public virtual JjmTblUser? UserKeyNavigation { get; set; }
}
