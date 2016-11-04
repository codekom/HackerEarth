    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
     
    namespace ppsum
    {
        class Program
        {
            static void Main(string[] args)
            {
                int t, i, j, n, m;
                t = int.Parse(Console.ReadLine());
                string[] st;
                int [,]arr=new int[102,102];
                while (t-- > 0)
                {
                    st = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    n = int.Parse(st[0]);
                    m = int.Parse(st[1]);
                    int[,] dp = new int[102, 102];
                    for (i = 0; i < n; i++)
                    {
                        st = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        for (j = 0; j < m; j++)
                        {
                            arr[i, j] = int.Parse(st[j]);
                        }
                    }
                    dp[0, 0] = 1;
                    int maxi = 1;
                    for (i = 1; i < n; i++)
                    {
                        if (arr[i, 0] > arr[i - 1, 0])
                        {
                            dp[i, 0] = 1 + dp[i - 1, 0];
                            maxi = Math.Max(maxi, dp[i, 0]);
                        }
                        else
                            break;
                    }
                    for (j = 1; j < m; j++)
                    {
                        if (arr[0, j] > arr[0, j - 1])
                        {
                            dp[0, j] = 1 + dp[0, j - 1];
                            maxi = Math.Max(maxi, dp[0, j]);
                        }
                        else
                            break;
                    }
                    for (i = 1; i < n; i++)
                    {
                        for (j = 1; j < m; j++)
                        {
                            if (dp[i - 1, j] == 0)
                            {
                                if (dp[i, j - 1] != 0)
                                {
                                    if (arr[i, j] > arr[i, j-1])
                                        dp[i, j] = 1 + dp[i, j - 1];
                                }
                            }
                            else if (dp[i, j - 1] == 0)
                            {
                                if (dp[i - 1, j] != 0)
                                {
                                    if (arr[i, j] > arr[i - 1, j])
                                        dp[i, j] = 1 + dp[i - 1, j];
                                }
                            }
                            else if (dp[i - 1, j] != 0 && dp[i, j - 1] != 0)
                            {
                                if (arr[i, j] > arr[i - 1, j] && arr[i, j] > arr[i, j - 1])
                                    dp[i, j] = 1 + Math.Max(dp[i - 1, j], dp[i, j - 1]);
                                else if (arr[i, j] > arr[i - 1, j])
                                    dp[i, j] = 1 + dp[i - 1, j];
                                else if (arr[i, j] > arr[i, j - 1])
                                    dp[i, j] = 1 + dp[i, j - 1];
                            }
                            maxi = Math.Max(maxi, dp[i, j]);
                        }
                    }
                    Console.WriteLine("{0}", maxi);
                }
            }
        }
    }
