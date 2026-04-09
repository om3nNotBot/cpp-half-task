#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
using namespace std;

struct Doctor {
    int id;
    char ad[50];
    char soyad[50];
    char ixtisas[50];
    int tecrube;
    char nomre[50];
    char mail[50];
};

Doctor** doctors = nullptr;
int countDoctors = 0;

void addToArray(Doctor* d) {
    Doctor** temp = new Doctor * [countDoctors + 1];

    for (int i = 0; i < countDoctors; i++)
        temp[i] = doctors[i];

    temp[countDoctors] = d;

    delete[] doctors;
    doctors = temp;
    countDoctors++;
}

void addDoctor() {
    system("cls");

    Doctor* d = new Doctor;

    cout << "ID: "; cin >> d->id;
    cout << "Ad: "; cin >> d->ad;
    cout << "Soyad: "; cin >> d->soyad;
    cout << "Ixtisas: "; cin >> d->ixtisas;
    cout << "Tecrube: "; cin >> d->tecrube;
    cout << "Nomre: "; cin >> d->nomre;
    cout << "Mail: "; cin >> d->mail;

    addToArray(d);

    cout << "\nElave olundu!\n";
    system("pause");
}

void updateDoctor() {
    system("cls");

    if (countDoctors == 0) {
        cout << "Doctor yoxdur!\n";
        system("pause");
        return;
    }

    const char* menu[2] = {
        "By ID",
        "Siyahidan sec"
    };

    int sec = 0;

    while (true) {
        system("cls");

        for (int i = 0; i < 2; i++) {
            cout << menu[i];
            if (i == sec) cout << " <-";
            cout << endl;
        }

        int key = _getch();

        if (key == 224 || key == 0) {
            key = _getch();

            if (key == 72) {
                sec--;
                if (sec < 0) sec = 1;
            }
            else if (key == 80) {
                sec++;
                if (sec > 1) sec = 0;
            }
        }
        else if (key == 13) break;
    }

    if (sec == 0) {
        int id;
        cout << "ID daxil et: ";
        cin >> id;

        for (int i = 0; i < countDoctors; i++) {
            if (doctors[i]->id == id) {
                cout << "Yeni Ad: "; cin >> doctors[i]->ad;
                cout << "Yeni Soyad: "; cin >> doctors[i]->soyad;
                cout << "Yeni Ixtisas: "; cin >> doctors[i]->ixtisas;
                cout << "Yeni Tecrube: "; cin >> doctors[i]->tecrube;
                cout << "Yeni Nomre: "; cin >> doctors[i]->nomre;
                cout << "Yeni Mail: "; cin >> doctors[i]->mail;

                cout << "\nUpdate olundu!\n";
                system("pause");
                return;
            }
        }

        cout << "Tapilmadi!\n";
        system("pause");
    }
    else {
        int index = 0;

        while (true) {
            system("cls");

            for (int i = 0; i < countDoctors; i++) {
                cout << doctors[i]->ad << " " << doctors[i]->soyad;
                if (i == index) cout << " <-";
                cout << endl;
            }

            int key = _getch();

            if (key == 224 || key == 0) {
                key = _getch();

                if (key == 72) index = (index - 1 + countDoctors) % countDoctors;
                else if (key == 80) index = (index + 1) % countDoctors;
            }
            else if (key == 13) {
                cout << "Yeni Ad: "; cin >> doctors[index]->ad;
                cout << "Yeni Soyad: "; cin >> doctors[index]->soyad;
                cout << "Yeni Ixtisas: "; cin >> doctors[index]->ixtisas;
                cout << "Yeni Tecrube: "; cin >> doctors[index]->tecrube;
                cout << "Yeni Nomre: "; cin >> doctors[index]->nomre;
                cout << "Yeni Mail: "; cin >> doctors[index]->mail;

                cout << "\nUpdate olundu!\n";
                system("pause");
                return;
            }
        }
    }
}

