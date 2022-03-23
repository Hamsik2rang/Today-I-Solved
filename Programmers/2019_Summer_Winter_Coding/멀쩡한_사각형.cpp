using namespace std;

int GCD(int a, int b)
{
    while (a % b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return b;
}

long long solution(int w, int h)
{
    long long answer = 0l;
    if (w * h == 1)
    {
        return 0;
	}
    if (w > h)
    {
        int temp = w;
        w = h;
        h = temp;
    }
    int gcd = GCD(h, w);
    answer = (long long)w * (long long)h - (w + h) + gcd;

    return answer;
}
