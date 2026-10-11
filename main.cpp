#include <iostream>
#include <string>

using namespace std;


struct Node {
    string data;
    Node* prev;
    Node* next;


    Node(string val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }


    void createInitialList() {
        clearList(); // Bersihkan list sebelumnya jika ada

        Node* nodeA = new Node("Song A");
        Node* nodeB = new Node("Song B");
        Node* nodeC = new Node("Song C");
        Node* nodeD = new Node("Song D");
        Node* nodeE = new Node("Song E");

        head = nodeA;


        nodeA->next = nodeB;

        nodeB->prev = nodeA;
        nodeB->next = nodeC;

        nodeC->prev = nodeB;
        nodeC->next = nodeD;

        nodeD->prev = nodeC;
        nodeD->next = nodeE;

        nodeE->prev = nodeD;
        tail = nodeE;

        cout << "[Info] List berhasil dibuat dengan 5 node awal!\n";
    }


    void displayForward() {
        if (head == nullptr) {
            cout << "List masih kosong!\n";
            return;
        }
        Node* current = head;
        cout << "Forward Traversal: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " <-> ";
            current = current->next;
        }
        cout << endl;
    }


    void displayBackward() {
        if (tail == nullptr) {
            cout << "List masih kosong!\n";
            return;
        }
        Node* current = tail;
        cout << "Backward Traversal: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->prev != nullptr) cout << " <-> ";
            current = current->prev;
        }
        cout << endl;
    }


    void insertMiddle() {
        Node* current = head;

        while (current != nullptr && current->data != "Song B") {
            current = current->next;
        }

        if (current != nullptr) {
            Node* newNode = new Node("Song X");
            Node* nextNode = current->next;


            newNode->next = nextNode;
            newNode->prev = current;


            current->next = newNode;
            if (nextNode != nullptr) {
                nextNode->prev = newNode;
            }
            cout << "[Info] Berhasil menyisipkan 'Song X' di antara Song B dan Song C.\n";
        } else {
            cout << "[Error] 'Song B' tidak ditemukan!\n";
        }
    }


    void deleteNodeC() {
        Node* current = head;
        while (current != nullptr && current->data != "Song C") {
            current = current->next;
        }

        if (current != nullptr) {
            Node* prevNode = current->prev; // Song X (atau B)
            Node* nextNode = current->next; // Song D

            if (prevNode != nullptr) {
                prevNode->next = nextNode;
            } else {
                head = nextNode;
            }

            if (nextNode != nullptr) {
                nextNode->prev = prevNode;
            } else {
                tail = prevNode;
            }

            delete current;
            cout << "[Info] Berhasil menghapus 'Song C'.\n";
        } else {
            cout << "[Error] 'Song C' tidak ditemukan!\n";
        }
    }


    void simulateBrowserHistory() {
        clearList();
        Node* n1 = new Node("Google");
        Node* n2 = new Node("YouTube");
        Node* n3 = new Node("GitHub");
        Node* n4 = new Node("StackOverflow");

        head = n1;
        n1->next = n2;

        n2->prev = n1;
        n2->next = n3;

        n3->prev = n2;
        n3->next = n4;

        n4->prev = n3;
        tail = n4;

        cout << "--- Simulasi Real-World (Browser History) ---\n";
        displayForward();
        cout << "Mengapa Doubly Linked List cocok? Karena mendukung navigasi tombol 'Back' (prev) dan 'Forward' (next) secara instan bolak-balik.\n";
    }

    void clearList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
};


int main() {
    DoublyLinkedList dll;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "       DOUBLY LINKED LIST MINI LAB       \n";
        cout << "=========================================\n";
        cout << "1. Buat List Awal (Song A - E) [Task 2]\n";
        cout << "2. Tampilkan Traversal Maju (Forward) [Task 3]\n";
        cout << "3. Tampilkan Traversal Mundur (Backward) [Task 4]\n";
        cout << "4. Sisip 'Song X' di antara B & C [Task 5]\n";
        cout << "5. Hapus 'Song C' [Task 6]\n";
        cout << "6. Simulasi Real-World (Browser History) [Task 7]\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu (0-6): ";
        cin >> choice;
        cout << "-----------------------------------------\n";

        switch (choice) {
            case 1:
                dll.createInitialList();
                dll.displayForward();
                break;
            case 2:
                dll.displayForward();
                break;
            case 3:
                dll.displayBackward();
                break;
            case 4:
                dll.insertMiddle();
                dll.displayForward();
                break;
            case 5:
                dll.deleteNodeC();
                dll.displayForward();
                break;
            case 6:
                dll.simulateBrowserHistory();
                break;
            case 0:
                cout << "Keluar dari program. Selesai!\n";
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (choice != 0);

    return 0;
}
