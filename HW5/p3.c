long reverse_logic(long x, long y, long z)
{
    long result;
    if (x < y){
        if (x > z){
            result = z - x;
        } else {
            result = x + z;
        }
    } else {
        if (y > z){
            result = z - y;
        } else {
            result = y + z;
        }
    }
    return result;
}