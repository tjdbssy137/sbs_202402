namespace ConsoleClient
{
    internal class Program
    {
        static void Main(string[] args)
        {
            App app = new App();
            
            // await으로 안 기다림
            Task<int> task = app.RunAsync();
            
            // 기다리기
            //task.Wait();
            // 기다리기2
            while(task.IsCompleted == false) 
            {
                Console.WriteLine("실행 중");
            }
            Console.WriteLine($"실행 완료 : {task.Result}");
            // 그동안 콘솔프로그래밍에서는 할거 다하고 앱이 종료 되었는데
            // WindowsAPI도 해봐서 알겠지만 보통 앱이 종료될때까지 프로그램을 무한루프로 계속 돌림


        }
    }
}
