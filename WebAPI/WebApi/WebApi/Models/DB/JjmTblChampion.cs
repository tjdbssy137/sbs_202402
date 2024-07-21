using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class JjmTblChampion
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<JjmTblUser> JjmTblUsers { get; set; } = new List<JjmTblUser>();
}
