using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PchTblChampion
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<PchTblUser> PchTblUsers { get; set; } = new List<PchTblUser>();
}
