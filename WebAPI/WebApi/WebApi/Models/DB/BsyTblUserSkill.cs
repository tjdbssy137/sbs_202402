using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class BsyTblUserSkill
{
    public int Key { get; set; }

    public int? UserKey { get; set; }

    public int? SkillKey { get; set; }

    public virtual BsyTblSkill? SkillKeyNavigation { get; set; }

    public virtual BsyTblUser? UserKeyNavigation { get; set; }
}
