using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http.Headers;
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
            // await 키워드 : async로 되어있는 비동기함수를 완료될때까지 기다리겠다.
            //                  : await + acync 함수
            //                     이렇게 하면 return 값이 Task<자료형>에서 자료형으로 변한다.
            // Task 키워드 : return 형 Task. (이함수는 비동기 함수 입니다.)

            // 스레드 : 
            //  싱글스레드 환경에서만 코딩
            // 스레드란, 코드를 실행시켜주는 아이
            // 스레드를 여러개 사용하면 멀티스레드

            var client = new HttpClient();
            var request = new HttpRequestMessage(HttpMethod.Get, "http://localhost:5226/User/Test");
            var response = await client.SendAsync(request);
            response.EnsureSuccessStatusCode();
            Console.WriteLine(await response.Content.ReadAsStringAsync());

            // 동기 비동기 차이점 말씀해주셨는데 기억 안남.
            int a = await GetMyValue();
            Task<int> b = GetMyValue();

            return 5;
            // Server Client 구조에서
            // 제일 중요한
            // 동기/비동기 구조

            /*Thread t = new Thread( async () =>
            {
                var client = new HttpClient();
                var request = new HttpRequestMessage(HttpMethod.Get, "http://localhost:5226/User/Test");
                var response = await client.SendAsync(request);
                response.EnsureSuccessStatusCode();
                Console.WriteLine(await response.Content.ReadAsStringAsync());
            });
            t.Start();
            t.Join();

            while (true) { };*/
        }

        public async Task<int> GetMyValue()
        {
            await Task.Delay(1000); // 새로운 스레드를 만들어서 걔가 1초 대기할 때까지 기다리는 것
           //Thread.Sleep(1000); // 현재 내 스레드를 1초동안 잠재우는 것
            return 1;
        }
    }
}
