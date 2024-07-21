namespace ConsoleClient
{
    internal class Program
    {
        static void Main(string[] args)
        {
            App app = new App();

            //await으로 안기다림 (Nonblocking) Async
            Task<int> task = app.RunAsync();


            //1. 기다리기
            //task.Wait();

            //2. 기다리기
            //blocking + Sync
            while (task.IsCompleted == false)
            {
                Console.WriteLine("실행중..");
            }

            

            Console.WriteLine($"실행완료.. : 결과 : {task.Result}");


            // 그동안 콘솔프로그래밍에서는
            // 할꺼다하고 앱이 종료되었죠?

            // WindowsAPI도 해봐서 아시겠지만
            // 보통 앱이 종료될때까지 프로그램을 무한루프로 계속돕니다.

            // 동기 비동기를 테스트하기 위해서 무한루프로 실행..
            while (true) { }
        }
    }
}
