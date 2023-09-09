#include <iostream>
#include <cstring>

using namespace std;

class Contact {
private:
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

public:
    Contact(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);

        homePhone = new char[strlen(home) + 1];
        strcpy(homePhone, home);

        workPhone = new char[strlen(work) + 1];
        strcpy(workPhone, work);

        mobilePhone = new char[strlen(mobile) + 1];
        strcpy(mobilePhone, mobile);

        additionalInfo = new char[strlen(info) + 1];
        strcpy(additionalInfo, info);
    }

    ~Contact() {
        delete[] fullName;
        delete[] homePhone;
        delete[] workPhone;
        delete[] mobilePhone;
        delete[] additionalInfo;
    }

    const char* getFullName() const {
        return fullName;
    }

    const char* getHomePhone() const {
        return homePhone;
    }

    const char* getWorkPhone() const {
        return workPhone;
    }

    const char* getMobilePhone() const {
        return mobilePhone;
    }

    const char* getAdditionalInfo() const {
        return additionalInfo;
    }
};

class PhoneBook {
private:
    Contact** contacts;
    int maxContacts;
    int currentContacts;

public:
    PhoneBook(int maxSize = 100) {
        maxContacts = maxSize;
        contacts = new Contact*[maxContacts];
        currentContacts = 0;
    }

    ~PhoneBook() {
        for (int i = 0; i < currentContacts; i++) {
            delete contacts[i];
        }
        delete[] contacts;
    }

    void addContact(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
        if (currentContacts < maxContacts) {
            contacts[currentContacts] = new Contact(name, home, work, mobile, info);
            currentContacts++;
            cout << "Абонент '" << name << "' добавлен в телефонную книгу." << endl;
        } else {
            cout << "Телефонная книга полна. Невозможно добавить нового абонента." << endl;
        }
    }

    void deleteContact(const char* name) {
        for (int i = 0; i < currentContacts; i++) {
            if (strcmp(contacts[i]->getFullName(), name) == 0) {
                delete contacts[i];

                // Сдвигаем элементы массива для удаления контакта
                for (int j = i; j < currentContacts - 1; j++) {
                    contacts[j] = contacts[j + 1];
                }

                currentContacts--;
                cout << "Абонент с ФИО '" << name << "' удален из телефонной книги." << endl;
                return;
            }
        }
        cout << "Абонент с ФИО '" << name << "' не найден в телефонной книге." << endl;
    }

    void Input() {
        char buff[50];
        cout << "Абонент с ФИО -> ";
        cin >> buff;
        char name[50];
        strcpy(name, buff);

        cout << "Домашний телефон -> ";
        cin >> buff;
        char home[50];
        strcpy(home, buff);

        cout << "Рабочий телефон -> ";
        cin >> buff;
        char work[50];
        strcpy(work, buff);

        cout << "Мобильный телефон -> ";
        cin >> buff;
        char mobile[50];
        strcpy(mobile, buff);

        cout << "Дополнительная информация -> ";
        cin >> buff;
        char additionalInfo[50];
        strcpy(additionalInfo, buff);

        addContact(name, home, work, mobile, additionalInfo);
    }
  void Print(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
    if (name == nullptr || home == nullptr || work == nullptr || mobile == nullptr || info == nullptr) {
        cout << "This contact has been deleted." << endl;
        return;
    }
    cout << "Name: " << name << "\tHome: " << home << "\tWork: " << work << "\tMobile: " << mobile << "\tInfo: " << info << endl;
}

    bool IsDeleted(const char* name, const char* home, const char* work, const char* mobile, const char* info) const {
        return (name == nullptr);
        return (home == nullptr);
        return (work == nullptr);
        return (mobile == nullptr);
        return (info == nullptr);
    }


    void findContact(const char* name) {
        for (int i = 0; i < currentContacts; i++) {
            if (strcmp(contacts[i]->getFullName(), name) == 0) {
                cout << "Информация о контакте:" << endl;
                cout << "ФИО: " << contacts[i]->getFullName() << endl;
                cout << "Домашний телефон: " << contacts[i]->getHomePhone() << endl;
                cout << "Рабочий телефон: " << contacts[i]->getWorkPhone() << endl;
                cout << "Мобильный телефон: " << contacts[i]->getMobilePhone() << endl;
                cout << "Дополнительная информация: " << contacts[i]->getAdditionalInfo() << endl;
                return;
            }
        }
        cout << "Абонент с ФИО '" << name << "' не найден в телефонной книге." << endl;
    }

    void showAllContacts() {
        for (int i = 0; i < currentContacts; i++) {
            cout << "Контакт:" << endl;
            cout << "ФИО: " << contacts[i]->getFullName() << endl;
            cout << "Домашний телефон: " << contacts[i]->getHomePhone() << endl;
            cout << "Рабочий телефон: " << contacts[i]->getWorkPhone() << endl;
            cout << "Мобильный телефон: " << contacts[i]->getMobilePhone() << endl;
            cout << "Дополнительная информация: " << contacts[i]->getAdditionalInfo() << endl;
            cout << endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;

    phoneBook.addContact("Тимур Ямчук", "+123456789", "+987654321", "+987123456", "Друзья");
    phoneBook.addContact("Дании Пластун", "+111111111", "+222222222", "+333333333", "Коллеги");
    phoneBook.addContact("Вадим Хубулури", "+444444444", "+555555555", "+666666666", "Семья");

    char name[50];
    char home[50];
    char work[50];
    char mobile[50];
    char info[50];

    cout << "Введите данные для нового контакта:" << endl;
    cout << "ФИО: ";
    cin >> name;

    cout << "Домашний телефон: ";
    cin >> home;

    cout << "Рабочий телефон: ";
    cin >> work;

    cout << "Мобильный телефон: ";
    cin >> mobile;

    cout << "Дополнительная информация: ";
    cin >> info;

    phoneBook.addContact(name, home, work, mobile, info);

    cout << "Список контактов:" << endl;
    phoneBook.showAllContacts();

    cout << "Поиск контакта по ФИО:" << endl;
    char searchName[50];
    cout << "Введите ФИО для поиска: ";
    cin >> searchName;
    phoneBook.findContact(searchName);

    cout << "Удаление контакта:" << endl;
    char deleteName[50];
    cout << "Введите ФИО для удаления: ";
    cin >> deleteName;
    phoneBook.deleteContact(deleteName);

    return 0;
}
