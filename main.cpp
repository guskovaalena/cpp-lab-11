#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <fstream>

using namespace std;

int main() {

    // 1. Контейнерные алгоритмы

    cout<<endl<<"КОНТЕЙНЕРНЫЕ АЛГОРИТМЫ"<<endl<<endl;

    list<int> list_1;

    int n1;
    cout<<"Введите целое число ИЛИ введите 0 для прерывания ввода: "<<endl;
    while (cin>>n1 && n1 != 0){
        list_1.push_back(n1);
    }
    cout<<"Введенные числа в списке длинной "<<list_1.size()<<": "<<endl;
    list<int>::iterator it1;
    for (it1 = list_1.begin(); it1 != list_1.end(); ++it1){
        cout<<*it1<<' ';
    }
    cout<<endl;

    int sum = 0;
    for (it1 = list_1.begin(); it1 != list_1.end(); ++it1){
        sum += *it1;
    }
    cout<<"Сумма элементов в списке: "<<sum<<endl;
    auto max_elem = max_element(list_1.begin(), list_1.end());
    cout<<"Максимальный элемент в списке: "<<*max_elem<<endl;
    auto min_elem = min_element(list_1.begin(), list_1.end());
    cout<<"Минимальный элемент в списке: "<<*min_elem<<endl;

    reverse(list_1.begin(), list_1.end());

    cout<<"Список в обратном порядке: "<<endl;
    for (it1 = list_1.begin(); it1 != list_1.end(); ++it1){
        cout<<*it1<<' ';
    }
    cout<<endl;

    list_1.sort();

    cout<<"Отсортированный по возрастанию список: "<<endl;
    for (it1 = list_1.begin(); it1 != list_1.end(); ++it1){
        cout<<*it1<<' ';
    }
    cout<<endl;

    // 2. Итераторы-адаптеры

    cout<<endl<<"ИТЕРАТОРЫ-АДАПТЕРЫ"<<endl<<endl;

    vector<int> vec_back;
    vector<int> vec_front;
    deque<int> deck;

    back_insert_iterator<vector<int>> back_it (vec_back);
    auto front_it = front_inserter(deck);
    int n2;
    cout<<"Введите целое число ИЛИ введите 0 для прерывания ввода: "<<endl;
    while (cin>>n2 && n2 != 0){
        *back_it = n2;
        *front_it = n2;
    }
    copy(deck.begin(), deck.end(), inserter(vec_front, vec_front.begin()));

    cout<<"Введенные числа вствлены в вектор с помощью back_inserter:"<<endl;
    for (auto it = vec_back.begin(); it != vec_back.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<endl;
    cout<<"Введенные числа вставлены в вектор с помощью перехода к deque и front_inserter:"<<endl;
    for (auto it = vec_front.begin(); it != vec_front.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<endl;


    // 3. Файловый ввод-вывод с итераторами

    cout<<endl<<"ФАЙЛОВЫЙ ВВОД-ВЫВОД С ИТЕРАТОРАМИ"<<endl<<endl;

    vector<string> str_vec;
    string st;
    cout<<"Введите строки для записи в файл text.txt"<<endl;
    while (cin>>st && st != "СТОП"){
        str_vec.push_back(st);
    }
    ofstream fout("text.txt");
    ostream_iterator<string> fout_it(fout, "\n");
    copy(str_vec.begin(), str_vec.end(), fout_it);
    fout.close();

    ifstream fin("text.txt");
    istream_iterator<string> fin_it(fin);
    istream_iterator<string> eof;
    cout<<"Содержимое файла text.txt: "<<endl;
    while (fin_it != eof) {
        cout << *fin_it++ << " ";
    }
    cout<<endl;
    fin.close();

    // 4. Взаимодействие итераторов

    cout<<endl<<"ВЗАИМОДЕЙСТВИЕ ИТЕРАТОРОВ"<<endl<<endl;

    std::vector<int> vec_1;
    std::deque<int> deck_1;

    int n3;
    cout<<"Введите целое число ИЛИ введите 0 для прерывания ввода: "<<endl;
    while (cin>>n3 && n3 != 0){
        vec_1.push_back(n3);
    }

    cout<<"Введенные числа в векторе: "<<endl;
    for (auto it = vec_1.begin(); it != vec_1.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<endl;
    copy(vec_1.begin(), vec_1.end(), front_insert_iterator<deque<int>>(deck_1));
    cout<<"Введенные числа в двухсторонней очереди: "<<endl;
    for (auto it = deck_1.begin(); it != deck_1.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<endl;

    // 5. Обратные итераторы

    cout<<endl<<"ОБРАТНЫЕ ИТЕРАТОРЫ"<<endl<<endl;

    list<int> list_2;

    int n4;
    cout<<"Введите целое число ИЛИ введите 0 для прерывания ввода: "<<endl;
    while (cin>>n4 && n4 != 0){
        list_2.push_back(n4);
    }
    cout<<"Введенные числа в списке длинной "<<list_2.size()<<": "<<endl;
    for (auto it = list_2.begin(); it1 != list_2.end(); ++it1){
        cout<<*it<<' ';
    }
    cout<<endl;

    cout<<"Вывод списка в обратном порядке с помощью обратных итераторов: "<<endl;
    for (list<int>::reverse_iterator r_it = list_2.rbegin(); r_it != list_2.rend(); ++r_it){
        cout<<*r_it<<' ';
    }
    cout<<endl;

    return 0;
}
