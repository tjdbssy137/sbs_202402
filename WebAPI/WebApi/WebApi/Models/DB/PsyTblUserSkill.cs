using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PsyTblUserSkill
{
    public int Key { get; set; }

    public int? UserKey { get; set; }

    public int? SkillKey { get; set; }

    public virtual PsyTblSkill? SkillKeyNavigation { get; set; }

    public virtual PsyTblUser? UserKeyNavigation { get; set; }
}
