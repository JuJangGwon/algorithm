inputMoney() 
{
    while (true) {
        const input = await Console.readLineAsync(MESSAGE.INPUT_MONEY);
        if (isNaN(+input))  throw new Error(ERROR.INVALID_MONEY);
        if (+input % 1000 !== 0) throw new Error(ERROR.INVALID_UNIT);
      
        this.count = +input / 1000;
        return ;
      } 
    }
}
