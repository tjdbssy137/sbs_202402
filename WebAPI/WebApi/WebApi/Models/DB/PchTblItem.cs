using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PchTblItem
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<PchTblUserItem> PchTblUserItems { get; set; } = new List<PchTblUserItem>();
}