void getDoctors() {
    system("cls");

    if (countDoctors == 0) {
        cout << "Doctor yoxdur!\n";
        system("pause");
        return;
    }

    char ixtisaslar[50][50];
    int countIxt = 0;

    for (int i = 0; i < countDoctors; i++) {
        bool var = false;

        for (int j = 0; j < countIxt; j++) {
            if (strcmp(ixtisaslar[j], doctors[i]->ixtisas) == 0) {
                var = true;
                break;
            }
        }

        if (!var) {
            strcpy(ixtisaslar[countIxt++], doctors[i]->ixtisas);
        }
    }

    int sec = 0;

    while (true) {
        system("cls");

        cout << "Ixtisas sec:\n";

        for (int i = 0; i < countIxt; i++) {
            if (i == sec) cout << ">> ";
            else cout << "   ";

            cout << ixtisaslar[i] << endl;
        }

        int key = _getch();

        if (key == 224 || key == 0) {
            key = _getch();

            if (key == 72) sec = (sec - 1 + countIxt) % countIxt;
            else if (key == 80) sec = (sec + 1) % countIxt;
        }
        else if (key == 13) break;
    }

    int indexes[50];
    int cnt = 0;

    for (int i = 0; i < countDoctors; i++) {
        if (strcmp(doctors[i]->ixtisas, ixtisaslar[sec]) == 0) {
            indexes[cnt++] = i;
        }
    }

    int secDoc = 0;

    while (true) {
        system("cls");

        for (int i = 0; i < cnt; i++) {
            if (i == secDoc) cout << ">> ";
            else cout << "   ";

            cout << doctors[indexes[i]]->ad << " "
                << doctors[indexes[i]]->soyad << endl;
        }

        int key = _getch();

        if (key == 224 || key == 0) {
            key = _getch();

            if (key == 72) secDoc = (secDoc - 1 + cnt) % cnt;
            else if (key == 80) secDoc = (secDoc + 1) % cnt;
        }
        else if (key == 13) {
            Doctor* d = doctors[indexes[secDoc]];

            system("cls");
            cout << "ID: " << d->id << endl;
            cout << "Ad: " << d->ad << endl;
            cout << "Soyad: " << d->soyad << endl;
            cout << "Ixtisas: " << d->ixtisas << endl;
            cout << "Tecrube: " << d->tecrube << endl;
            cout << "Nomre: " << d->nomre << endl;
            cout << "Mail: " << d->mail << endl;

            system("pause");
            return;
        }
    }
}

void getDoctorById() {
    system("cls");

    int id;
    cout << "ID daxil et: ";
    cin >> id;

    for (int i = 0; i < countDoctors; i++) {
        if (doctors[i]->id == id) {
            cout << "\nID: " << doctors[i]->id << endl;
            cout << "Ad: " << doctors[i]->ad << endl;
            cout << "Soyad: " << doctors[i]->soyad << endl;
            cout << "Ixtisas: " << doctors[i]->ixtisas << endl;
            cout << "Tecrube: " << doctors[i]->tecrube << endl;
            cout << "Nomre: " << doctors[i]->nomre << endl;
            cout << "Mail: " << doctors[i]->mail << endl;

            system("pause");
            return;
        }
    }

    cout << "Tapilmadi!\n";
    system("pause");
}

void showMenu(int secim) {
    system("cls");

    const char* menu[5] = {
        "Add Doctor",
        "Update Doctor",
        "Get Doctors",
        "Get Doctor By ID",
        "Exit"
    };

    for (int i = 0; i < 5; i++) {
        cout << menu[i];

        if (i == secim)
            cout << " <-";

        cout << endl;
    }
}

void initDoctors() {
    Doctor* d1 = new Doctor{ 1, "Ali", "Huseynov", "Kardio", 10, "0501111111", "ali@mail.com" };
    addToArray(d1);

    Doctor* d2 = new Doctor{ 2, "Aysel", "Memmedova", "Kardio", 7, "0502222222", "aysel@mail.com" };
    addToArray(d2);

    Doctor* d3 = new Doctor{ 3, "Rauf", "Aliyev", "Kardio", 12, "0503333333", "rauf@mail.com" };
    addToArray(d3);

    Doctor* d4 = new Doctor{ 4, "Nigar", "Quliyeva", "Nevroloq", 8, "0504444444", "nigar@mail.com" };
    addToArray(d4);

    Doctor* d5 = new Doctor{ 5, "Elvin", "Mammadli", "Nevroloq", 6, "0505555555", "elvin@mail.com" };
    addToArray(d5);

    Doctor* d6 = new Doctor{ 6, "Leyla", "Hesenova", "Nevroloq", 9, "0506666666", "leyla@mail.com" };
    addToArray(d6);

    Doctor* d7 = new Doctor{ 7, "Orxan", "Baxshaliyev", "Cerrah", 11, "0507777777", "orxan@mail.com" };
    addToArray(d7);

    Doctor* d8 = new Doctor{ 8, "Sevda", "Ibrahimova", "Cerrah", 5, "0508888888", "sevda@mail.com" };
    addToArray(d8);

    Doctor* d9 = new Doctor{ 9, "Tural", "Suleymanov", "Cerrah", 13, "0509999999", "tural@mail.com" };
    addToArray(d9);
}

int main() {
    initDoctors();
    int secim = 0;

    while (true) {
        showMenu(secim);

        int key = _getch();

        if (key == 224 || key == 0) {
            key = _getch();

            if (key == 72) {
                secim--;
                if (secim < 0) secim = 4;
            }
            else if (key == 80) {
                secim++;
                if (secim > 4) secim = 0;
            }
        }
        else if (key == 13) {
            switch (secim) {
            case 0: addDoctor(); break;
            case 1: updateDoctor(); break;
            case 2: getDoctors(); break;
            case 3: getDoctorById(); break;
            case 4: return 0;
            }
        }
    }
}
