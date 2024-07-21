using Microsoft.AspNetCore.Mvc;

namespace WebApi.Controllers
{
    //Controller안의 함수는
    // Client가 요청할수있는 라우트가 된다.
    [ApiController]
    [Route("[controller]")]
    public class WeatherForecastController : ControllerBase
    {
        private readonly ILogger<WeatherForecastController> _logger;

        public WeatherForecastController(ILogger<WeatherForecastController> logger)
        {
            _logger = logger;
        }

        [HttpGet("Test")]
        public List<int> Test()
        {
            List<int> values = new List<int>();
            for (int i = 0; i < 10; i++)
            {
                values.Add(i);
            }

            return values;
        }
    }
}
