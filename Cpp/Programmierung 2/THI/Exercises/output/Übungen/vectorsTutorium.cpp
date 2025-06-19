#include <vector>
#include <iostream>
using namespace std;

// 1. Schreibe eine Funktion, die einen Vektor von ganzen Zahlen als Parameter erhält 
// und die Summe aller Elemente im Vektor zurückgibt.
int sumOfElements(const vector<int> vec) {
   int sum = 0;
   for (int i = 0; i < vec.size(); i++) {
    sum += vec[i];
   }
   return sum;
}

// 2. Implementiere eine Funktion, die einen Vektor von Zeichenfolgen als Parameter erhält
// und die längste Zeichenfolge im Vektor zurückgibt.
    string longestString(const vector<string> vec) {
    // todo
}

// 3. Schreibe eine Funktion, die einen Vektor von ganzen Zahlen als Parameter erhält 
// und einen neuen Vektor zurückgibt, der nur die geraden Zahlen aus dem ursprünglichen Vektor enthält.
std::vector<int> getEvenNumbers(vector<int> vec) {
    vector<int> evenNumbers;
    for (int num : vec) {
        if (num % 2 == 0) {
            evenNumbers.push_back(num);
        }
        return evenNumbers;
    }
}

// 4. Erstelle eine Funktion, die zwei Vektoren von ganzen Zahlen als Parameter erhält 
// und prüft, ob sie identisch sind (dh ob sie die gleichen Elemente in derselben Reihenfolge enthalten).
bool areVectorsIdentical(std::vector<int> vec1, std::vector<int> vec2) {
   //todo
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Sum of elements: " << sumOfElements(numbers) << std::endl;

    std::vector<std::string> strings = {"apple", "banana", "orange", "grapefruit"};
    std::cout << "Longest string: " << longestString(strings) << std::endl;

    std::vector<int> even = getEvenNumbers(numbers);
    std::cout << "Even numbers: ";
    for (int num : even) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> numbers1 = {1, 2, 3};
    std::vector<int> numbers2 = {1, 2, 3};
    std::cout << "Are vectors identical? " << std::boolalpha << areVectorsIdentical(numbers1, numbers2) << std::endl;

    return 0;
}