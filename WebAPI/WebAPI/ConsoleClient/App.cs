using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleClient
{
    internal class App
    {
        public void Run()
        {

            // Server Client 구조에서
            // 제일 중요한
            // 동기/비동기 구조

            Thread t = new Thread( async () =>
            {
                var client = new HttpClient();
                var request = new HttpRequestMessage(HttpMethod.Get, "http://localhost:5226/User/Test");
                var response = await client.SendAsync(request);
                response.EnsureSuccessStatusCode();
                Console.WriteLine(await response.Content.ReadAsStringAsync());
            });
            t.Start();
            t.Join();

            while (true) { };
        }
    }
}
