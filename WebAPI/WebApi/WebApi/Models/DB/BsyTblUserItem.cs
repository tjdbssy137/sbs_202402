using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class BsyTblUserItem
{
    public int Key { get; set; }

    public int? UserKey { get; set; }

    public int? ItemKey { get; set; }

    public virtual BsyTblItem? ItemKeyNavigation { get; set; }

    public virtual BsyTblUser? UserKeyNavigation { get; set; }
}
