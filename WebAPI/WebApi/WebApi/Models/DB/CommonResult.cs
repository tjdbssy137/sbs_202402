namespace WebApi.Models.Dto
{
    public class CommonResult<T>
    {
        public bool IsSuccess { get; set; } = false;
        public string Message { get; set; } = string.Empty;
        public EStatusCode StatusCode { get; set; } = EStatusCode.OK;
        public T Data { get; set; }
    }

    public enum EStatusCode
    { 
        OK,
        NotFoundEntity,
        ServerException
    }


    public class CommonExeption : Exception
    {
        protected EStatusCode _statusCode = EStatusCode.OK;
        public int StatusCode => (int)_statusCode;
        
        protected object _data;
        public object Data => _data;

        public CommonExeption(EStatusCode statusCode, string message, object data = null) : base(message) 
        {
            _statusCode = statusCode;
            _data = data;
        }

        public override string ToString()
        {
            return $"[{StatusCode}] {this.Message}";
        }
    }
}
