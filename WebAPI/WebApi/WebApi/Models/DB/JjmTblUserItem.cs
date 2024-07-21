using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class JjmTblUserItem
{
    public int Key { get; set; }

    public int? UserKey { get; set; }

    public int? ItemKey { get; set; }

    public virtual JjmTblItem? ItemKeyNavigation { get; set; }

    public virtual JjmTblUser? UserKeyNavigation { get; set; }
}
