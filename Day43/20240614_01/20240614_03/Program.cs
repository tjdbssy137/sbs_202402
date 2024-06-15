namespace _20240614_03
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.Write($"input : ");
            var input = Console.ReadLine();

            /*int a = 1;
            if (0 < a)
            {
                Console.WriteLine("들어온다.");
            }

            if ( input == "1")
            {
                Console.WriteLine("1");
            }
            else if (input == "2")
            {
                Console.WriteLine("2");
            }*/
            int size = int.Parse(input);
           for(int y = 0; y < size; y++) 
            {
                for(int x = 0; x < size; x++)
                {
                    if(y <= x)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                for (int x = 0; x < size; x++)
                {
                    if (size - x - 1 <= y)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }

           for(int y = 0; y < size; y++) 
            {
                for (int x = 0; x < size; x++)
                {
                    if (x <= size - y - 1)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                for (int x = 0; x < size; x++)
                {
                    if (x <= y)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();

            }
        }
    }
}
