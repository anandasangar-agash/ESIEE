unsigned int packet_size(unsigned int n) {
    unsigned int count = 0;

    if (n == 0)
        return 0;

    while (!(n & 0x80000000))
        n <<= 1;

    while (n & 0x80000000) {
        count++;
        n <<= 1;
    }

    return count;
}