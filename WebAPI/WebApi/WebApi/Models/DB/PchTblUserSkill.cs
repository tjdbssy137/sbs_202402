using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PchTblUserSkill
{
    public int Key { get; set; }

    public int? UserKey { get; set; }

    public int? SkillKey { get; set; }

    public virtual PchTblSkill? SkillKeyNavigation { get; set; }

    public virtual PchTblUser? UserKeyNavigation { get; set; }
}
