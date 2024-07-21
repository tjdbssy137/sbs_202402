using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PsyTblItem
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<PsyTblUserItem> PsyTblUserItems { get; set; } = new List<PsyTblUserItem>();
}
