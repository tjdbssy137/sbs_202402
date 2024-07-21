using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleClient
{
    internal class App
    {
        public async Task<int> RunAsync()
        {
            // async, await, Task 키워드
            // async 키워드 : 이함수는 비동기 함수입니다.
            // Task 키워드 : return 형이 Task 입니다. (스레드)

            // await 키워드 : Async로 되어있는 비동기함수를 완료될때까지 기다리겠다.
            //              : await + async함수
            //               이렇게하면 return값이 Task<자료형> 에서 자료형 으로 변한다.

            // 스레드 : 
            //   싱글스레드 환경에서만 코딩
            // 스레드는 코드를 실행주는 아이
            // 스레드를 여러개사용하면 멀티스레드

            var client = new HttpClient();
            var request = new HttpRequestMessage(HttpMethod.Get, "http://localhost:5123/WeatherForecast/Test");
            var response = await client.SendAsync(request);
            response.EnsureSuccessStatusCode();
            Console.WriteLine(await response.Content.ReadAsStringAsync());



            int a = await GetMyValue();
            Task<int> b = GetMyValue();

            return 5;
        }


        public async Task<int> GetMyValue()
        {
            await Task.Delay(1000);  // 새로운 스레드를 만들어서 걔가 1초 대기할때까지 기다리는거

            //Thread.Sleep(1000);  // 현재 내 스레드를 1초동안 잠재우는것

            return 1;
        }
    }
}
