
int f(int x);

int main()
{
    if ((f(0x00) == 0xff))
        return 0;
    return 1;
}
