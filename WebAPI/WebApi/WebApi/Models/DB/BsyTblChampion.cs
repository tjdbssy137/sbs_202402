using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class BsyTblChampion
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<BsyTblUser> BsyTblUsers { get; set; } = new List<BsyTblUser>();
}
