
int toLowerCase(char a)
{
    if ((a >= 'A') && (a <= 'Z'))
    {
        return a += 32;
    }
    return a;
}

int toUpperCase(char a)
{
    if ((a >= 'a') && (a <= 'z'))
    {
        return a -= 32;
    }
    return a;
}