using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PchTblUserItem
{
    public int Key { get; set; }

    public int? UserKey { get; set; }

    public int? ItemKey { get; set; }

    public virtual PchTblItem? ItemKeyNavigation { get; set; }

    public virtual PchTblUser? UserKeyNavigation { get; set; }
}
