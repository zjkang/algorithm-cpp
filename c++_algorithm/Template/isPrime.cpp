bool isPrime(int num){
    if (num==1) return false;
     int tmp=sqrt(num);
     for(int i=2;i<=tmp;i++)
        if(num%i==0)
          return 0;
     return 1;
}
