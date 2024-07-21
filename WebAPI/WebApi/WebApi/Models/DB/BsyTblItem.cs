using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class BsyTblItem
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<BsyTblUserItem> BsyTblUserItems { get; set; } = new List<BsyTblUserItem>();
}
