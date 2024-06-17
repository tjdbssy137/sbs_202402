using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

// 하이로우세븐 C# 버전
namespace _20240617_02
{
    public class App
    {
        // C++ 에서는
        // 접근제어자 : 그 아래에 함수를 선언
        // C#에서는 모든 함수, 변수 앞에 접근 제어를 직접 써줘야함.
        // C# 클래스 변수 선언의 특별한 점 : 클래스 변수선언과 동시에 동적할당이 가능
        private List<int> _cards = new List<int>();
        private List<int> _displayCards = new List<int>();

        private int _money = 1000;
        private int _order = 0; // 사용중인 카드 인덱스
        private int _bet = 0; 
        private int _bettingMoney = 0;
        public void Run()
        {
            //카드 추가
            for (int i = 0; i < 52; i++)
            {
                _cards.Add(i);
            }

            //섞기
            Random random = new Random();
            for (int i = 0; i < 500; i++)
            {
                int first = random.Next(_cards.Count);
                int second = random.Next(_cards.Count);

                int temp = _cards[first];
                _cards[first] = _cards[second];
                _cards[second] = temp;
            }

            // 본 게임
            while (true)
            {
                if (_cards.Count <= 0 || _money <= 0)
                {
                    Console.WriteLine("Game Over");
                    break;
                }
                PrintCards();
                ExpectCard();
                Calculator();
            }
        }

        public void PrintCards()
        {
            Console.WriteLine("===============================");
            for (; _displayCards.Count <= 4; _order++)
            {
                if (_order == 52)
                {
                    Console.WriteLine("카드를 전부 사용하였습니다. 게임이 종료 됩니다.");
                    break;
                }
                if (_displayCards.Count < 4)
                {
                    IndextToCardNumber();
                    _displayCards.Add(0);
                }
                else
                {
                    Console.WriteLine("XX");
                    _displayCards.Add(0);
                    break;
                }
            }
            Console.WriteLine("===============================");
        }
        public void ExpectCard()
        {
            Console.WriteLine("하이(0) / 로우(1) / 세븐(2)");
            Console.WriteLine("**하이는 2배, 로우는 2배, 세븐은 10배입니다.**");
            var inputBet = Console.ReadLine();
            _bet = int.Parse(inputBet ?? "0");
            Console.WriteLine("배팅하실 금액을 입력해주세요.");
            Console.WriteLine($"현재 보유 금액 : {_money}");
            var inputBettingMoney = Console.ReadLine();
            _bettingMoney = int.Parse(inputBettingMoney ?? "0");
        }
        public void Calculator()
        {
            Console.Write("XX는 ");
            IndextToCardNumber();
            if (7 < _cards[_order] % 13 + 1)
            {
                if (0 == _bet)
                {
                    _money += (_bettingMoney * 2);
                    Console.WriteLine($"축하합니다 {_bettingMoney * 2}원을 얻으셨습니다!");
                }
                else
                {
                    _money -= (_bettingMoney * 2);
                    if (_money < 0)
                    {
                        Console.WriteLine($"축하합니다 {_bettingMoney * 2}원을 잃으셨습니다! 현재 금액은 " +
                            $"{_money}로 파산하셨습니다.");
                    }
                    else
                    {
                        Console.WriteLine($"{_bettingMoney * 2}원을 잃으셨습니다!");
                    }
                }
            }
            else if (_cards[_order] % 13 + 1 < 7)
            {
                if (1 == _bet)
                {
                    _money += (_bettingMoney * 2);
                    Console.WriteLine($"축하합니다 {_bettingMoney * 2}원을 얻으셨습니다!");
                }
                else
                {
                    _money -= (_bettingMoney * 2);
                    if (_money < 0)
                    {
                        Console.WriteLine($"{_bettingMoney * 2}원을 잃으셨습니다! 현재 금액은 " +
                            $"{_money}로 파산하셨습니다.");
                    }
                    else
                    {
                        Console.WriteLine($"{_bettingMoney * 2}원을 잃으셨습니다!");
                    }
                }
            }
            else if (_cards[_order] % 13 + 1 == 7)
            {
                if (2 == _bet)
                {
                    _money += (_bettingMoney * 10);
                    Console.WriteLine($"축하합니다 {_bettingMoney * 10}원을 얻으셨습니다!");
                }
                else
                {
                    _money -= (_bettingMoney * 10);
                    if (_money < 0)
                    {
                        Console.WriteLine($"{_bettingMoney * 10}원을 잃으셨습니다! 현재 금액은 " +
                            $"{_money}로 파산하셨습니다.");
                    }
                    else
                    {
                        Console.WriteLine($"{_bettingMoney * 10}원을 잃으셨습니다!");
                    }
                }
            }
            _displayCards.Clear();
            _order -= 3;
        }
        public void IndextToCardNumber()
        {
            switch (_cards[_order] / 13)
            {
                case 0:
                    Console.Write("♤");
                    break;
                case 1:
                    Console.Write("◆"); 
                    break;
                case 2:
                    Console.Write("♥"); 
                    break;
                case 3:
                    Console.Write("♧"); 
                    break;
            }

            switch (_cards[_order] % 13 + 1)
            {
                case 1:
                    Console.Write(" A ");
                    break;
                case 11:
                    Console.Write(" J ");
                    break;
                case 12:
                    Console.Write(" Q ");
                    break;
                case 13:
                    Console.Write(" K ");
                    break;
                default:
                    Console.Write($"{_cards[_order] % 13 + 1}");
                    break;
            }
            Console.WriteLine("");
        }
    }
}