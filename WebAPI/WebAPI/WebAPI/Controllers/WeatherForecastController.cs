using Microsoft.AspNetCore.Mvc;

namespace WebAPI.Controllers
{
    // Controller ���� �Լ���
    // Client�� ��û�� �� �ִ� ���Ʈ�� �ȴ�.

    [ApiController]
    [Route("[controller]")]
    public class WeatherForecastController : ControllerBase
    {
       
        private readonly ILogger<WeatherForecastController> _logger;

        public WeatherForecastController(ILogger<WeatherForecastController> logger)
        {
            _logger = logger;
        }
        
        // ��û �� ���� ó���ϴ� �ڵ�
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
