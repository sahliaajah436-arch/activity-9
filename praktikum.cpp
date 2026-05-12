#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

    int generateId() {
        return ++globalId;
    }

public:
    User(string nama, string email) {
        this->id = generateId();
        this->nama = nama;
        this->email = email;
    }

    int getId() {
        return id;
    }

    string getNama() {
        return nama;
    }

    string getEmail() {
        return email;
    }
};

int User::globalId = 0;

class Member : public User {
private:
    bool status; // true = aktif, false = nonaktif

public:
    Member(string nama, string email, bool status)
        : User(nama, email) {
        this->status = status;
    }

    void showProfile() {
        cout << "ID      : " << id << endl;
        cout << "Nama    : " << nama << endl;
        cout << "Email   : " << email << endl;
        cout << "Status  : " << (status ? "Aktif" : "Nonaktif") << endl;
        cout << "------------------------" << endl;
    }

    void setStatus(bool status) {
        this->status = status;
    }

    bool getStatus() {
        return status;
    }
};

class Admin : public User {
public:
    Admin(string nama, string email)
        : User(nama, email) {}

    void showAllMember(vector<Member*> members) {
        cout << "\n=== DAFTAR MEMBER ===\n";

        for (Member* member : members) {
            member->showProfile();
        }
    }

    void toggleActivationMember(Member* member) {
        member->setStatus(!member->getStatus());

        cout << member->getNama()
             << " berhasil diubah statusnya menjadi "
             << (member->getStatus() ? "Aktif" : "Nonaktif")
             << endl;
    }
};

int main() {

    Member* member1 = new Member("Shahlia", "shahlia@gmail.com", true);
    Member* member2 = new Member("Ama", "ama@gmail.com", false);

    vector<Member*> daftarMember;
    daftarMember.push_back(member1);
    daftarMember.push_back(member2);

    Admin* admin = new Admin("Admin", "admin@gmail.com");

    admin->showAllMember(daftarMember);

    cout << "\n=== TOGGLE STATUS MEMBER ===\n";
    admin->toggleActivationMember(member2);

    cout << "\n=== DATA SETELAH DIUBAH ===\n";
    admin->showAllMember(daftarMember);

    return 0;
}