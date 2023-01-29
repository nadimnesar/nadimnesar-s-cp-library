ll binarytodecimal(ll binary)
{
    ll i = 0, decimal = 0;
    while(binary != 0)
    {
        decimal = decimal + pow(2, i)*(binary%10);
        binary /= 10;
        i++;
    }
    return decimal;
}
