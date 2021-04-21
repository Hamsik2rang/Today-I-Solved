using System;
using System.Text;
using System.Collections.Generic;

namespace AlgoCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();
            // 첫 번째 데이터(Key)는 탑의 높이, 두 번째 데이터(Value)는 탑의 인덱스입니다.
            var st = new Stack<KeyValuePair<int, int>>();
            int count = Convert.ToInt32(Console.ReadLine());

            int[] height = Array.ConvertAll(Console.ReadLine().Split(), s => Convert.ToInt32(s));
            for (int i = 0; i < count; i++)
            {
                int index = i + 1;
                // 송신 가능성이 있는 탑이 하나도 없는 경우 새 탑을 송신 가능한 탑에 넣고 다음 탑으로
                if (st.Count == 0)
                {
                    st.Push(new KeyValuePair<int, int>(height[i], index));
                    sb.Append(0 + " ");
                    continue;
                }
                
                while (st.Count > 0)
                {
                    //스택의 맨 위가 현재 탑보다 높이가 높으면 해당 탑이 송신탑이 됨
                    if(st.Peek().Key > height[i])
                    {
                        sb.Append(st.Peek().Value+" ");
                        break;
                    }
                    st.Pop();
                }
                // 스택이 다 빌 때까지 찾아도 송신탑이 없으면 0 출력
                if (st.Count == 0)
                {
                    sb.Append(0 + " ");
                }
                // 현재 탑 스택에 추가
                st.Push(new KeyValuePair<int, int>(height[i], index));
            }
            Console.WriteLine(sb);
        }
    }
}
