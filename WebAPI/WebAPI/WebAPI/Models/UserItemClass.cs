namespace WebApi.Models
{
    public class RequestDtoInsertUserItem
    {
        public int UserKey { get; set; }
        public int ItemKey { get; set; }
    }

    public class ResponseDtoInsertUserItem
    {
    }

    public class RequestDtoUpdateUserItem
    {
        public int Key { get; set; }
        public int UserKey { get; set; }
        public int ItemKey { get; set; }
    }

    public class ResponseDtoUpdateUserItem
    {
    }

    public class RequestDtoDeleteUserItem
    {
        public int Key { get; set; }
    }

    public class ResponseDtoDeleteUserItem
    {
    }
}
