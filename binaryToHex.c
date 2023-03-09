char * binaryToHex(int binary[32])
{
    char hex[8];
    int temp[4];
    temp[0] = 0;
    temp[1] = 0;
    temp[2] = 0;
    temp[3] = 0;
    int skip = 0;
    
    for(int i = 0; i < 8 ; i++)
    {
        skip = (i * 4);
        binary[31 - skip] = temp[3];
        binary[30 - skip] = temp[2];
        binary[29 - skip] = temp[1];
        binary[28 - skip] = temp[0];
        
        if((temp[0] == 0) & (temp[1] == 0) & (temp[2] == 0 ) & (temp[3] == 0))
        {
            hex[7- i] = 0;
        }
        if((temp[0] == 1) & (temp[1] == 0) & (temp[2] == 0 ) & (temp[3] == 0))
        {
            hex[7- i] = 1;
        }
        if((temp[0] == 0) & (temp[1] == 1) & (temp[2] == 0 ) & (temp[3] == 0))
        {
            hex[7- i] = 2;
        }
        if((temp[0] == 1) & (temp[1] == 1) & (temp[2] == 0 ) & (temp[3] == 0))
        {
            hex[7- i] = 3;
        }
        if((temp[0] == 0) & (temp[1] == 0) & (temp[2] == 1 ) & (temp[3] == 0))
        {
            hex[7- i] = 4;
        }
        if((temp[0] == 1) & (temp[1] == 0) & (temp[2] == 1 ) & (temp[3] == 0))
        {
            hex[7- i] = 5;
        }
        if((temp[0] == 0) & (temp[1] == 1) & (temp[2] == 1 ) & (temp[3] == 0))
        {
            hex[7- i] = 6;
        }
        if((temp[0] == 1) & (temp[1] == 1) & (temp[2] == 1 ) & (temp[3] == 0))
        {
            hex[7- i] = 7;
        }
        if((temp[0] == 0) & (temp[1] == 0) & (temp[2] == 0 ) & (temp[3] == 1))
        {
            hex[7- i] = 8;
        }
        if((temp[0] == 1) & (temp[1] == 0) & (temp[2] == 0 ) & (temp[3] == 1))
        {
            hex[7- i] = 9;
        }
        if((temp[0] == 0) & (temp[1] == 1) & (temp[2] == 0 ) & (temp[3] == 1))
        {
            hex[7- i] = 'a';
        }
        if((temp[0] == 1) & (temp[1] == 1) & (temp[2] == 0 ) & (temp[3] == 1))
        {
            hex[7- i] = 'b';
        }
        if((temp[0] == 0) & (temp[1] == 0) & (temp[2] == 1 ) & (temp[3] == 1))
        {
            hex[7- i] = 'c';
        }
        if((temp[0] == 1) & (temp[1] == 0) & (temp[2] == 1 ) & (temp[3] == 1))
        {
            hex[7- i] = 'd';
        }
        if((temp[0] == 0) & (temp[1] == 1) & (temp[2] == 1 ) & (temp[3] == 1))
        {
            hex[7- i] = 'e';
        }
        if((temp[0] == 1) & (temp[1] == 1) & (temp[2] == 1 ) & (temp[3] == 1))
        {
            hex[7- i] = 'f';
        }
    }
    return hex;
}
