function solution(phone_book) {
  const map = {};
  const result = phone_book.sort().every((phoneNumber) => {
    const filter = phoneNumber.split("").every((num, index) => {
      const tempNum = phoneNumber.slice(0, index + 1);
      //
      if (map[tempNum]) {
        return false;
      }
      return true;
    });
    map[phoneNumber] = 1;
    return filter;
  });
  return result;
}
