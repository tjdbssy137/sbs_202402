using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20240619_04
{

    public interface ICreature
    { 
        string Name { get; set; }
        float Hp {  get; set; }
        void Attack(ICreature target);
        int Damage { get; set; }

        int skill { get; set; }
    }

    /*public interface IAttacker
    {
        void Attack(ICreature target);
        float Damage { get; set; }
    }*/


    public class Hero : ICreature
        //C#은 interface만 다중 상속이 되고 class는 다중 상속이 안 됨
    {
        public int Damage { get; set; } = 30;
        public string Name { get; set; } = "Hero1";
        public float Hp { get; set; } = 100;

        public int skill { get; set; } = 30;

        void ICreature.Attack(ICreature target) // 인터페이스를 상속 받으면 무조건 상속받은 인터페이스의 함수를 정의해야함.
        {
            Console.WriteLine($"Hero가 {this.Damage}만큼 공격했습니다.");
            target.Hp -= this.Damage;
            Console.WriteLine($"Monster의 체력이 {target.Hp}(이)가 되었습니다.");
        }
    }
    public class Monster : ICreature
    {
        public int Damage { get; set; } = 30;
        public string Name { get; set; } = "Monster1";
        public float Hp { get; set; } = 100;

        public int skill { get; set; } = 30;

        void ICreature.Attack(ICreature target) // 인터페이스를 상속 받으면 무조건 상속받은 인터페이스의 함수를 정의해야함.
        {
            Console.WriteLine($"Monster가 {this.Damage}만큼 공격했습니다.");
            target.Hp -= this.Damage;
            Console.WriteLine($"Hero의 체력이 {target.Hp}(이)가 되었습니다.");
        }
    }
    public class App
    {

        Random random = new Random();
        public void Run()
        {
            
            List<ICreature> creatures = new List<ICreature>();
            creatures.Add(new Hero());
            creatures.Add(new Monster());

            while (true)
            {
                if (creatures[1].Hp <= 0)
                {
                    Console.WriteLine("게임을 종료합니다. Hero 승리");
                    break;
                }

                if (creatures[0].Hp <= 0)
                {
                    Console.WriteLine("게임을 종료합니다. Monster 승리");
                    break;
                }

                if (creatures[0] is ICreature)
                {
                    ICreature attacker = (ICreature)creatures[0];

                    if(attacker != null)
                    {
                        attacker.Attack(creatures[1]);
                    }
                }

                if (creatures[1] is ICreature)
                {
                    ICreature attacker = (ICreature)creatures[1];

                    if (attacker != null)
                    {
                        attacker.Attack(creatures[0]);
                    }
                }
            }

            /*while (true)
            {
                
                creatures[0].Damage = random.Next(20, creatures[0].skill);
                creatures[0].Attack(creatures[1]);
                if (creatures[1].Hp <= 0)
                {
                    Console.WriteLine("게임을 종료합니다. Hero 승리");
                    break;
                }
                
                creatures[1].Damage = random.Next(20, creatures[1].skill);
                creatures[1].Attack(creatures[0]);
                if (creatures[0].Hp <= 0)
                {
                    Console.WriteLine("게임을 종료합니다. Monster 승리");
                    break;
                }

                creatures[0].skill += random.Next(0, 5);
                Console.WriteLine($"\nHero의 최대 Damage가 {creatures[0].skill}가 되었습니다");
                creatures[1].skill += random.Next(0, 5);
                Console.WriteLine($"Monster의 최대 Damage가 {creatures[1].skill} 가 되었습니다");
                Console.WriteLine("=========================================");

            }*/

        }
    }
}
