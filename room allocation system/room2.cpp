#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Data structure to represent a room
struct Room {
    int roomNumber;
    string host;
    int startTime;
    int endTime;
    bool chairBooking;

    Room(int num, string h, int start, int end, bool chair) : roomNumber(num), host(h), startTime(start), endTime(end), chairBooking(chair) {}
};

// Function to book a room
void bookRoom(vector<Room>& rooms, int roomNumber, string host, int startTime, int endTime, bool chairBooking) {
    Room newRoom(roomNumber, host, startTime, endTime, chairBooking);

    // Check if the room is available during the specified time
    auto overlap = find_if(rooms.begin(), rooms.end(), [&startTime, &endTime](const Room& r) {
        return (startTime < r.endTime && endTime > r.startTime);
    });

    if (overlap == rooms.end()) {
        // Room is available, book it
        rooms.push_back(newRoom);
        cout << "Room " << roomNumber << " booked successfully.\n";
    } else {
        cout << "Room " << roomNumber << " is not available during the specified time.\n";
    }
}

// Function to display room status
void displayRoomStatus(const vector<Room>& rooms) {
    cout << "Room Status:\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "Room No.\tHost\t\t\t\tStart Time\tEnd Time\tChair Booking\n";
    cout << "---------------------------------------------------------------------------------------\n";

    for (const auto& room : rooms) {
        cout << room.roomNumber << "\t\t" << room.host << "\t\t\t" << room.startTime << "\t\t" << room.endTime << "\t\t" << (room.chairBooking ? "Yes" : "No") << "\n";
    }

    cout << "----------------------------------------------------------------------------------------\n";
}

int main() {
    vector<Room> rooms;

    while (true) {
        cout << "\nRoom Allotment and Booking System\n";
        cout << "1. Book a Room\n";
        cout << "2. Display Room Status\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int roomNumber, startTime, endTime;
                string host;
                bool chairBooking;

                cout << "Enter Room Number: ";
                cin >> roomNumber;

                cout << "Enter Host Name: ";
                cin.ignore();
                getline(cin, host);

                cout << "Enter Start Time: ";
                cin >> startTime;

                cout << "Enter End Time: ";
                cin >> endTime;

                cout << "Chair Booking (1 for Yes, 0 for No): ";
                cin >> chairBooking;

                bookRoom(rooms, roomNumber, host, startTime, endTime, chairBooking);
                break;
            }
            case 2:
                displayRoomStatus(rooms);
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
