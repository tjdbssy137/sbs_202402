using Microsoft.AspNetCore.Mvc;

namespace WebAPI.Controllers
{
    // Controller 안의 함수는
    // Client가 요청할 수 있는 라우트가 된다.

    [ApiController]
    [Route("[controller]")]
    public class WeatherForecastController : ControllerBase
    {
       
        private readonly ILogger<WeatherForecastController> _logger;

        public WeatherForecastController(ILogger<WeatherForecastController> logger)
        {
            _logger = logger;
        }
        
        // 요청 온 것을 처리하는 코드
        [HttpGet("Test")]
        public List<int> Get()
        {
            List<int> values = new List<int>();
            for(int i = 0; i < 10; i++) 
            {
                values.Add(i);
            }
            return values;
        }
    }
}
