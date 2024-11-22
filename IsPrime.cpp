bool isPrime(int num) 
    {
        if(num < 2)
            return false;
        for(int i=2; i < int(pow(num,0.5)) + 1; i++)
            if(num % i == 0)
                return false;
        return true;
    }
