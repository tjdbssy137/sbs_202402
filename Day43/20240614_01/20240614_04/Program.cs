namespace _20240614_04
{
    public class Program
    {
        public static void Main(string[] args)
        {
            while(true) 
            {
                Console.WriteLine("수식 or quit을 입력하세요.");
                var input = Console.ReadLine();
                if(input == "quit")
                {
                    break;
                }
                Console.WriteLine("첫번째 숫자를 입력하세요.");
                var num1string = Console.ReadLine();
                Console.WriteLine("두번째 숫자를 입력하세요.");
                var num2string = Console.ReadLine();

                int num1 = int.Parse(num1string ?? "0"); // 앞에 값이 null값이면 0을 써라
                int num2 = int.Parse(num2string ?? "0"); // 앞에 값이 null값이면 0을 써라
                switch (input)
                {
                    case "*":
                        Console.WriteLine($"{num1} * {num2} = {num1 * num2}"); 
                        break;
                    case "/":
                        Console.WriteLine($"{num1} / {num2} = {num1 / num2}");
                        break;
                    case "-":
                        Console.WriteLine($"{num1} - {num2} = {num1 - num2}");
                        break;
                    case "+":
                        Console.WriteLine($"{num1} + {num2} = {num1 + num2}");
                        break;
                    default:
                        break;
                }
            }
        }
    }
}
