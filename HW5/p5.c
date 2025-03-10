long loop_while_hw5(long a, long b)
{
    long result = 1;
    while (!(b >= a)) {
        result = result + (a - b);
        b = b + 1;
    }
    return result;
}