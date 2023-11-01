#include <stdio.h>
#include <stdint.h>

unsigned int reverseBits(unsigned int x)
{
    unsigned int bitLength = sizeof(x) * 8;
    unsigned int buffer = 0;
    for(int i=0; i<bitLength; i++)
    {
        if((x & (1 << i)))
            buffer |= 1 << ((bitLength - 1) - i);
    }
    return buffer;
}

// unsigned int reverseBits(unsigned int num)
// {
//     unsigned int NO_OF_BITS = sizeof(num) * 8;
//     unsigned int reverse_num = 0;
//     int i;
//     for (i = 0; i < NO_OF_BITS; i++) {
//         if ((num & (1 << i)))
//             reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
//     }
//     return reverse_num;
// }

int main()
{
    uint8_t _val = 0x02;
    printf("2's complement of 0x%x is 0x%x\n", _val, (~_val+0x01));

    unsigned int _val2 = 0x02;
    unsigned int _reversed;
    _reversed = reverseBits(_val2);
    printf("Reversed bit of 0x%x is 0x%x\n", _val, _reversed);
    return 0;
}