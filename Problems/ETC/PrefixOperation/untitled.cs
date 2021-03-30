using System;
using System.Collections.Generic;

namespace AlgoCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = "3+4-2*5";

            Console.WriteLine(Solution(s));
        }

        static string Solution(string expression)
        {
            string answer = "";
            string prefix = "";
            bool isZeroDivided = false;
            var st = new Stack<char>();
            var operand = new Stack<int>();

            foreach (char c in expression)
            {
                if (c >= '0' && c <= '9')
                {
                    prefix += c;
                }
                else if (c == '+' || c == '-')
                {
                    while (st.Count != 0)
                    {
                        prefix += st.Pop();
                    }
                    st.Push(c);
                }
                else
                {
                    while (st.Count != 0 && st.Peek() != '+' && st.Peek() != '-')
                    {
                        prefix += st.Pop();
                    }
                    st.Push(c);
                }
            }

            while (st.Count > 0)
            {
                prefix += st.Pop();
            }

            for (int i = 0; i < prefix.Length; i++)
            {
                if (prefix[i] >= '0' && prefix[i] <= '9')
                {
                    operand.Push(prefix[i] - '0');
                }
                else
                {
                    int rvalue = operand.Pop();
                    int lvalue = operand.Pop();
                    operand.Push(Operation(lvalue, prefix[i], rvalue, ref isZeroDivided));

                    if (isZeroDivided)
                    {
                        return "Impossible";
                    }
                }
            }
            answer = Convert.ToString(operand.Peek());

            return answer;
        }
        static int Operation(int lvalue, char op, int rvalue,ref bool isZeroDivided)
        {
            int result = 0;
            switch (op)
            {
                case '+':
                    result = lvalue + rvalue;
                    break;
                case '-':
                    result = lvalue - rvalue;
                    break;
                case '*':
                    result = lvalue * rvalue;
                    break;
                case '/':
                    if (rvalue == 0)
                    {
                        isZeroDivided = true;
                        return 0;
                    }
                    result = lvalue / rvalue;
                    break;
                default:
                    break;
            }

            return result;
        }
    }
}
