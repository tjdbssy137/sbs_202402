using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class JjmTblItem
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<JjmTblUserItem> JjmTblUserItems { get; set; } = new List<JjmTblUserItem>();
}
