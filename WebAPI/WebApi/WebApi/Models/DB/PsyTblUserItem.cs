using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PsyTblUserItem
{
    public int Key { get; set; }

    public int? UserKey { get; set; }

    public int? ItemKey { get; set; }

    public virtual PsyTblItem? ItemKeyNavigation { get; set; }

    public virtual PsyTblUser? UserKeyNavigation { get; set; }
}
