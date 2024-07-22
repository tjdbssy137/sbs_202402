namespace WebApi.Models.Dto
{
    public class RequestDtoGetChampionInfoByUserKey
    {
        public int UserKey { get; set; }
    }

    public class ResponseDtoGetChampionInfoByUserKey
    {
        public int UserKey { get; set; }
        public int ChampionLevel { get; set; }
        public string ChampionName { get; set; } = string.Empty;
    }

    public class RequestDtoGetItemListByUserKey
    {
        public int UserKey { get; set; }
    }

    public class ResponseDtoGetItemListByUserKey
    {
        public List<ResponseDtoGetItemListByUserKeyElement> List { get; set; }
    }

    public class ResponseDtoGetItemListByUserKeyElement
    {
        public int ItemKey { get; set; }
        public string ItemName { get; set; } = string.Empty;
    }

    public class RequestDtoGetSkillListByUserKey
    {
        public int UserKey { get; set; }
    }

    public class ResponseDtoGetSkillListByUserKey
    {
        public List<ResponseDtoGetSkillListByUserKeyElement> List { get; set; }
    }

    public class ResponseDtoGetSkillListByUserKeyElement
    {
        public int SkillKey { get; set; }

        public string SkillName { get; set; } = string.Empty;
    }

    // 리스트용 클래스가 하나 더 필요


    // SKILL

    public class RequestDtoInsertUserSkill
    {
        public int UserKey { get; set; }
        public int SkillKey { get; set; }
    }

    public class ResponseDtoInsertUserSkill
    {
    }

    public class RequestDtoUpdateUserSkill
    {
        public int Key { get; set; }
        public int UserKey { get; set; }
        public int SkillKey { get; set; }
    }

    public class ResponseDtoUpdateUserSkill
    {
    }

    public class RequestDtoDeleteUserSkill
    {
        public int Key { get; set; }
    }

    public class ResponseDtoDeleteUserSkill
    {
    }
}
