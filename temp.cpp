#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    // 초기값으로 첫 번째 숫자 설정
    std::string sequence = input.substr(0, 1);

    // 주어진 문자열을 탐색하면서 엄격히 증가하는 수열 만들기
    for (int i = 1; i < input.length(); i++) {
        // 현재 숫자가 이전 숫자보다 크면 수열에 추가
        if (input[i] > sequence.back()) {
            sequence += input[i];
        }
    }

    // 결과 출력
    std::cout << sequence.back() << std::endl;

    return 0;
}