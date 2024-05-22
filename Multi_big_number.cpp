#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string add(string lhs, string rhs) { //recibe 2 cadenas
    int length = max(lhs.size(), rhs.size()); //determina el tama�o de las cadenas recibidas
    int carry = 0;
    int sum_col;  // sum of two digits in the same column
    string result;

    // usamos estos while para ver si ambas cadenas son de igual tama�o, si no desiguales a�adimos ceros a la cadena 
    while (lhs.size() < length)
        lhs.insert(0, "0");

    while (rhs.size() < length)
        rhs.insert(0, "0");

    // build result string from right to left
    for (int i = length - 1; i >= 0; i--) {
        sum_col = (lhs[i] - '0') + (rhs[i] - '0') + carry; //(lhs[i] - '0') + (rhs[i] - '0') dentro de ASCII si restamos 0 con el caracter del digito colocado nos dar� su n�mero equivalente
        carry = sum_col / 10; //calcula el valor de acarreo para la siguiente suma
        result.insert(0, to_string(sum_col % 10)); // inserta el digito resultante en la posici�n inicial e la cadena
    }

    if (carry)
        result.insert(0, to_string(carry));

    // remove leading zeros
    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string subtract(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    int diff;
    string result;

    while (lhs.size() < length)
        lhs.insert(0, "0");

    while (rhs.size() < length)
        rhs.insert(0, "0");

    for (int i = length - 1; i >= 0; i--) {
        diff = (lhs[i] - '0') - (rhs[i] - '0');
        if (diff >= 0)
            result.insert(0, to_string(diff));
        else {
            int j = i - 1;
            while (j >= 0) {
                lhs[j] = ((lhs[j] - '0') - 1) % 10 + '0';
                if (lhs[j] != '9')
                    break;
                else
                    j--;
            }
            result.insert(0, to_string(diff + 10));
        }
    }
    // remove leading zeros
    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string multiply(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());

    while (lhs.size() < length)
        lhs.insert(0, "0");

    while (rhs.size() < length)
        rhs.insert(0, "0");

    if (length == 1)
        return to_string((lhs[0] - '0') * (rhs[0] - '0'));

    string lhs0 = lhs.substr(0, length / 2); //mitad superior
    string lhs1 = lhs.substr(length / 2, length - length / 2); //mitad inferior
    string rhs0 = rhs.substr(0, length / 2);
    string rhs1 = rhs.substr(length / 2, length - length / 2);

    string p0 = multiply(lhs0, rhs0); 
    string p1 = multiply(lhs1, rhs1);
    string p2 = multiply(add(lhs0, lhs1), add(rhs0, rhs1));
    string p3 = subtract(p2, add(p0, p1));

    for (int i = 0; i < 2 * (length - length / 2); i++)
        p0.append("0");
    for (int i = 0; i < length - length / 2; i++)
        p3.append("0");

    string result = add(add(p0, p1), p3);

    // remove leading zeros
    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

int main() {
    string x = "1234567891";
    string y = "9876543219";

    cout << "Resultado: " << multiply(x, y);

    return 0;
}